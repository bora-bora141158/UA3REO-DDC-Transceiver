#ifndef LCD_Layout_800x480_h
#define LCD_Layout_800x480_h
#include "lcd_driver.h"
#if (defined(LAY_800x480))

#include "lcd.h"
#include "fonts.h"

// decoration of screen elements

#define BACKGROUND_COLOR COLOR_BLACK                          // background fill
#define COLOR_BUTTON_TEXT rgb888torgb565(255, 255, 255)         // active color of the status button
#define COLOR_BUTTON_INACTIVE_TEXT rgb888torgb565(130, 130, 130) // inactive color
#define COLOR_BUTTON_BACKGROUND rgb888torgb565(50, 50, 50)		// buttons background

// top row of status buttons
#define LAY_TOPBUTTONS_X1 0
#define LAY_TOPBUTTONS_X2 (LCD_WIDTH - 1)
#define LAY_TOPBUTTONS_Y1 95
#define LAY_TOPBUTTONS_Y2 55
#define LAY_TOPBUTTONS_COUNT 10
#define LAY_TOPBUTTONS_HEIGHT 30
#define LAY_TOPBUTTONS_WIDTH (LCD_WIDTH / LAY_TOPBUTTONS_COUNT)

#define LAY_TOPBUTTONS_PRE_X (LAY_TOPBUTTONS_X1)
#define LAY_TOPBUTTONS_PRE_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_PRE_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_PRE_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_ATT_X (LAY_TOPBUTTONS_PRE_X + LAY_TOPBUTTONS_PRE_W)
#define LAY_TOPBUTTONS_ATT_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_ATT_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_ATT_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_PGA_X (LAY_TOPBUTTONS_ATT_X + LAY_TOPBUTTONS_ATT_W)
#define LAY_TOPBUTTONS_PGA_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_PGA_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_PGA_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_DRV_X (LAY_TOPBUTTONS_PGA_X + LAY_TOPBUTTONS_PGA_W)
#define LAY_TOPBUTTONS_DRV_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_DRV_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_DRV_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_AGC_X (LAY_TOPBUTTONS_DRV_X + LAY_TOPBUTTONS_DRV_W)
#define LAY_TOPBUTTONS_AGC_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_AGC_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_AGC_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_DNR_X (LAY_TOPBUTTONS_AGC_X + LAY_TOPBUTTONS_AGC_W)
#define LAY_TOPBUTTONS_DNR_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_DNR_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_DNR_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_NB_X (LAY_TOPBUTTONS_DNR_X + LAY_TOPBUTTONS_DNR_W)
#define LAY_TOPBUTTONS_NB_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_NB_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_NB_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_NOTCH_X (LAY_TOPBUTTONS_NB_X + LAY_TOPBUTTONS_NB_W)
#define LAY_TOPBUTTONS_NOTCH_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_NOTCH_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_NOTCH_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_FAST_X (LAY_TOPBUTTONS_NOTCH_X + LAY_TOPBUTTONS_NOTCH_W)
#define LAY_TOPBUTTONS_FAST_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_FAST_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_FAST_H LAY_TOPBUTTONS_HEIGHT

#define LAY_TOPBUTTONS_MUTE_X (LAY_TOPBUTTONS_FAST_X + LAY_TOPBUTTONS_FAST_W)
#define LAY_TOPBUTTONS_MUTE_Y LAY_TOPBUTTONS_Y1
#define LAY_TOPBUTTONS_MUTE_W LAY_TOPBUTTONS_WIDTH
#define LAY_TOPBUTTONS_MUTE_H LAY_TOPBUTTONS_HEIGHT

//clock
#define LAY_CLOCK_POS_Y 17
#define LAY_CLOCK_POS_HRS_X (LCD_WIDTH - 75)
#define LAY_CLOCK_POS_MIN_X (LAY_CLOCK_POS_HRS_X + 25)
#define LAY_CLOCK_POS_SEC_X (LAY_CLOCK_POS_MIN_X + 25)
#define LAY_CLOCK_FONT (GFXfont *)&FreeSans9pt7b

