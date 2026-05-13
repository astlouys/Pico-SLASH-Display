# ==========================================================================================================================================
# CMakeLists.txt for project Pico-SLASH-Display.
# St-Louys Andre - April 2023
# astlouys@gmail.com
# Revision 28-NOV-2025
# Version 5.00
#
# REVISION HISTORY:
# =================
# 05-APR-2023 1.00 - Initial release.
# 05-OCT-2023 2.00 - Minor updates.
# 17-AUG-2024 3.00 - Add support for MQTT protocol.
# 30-SEP_2024 4.00 - Network SSID, Network password and MQTT broker IP address are now read by CMakeLists.txt from environment variables.
# 16-APR-2025 4.01 - Add MQTT password in environment variable.
# 28-NOV-2025 5.00 - Branch from Pico-RGB-Matrix to become part of SLASH Smart Home ecosystem.
# ==========================================================================================================================================
#
#
#
cmake_minimum_required(VERSION 3.16)
#
#
#
# include(/home/pi/pico/pico-extras/external/pico_extras_import.cmake)
#
# Pico SDK may be initialized from Git
## set(PICO_SDK_FETCH_FROM_GIT on)
# set(PICO_SDK_PATH "/home/pi/pico/pico-sdk")
# set(PICO_BOARD pico_w)
set(PICO_BOARD pico_w CACHE STRING "Board type")
#
#
#
# Pico SDK may also be cloned locally without copying <pico_sdk_import.cmake>
## include(/home/pi/pico/pico-sdk/pico_sdk_init.cmake)
include(pico_sdk_import.cmake)
#
#
#
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()
#
#
#
project(Pico-SLASH-Display)
#
#
#
# set (CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set (C_STANDARD 11)
set (CXX_STANDARD 17)
#
#
#
# Initialize the SDK
pico_sdk_init()
#
#
#
# =====================================================================================================================
#                                         Optionally add options to the compiler.
# =====================================================================================================================
add_compile_options(
        -Wall
#        -Wdeclaration-after-statement
#        -Wno-format
        -Wno-missing-braces
        -Wno-pointer-sign
        -Wimplicit-function-declaration
        -Wimplicit-int
        -Wincompatible-pointer-types
        -Winfinite-recursion
        -Wint-conversion
        -Wmaybe-uninitialized
        -Wmisleading-indentation
        -Wparentheses
        -Wreturn-type
        -Wshift-negative-value
        -Wuninitialized
        -Wunused
        -Wunused-but-set-parameter
        -Wunused-but-set-variable
        -Wunused-function
        -Wunused-label
        -Wunused-parameter
        -Wunused-variable
)
#
#
#
if (PICO_CYW43_SUPPORTED) # set by BOARD=pico-w
  if (NOT TARGET pico_cyw43_arch)
    message("Skipping build as support is not available")
  else()
    set(WIFI_SSID      "$ENV{WIFI_SSID}"      CACHE INTERNAL "WIFI_SSID")
    set(WIFI_PASSWORD  "$ENV{WIFI_PASSWORD}"  CACHE INTERNAL "WIFI_PASSWORD")
    set(MQTT_BROKER_IP "$ENV{MQTT_BROKER_IP}" CACHE INTERNAL "MQTT_BROKER_IP")
    set(MQTT_PASSWORD  "$ENV{MQTT_PASSWORD}"  CACHE INTERNAL "MQTT_PASSWORD")
    message("========================================================================================================")
    message("Setting WiFi network name (SSID) to: <${WIFI_SSID}>")
    message("Setting WiFi network password to:    <${WIFI_PASSWORD}>")
    message("Setting MQTT broker IP address to:   <${MQTT_BROKER_IP}>")
    message("Setting MQTT password to:            <${MQTT_PASSWORD}>")
    message("========================================================================================================")
    if ("${WIFI_SSID}" STREQUAL "")
      message("Environment variable WIFI_SSID (network name) is not defined... aborting build process.")
      message("(edit your .bashrc file to add the WIFI_SSID environment variable or modify the CMakeLists.txt file to define it there.")
      return()
    elseif ("${WIFI_PASSWORD}" STREQUAL "")
      message("Environment variable WIFI_PASSWORD (network password) is not defined... aborting build process.")
      message("(edit your .bashrc file to add the WIFI_PASSWORD environment variable or modify the CMakeLists.txt file to define it there.")
      return()
    elseif ("${MQTT_BROKER_IP}" STREQUAL "")
      message("Environment variable MQTT_BROKER_IP (MQTT broket IP address) is not defined... aborting build process.")
      message("(edit your .bashrc file to add the MQTT_BROKER_IP environment variable or modify the CMakeLists.txt file to define it there.")
      return()
    elseif ("${MQTT_PASSWORD}" STREQUAL "")
      message("Environment variable MQTT_PASSWORD is not defined... aborting build process.")
      message("(edit your .bashrc file to add the MQTT_PASSWORD environment variable or modify the CMakeLists.txt file to define it there.")
      return()
    else()
      #
      add_executable(
        Pico-SLASH-Display
        Pico-SLASH-Display.c
        Pico-WiFi-Module.c
        Pico-NTP-Module.c
        Pico-MQTT-Module.c
      )
      #
      # add_compile_definitions(WIFI_SSID="${WIFI_SSID}" WIFI_PASSWORD="${WIFI_PASSWORD}")
      target_compile_definitions(
        Pico-SLASH-Display PRIVATE
        WIFI_SSID=\"${WIFI_SSID}\"
        WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
        MQTT_BROKER_IP=\"${MQTT_BROKER_IP}\"
        MQTT_PASSWORD=\"${MQTT_PASSWORD}\"
        NO_SYS=1
      )
      #
      # Add the standard include files / directories to the build
      target_include_directories(
        Pico-SLASH-Display PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
      )
      #
      # include_directories(/home/pi/pico/pico-sdk/lib/lwip/contrib/ports/unix/port/include)
      # Add libraries requested to the build
      target_link_libraries(
        Pico-SLASH-Display
        hardware_adc
        hardware_clocks
        hardware_flash
        hardware_i2c
        hardware_irq
        hardware_pwm
        hardware_rtc
        hardware_sync
        hardware_uart
        hardware_watchdog
        pico_bootrom
        pico_cyw43_arch_lwip_threadsafe_background
        pico_httpd_content #
        pico_lwip
        pico_lwip_http #
        pico_lwip_mdns #
        pico_lwip_mqtt
        pico_multicore
        pico_platform
        pico_stdlib
      )
      #
      # Enable usb output, disable uart output
      pico_enable_stdio_usb(Pico-SLASH-Display  1)
      pico_enable_stdio_uart(Pico-SLASH-Display 0)
      #
      #
      pico_add_extra_outputs(Pico-SLASH-Display)


      pico_add_library(pico_httpd_content NOFLAG)
#      pico_set_lwip_httpd_content(
#        pico_httpd_content INTERFACE
#        ${CMAKE_CURRENT_LIST_DIR}/content/404.html
#        ${CMAKE_CURRENT_LIST_DIR}/content/index.shtml
#        ${CMAKE_CURRENT_LIST_DIR}/content/test.shtml
#        ${CMAKE_CURRENT_LIST_DIR}/content/ledpass.shtml
#        ${CMAKE_CURRENT_LIST_DIR}/content/ledfail.shtml
#        ${CMAKE_CURRENT_LIST_DIR}/content/img/rpi.png
#      )
    endif()
  endif()
endif()
#
