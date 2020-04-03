#ifndef SETTINGS_h
#define SETTINGS_h

#include "stm32h7xx_hal.h"
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "bands.h"

#define ADCDAC_CLOCK 122880000			//Частота генератора АЦП/ЦАП
#define MAX_FREQ_HZ 750000000				//Максимальная частота приёма (из даташита АЦП)
#define MAX_TX_FREQ_HZ 60000000			//Максимальная частота передачи (половина от тактового сигнала ЦАП)
#define TRX_SAMPLERATE 48000				//частота дискретизации аудио-потока
#define MAX_TX_AMPLITUDE 0.9f				//Максимальный размах при передаче в ЦАП
#define AGC_CLIP_THRESHOLD -15.0f		//Максимальный уровень усиления в AGC, выше него происходит клиппинг, dbFS
#define AGC_OPTIMAL_THRESHOLD -25.0f	//Рабочий уровень усиления в AGC, dbFS
#define AGC_MAX_GAIN 50.0f					//Максимальное усиление в AGC
#define AGC_NOISE_GATE -90.0f				//ниже этого уровня - не усиливаем
#define TUNE_POWER 100							//% от выбранной в настройках мощности при запуске TUNE (100 - полная)
#define TX_AGC_MAXGAIN 500.0f				//Максимальное усиление микрофона при компрессировании
#define TX_AGC_NOISEGATE 0.00001f		//Минимальный уровень сигнала для усиления (ниже - шум, отрезаем)
#define TOUCHPAD_DELAY 200					//Время защиты от анти-дребезга нажания на тачпад
#define AUTOGAIN_MAX_AMPLITUDE 16383.0f //максимальная амлитуда, по достижению которой автокорректировщик входных цепей завершает работу, а при переполнении - снижает усиление
#define AUTOGAIN_CORRECTOR_WAITSTEP 7   //ожидание усреднения результатов при работе автокорректора входных цепей
#define ENCODER_INVERT 1						//инвертировать вращение влево-вправо у основного энкодера
#define ENCODER2_INVERT 0						//инвертировать вращение влево-вправо у дополнительного энкодера
#define KEY_HOLD_TIME 500						//время длительного нажатия на кнопку клавиатуры для срабатывания, мс
#define SHIFT_INTERVAL 400.0f				//диапазон расстройки ручкой SHIFT (400.0f = -200hz / +200hz)
#define EEPROM_WRITE_INTERVAL 10000	//Запись в EEPROM не чаще, чем раз в 10 секунд (против износа)
#define MAX_RF_POWER 7.0f						//Максимум мощности (для шкалы измерителя)
#define SWR_CRITICAL 5.0f						//Максимальный КСВ, при котором отключается передатчик
#define SHOW_LOGO false							//Отображать логотип при загрузке (из lcd.h)
#define POWERDOWN_TIMEOUT 1000			//время нажатия на кнопку выключения, для срабатывания, мс
#define USB_RESTART_TIMEOUT 5000		//время, через которое происходит рестарт USB если нет пакетов
#define ILI9481 true								//он же HX8357B //другие комментируем
#define FMC_REMAP true							//ремап памяти FMC
#define FSMC_REGISTER_SELECT 18 		//из FSMC настроек в STM32Cube (A18, A6, и т.д.)
#define SCREEN_ROTATE 0							//перевернуть экран вверх ногами

#define ADC_BITS 16						//разрядность АЦП
#define FPGA_BUS_BITS 32				//разрядность данных из FPGA
#define CODEC_BITS 32				//разрядность данных в аудио-кодеке
#define FPGA_BUS_FULL_SCALE 65536		   //максимальная аплитуда сигнала в шине // powf(2,FPGA_BUS_BITS)
#define FPGA_BUS_FULL_SCALE_POW ((float64_t)FPGA_BUS_FULL_SCALE*(float64_t)FPGA_BUS_FULL_SCALE) //магнитуда максимального сигнала в шине // (FPGA_BUS_FULL_SCALE*FPGA_BUS_FULL_SCALE)
#define CODEC_BITS_FULL_SCALE 4294967296		   //максимальная аплитуда сигнала в шине // powf(2,FPGA_BUS_BITS)
#define CODEC_BITS_FULL_SCALE_POW ((float64_t)CODEC_BITS_FULL_SCALE*(float64_t)CODEC_BITS_FULL_SCALE) //магнитуда максимального сигнала в шине // (FPGA_BUS_FULL_SCALE*FPGA_BUS_FULL_SCALE)
#define ADC_FULL_SCALE 65536		   //максимальная аплитуда сигнала в АЦП // powf(2,ADC_BITS)
#define FLOAT_FULL_SCALE_POW 4

// задержки при работе с EEPROM
#define EEPROM_CO_DELAY 0 // command
#define EEPROM_AD_DELAY 0 // addr
#define EEPROM_WR_DELAY 5 // write
#define EEPROM_RD_DELAY 0 // read
#define EEPROM_ERASE_DELAY 40 // do erase
#define EEPROM_REPEAT_TRYES 40 // command tryes

#define MAX_WIFIPASS_LENGTH 32
#define WIFI_DEBUG false //вывод отладки WIFI на экран

#define W25Q16_COMMAND_Write_Enable 0x06
#define W25Q16_COMMAND_Erase_Chip 0xC7
#define W25Q16_COMMAND_Sector_Erase 0x20
#define W25Q16_COMMAND_Page_Program 0x02
#define W25Q16_COMMAND_Read_Data 0x03
#define W25Q16_COMMAND_Power_Down 0xB9
#define W25Q16_COMMAND_Power_Up 0xAB
#define W25Q16_SECTOR_SIZE 4096
#define W25Q16_MARGIN_LEFT_SETTINGS (W25Q16_SECTOR_SIZE*0)
#define W25Q16_MARGIN_LEFT_CALIBRATION (W25Q16_SECTOR_SIZE*8)

