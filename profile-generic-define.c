/* ============================================================================================================================================================= *\
   profile-generic-define.c
   astlouys@gmail.com
   https://github.com/astlouys/Pico-ASTL_Display
   Revision 09-APR-2026
\* ============================================================================================================================================================= */



/* $PAGE */
/* $TITLE=Basic options / configuration / parameters for profile-generic-define Device Profile define file. */
/* ============================================================================================================================================================= *\
                     ===== SECTION BELOW CONTAINS COMPILE-TIME SYSTEM OPTIONS / CONFIGURATION OR PARAMETERS THAT CAN BE ADAPTED BY USERS =====
                                                SOME OF THESE ITEMS ARE ALSO ADJUSTABLE AT RUNTIME, OTHERS ARE NOT.
\* ============================================================================================================================================================= */
#pragma message "\n\n==================================> Firmware built with <profile-generic-define> Device Profile define file.\n\n"


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                              When current flash configuration of the RGB-Matrix is erased, a default configuration will be generated.
                          On top of this default configuration, the files below will be used to customize / adapt this flash configuration.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define PROFILE_CONFIG_FILE "profile-generic-config.c"
#define CALENDAR_FILE       "calendar-generic.c"


/* ============================================================================================================================================================= *\
                                                                     Network credentials.
                  They should not be required since they are read from environment variables. Those environment variables may be overwritten here.
\* ============================================================================================================================================================= */
// #define WIFI_SSID     "MyNetworkName"      // this network SSID will be used to generate a default flash configuration is no SSID is read from environment variable.
// #define WIFI_PASSWORD "MyNetworkPassword"  // this network password will be used to generate a default flash configuration is no SSID is read from environment variable.



/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                  Device language selection. Only ONE (1) language must be defined. See User Guide for instructions on how to add a new language.
                                         Those messages for which a translation has not been defined will be displayed in English.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* NOTE: Language selection must be done below. */
#define LANGUAGE_ENGLISH   1
#define LANGUAGE_FRENCH    2

/* NOTE: Only one language mus be selected. */
// #define FIRMWARE_LANGUAGE LANGUAGE_FRENCH
#define FIRMWARE_LANGUAGE LANGUAGE_ENGLISH


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
        WARNING: ONE AND ONLY ONE of the two lines below must be uncommented, depending if your Pico-RGB-Matrix control board is the old or the new version.                                 
     Old board hardware version of the RGB Matrix control board has the two Pico's sockets side-by-side while the new board hardware version of the RGB Matrix
              control board has one Pico socket on each side of the board (one on the left side and one on the right side of the control board).
                                            Uncomment the line below corresponding to your control board version.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// #define OLD_BOARD  // Old board has both Pico sockets side by side on the control board.
