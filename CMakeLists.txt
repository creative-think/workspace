cmake_minimum_required(VERSION 3.15)

project(work)

message("--------------- Options ---------------")
message("  CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("  CMAKE_BUILD_TYPE: Hello !")

#头文件
include_directories(src/include)
#源文件
aux_source_directory(src/main dir_srcs)
#库文件
link_directories(&{CMAKE_CURRENT_LIST_DIR}/lib)

#编译器相关设置
set(CMAKE_CXX_COMPILER   "clang++")   # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "-std=c++14")   # c++14
set(CMAKE_CXX_FLAGS   "-g")           # 调试信息
set(CMAKE_CXX_FLAGS   "-Wall")        # 开启所有警告
#set(CMAKE_CXX_STANDARD 14)

set(work ${dir_srcs} src/include/common.h src/include/string_util.h src/main/string_util.cpp)

add_executable(work ${work})