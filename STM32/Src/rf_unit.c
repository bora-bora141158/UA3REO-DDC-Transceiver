#include "stm32h7xx_hal.h"
#include "main.h"
#include "rf_unit.h"
#include "lcd.h"
#include "trx_manager.h"
#include "settings.h"
#include "system_menu.h"
#include "functions.h"
#include "audio_filters.h"

static uint8_t getBPFByFreq(uint32_t freq)
{
	if (freq >= CALIBRATE.BPF_0_START && freq < CALIBRATE.BPF_0_END)
		return 0;
	if (freq >= CALIBRATE.BPF_1_START && freq < CALIBRATE.BPF_1_END)
		return 1;
	if (freq >= CALIBRATE.BPF_2_START && freq < CALIBRATE.BPF_2_END)
		return 2;
	if (freq >= CALIBRATE.BPF_3_START && freq < CALIBRATE.BPF_3_END)
		return 3;
	if (freq >= CALIBRATE.BPF_4_START && freq < CALIBRATE.BPF_4_END)
		return 4;
	if (freq >= CALIBRATE.BPF_5_START && freq < CALIBRATE.BPF_5_END)
		return 5;
	if (freq >= CALIBRATE.BPF_6_START && freq < CALIBRATE.BPF_6_END)
		return 6;
	if (freq >= CALIBRATE.BPF_HPF)
		return 7;
	return 255;
}