#define NEW_BOARD  // New board has one Pico socket on each side of the control board.


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                  Alternate displays allows displaying temperature, humidity and / or other data alternately on the <date> line on RGB matrix.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define ALTERNATE_SUPPORT


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
      Messsage Queuing Telemetry Transport (MQTT) protocol support. Except if you plan to use your Pico-RGB-Matrix as a stand-alone device, you should enable
       MQTT support. This will allow your device to communicate with all other devices compatibles with the ASTL Smart Home ecosystem and share information.
         Refer to the User Guide of any Pico-ASTL-xxx device to get more information about devices that are currently supported in this family of products.
                                 MQTT_WILL_TOPIC represents the target device to receive will message when current device terminates.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define MQTT_SUPPORT


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
      There must be only ONE MQTT_TIME_SERVER among all ASTL ecosystem devices. Ideally, choose a device with a real-time clock IC which is battery backed-up.
      NOTE: A Waveshare's Pico-RGB-Matrix with a DS-3231 real-time clock IC is a good choice. It has shown a very small time drift over long periods of time.
       The device choosen should be the only one using Network Time Protocol (NTP) to synchronize itself over the Internet. It becomes the <MQTT Time Server>
        and will synchronize all other devices of the ASTL ecosystem over MQTT. Also try to locate the choosen device nearby your Wi-Fi router so that Wi-Fi
      communication is flawless and that NTP requests are successful most of the time. Even if a few NTP requests fail, the fact that the device is backed-up
                                          by a real-time clock IC will make sure the time reference device is reliable.
                      Comment-out the line below on all devices except the one choosen to become the MQTT Time Server, based on comments above.
          If more than one device has MQTT_TIME_SERVER enabled, when a time request is done by one device, all MQTT_TIME_SERVER-enabled devices will answer
             with as many time settings, causing unnecessary network traffic and possibly causing glitches with time synchronization in different devices.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define MQTT_TIME_SERVER


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
        Sound Server Drive option will trigger jingles from Sound Server. It must be enabled ("define") on ONLY ONE device, ideally the MQTT Timer Server.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define SOUND_SERVER_DRIVE


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                         WARNING: If this option is turned On, ABSOLUTELY NO SOUND will be generated by the device's on-board active buzzer
                                                    (the electronic to generate sound will not be initialized). 
             Instead of the RGB-matrix on-board active buzzer, you may want to use the Sound Server device to generate MP3 sounds on the ASTL network.
                           the ASTL Smart Home ecosystem. At that time, it could become interesting to shut off some units with this option.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// #define NO_SOUND


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
         Network Time Protocol (NTP) support. Only one device in the whole ASTL Smart Home ecosystem must have NTP enabled (usually the "MQTT Time Server").
          This MQTT-TIME_SERVER device will resynchronize itself with NTP regularly and will then re-synchronize all other devices on the ASTL ecosystem.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define NTP_SUPPORT


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
      Waveshare's Pico-RGB-Matrix features an active buzzer. In this type of buzzer, there is an integrated oscillator so that the sound (the "frequency") is
        always the same and can't be changed. A "passive buzzer" doesn't have an integrated oscillator and the sound frequency can be changed. However, this
     requires to drive the buzzer with pulse-wide modulation ("PWM") signal, which is a little more complicated for the software. The definition below may be
                                                 used if you implement such a passive buzzer in the Pico-ASTL-Display.
                                  Consider using the Pico-ASTL-SoundServer to generate MP3 jingles or sound on the ASTL network instead.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// #define PASSIVE_BUZZER_SUPPORT  // has been replaced by a Sound Server in the ASTL Smart Home ecosystem.


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                                  This option is planned to bypass eventual device tests and or other behavior at device startup.
                                         Since such functions have not been implemented for now, the options is disabled.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// #define QUICK_START


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                                       Enable Firmware support of the remote control included with the Pico-RGB-Matrix device.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define REMOTE_SUPPORT  // remote control support.


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
       Except if you have very good reason to do so, watchdog support must be enabled at all time. There are three different watchdogs used in this Firmware.
     They will restart the device in case of a crash in the Firmware. If the watchdog is disabled, the RGB Matrix may freeze with a few LEDs being "over-bright"
           in the display, with matrix scan not performing its job. This could reduce significantly the life span of those LEDs. Hopefully, overtime, most
                       cases causing potential Firmware crashes will be identified and fixed. Nonetheless, watchdog should remain enabled.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define WATCHDOG_SUPPORT


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                      Wi-Fi support is required for many options: NTP clock synchronization, all MQTT protocol based devices, Sound Server, etc...
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define WIFI_SUPPORT


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- *\
                           ZigBee protocol allows control of different ZigBee devices (heat control, lights, intelligent switches, etc)
                                                          NOTE: ZigBee protocol has not been implemented yet.
\* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// #define ZIGBEE_SUPPORT


/* ============================================================================================================================================================= *\
                                                                 END OF PROFILE: PROFILE-GENERIC-DEFINE
\* ============================================================================================================================================================= */
