

if (CONFIG_WIFI_WHD)

  set (WHD_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/lib/wifi-host-driver)
  set (WHD_CORE_DIR   ${WHD_DIR}/WiFi_Host_Driver)
  set (WHD_EXT_DIR    ${WHD_DIR}/External)
  set (WHD_CHIP       "4343W")
  set (WHD_CHIP_NVRAM "MURATA-1DX")

  # whd common
  zephyr_library_named(whd)

  zephyr_include_directories(
    ${WHD_CORE_DIR}/inc
    ${WHD_CORE_DIR}/resources/resource_imp
    ${WHD_CORE_DIR}/src
    ${WHD_CORE_DIR}/src/include
    ${WHD_CORE_DIR}/src/bus_protocols
  )

  zephyr_sources(
    ${WHD_CORE_DIR}/resources/resource_imp/whd_resources.c

    ${WHD_CORE_DIR}/src/whd_ap.c
    ${WHD_CORE_DIR}/src/whd_buffer_api.c
    ${WHD_CORE_DIR}/src/whd_cdc_bdc.c
    ${WHD_CORE_DIR}/src/whd_chip.c
    ${WHD_CORE_DIR}/src/whd_chip_constants.c
    ${WHD_CORE_DIR}/src/whd_clm.c
    ${WHD_CORE_DIR}/src/whd_debug.c
    ${WHD_CORE_DIR}/src/whd_events.c
    ${WHD_CORE_DIR}/src/whd_logging.c
    ${WHD_CORE_DIR}/src/whd_management.c
    ${WHD_CORE_DIR}/src/whd_network_if.c
    ${WHD_CORE_DIR}/src/whd_resource_if.c
    ${WHD_CORE_DIR}/src/whd_sdpcm.c
    ${WHD_CORE_DIR}/src/whd_thread.c
    ${WHD_CORE_DIR}/src/whd_utils.c
    ${WHD_CORE_DIR}/src/whd_wifi.c
    ${WHD_CORE_DIR}/src/whd_wifi_api.c
    ${WHD_CORE_DIR}/src/whd_wifi_p2p.c

    ${WHD_CORE_DIR}/src/bus_protocols/whd_bus.c
    ${WHD_CORE_DIR}/src/bus_protocols/whd_bus_common.c
    ${WHD_CORE_DIR}/src/bus_protocols/whd_bus_sdio_protocol.c
    ${WHD_CORE_DIR}/src/bus_protocols/whd_bus_spi_protocol.c
  )

  # resource & chip
  add_library(whd-${WHD_CHIP} INTERFACE)

  target_include_directories(whd-4343W INTERFACE
    ${WHD_CORE_DIR}/firmware/COMPONENT_${WHD_CHIP}
    ${WHD_CORE_DIR}/clm/COMPONENT_${WHD_CHIP}
    ${WHD_CORE_DIR}/nvram/COMPONENT_${WHD_CHIP}/COMPONENT_${WHD_CHIP_NVRAM}
  )

  file (GLOB WHD_${WHD_CHIP}_SRCS
    ${WHD_CORE_DIR}/firmware/COMPONENT_${WHD_CHIP}/*.c
    ${WHD_CORE_DIR}/clm/COMPONENT_${WHD_CHIP}/*.c
  )

  target_sources(whd-${WHD_CHIP} INTERFACE WHD_${WHD_CHIP}_SRCS)

  # bsp
  add_library(whd-bsp INTERFACE)

  target_include_directories(whd-bsp INTERFACE
    ${WHD_EXT_DIR}/bsp
    ${WHD_EXT_DIR}/hal
    ${WHD_EXT_DIR}/rtos
  )

  target_link_libraries(whd PUBLIC whd-${WHD_CHIP} whd-bsp)

endif()
