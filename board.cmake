# SPDX-License-Identifier: Apache-2.0

board_runner_args(dfu-util --alt=0 --pid=2341:035b --dfuse --dt-flash=yes)
include(${ZEPHYR_BASE}/boards/common/dfu-util.board.cmake)
