/**
 * \file dogm162x_cmds.h
 *
 * \brief command descriptions for the DOG-M162x LCD Module
 *
 *
 * \author Bernhard Rohloff <rohloff.bernhard@gmail.com>
 */

#ifndef DOGM162X_CMDS_H
#define DOGM162X_CMDS_H

// #define DOGM126_

#define DOGM126_CMD_FUNCTION_SET                   0x20
#define DOGM126_INTERFACE_8_BIT                    0x10
#define DOGM126_INTERFACE_4_BIT                    0x00
#define DOGM126_2_LINE_DISPLAY                     0x08
#define DOGM126_1_LINE_DISPLAY                     0x00
#define DOGM126_DOUBLE_HEIGHT_FONT                 0x04
#define DOGM126_INSTRUCTION_TABLE_00               0x00
#define DOGM126_INSTRUCTION_TABLE_01               0x01
#define DOGM126_INSTRUCTION_TABLE_10               0x10

/*** Instruction Table 00 ***/
#define DOGM126_CMD_SHIFT_CURSOR_AND_DISPLAY       0x10
#define DOGM126_COURSOR_RIGHT                      0x04
#define DOGM126_COURSOR_LEFT                       0x00
#define DOGM126_DISPLAY_SHIFT                      0x08

#define DOGM126_CMD_SET_CGRAM                      0x20
#define DOGM126_CGRAM_ADDRESS(x)                   (x & 0x3F)

/***Instruction Table 01 ***/
#define DOGM126_CMD_BIAS_SET                       0x14
#define DOGM126_BIAS_1_4                           0x80
#define DOGM126_BIAS_1_5                           0x00
#define DOGM126_3_LINE_APPLICATION                 0x01

#define DOGM126_CMD_SET_ICON_ADDRESS               0x40
#define DOGM126_ICON_ADDRESS(x)                    (x & 0x0F)

#define DOGM126_CMD_POWER_ICON_CTRL_CONTRAST       0x50
#define DOGM126_ICON_ON                            0x08
#define DOGM126_ICON_OFF                           0x00
#define DOGM126_BOOSTER_ON                         0x04
#define DOGM126_BOOSTER_OFF                        0x00
#define DOGM126_CONTRAST_MODE_SET_0                0x00
#define DOGM126_CONTRAST_MODE_SET_1                0x01
#define DOGM126_CONTRAST_MODE_SET_2                0x10
#define DOGM126_CONTRAST_MODE_SET_3                0x11

#define DOGM126_CMD_FOLLOWER_CTRL                  0x60
#define DOGM126_FOLLOWER_ON                        0x08
#define DOGM126_FOLLOWER_OFF                       0x00
#define DOGM126_AMPLIFIER_RATIO_2                  0x04
#define DOGM126_AMPLIFIER_RATIO_1                  0x02
#define DOGM126_AMPLIFIER_RATIO_0                  0x00

#define DOGM126_CMD_SET_CONTRAST                   0x70
#define DOGM126_CONTRAST(x)                        (x & 0x0F)

/*** Instruction Table 10 ***/
#define DOGM126_CMD_DOUBLE_HEIGHT_POSITION         0x10
#define DOGM126_DOUBLE_HEIGHT_UP                   0x80
#define DOGM126_DOUBLE_HEIGHT_DOWN                 0x00

#endif
