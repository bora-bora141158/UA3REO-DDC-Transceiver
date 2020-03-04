#ifndef LCD_Layout_h
#define LCD_Layout_h

#include "lcd.h"
#include "fonts.h"

#define BACKGROUND_COLOR COLOR_BLACK
#define COLOR_BUTTON_TEXT COLOR_DGREEN
#define COLOR_BUTTON_INACTIVE_TEXT rgb888torgb565(150, 150, 150)

#define LAY_CLOCK_POS_Y 17
#define LAY_CLOCK_POS_HRS_X 405
#define LAY_CLOCK_POS_MIN_X 430
#define LAY_CLOCK_POS_SEC_X 455
#define LAY_CLOCK_FONT FreeSans9pt7b

#define LAY_TOPBUTTONS_X1 0
#define LAY_TOPBUTTONS_X2 (LCD_WIDTH - 1)
#define LAY_TOPBUTTONS_Y1 0
#define LAY_TOPBUTTONS_Y2 65

#define LAY_TOPBUTTONS_VFO_X 0
#define LAY_TOPBUTTONS_VFO_Y 0
#define LAY_TOPBUTTONS_VFO_W 50
#define LAY_TOPBUTTONS_VFO_H 22

#define LAY_TOPBUTTONS_MODE_X 50
#define LAY_TOPBUTTONS_MODE_Y 0
#define LAY_TOPBUTTONS_MODE_W 60
#define LAY_TOPBUTTONS_MODE_H 22

#define LAY_TOPBUTTONS_PRE_X 110
#define LAY_TOPBUTTONS_PRE_Y 0
#define LAY_TOPBUTTONS_PRE_W 50
#define LAY_TOPBUTTONS_PRE_H 22

#define LAY_TOPBUTTONS_ATT_X 155
#define LAY_TOPBUTTONS_ATT_Y 0
#define LAY_TOPBUTTONS_ATT_W 50
#define LAY_TOPBUTTONS_ATT_H 22

#define LAY_TOPBUTTONS_DRV_X 205
#define LAY_TOPBUTTONS_DRV_Y 0
#define LAY_TOPBUTTONS_DRV_W 50
#define LAY_TOPBUTTONS_DRV_H 22

#define LAY_TOPBUTTONS_AGC_X 255
#define LAY_TOPBUTTONS_AGC_Y 0
#define LAY_TOPBUTTONS_AGC_W 50
#define LAY_TOPBUTTONS_AGC_H 22

#define LAY_TOPBUTTONS_LOCK_X 305
#define LAY_TOPBUTTONS_LOCK_Y 0
#define LAY_TOPBUTTONS_LOCK_W 50
#define LAY_TOPBUTTONS_LOCK_H 22

#define LAY_TOPBUTTONS_FAST_X 0
#define LAY_TOPBUTTONS_FAST_Y 24
#define LAY_TOPBUTTONS_FAST_W 50
#define LAY_TOPBUTTONS_FAST_H 22

#define LAY_TOPBUTTONS_DNR_X 50
#define LAY_TOPBUTTONS_DNR_Y 24
#define LAY_TOPBUTTONS_DNR_W 50
#define LAY_TOPBUTTONS_DNR_H 22

#define LAY_TOPBUTTONS_CLAR_X 105
#define LAY_TOPBUTTONS_CLAR_Y 24
#define LAY_TOPBUTTONS_CLAR_W 50
#define LAY_TOPBUTTONS_CLAR_H 22

#define LAY_FREQ_X_OFFSET_100 29
#define LAY_FREQ_X_OFFSET_10 66
#define LAY_FREQ_X_OFFSET_1 106
#define LAY_FREQ_X_OFFSET_KHZ 160
#define LAY_FREQ_X_OFFSET_HZ 300
#define LAY_FREQ_HEIGHT 51
#define LAY_FREQ_Y 120
#define LAY_FREQ_FONT FreeSans36pt7b
#define LAY_FREQ_COLOR_MHZ COLOR_WHITE
#define LAY_FREQ_COLOR_KHZ COLOR_WHITE
#define LAY_FREQ_COLOR_HZ rgb888torgb565(110, 110, 110)
#define LAY_FREQ_DELIMITER_Y_OFFSET 2
#define LAY_FREQ_DELIMITER_X1_OFFSET 140
#define LAY_FREQ_DELIMITER_X2_OFFSET 280

