#include <iostream>
#include <type_traits>

template <typename T, typename U = void>
struct has_non_void_value_type : std::false_type {};

// template <typename T>
// struct has_non_void_value_type<T, std::enable_if_t<!std::is_void_v<typename T::value_type>>> : std::true_type {

// };

// C++17 中的 void_t 用于简化 SFINAE
template <typename T>
struct has_non_void_value_type<T, std::void_t<typename T::value_type>> : std::true_type {};

template <typename T, bool HasValueType = has_non_void_value_type<T>::value>
struct TypePrinter;

// 当T有成员类型value_type的时候
template <typename T>
struct TypePrinter<T, true> {
    static void print() {
        std::cout << "T has a value_type member." << std::endl;
    }
};

template <typename T>
struct TypePrinter<T, false> {
    static void print() {
        std::cout << "T does not have a value_type member." << std::endl;
    }
};

struct WithValueType {
    using value_type = int;
};

struct WithoutValueType {};

int main() {
    TypePrinter<WithValueType>::print(); 
    TypePrinter<WithoutValueType>::print(); 
    return 0;
}