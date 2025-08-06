cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(Specialization)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建可执行文件
add_executable(Specialization Specialization.cpp)

# 设置编译选项
if(MSVC)
    # Windows MSVC 编译器选项
    target_compile_options(Specialization PRIVATE /W4)
else()
    # GCC/Clang 编译器选项
    target_compile_options(Specialization PRIVATE -Wall -Wextra -Wpedantic)
endif()

# 设置输出目录
set_target_properties(Specialization PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 打印项目信息
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}") 