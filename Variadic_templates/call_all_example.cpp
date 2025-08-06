#include <iostream>
#include <string>

// 全局变量用于演示
static int x = 10, y = 20;
static std::string message = "Hello";

// 各种测试函数
void func1() {
    std::cout << "func1: x = " << x << std::endl;
    x += 5;
}

void func2() {
    std::cout << "func2: y = " << y << std::endl;
    y *= 2;
}

void func3() {
    std::cout << "func3: message = " << message << std::endl;
    message += " World";
}

void func4() {
    std::cout << "func4: x + y = " << x + y << std::endl;
}

// 带返回值的函数
int getX() {
    return x;
}

int getY() {
    return y;
}

// call_all 函数定义
template<typename... Args>
void call_all(Args... args) {
    (..., args());  // 逗号折叠表达式
}

// 带返回值的 call_all 版本
template<typename... Args>
auto call_all_with_return(Args... args) -> decltype(auto) {
    return (..., args());  // 返回最后一个函数的返回值
}

int main() {
    std::cout << "=== call_all 函数示例 ===" << std::endl;
    
    std::cout << "初始状态: x = " << x << ", y = " << y << ", message = " << message << std::endl;
    
    // 调用 call_all
    std::cout << "\n调用 call_all(func1, func2, func3, func4):" << std::endl;
    call_all(func1, func2, func3, func4);
    
    std::cout << "\n最终状态: x = " << x << ", y = " << y << ", message = " << message << std::endl;
    
    // 带返回值的调用
    std::cout << "\n调用带返回值的函数:" << std::endl;
    auto result = call_all_with_return(getX, getY);
    std::cout << "最后一个函数的返回值: " << result << std::endl;
    
    // 演示逗号折叠的执行顺序
    std::cout << "\n演示逗号折叠的执行顺序:" << std::endl;
    int a = 1, b = 2, c = 3;
    auto fold_result = (a++, b++, c++);  // 逗号折叠
    std::cout << "fold_result = " << fold_result << std::endl;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    
    return 0;
} 