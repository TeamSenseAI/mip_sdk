cmake_minimum_required(VERSION 3.10)
project(mip_sdk C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(MIP_DIR "${SRC_DIR}/mip")

#
# Build options
#

option(WITH_SERIAL "Build serial connection support into the library and examples" ON)
option(WITH_TCP    "Build TCP connection support into the library and exampels" OFF)

set(MIP_TIMESTAMP_TYPE "" CACHE STRING "Override the type used for received data timestamps and timeouts (must be unsigned or at least 64 bits).")

option(BUILD_PACKAGE "Whether to build a package from the resulting binaries" OFF)

#
# Utils
#

set(UTILS_DIR "${MIP_DIR}/utils")

set(UTILS_SOURCES
    "${UTILS_DIR}/byte_ring.c"
    "${UTILS_DIR}/byte_ring.h"
    "${UTILS_DIR}/serialization.c"
    "${UTILS_DIR}/serialization.h"
)

#
# MIP Control
#

set(MIP_SOURCES
    "${MIP_DIR}/mip_cmdqueue.c"
    "${MIP_DIR}/mip_cmdqueue.h"
    "${MIP_DIR}/mip_dispatch.c"
    "${MIP_DIR}/mip_dispatch.h"
    "${MIP_DIR}/mip_field.c"
    "${MIP_DIR}/mip_field.h"
    "${MIP_DIR}/mip_offsets.h"
    "${MIP_DIR}/mip_packet.c"
    "${MIP_DIR}/mip_packet.h"
    "${MIP_DIR}/mip_parser.c"
    "${MIP_DIR}/mip_parser.h"
    "${MIP_DIR}/mip_result.c"
    "${MIP_DIR}/mip_result.h"
    "${MIP_DIR}/mip_types.h"
    "${MIP_DIR}/definitions/descriptors.c"
    "${MIP_DIR}/definitions/descriptors.h"
    "${MIP_DIR}/mip.hpp"
    "${MIP_DIR}/mip_all.h"
)

set(MIPDEV_SOURCES
    "${MIP_DIR}/mip_interface.c"
    "${MIP_DIR}/mip_interface.h"
    "${MIP_DIR}/mip_device.cpp"
    "${MIP_DIR}/mip_device.hpp"
)

set(MIPDEF_SOURCES
    "${MIP_DIR}/definitions/commands_3dm.c"
    "${MIP_DIR}/definitions/commands_3dm.h"
    "${MIP_DIR}/definitions/commands_base.c"
    "${MIP_DIR}/definitions/commands_base.h"
    "${MIP_DIR}/definitions/commands_filter.c"
    "${MIP_DIR}/definitions/commands_filter.h"
    "${MIP_DIR}/definitions/commands_gnss.c"
    "${MIP_DIR}/definitions/commands_gnss.h"
    "${MIP_DIR}/definitions/commands_rtk.c"
    "${MIP_DIR}/definitions/commands_rtk.h"
    "${MIP_DIR}/definitions/commands_system.c"
    "${MIP_DIR}/definitions/commands_system.h"
    "${MIP_DIR}/definitions/data_filter.c"
    "${MIP_DIR}/definitions/data_filter.h"
    "${MIP_DIR}/definitions/data_gnss.c"
    "${MIP_DIR}/definitions/data_gnss.h"
    "${MIP_DIR}/definitions/data_sensor.c"
    "${MIP_DIR}/definitions/data_sensor.h"
    "${MIP_DIR}/definitions/data_shared.c"
    "${MIP_DIR}/definitions/data_shared.h"
    "${MIP_DIR}/definitions/data_system.c"
    "${MIP_DIR}/definitions/data_system.h"
    ${INTDEF_SOURCES}
)

string(REPLACE ".h" ".hpp" MIPDEF_HPP_SOURCES "${MIPDEF_SOURCES}")
string(REPLACE ".c" ".cpp" MIPDEF_CPP_SOURCES "${MIPDEF_HPP_SOURCES}")

if(WITH_SERIAL)
    list(APPEND UTILS_SOURCES
        "${UTILS_DIR}/serial_port.c"
        "${UTILS_DIR}/serial_port.h"
    )
    list(APPEND MIP_INTERFACE_SOURCES
        "${MIP_DIR}/platform/serial_connection.hpp"
        "${MIP_DIR}/platform/serial_connection.cpp"
    )
endif()

set(ALL_MIP_SOURCES
    ${MIPDEF_SOURCES}
    ${MIPDEF_CPP_SOURCES}
    ${MIPDEV_SOURCES}
    ${MIP_SOURCES}
    ${UTILS_SOURCES}
    ${MIP_CPP_HEADERS}
    ${MIP_INTERFACE_SOURCES}
)


option(MIP_DISABLE_CPP "Excludes all C++ files from the project." ON)
if(MIP_DISABLE_CPP)
    list(FILTER ALL_MIP_SOURCES EXCLUDE REGEX "[c|h]pp$")
endif()

add_library(mip_sdk ${ALL_MIP_SOURCES})

add_dependencies(mip_sdk prebuild_targets nuttx_context)
target_compile_options(mip_sdk
        PRIVATE
                -Wno-shadow
)

if("${PX4_PLATFORM}" MATCHES "nuttx")
    target_compile_definitions(mip_sdk PUBLIC __NUTTX__)
endif()
