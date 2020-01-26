cmake_minimum_required(VERSION 3.15)

project(work)

# BOOST
## 设置个变量控制
SET(BOOST_MIN_VERSION "1.72.0")
## 动态查找
FIND_PACKAGE(Boost ${BOOST_MIN_VERSION} REQUIRED)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error:Boost (version >=${BOOST_MIN_VERSION}) required.\n")
endif()
message("------------ Options -------------")
message("  CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("  CMAKE_BUILD_TYPE: Hello World!")

# 编译google test，会在当前目录生成libtest.a静态库
add_subdirectory(./googletest)
#头文件
include_directories(${PROJECT_SOURCE_DIR}/src/include ./googletest/include)
# BOOST
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_SIRS})
#源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src/main dir_srcs)
#库文件 : libtest.a 添加到链接路径中
link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/googletest)

#需要添加googletest运行需要的pthread
set(LIBRARIES pthread)

#编译器相关设置
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set(WORK ${dir_srcs} src/main/timer.cpp)

add_custom_target(cmake-build-debug)
add_executable(${PROJECT_NAME} ${WORK})

target_link_libraries(${PROJECT_NAME} gtest ${Boost_LIBRARIES})
