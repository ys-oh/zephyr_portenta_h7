cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blinky)

file (GLOB TEST_SRCS src/*.c)

target_sources(app PRIVATE ${TEST_SRCS})
