cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(VariadicTemplates)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建可执行文件
add_executable(VariadicTemplates variadic_templates.cpp)
add_executable(FoldExamples fold_examples.cpp)
add_executable(TestSub test_sub.cpp)
add_executable(CallAllExample call_all_example.cpp)

# 设置编译选项
if(MSVC)
    # Windows MSVC 编译器选项
    target_compile_options(VariadicTemplates PRIVATE /W4)
    target_compile_options(FoldExamples PRIVATE /W4)
    target_compile_options(TestSub PRIVATE /W4)
    target_compile_options(CallAllExample PRIVATE /W4)
else()
    # GCC/Clang 编译器选项
    target_compile_options(VariadicTemplates PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(FoldExamples PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(TestSub PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(CallAllExample PRIVATE -Wall -Wextra -Wpedantic)
endif()

# 设置输出目录
set_target_properties(VariadicTemplates PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
set_target_properties(FoldExamples PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
set_target_properties(TestSub PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
set_target_properties(CallAllExample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 打印项目信息
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# 添加调试信息
message(STATUS "Source files: variadic_templates.cpp, fold_examples.cpp, test_sub.cpp, call_all_example.cpp")
message(STATUS "Targets: VariadicTemplates, FoldExamples, TestSub, CallAllExample")