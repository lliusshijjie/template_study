#include <iostream>

// 右折叠 (Right Fold) ->  (... - args)
template <typename... Args>
auto rightFold(Args... args) -> decltype(auto)
{
    return (... - args);  // a - (b - (c - d))
}

// 左折叠 (Left Fold) ->  (args - ...)  
template <typename... Args>
auto leftFold(Args... args) -> decltype(auto)
{
    return (args - ...);  // ((a - b) - c) - d
}

// 二元右折叠
template <typename... Args>
auto binaryRightFold(Args... args) -> decltype(auto)
{
    return (args - ... - 0);  // ((a - b) - c) - 0
}

// 二元左折叠
template <typename... Args>
auto binaryLeftFold(Args... args) -> decltype(auto)
{
    return (0 - ... - args);  // 0 - (a - (b - c))
}

// 逻辑运算折叠
template <typename... Args>
auto logicalAnd(Args... args) -> decltype(auto)
{
    return (args && ...);  // a && b && c && d
}

template <typename... Args>
auto logicalOr(Args... args) -> decltype(auto)
{
    return (args || ...);  // a || b || c || d
}

// 逗号折叠 (用于打印)
template <typename... Args>
void printAll(Args... args)
{
    ((std::cout << args << " "), ...);  // 逗号折叠
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== 折叠表达式示例 ===" << std::endl;
    
    // 减法折叠 - 使用与您的 mySub 相同的参数
    std::cout << "参数: 1, 10, 3.14, 666" << std::endl;
    std::cout << "右折叠 (... - args): " << rightFold(1, 10, 3.14, 666) << std::endl;
    std::cout << "左折叠 (args - ...): " << leftFold(1, 10, 3.14, 666) << std::endl;
    
    // 二元折叠
    std::cout << "二元右折叠 (1-2-3-4-0): " << binaryRightFold(1, 2, 3, 4) << std::endl;
    std::cout << "二元左折叠 (0-1-2-3-4): " << binaryLeftFold(1, 2, 3, 4) << std::endl;
    
    // 逻辑运算
    std::cout << "逻辑与 (true && false && true): " << logicalAnd(true, false, true) << std::endl;
    std::cout << "逻辑或 (true || false || false): " << logicalOr(true, false, false) << std::endl;
    
    // 逗号折叠
    std::cout << "打印所有参数: ";
    printAll(1, "hello", 3.14, true);
    
    return 0;
} 