//WIFI
#define LAY_STATUS_WIFI_ICON_X (LCD_WIDTH - 98)
#define LAY_STATUS_WIFI_ICON_Y 3

// frequency output VFO-A
#define LAY_FREQ_X_OFFSET_100 37
#define LAY_FREQ_X_OFFSET_10 73
#define LAY_FREQ_X_OFFSET_1 113
#define LAY_FREQ_X_OFFSET_KHZ 170
#define LAY_FREQ_X_OFFSET_HZ 307
#define LAY_FREQ_HEIGHT 51
#define LAY_FREQ_WIDTH 370
#define LAY_FREQ_TOP_OFFSET 4
#define LAY_FREQ_LEFT_MARGIN 37
#define LAY_FREQ_RIGHT_MARGIN (LCD_WIDTH - LAY_FREQ_LEFT_MARGIN - LAY_FREQ_WIDTH)
#define LAY_FREQ_BOTTOM_OFFSET 8
#define LAY_FREQ_BLOCK_HEIGHT (LAY_FREQ_HEIGHT + LAY_FREQ_TOP_OFFSET + LAY_FREQ_BOTTOM_OFFSET)
#define LAY_FREQ_Y_TOP 0
#define LAY_FREQ_Y_BASELINE (LAY_FREQ_Y_TOP + LAY_FREQ_HEIGHT + LAY_FREQ_TOP_OFFSET)
#define LAY_FREQ_Y_BASELINE_SMALL (LAY_FREQ_Y_BASELINE - 2)
#define LAY_FREQ_FONT (GFXfont *)&FreeSans36pt7b
#define LAY_FREQ_SMALL_FONT (GFXfont *)&Quito32pt7b
#define LAY_FREQ_COLOR_MHZ COLOR_WHITE
#define LAY_FREQ_COLOR_KHZ COLOR_WHITE
#define LAY_FREQ_COLOR_HZ rgb888torgb565(150, 150, 150)
#define LAY_FREQ_DELIMITER_Y_OFFSET 0
#define LAY_FREQ_DELIMITER_X1_OFFSET 151
#define LAY_FREQ_DELIMITER_X2_OFFSET 289

// frequency output VFO-B
#define LAY_FREQ_B_LEFT (LAY_FREQ_RIGHT_MARGIN + 32)
#define LAY_FREQ_B_X_OFFSET_100 (LAY_FREQ_B_LEFT + 37)
#define LAY_FREQ_B_X_OFFSET_10 (LAY_FREQ_B_LEFT + 73)
#define LAY_FREQ_B_X_OFFSET_1 (LAY_FREQ_B_LEFT + 105)
#define LAY_FREQ_B_X_OFFSET_KHZ (LAY_FREQ_B_LEFT + 153)
#define LAY_FREQ_B_X_OFFSET_HZ (LAY_FREQ_B_LEFT + 268)
#define LAY_FREQ_B_HEIGHT 51
#define LAY_FREQ_B_WIDTH 288
#define LAY_FREQ_B_TOP_OFFSET 4
#define LAY_FREQ_B_LEFT_MARGIN (LAY_FREQ_B_LEFT + 37)
#define LAY_FREQ_B_RIGHT_MARGIN (LCD_WIDTH - LAY_FREQ_B_LEFT_MARGIN - LAY_FREQ_B_WIDTH)
#define LAY_FREQ_B_BOTTOM_OFFSET 8
#define LAY_FREQ_B_BLOCK_HEIGHT (LAY_FREQ_B_HEIGHT + LAY_FREQ_B_TOP_OFFSET + LAY_FREQ_B_BOTTOM_OFFSET)
#define LAY_FREQ_B_Y_TOP 0
#define LAY_FREQ_B_Y_BASELINE (LAY_FREQ_B_Y_TOP + LAY_FREQ_B_HEIGHT + LAY_FREQ_B_TOP_OFFSET)
#define LAY_FREQ_B_Y_BASELINE_SMALL (LAY_FREQ_B_Y_BASELINE - 2)
#define LAY_FREQ_B_FONT (GFXfont *)&FreeSans32pt7b
#define LAY_FREQ_B_SMALL_FONT (GFXfont *)&FreeSans18pt7b
#define LAY_FREQ_B_COLOR_MHZ rgb888torgb565(120, 120, 120)
#define LAY_FREQ_B_COLOR_KHZ rgb888torgb565(120, 120, 120)
#define LAY_FREQ_B_COLOR_HZ rgb888torgb565(120, 120, 120)
#define LAY_FREQ_B_DELIMITER_Y_OFFSET 0
#define LAY_FREQ_B_DELIMITER_X1_OFFSET (LAY_FREQ_B_LEFT + 140)
#define LAY_FREQ_B_DELIMITER_X2_OFFSET (LAY_FREQ_B_LEFT + 253)