void RF_UNIT_UpdateState(bool clean) //передаём значения в RF-UNIT
{
	bool dualrx_lpf_disabled = false;
	bool dualrx_bpf_disabled = false;
	if ((TRX.Dual_RX_Type != VFO_SEPARATE) && SecondaryVFO()->Freq > CALIBRATE.LPF_END)
		dualrx_lpf_disabled = true;
	if ((TRX.Dual_RX_Type != VFO_SEPARATE) && getBPFByFreq(CurrentVFO()->Freq) != getBPFByFreq(SecondaryVFO()->Freq))
		dualrx_bpf_disabled = true;

	float32_t att_val = TRX.ATT;
	bool att_val_16 = false, att_val_8 = false, att_val_4 = false, att_val_2 = false, att_val_1 = false, att_val_05 = false;
	if(att_val >= 16.0f)
	{
		att_val_16 = true;
		att_val -= 16.0f;
	}
	if(att_val >= 8.0f)
	{
		att_val_8 = true;
		att_val -= 8.0f;
	}
	if(att_val >= 4.0f)
	{
		att_val_4 = true;
		att_val -= 4.0f;
	}
	if(att_val >= 2.0f)
	{
		att_val_2 = true;
		att_val -= 2.0f;
	}
	if(att_val >= 1.0f)
	{
		att_val_1 = true;
		att_val -= 1.0f;
	}
	if(att_val >= 0.5f)
	{
		att_val_05 = true;
		att_val -= 0.5f;
	}
	
	uint8_t bpf = getBPFByFreq(CurrentVFO()->Freq);
	
	uint8_t band_out = 0;
	int8_t band = getBandFromFreq(CurrentVFO()->Freq, true);
	if(band == 0) //2200m
		band_out = 0;
	if(band == 3) //160m
		band_out = 1;
	if(band == 6) //80m
		band_out = 2;
	if(band == 10) //60m
		band_out = 3;
	if(band == 12) //40m
		band_out = 4;
	if(band == 15) //30m
		band_out = 5;
	if(band == 18) //20m
		band_out = 6;
	if(band == 21) //17m
		band_out = 7;
	if(band == 23) //15m
		band_out = 8;
	if(band == 25) //12m
		band_out = 9;
	if(band == 27) //CB
		band_out = 10;
	if(band == 28) //10m
		band_out = 11;
	if(band == 29) //6m
		band_out = 12;
	if(band == 30) //FM
		band_out = 13;
	if(band == 32) //2m
		band_out = 14;
	if(band == 33) //70cm
		band_out = 15;
	
	HAL_GPIO_WritePin(RFUNIT_RCLK_GPIO_Port, RFUNIT_RCLK_Pin, GPIO_PIN_RESET); //защёлка
	MINI_DELAY
	for (uint8_t registerNumber = 0; registerNumber < 24; registerNumber++)
	{
		HAL_GPIO_WritePin(RFUNIT_CLK_GPIO_Port, RFUNIT_CLK_Pin, GPIO_PIN_RESET); //клок данных
		MINI_DELAY
		HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_RESET); //данные
		MINI_DELAY
		if (!clean)
		{
			//U7-QH LPF_ON
			if (registerNumber == 0 && TRX.LPF && (CurrentVFO()->Freq <= CALIBRATE.LPF_END) && !dualrx_lpf_disabled)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QG LNA_ON
			if (registerNumber == 1 && !TRX_on_TX() && TRX.LNA)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QF ATT_ON_0.5
			if (registerNumber == 2 && att_val_05)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QE ATT_ON_1
			if (registerNumber == 3 && att_val_1)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QD ATT_ON_2
			if (registerNumber == 4 && att_val_2)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QC ATT_ON_4
			if (registerNumber == 5 && att_val_4)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QB ATT_ON_8
			if (registerNumber == 6 && att_val_8)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U7-QA ATT_ON_16
			if (registerNumber == 7 && att_val_16)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			
			//U1-QH NOT USED
			if (registerNumber == 8) {}
			//U1-QG BPF_2_A0
			if (registerNumber == 9 && TRX.BPF && !dualrx_bpf_disabled && (bpf == 5 || bpf == 6))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U1-QF BPF_2_A1
			if (registerNumber == 10 && TRX.BPF && !dualrx_bpf_disabled && (bpf == 0 || bpf == 6))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U1-QE BPF_2_EN
			if (registerNumber == 11 && (!TRX.BPF || dualrx_bpf_disabled || (bpf != 0 && bpf != 5 && bpf != 6 && bpf != 7)))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U1-QD BPF_1_A0
			if (registerNumber == 12 && TRX.BPF && !dualrx_bpf_disabled && (bpf == 1 || bpf == 2))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U1-QC BPF_1_A1
			if (registerNumber == 13 && TRX.BPF && !dualrx_bpf_disabled && (bpf == 4 || bpf == 2))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U1-QB BPF_1_EN
			if (registerNumber == 14 && (!TRX.BPF || dualrx_bpf_disabled || (bpf != 1 && bpf != 2 && bpf != 3 && bpf != 4)))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U1-QA BPF_ON
			if (registerNumber == 15 && TRX.BPF && !dualrx_bpf_disabled)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			
			//U3-QH BAND_OUT_0
			if (registerNumber == 16 && bitRead(band_out, 0))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U3-QG PTT_OUT
			if (registerNumber == 17 && TRX_on_TX() && CurrentVFO()->Mode != TRX_MODE_LOOPBACK)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U3-QF BAND_OUT_2
			if (registerNumber == 18 && bitRead(band_out, 2))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U3-QE BAND_OUT_3
			if (registerNumber == 19 && bitRead(band_out, 3))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U3-QD TUNE_OUT
			if (registerNumber == 20 && TRX_Tune)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U3-QC BAND_OUT_1
			if (registerNumber == 21 && bitRead(band_out, 1))
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
			//U3-QB FAN_OUT
			if (registerNumber == 22 && ((TRX_on_TX() && CurrentVFO()->Mode != TRX_MODE_LOOPBACK) || TRX_Fan_Timeout > 0)) //FAN
			{
				if(TRX_Fan_Timeout < (30 * 100)) //PWM
				{
					const uint8_t on_ticks = 1;
					const uint8_t off_ticks = 1;
					static bool pwm_status = false; //true - on false - off
					static uint8_t pwm_ticks = 0;
					pwm_ticks++;
					if(pwm_status)
						HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
					if((pwm_status && pwm_ticks==on_ticks) || (!pwm_status && pwm_ticks==off_ticks))
					{
						pwm_status = !pwm_status;
						pwm_ticks = 0;
					}
				}
				else
					HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
				if (TRX_Fan_Timeout > 0)
					TRX_Fan_Timeout--;
			}
			//U3-QA ANT1_TX_OUT
			if (registerNumber == 23 && !TRX.ANT)
				HAL_GPIO_WritePin(RFUNIT_DATA_GPIO_Port, RFUNIT_DATA_Pin, GPIO_PIN_SET);
		}
		MINI_DELAY
		HAL_GPIO_WritePin(RFUNIT_CLK_GPIO_Port, RFUNIT_CLK_Pin, GPIO_PIN_SET);
	}
	MINI_DELAY
	HAL_GPIO_WritePin(RFUNIT_CLK_GPIO_Port, RFUNIT_CLK_Pin, GPIO_PIN_RESET);
	MINI_DELAY
	HAL_GPIO_WritePin(RFUNIT_RCLK_GPIO_Port, RFUNIT_RCLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RFUNIT_OE_GPIO_Port, RFUNIT_OE_Pin, GPIO_PIN_RESET);
}

