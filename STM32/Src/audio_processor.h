#ifndef AUDIO_PROCESSOR_h
#define AUDIO_PROCESSOR_h

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arm_math.h"

#define FPGA_AUDIO_BUFFER_SIZE 32
#define FPGA_AUDIO_BUFFER_HALF_SIZE FPGA_AUDIO_BUFFER_SIZE/2
#define APROCESSOR_BLOCK_SIZE 16
#define CLICK_REMOVE_THRESHOLD 10000 //peak difference from avg amplitude
#define CLICK_REMOVE_STEPSIZE 10 //peak difference from avg amplitude
#define RF_AGC_UP_STEPSIZE 1 //audio level control

#define FM_RX_LPF_ALPHA		0.05f			// For FM demodulator:  "Alpha" (low-pass) factor to result in -6dB "knee" at approx. 270 Hz 0.05f
#define FM_RX_HPF_ALPHA		0.96f			// For FM demodulator:  "Alpha" (high-pass) factor to result in -6dB "knee" at approx. 180 Hz 0.96f
#define	FM_SQUELCH_HYSTERESIS	0.5f			// Hysteresis for FM squelch
#define FM_SQUELCH_PROC_DECIMATION	50		// Number of times we go through the FM demod algorithm before we do a squelch calculation
#define FM_RX_SQL_SMOOTHING	0.005f			// Smoothing factor for IIR squelch noise averaging

extern DMA_HandleTypeDef hdma_i2s3_ext_rx;
extern DMA_HandleTypeDef hdma_spi3_tx;

extern void processRxAudio(void);
extern void processTxAudio(void);
extern void initAudioProcessor(void);
extern uint32_t AUDIOPROC_samples;
extern uint32_t AUDIOPROC_TXA_samples;
extern uint32_t AUDIOPROC_TXB_samples;
extern int32_t Processor_AudioBuffer_A[FPGA_AUDIO_BUFFER_SIZE];
extern int32_t Processor_AudioBuffer_B[FPGA_AUDIO_BUFFER_SIZE];
extern uint8_t Processor_AudioBuffer_ReadyBuffer;
extern bool Processor_NeedBuffer;
extern DMA_HandleTypeDef hdma_memtomem_dma2_stream0;
extern DMA_HandleTypeDef hdma_memtomem_dma2_stream1;
extern DMA_HandleTypeDef hdma_memtomem_dma2_stream2;
extern DMA_HandleTypeDef hdma_memtomem_dma2_stream3;
extern uint16_t fpga_index_copy;
extern float32_t Processor_AVG_amplitude;
extern float32_t Processor_TX_MAX_amplitude;
extern float32_t ALC_need_gain;
extern float32_t FPGA_Audio_Buffer_Q_tmp[FPGA_AUDIO_BUFFER_HALF_SIZE];
extern float32_t FPGA_Audio_Buffer_I_tmp[FPGA_AUDIO_BUFFER_HALF_SIZE];
extern float32_t fm_sql_avg;
static void DemodFM(void);
extern float32_t Processor_RX_Audio_Samples_MAX_value;
extern float32_t Processor_RX_Audio_Samples_MIN_value;

#endif