// display statuses under frequency
#define LAY_STATUS_Y_OFFSET (LAY_FREQ_Y_TOP + LAY_FREQ_BLOCK_HEIGHT + 1)
#define LAY_STATUS_HEIGHT 30
#define LAY_STATUS_BAR_X_OFFSET 60
#define LAY_STATUS_BAR_Y_OFFSET 16
#define LAY_STATUS_BAR_HEIGHT 10
#define LAY_STATUS_TXRX_X_OFFSET 3
#define LAY_STATUS_TXRX_Y_OFFSET -50
#define LAY_STATUS_TXRX_FONT (GFXfont *)&FreeSans9pt7b
#define LAY_STATUS_VFO_X_OFFSET 0
#define LAY_STATUS_VFO_Y_OFFSET -43
#define LAY_STATUS_VFO_BLOCK_WIDTH 37
#define LAY_STATUS_VFO_BLOCK_HEIGHT 22
#define LAY_STATUS_VFO_COLOR COLOR_BLACK
#define LAY_STATUS_VFO_BGCOLOR COLOR_WHITE
#define LAY_STATUS_ANT_X_OFFSET 0
#define LAY_STATUS_ANT_Y_OFFSET -23
#define LAY_STATUS_ANT_BLOCK_WIDTH 37
#define LAY_STATUS_ANT_BLOCK_HEIGHT 22
#define LAY_STATUS_TX_LABELS_OFFSET_X 5
#define LAY_STATUS_TX_LABELS_MARGIN_X 55
#define LAY_STATUS_BAR_LEFT_COLOR rgb888torgb565(100, 100, 255)
#define LAY_STATUS_BAR_RIGHT_COLOR rgb888torgb565(255, 100, 100)
#define LAY_STATUS_BAR_LABELS_COLOR rgb888torgb565(32, 171, 17)
#define LAY_STATUS_RX_COLOR COLOR_WHITE
#define LAY_STATUS_TX_COLOR COLOR_RED
#define LAY_STATUS_LABELS_BW_COLOR COLOR_WHITE
#define LAY_STATUS_LABELS_TX_COLOR rgb888torgb565(32, 171, 17)
#define LAY_STATUS_SMETER_WIDTH 400
#define LAY_STATUS_SMETER_MARKER_HEIGHT 25
#define LAY_STATUS_PMETER_WIDTH 300
#define LAY_STATUS_AMETER_WIDTH 90
#define LAY_STATUS_ALC_BAR_X_OFFSET 10
#define LAY_STATUS_LABELS_OFFSET_Y 0
#define LAY_STATUS_LABELS_FONT_SIZE 1
#define LAY_STATUS_LABEL_S_VAL_X_OFFSET 10
#define LAY_STATUS_LABEL_S_VAL_Y_OFFSET 10
#define LAY_STATUS_LABEL_S_VAL_FONT (GFXfont *)&FreeSans7pt7b
#define LAY_STATUS_LABEL_S_VAL_COLOR rgb888torgb565(249, 205, 46)
#define LAY_STATUS_LABEL_DBM_X_OFFSET 5
#define LAY_STATUS_LABEL_DBM_Y_OFFSET 20
#define LAY_STATUS_LABEL_DBM_COLOR rgb888torgb565(32, 191, 17)
#define LAY_STATUS_LABEL_BW_X_OFFSET 470
#define LAY_STATUS_LABEL_BW_Y_OFFSET 20
#define LAY_STATUS_LABEL_BW_COLOR rgb888torgb565(0, 200, 255)
#define LAY_STATUS_LABEL_RIT_X_OFFSET 545
#define LAY_STATUS_LABEL_RIT_Y_OFFSET 20
#define LAY_STATUS_LABEL_RIT_COLOR COLOR_WHITE
#define LAY_STATUS_LABEL_THERM_X_OFFSET 595
#define LAY_STATUS_LABEL_THERM_Y_OFFSET 20
#define LAY_STATUS_LABEL_THERM_COLOR rgb888torgb565(249, 205, 46)
#define LAY_STATUS_LABEL_NOTCH_X_OFFSET 670
#define LAY_STATUS_LABEL_NOTCH_Y_OFFSET 20
#define LAY_STATUS_LABEL_NOTCH_COLOR rgb888torgb565(0, 200, 255)
#define LAY_STATUS_LABEL_FFT_BW_X_OFFSET 740
#define LAY_STATUS_LABEL_FFT_BW_Y_OFFSET 20
#define LAY_STATUS_LABEL_ACTIVE_COLOR rgb888torgb565(32, 191, 17)
#define LAY_STATUS_LABEL_INACTIVE_COLOR rgb888torgb565(90, 90, 90)
#define LAY_STATUS_LABEL_LOCK_X_OFFSET 740
#define LAY_STATUS_LABEL_LOCK_Y_OFFSET 5
#define LAY_STATUS_SMETER_COLOR rgb888torgb565(249, 205, 46)
#define LAY_STATUS_SMETER_STRIPE_COLOR COLOR_RED
#define LAY_STATUS_SMETER_PEAK_COLOR rgb888torgb565(249, 151, 46)
#define LAY_STATUS_SMETER_PEAK_HOLDTIME 1000
#define LAY_STATUS_SMETER_TXLABELS_MARGIN 55
#define LAY_STATUS_SMETER_TXLABELS_PADDING 23
#define LAY_STATUS_TX_LABELS_VAL_WIDTH 25
#define LAY_STATUS_TX_LABELS_VAL_HEIGHT 8
#define LAY_STATUS_TX_ALC_X_OFFSET 40
#define LAY_STATUS_MODE_X_OFFSET (LCD_WIDTH - LAY_FREQ_RIGHT_MARGIN + 5)
#define LAY_STATUS_MODE_Y_OFFSET -42
#define LAY_STATUS_MODE_B_X_OFFSET (LCD_WIDTH - LAY_FREQ_B_RIGHT_MARGIN + 5)
#define LAY_STATUS_MODE_B_Y_OFFSET -30
#define LAY_STATUS_MODE_BLOCK_WIDTH 48
#define LAY_STATUS_MODE_BLOCK_HEIGHT 22
#define LAY_STATUS_MODE_COLOR rgb888torgb565(249, 205, 46)
#define LAY_STATUS_ERR_OFFSET_X (LCD_WIDTH - 50)
#define LAY_STATUS_ERR_OFFSET_Y 25
#define LAY_STATUS_ERR_WIDTH 50
#define LAY_STATUS_ERR_HEIGHT 8
#define LAY_STATUS_ERR2_OFFSET_X 27
#define LAY_STATUS_ERR_COLOR COLOR_RED

