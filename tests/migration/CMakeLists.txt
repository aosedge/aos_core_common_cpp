#
# Copyright (C) 2024 Renesas Electronics Corporation.
# Copyright (C) 2024 EPAM Systems, Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

set(TARGET migration_test)

# ######################################################################################################################
# Sources
# ######################################################################################################################

set(SOURCES migration_test.cpp)

# ######################################################################################################################
# Target
# ######################################################################################################################

add_executable(${TARGET} ${SOURCES})

gtest_discover_tests(${TARGET})

# ######################################################################################################################
# Libraries
# ######################################################################################################################

target_link_libraries(${TARGET} migration GTest::gmock_main)