void RF_UNIT_ProcessSensors(void)
{
	float32_t forward = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_2) * TRX_STM32_VREF / 65535.0f;
	float32_t backward = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_1) * TRX_STM32_VREF / 65535.0f;
	//float32_t rf_thermal = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_3) * TRX_STM32_VREF / 65535.0f;
	//float32_t alc = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_4) * TRX_STM32_VREF / 65535.0f;
	static float32_t TRX_VLT_forward = 0.0f;
	static float32_t TRX_VLT_backward = 0.0f;
	
	forward = forward / (510.0f / (0.1f + 510.0f)); //корректируем напряжение исходя из делителя напряжения (0.1ом и 510ом)
	if (forward < 0.01f)							//меньше 10mV не измеряем
	{
		TRX_VLT_forward = 0.0f;
		TRX_VLT_backward = 0.0f;
		TRX_SWR = 1.0f;
		return;
	}

	forward += 0.62f;							  // падение на диоде
	forward = forward * CALIBRATE.swr_trans_rate; // Коэффициент трансформации КСВ метра

	backward = backward / (510.0f / (0.1f + 510.0f)); //корректируем напряжение исходя из делителя напряжения (0.1ом и 510ом)
	if (backward >= 0.01f)							  //меньше 10mV не измеряем
	{
		backward += 0.62f;								// падение на диоде
		backward = backward * CALIBRATE.swr_trans_rate; //Коэффициент трансформации КСВ метра
	}
	else
		backward = 0.001f;

	TRX_VLT_forward = TRX_VLT_forward + (forward - TRX_VLT_forward) / 2;
	TRX_VLT_backward = TRX_VLT_backward + (backward - TRX_VLT_backward) / 2;
	TRX_SWR = (TRX_VLT_forward + TRX_VLT_backward) / (TRX_VLT_forward - TRX_VLT_backward);

	if (TRX_VLT_backward > TRX_VLT_forward)
		TRX_SWR = 10.0f;
	if (TRX_SWR > 10.0f)
		TRX_SWR = 10.0f;
	
	TRX_PWR_Forward = (TRX_VLT_forward * TRX_VLT_forward) / 50.0f;
	if (TRX_PWR_Forward < 0.0f)
			TRX_PWR_Forward = 0.0f;
	TRX_PWR_Backward = (TRX_VLT_backward * TRX_VLT_backward) / 50.0f;
	if (TRX_PWR_Backward < 0.0f)
			TRX_PWR_Backward = 0.0f;

	LCD_UpdateQuery.StatusInfoBar = true;
}