//bottom buttons
#define BOTTOM_BUTTONS_BLOCK_HEIGHT 30
#define BOTTOM_BUTTONS_BLOCK_TOP (LCD_HEIGHT - BOTTOM_BUTTONS_BLOCK_HEIGHT)
#define BOTTOM_BUTTONS_COUNT 8
#define BOTTOM_BUTTONS_ONE_WIDTH (LCD_WIDTH / BOTTOM_BUTTONS_COUNT)

//text bar under wtf
#define LAY_TEXTBAR_FONT 2
#define LAY_TEXTBAR_TEXT_X_OFFSET 85

// FFT and waterfall
#define LAY_FFT_HEIGHT_STYLE1 140  // specify the maximum FFT height
#define LAY_WTF_HEIGHT_STYLE1 180 // specify the maximum height of the waterfall
#define LAY_FFT_HEIGHT_STYLE2 160 // specify the maximum FFT height
#define LAY_WTF_HEIGHT_STYLE2 160  // specify the maximum height of the waterfall
#define LAY_FFT_HEIGHT_STYLE3 220 // specify the maximum FFT height
#define LAY_WTF_HEIGHT_STYLE3 100  // specify the maximum height of the waterfall
#define LAY_FFT_PRINT_SIZE LCD_WIDTH                                           // specify the width of the displayed FFT
#define LAY_FFT_CWDECODER_OFFSET 17                                            // space for the text of the CW decoder

