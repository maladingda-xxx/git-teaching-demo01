cmake_minimum_required(VERSION 4.2)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

# 可选：让编译器输出更多警告，方便排查代码问题
add_compile_options(-Wall -Wextra -Wpedantic)

# 1. 收集当前目录（及子目录）下所有 .cpp 文件
file(GLOB_RECURSE ALL_CPPS "*.cpp")

# 2. 为每一个 .cpp 单独生成一个可执行文件
foreach(SOURCE ${ALL_CPPS})
    # 提取文件名（不带扩展名），作为可执行文件的名字
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE}
            duilie.cpp
    )
endforeach()