#define LAY_STATUS_Y_OFFSET 140
#define LAY_STATUS_HEIGHT 30
#define LAY_STATUS_BAR_X_OFFSET 60
#define LAY_STATUS_BAR_HEIGHT 15
#define LAY_STATUS_TXRX_X_OFFSET 20
#define LAY_STATUS_TXRX_Y_OFFSET 14
#define LAY_STATUS_TXRX_FONT FreeSans9pt7b
#define LAY_STATUS_TX_COLOR COLOR_RED
#define LAY_STATUS_TX_LABELS_OFFSET_X 5
#define LAY_STATUS_TX_LABELS_MARGIN_X 55
#define LAY_STATUS_BAR_COLOR COLOR_RED
#define LAY_STATUS_RX_COLOR COLOR_GREEN
#define LAY_STATUS_LABELS_NOTCH_COLOR COLOR_BLUE
#define LAY_STATUS_LABELS_BW_COLOR COLOR_WHITE
#define LAY_STATUS_LABELS_TX_COLOR COLOR_GREEN
#define LAY_STATUS_SMETER_WIDTH 320
#define LAY_STATUS_PMETER_WIDTH 270
#define LAY_STATUS_AMETER_WIDTH 90
#define LAY_STATUS_ALC_BAR_X_OFFSET 10
#define LAY_STATUS_LABELS_OFFSET_Y 20
#define LAY_STATUS_LABELS_FONT_SIZE 1
#define LAY_STATUS_LABEL_DBM_X_OFFSET 29
#define LAY_STATUS_LABEL_DBM_Y_OFFSET 5
#define LAY_STATUS_LABEL_NOTCH_X_OFFSET 6
#define LAY_STATUS_LABEL_DBM_WIDTH 23
#define LAY_STATUS_LABEL_DBM_HEIGHT 8
#define LAY_STATUS_LABEL_BW_WIDTH 44
#define LAY_STATUS_LABEL_BW_HEIGHT 8

#define LAY_STATUS_SMETER_COLOR COLOR_WHITE
#define LAY_STATUS_SMETER_TXLABELS_MARGIN 55
#define LAY_STATUS_SMETER_TXLABELS_PADDING 23
#define LAY_STATUS_TX_LABELS_VAL_WIDTH 25
#define LAY_STATUS_TX_LABELS_VAL_HEIGHT 8
#define LAY_STATUS_TX_ALC_X_OFFSET 40

#define LAY_STATUS_ERR_OFFSET_X 420
#define LAY_STATUS_ERR_OFFSET_Y 25
#define LAY_STATUS_ERR_WIDTH 50
#define LAY_STATUS_ERR_HEIGHT 8
#define LAY_STATUS_ERR2_OFFSET_X 27
#define LAY_STATUS_ERR_COLOR COLOR_RED

#define LAY_TEXTBAR_FONT 2
#define LAY_TEXTBAR_TEXT_X_OFFSET 75

#define LAY_FFT_MAX_HEIGHT 40                                   //указываем максимальную высоту FFT
#define LAY_FFT_WTF_HEIGHT 100                                   //указываем максимальную высоту водопада
#define LAY_FFT_BOTTOM_OFFSET (LCD_HEIGHT - LAY_FFT_WTF_HEIGHT) //начало FFT и водопада
#define LAY_FFT_PRINT_SIZE 480                                  //указываем размер выводимого FFT
#define LAY_FFT_CWDECODER_OFFSET 17                             //место под текст CW декодера

#define LAY_SYSMENU_X1 5
#define LAY_SYSMENU_X2 400
#define LAY_SYSMENU_W 458

#endif