#define LAY_FFT_FFT_MAX_HEIGHT (LAY_FFT_HEIGHT_STYLE3) // maximum possible FFT height
#define LAY_FFT_WTF_MAX_HEIGHT (LAY_WTF_HEIGHT_STYLE1) // maximum possible WTF height
#define LAY_FFT_FFTWTF_POS_Y ((uint16_t)(LCD_HEIGHT - LAY_FFT_HEIGHT_STYLE1 - LAY_WTF_HEIGHT_STYLE1 - BOTTOM_BUTTONS_BLOCK_HEIGHT))    // start of FFT and waterfall
#define LAY_FFT_FFTWTF_HEIGHT (LAY_FFT_FFTWTF_POS_Y + LAY_FFT_HEIGHT_STYLE1 + LAY_WTF_HEIGHT_STYLE1)

//Touch buttons layout
#define LAY_BUTTON_PADDING 1
#define LAY_BUTTON_TEXT rgb888torgb565(255, 255, 255)
#define LAY_BUTTON_INACTIVE_TEXT rgb888torgb565(130, 130, 130)
#define LAY_BUTTON_BACK_COLOR rgb888torgb565(60, 60, 60)
#define LAY_BUTTON_BORDER_COLOR rgb888torgb565(105, 105, 105)
#define LAY_BUTTON_LIGHTER_ACTIVE_COLOR rgb888torgb565(32, 191, 17)
#define LAY_BUTTON_LIGHTER_INACTIVE_COLOR rgb888torgb565(90, 90, 90)
#define LAY_BUTTON_LIGHTER_WIDTH 0.4f
#define LAY_BUTTON_LIGHTER_HEIGHT 4

// system menu
#define LAY_SYSMENU_X1 5
#define LAY_SYSMENU_X2 400
#define LAY_SYSMENU_X2_BIGINT 350
#define LAY_SYSMENU_X2R_BIGINT 400
#define LAY_SYSMENU_W 458
#define LAY_SYSMENU_ITEM_HEIGHT 18

#define LAY_BANDMAP_CW_COLOR rgb888torgb565(50, 50, 255)
#define LAY_BANDMAP_SSB_COLOR rgb888torgb565(50, 237, 255)
#define LAY_BANDMAP_DIGI_COLOR rgb888torgb565(255, 50, 50)
#define LAY_BANDMAP_AM_COLOR rgb888torgb565(219, 255, 50)
#define LAY_BANDMAP_FM_COLOR rgb888torgb565(255, 50, 208)

#endif
#endif
