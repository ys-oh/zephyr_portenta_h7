

if (CONFIG_WIFI_WHD)

  set (WHD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/lib/wifi-host-driver)
  set (WHD_CORE_DIR       ${WHD_DIR}/WiFi_Host_Driver)
  set (WHD_RESOURCE_DIR   ${WHD_CORE_DIR}/resources)
  set (WHD_EXT_DIR        ${WHD_DIR}/External)
  set (WHD_CHIP           4343W)
  set (WHD_CHIP_NVRAM     MURATA-1DX)

  # whd common
  zephyr_library_named(whd)

  zephyr_include_directories(
    ${WHD_DIR}
    ${WHD_CORE_DIR}/inc
    ${WHD_CORE_DIR}/resources/resource_imp
    ${WHD_CORE_DIR}/src
    ${WHD_CORE_DIR}/src/include
    ${WHD_CORE_DIR}/src/bus_protocols

    # bsp
    ${WHD_EXT_DIR}/bsp
    ${WHD_EXT_DIR}/hal
    ${WHD_EXT_DIR}/rtos

    # resource & chip
    ${WHD_RESOURCE_DIR}/firmware/COMPONENT_${WHD_CHIP}
    ${WHD_RESOURCE_DIR}/clm/COMPONENT_${WHD_CHIP}
    ${WHD_RESOURCE_DIR}/nvram/COMPONENT_${WHD_CHIP}/COMPONENT_${WHD_CHIP_NVRAM}
  )

  file (GLOB WHD_CHIP_SRCS
    ${WHD_RESOURCE_DIR}/firmware/COMPONENT_${WHD_CHIP}/*.c
    ${WHD_RESOURCE_DIR}/clm/COMPONENT_${WHD_CHIP}/*.c
  )

  zephyr_sources(
    ${WHD_CORE_DIR}/resources/resource_imp/whd_resources.c
    ${WHD_CHIP_SRCS}

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

    # port
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/cyabs_rtos_zephyr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/cyhal_gpio_zephyr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/cyhal_sdio_zephyr.c
  )

  zephyr_compile_definitions(
      CYBSP_WIFI_INTERFACE_TYPE=0 # CYBSP_SDIO_INTERFACE
  )

endif()
