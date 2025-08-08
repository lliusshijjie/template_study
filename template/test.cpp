#include <iostream>
#include <type_traits>

// 1. 检测类型是否支持加法
template <typename T, typename = void>
struct is_addable : std::false_type {};

template <typename T>
struct is_addable<T, decltype(void(std::declval<T>() + std::declval<T>()))> : std::true_type {};

// 2. 可变参数加法的实现
template <typename T, typename... Args>
constexpr auto add(T first, Args... args) {
    // 确保所有类型相同且支持加法
    static_assert(is_addable<T>::value, "Type must be addable");
    static_assert((std::is_same_v<T, Args> && ...), "All types must be the same");

    if constexpr (sizeof...(args) == 0) {
        return first;
    } else {
        return first + add(args...);
    }
}

// 折叠表达式实现（C++17）
template <typename... Args>
constexpr auto add_fold(Args... args) {
    // 确保至少有一个参数且所有类型相同
    static_assert(sizeof...(args) > 0, "At least one argument is required");
    using CommnType = std::common_type_t<Args...>;

    // 确保支持加法
    static_assert(is_addable<CommnType>::value, "Type must be addable");
    
    // 使用折叠表达式进行加法
    return (... + args); 
}

// 检测类型是否支持减法
template <typename T, typename = void>
struct is_subable : std::false_type {};

template <typename T>
struct is_subable<T, decltype(void(std::declval<T>() - std::declval<T>()))> : std::true_type {};

// 可变参数减法的实现
template <typename T, typename... Args>
constexpr auto sub(T first, Args... args) {
    static_assert(is_subable<T>::value, "Type must be subable");
    static_assert((std::is_same_v<T, Args> && ...), "All types must be the same");
    if constexpr (sizeof...(args) == 0) {
        return first;
    } else {
        return first - sub(args...);
    }
}

// 折叠表达式实现的减法
template <typename... Args>
constexpr auto sub_fold(Args... args) {
    static_assert(sizeof...(args) > 0, "At least one argument is required");
    using CommonType = std::common_type_t<Args...>;

    static_assert(is_subable<CommonType>::value, "Type must be subable");

    // 左折叠表达式进行减法
    return (... - args);
}


int main() {   
    // 测试整数加法
    std::cout << "Testing add and add_fold functions:" << std::endl;
    constexpr int sum1 = add(1, 2, 3, 4, 5);
    constexpr int sum2 = add_fold(1, 2, 3, 4, 5);
    std::cout << "Sum using add: " << sum1 << std::endl;
    std::cout << "Sum using add_fold: " << sum2 << std::endl;

    // 测试浮点数加法
    constexpr double sum3 = add(1.1, 2.2, 3.3);
    constexpr double sum4 = add_fold(1.1, 2.2, 3.3);
    std::cout << "Sum using add (double): " << sum3 << std::endl;
    std::cout << "Sum using add_fold (double): " << sum4 << std::endl;

    std::string str1("Liu");
    std::string str2("Shi");
    std::string str3("jie");

    std::string str4 = add(str1, str2, str3);
    std::string str5 = add_fold(str1, str2, str3);
    std::cout << "Sum using add (string): " << str4 << std::endl;
    std::cout << "Sum using add_fold (string): " << str5 << std::endl;

    // 测试不同类型的加法（编译时错误）
    // auto sum5 = add(1, 3.14);
    constexpr auto sum6 = add_fold(1, 3.14); 
    std::cout << "Sum using add_fold with mixed types: " << sum6 << std::endl;

    std::cout << "Testint sub and sub_fold functions: " << std::endl;
    constexpr int sub1 = sub(10, 2, 2);
    constexpr int sub2 = sub_fold(10, 2, 2);
    std::cout << "Sub using sub: " << sub1 << std::endl;
    std::cout << "Sub using sub_fold: " << sub2 << std::endl;

    constexpr double sub3 = sub(10.0, 2.0, 2.0);
    constexpr double sub4 = sub_fold(10.0, 2.0, 2.0);
    std::cout << "Sub using sub (double): " << sub3 << std::endl;
    std::cout << "Sub using sub_fold (double): " << sub4 << std::endl;

    // 测试不同类型的减法（编译时错误）
    // auto sub5 = sub(10, 2.0);
    auto sub6 = sub_fold(10, 2.0);
    std::cout << "Sub using sub_fold with mixed types: " << sub6 << std::endl;
    return 0;
}