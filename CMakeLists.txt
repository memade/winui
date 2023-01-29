cmake_minimum_required(VERSION 3.25.1)

project(winui)

string(TOUPPER ${PROJECT_NAME} MAIN_PROJECT_NAME_UPPER)

set(CMAKE_CXX_STANDARD 23)
# 添加预定义宏
add_definitions(-DUNICODE -D_UNICODE)

set(SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(CURRENT_SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set(LOCAL_CMAKE_MODULES_PATH ${SOLUTION_ROOT_DIR}/cmake/modules/)


LIST(APPEND CMAKE_MODULE_PATH ${LOCAL_CMAKE_MODULES_PATH})
include(global_methods)
include(msvc_methods)

# 设置默认编译类型
MEMADE_SET_CMAKE_CONFIGURATION_TYPES("Debug;Release;")

#Project generic header definition
#include_directories(${LOCAL_SRC_PATH})
#include_directories(${LOCAL_COMMON_INCLUDE_PATH})
#include_directories(${LCOAL_PROJECTS_3RDPARTY_PATH})

option(ENABLE_MSVC_CRT_MT_${MAIN_PROJECT_NAME_UPPER} "Enable ${PROJECT_NAME} msvc crt /MT /MTd compile." ON)

MEMADE_SET_CMAKETARGETS_FOLDER()

MEMADE_OUTPATHCONFIG("bin" "" "")
add_subdirectory(${CURRENT_SOLUTION_DIR}/src/core/)

add_subdirectory(${CURRENT_SOLUTION_DIR}/tests/testwinui/)
set_target_properties(testwinui PROPERTIES FOLDER "tests")
MEMADE_OUTPATHCONFIG("")

#[[
MEMADE_OUTPATHCONFIG("bin/${CMAKE_VS_PLATFORM_NAME}/${VS_CONFIGURATION}/components/" "" "" ON)
add_subdirectory(${CURRENT_SOLUTION_DIR}/src/components/CFHMarketData)
set_target_properties(CFHMarketData PROPERTIES FOLDER "components")
add_subdirectory(${CURRENT_SOLUTION_DIR}/src/components/CFHTradeOrder)
set_target_properties(CFHTradeOrder PROPERTIES FOLDER "components")
add_subdirectory(${CURRENT_SOLUTION_DIR}/src/components/LMAXMarketData)
set_target_properties(LMAXMarketData PROPERTIES FOLDER "components")
add_subdirectory(${CURRENT_SOLUTION_DIR}/src/components/LMAXTradeOrder)
set_target_properties(LMAXTradeOrder PROPERTIES FOLDER "components")
MEMADE_OUTPATHCONFIG("")
]]
#MSVC_SET_STARTUP_PROJECT(bridge ${CMAKE_CURRENT_SOURCE_DIR})