typedef struct
{
	uint32_t Freq;
	uint_fast8_t Mode;
	uint_fast16_t HPF_Filter_Width;
	uint_fast16_t LPF_Filter_Width;
	bool ManualNotchFilter;
	bool AutoNotchFilter;
	uint_fast16_t NotchFC;
	bool DNR;
	bool AGC;
} VFO;

//режим работы двойного приёмника
typedef enum
{
	VFO_SEPARATE,
	VFO_A_AND_B,
	VFO_A_PLUS_B,
} DUAL_RX_TYPE;

//сохранение старых значений семплов для DC фильтра. Несколько состояний для разных потребителей
typedef struct
{
	float32_t x_prev;
	float32_t y_prev;
} DC_filter_state_type;

//Сохранение настроек по бендам
typedef struct
{
	uint32_t Freq;
	uint8_t Mode;
	bool LNA;
	bool ATT;
	bool ADC_Driver;
	bool ADC_PGA;
	uint8_t FM_SQL_threshold;
	bool DNR;
	bool AGC;
} BAND_SAVED_SETTINGS_TYPE;

extern struct TRX_SETTINGS
{
	uint8_t flash_id;
	bool current_vfo; // false - A; true - B
	VFO VFO_A;
	VFO VFO_B;
	bool Fast;
	BAND_SAVED_SETTINGS_TYPE BANDS_SAVED_SETTINGS[BANDS_COUNT];
	bool LNA;
	bool ATT;
	bool LPF;
	bool BPF;
	bool ADC_Driver;
	uint8_t RX_AGC_speed;
	bool BandMapEnabled;
	bool InputType_MIC;
	bool InputType_LINE;
	bool InputType_USB;
	uint16_t CW_LPF_Filter;
	uint16_t CW_HPF_Filter;
	uint16_t SSB_LPF_Filter;
	uint16_t SSB_HPF_Filter;
	uint16_t AM_LPF_Filter;
	uint16_t FM_LPF_Filter;
	uint8_t RF_Power;
	uint8_t FM_SQL_threshold;
	uint8_t FFT_Zoom;
	bool AutoGain;
	bool CWDecoder;
	bool FFT_Enabled;
	uint16_t CW_GENERATOR_SHIFT_HZ;
	uint8_t ENCODER_SLOW_RATE;
	uint8_t LCD_Brightness;
	uint8_t Standby_Time;
	uint16_t Key_timeout;
	uint8_t FFT_Averaging;
	bool WIFI_Enabled;
	char WIFI_AP[MAX_WIFIPASS_LENGTH];
	char WIFI_PASSWORD[MAX_WIFIPASS_LENGTH];
	int8_t WIFI_TIMEZONE;
	uint16_t SPEC_Begin;
	uint16_t SPEC_End;
	uint16_t CW_SelfHear;
	bool ADC_PGA;
	bool ADC_RAND;
	bool ADC_SHDN;
	bool ADC_DITH;
	uint8_t FFT_Window;
	bool Locked;
	bool CLAR;
	bool TWO_SIGNAL_TUNE;
	uint8_t IF_Gain;
	bool CW_KEYER;
	uint16_t CW_KEYER_WPM;
	bool S_METER_Style;
	uint8_t TX_AGC_speed;
	bool Debug_Console;
	DUAL_RX_TYPE Dual_RX_Type;
	DC_filter_state_type DC_Filter_State[8];
	uint8_t FFT_Style;
	bool ShiftEnabled;
	uint8_t DNR_SNR_THRESHOLD;
	uint8_t DNR_AVERAGE;
	uint8_t DNR_MINIMAL;
	bool NOISE_BLANKER;
	uint8_t NOISE_BLANKER_THRESHOLD;
	
	uint8_t ENDBit;
} TRX;

extern struct TRX_CALIBRATE
{
	uint8_t flash_id;
	uint8_t CIC_GAINER_val;
	uint8_t CICFIR_GAINER_val;
	uint8_t TXCICFIR_GAINER_val;
	uint8_t DAC_GAINER_val;
	uint8_t rf_out_power[32];
	int16_t smeter_calibration;
	int16_t adc_offset;
	int16_t att_db;	
	int16_t lna_gain_db;
	uint32_t LPF_END;
	uint32_t BPF_0_START; //UHF
	uint32_t BPF_0_END; //UHF
	uint32_t BPF_1_START;
	uint32_t BPF_1_END;
	uint32_t BPF_2_START;
	uint32_t BPF_2_END;
	uint32_t BPF_3_START;
	uint32_t BPF_3_END;
	uint32_t BPF_4_START;
	uint32_t BPF_4_END;
	uint32_t BPF_5_START;
	uint32_t BPF_5_END;
	uint32_t BPF_6_START;
	uint32_t BPF_6_END;
	uint32_t BPF_7_HPF;
	float32_t swr_trans_rate;
	int32_t swr_trans_rate_shadow;
} CALIBRATE;

extern volatile bool NeedSaveSettings;
extern volatile bool NeedSaveCalibration;
extern volatile bool EEPROM_Busy;

extern void LoadSettings(bool clear);
extern void LoadCalibration(void);
extern void SaveSettings(void);
extern void SaveCalibration(void);
extern VFO *CurrentVFO(void);
extern VFO *SecondaryVFO(void);

#endif
