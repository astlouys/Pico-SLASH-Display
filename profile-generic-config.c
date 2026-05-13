/* ============================================================================================================================================================= *\
   profile-generic-config.c
   astlouys@gmail.com
   https://github.com/astlouys/Pico-RGB-Matrix
   Revision 09-APR-2026

   You should gie a specific name to this file    
\* ============================================================================================================================================================= */



/* $PAGE */
/* $TITLE=Basic configuration / parameters for profile-generic-config Device Profile. */
/* ============================================================================================================================================================= *\
   =============================================================================================================================================================
                     ===== SECTION BELOW CONTAINS COMPILE-TIME SYSTEM OPTIONS / CONFIGURATION OR PARAMETERS THAT CAN BE ADAPTED BY USERS =====
                                                SOME OF THESE ITEMS ARE ALSO ADJUSTABLE AT RUNTIME, OTHERS ARE NOT.
   =============================================================================================================================================================
\* ============================================================================================================================================================= */
#pragma message "==================================> Firmware built with <profile-generic-config> Device Profile."


/* ============================================================================================================================================================= *\
                                                                    General configuration.
\* ============================================================================================================================================================= */
ActiveConfig0.BrightnessLoLimit =   1;
ActiveConfig0.BrightnessHiLimit = 200;
ActiveConfig0.BrightnessLevel   = 200;

ActiveConfig0.FlagButtonFeedback = FLAG_ON;         // audible feedback for local buttons.
ActiveConfig0.FlagIrFeedback     = FLAG_ON;         // audible feedback for remote control.



/* ============================================================================================================================================================= *\
                                                                    Auto-scroll configuration.
\* ============================================================================================================================================================= */
/* ---------------------------- *\
    Functions available:
    200) Firmware version.
    201) Microcontroller.
    202) Temperature.
    203) Brightness info.
    204) Alarms.
    205) Events today.
    206) Events this week.
    207) Events current month.
    208) Events this year (all events).
    209) Daylight Saving Time
    210) Network credentials.
    211) Network information.
    212) Idle time monitor.
    213) Silence period.
    214) First free heap pointer.
    215) Auto-scrolls information.
    216) Total system up-time.
\* ---------------------------- */

ActiveConfig0.AutoScroll[0].Period = 15;  // AutoScroll every this number of minutes.

ActiveConfig0.AutoScroll[0].FunctionId[0]  = 200;
ActiveConfig0.AutoScroll[0].FunctionId[1]  = 203;
ActiveConfig0.AutoScroll[0].FunctionId[2]  = 207;
ActiveConfig0.AutoScroll[0].FunctionId[3]  = 211;
ActiveConfig0.AutoScroll[0].FunctionId[4]  = 216;
ActiveConfig0.AutoScroll[0].FunctionId[5]  = 0;    // null entry
ActiveConfig0.AutoScroll[0].FunctionId[6]  = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[7]  = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[8]  = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[9]  = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[10] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[11] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[12] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[13] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[14] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[15] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[16] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[17] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[18] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[19] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[20] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[21] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[22] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[23] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[24] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[25] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[26] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[27] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[28] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[29] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[30] = 0;    // null entry.
ActiveConfig0.AutoScroll[0].FunctionId[31] = 0;    // null entry.



/* ============================================================================================================================================================= *\
                                                                              Alarms.
\* ============================================================================================================================================================= */
// Loop1UInt16 = 0;

// ActiveConfig0.Alarm[Loop1UInt16].FlagStatus      = FLAG_ON;
// ActiveConfig0.Alarm[Loop1UInt16].Hour            =       7;
// ActiveConfig0.Alarm[Loop1UInt16].Minute          =      45;
// ActiveConfig0.Alarm[Loop1UInt16].DayMask         =    0x7F;
// ActiveConfig0.Alarm[Loop1UInt16].NumberOfBeeps   =       2;
// ActiveConfig0.Alarm[Loop1UInt16].BeepMSec        =      50;
// ActiveConfig0.Alarm[Loop1UInt16].RepeatPeriod    =      15;
// ActiveConfig0.Alarm[Loop1UInt16].RingDuration    =      90;
// ActiveConfig0.Alarm[Loop1UInt16].NumberOfScrolls =       1;
// sprintf(ActiveConfig0.Alarm[Loop1UInt16].Message, "C'est l'heure du dejeuner");

// ++Loop1UInt16;
