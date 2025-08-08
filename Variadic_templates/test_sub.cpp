#include <iostream>

// 右折叠 (Right Fold) 
template <typename... Args>
auto rightFold(Args... args) -> decltype(auto)
{
    return (args - ...);  // a - (b - (c - d))
}

// 左折叠 (Left Fold) 
template <typename... Args>
auto leftFold(Args... args) -> decltype(auto)
{
    return (... - args);  // ((a - b) - c) - d
}

int main()
{
    std::cout << "=== 减法折叠测试 ===" << std::endl;
    
    // 测试参数: 1, 10, 3.14, 666
    std::cout << "参数: 1, 10, 3.14, 666" << std::endl;
    
    // 右折叠计算
    auto right_result = rightFold(1, 10, 3.14, 666);
    std::cout << "右折叠 (args - ...): " << right_result << std::endl;
    std::cout << "计算过程: 1 - (10 - (3.14 - 666)) = 1 - (10 - (-662.86)) = 1 - 672.86 = -671.86" << std::endl;
    
    // 左折叠计算
    auto left_result = leftFold(1, 10, 3.14, 666);
    std::cout << "左折叠 (... - args): " << left_result << std::endl;
    std::cout << "计算过程: ((1 - 10) - 3.14) - 666 = (-9 - 3.14) - 666 = -12.14 - 666 = -678.14" << std::endl;
    
    return 0;
} 