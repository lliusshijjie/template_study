#include <iostream>
#include <type_traits>

template <typename T, typename U = void>
class Logger {
public:
    static void log(const T& message) {
        std::cout << "Log: " << message << std::endl;
    }
};


template <typename T>
class Logger<T, std::enable_if_t<std::is_pointer_v<T>>> {
public:
    static void log(const T& message) {
        if (message) {
            std::cout << "Log*: " << message << std::endl;
        } else {
            std::cout << "Log: nullptr" << std::endl;
        }
    }
};

template<>
class Logger<std::string> {
public:
    static void log(const std::string message) {
        std::cout << "StringLog: " << message << std::endl;
    } 
};

template <typename T>
class LogOne {
public:
    static void logOne(const T& message) {
        Logger<T>::log(message);
    }
};

template <typename... Args>
void logAll(const Args&... args) {
    (LogOne<Args>::logOne(args), ...);
}

template <int N>
struct Fibonacci {
    inline static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value; 
};

template <>
struct Fibonacci<0> {
    inline static const int value = 0;
};

template <>
struct Fibonacci<1> {
    inline static const int value = 1; 
};

template <typename T, typename = void>
struct is_addable : std::false_type {};

template <typename T>
struct is_addable<T, decltype(void(std::declval<T>() + std:: declval<T>()))> : std::true_type {};

// C++17
// template <typename T>
// inline constexpr bool is_addable_v = false;

// template <typename T>
// inline constexpr bool is_addable_v = <T, decltype(void(std::declval<T>() + std::declval<T>()))> = true;

template <int... N>
struct Sum;

template <>
struct Sum<> {
    static constexpr int value = 0;
};

template <int N, int... Rest>
struct Sum<N, Rest...> {
    static constexpr int value = N + Sum<Rest...>::value;
};

int main() {
    // Example usage of Logger with different types
    // Logger<int>::log(42);
    // Logger<const char *>::log("Hello World!");
    // Logger<std::string>::log("Hello String!");
    // int x = 42;
    // const char* str = "Hello World!";
    // std::string s = "Hello String!";
    // logAll(x, str, s);

    // Example usage of Fibonacci
    // constexpr int fib10 = Fibonacci<15>::value;
    // constexpr int fib20 = Fibonacci<20>::value;
    // std::cout << "Fibonacci(10): " << fib10 << std::endl;
    // std::cout << "Fibonacci(20): " << fib20 << std::endl;
    // int fibonacci[30] = {0};
    // fibonacci[0] = 0, fibonacci[1] = 1;
    // for (int i = 2; i <= 20; i++) {
    //     fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    //     if (i % 10 == 0) {
    //         std:: cout << "fibonacci(" << i << "): " << fibonacci[i] << std::endl;
    //     }
    // }

    // Example usage of is_addable
    // static_assert(is_addable<int>::value, "int shoule be addable");
    // static_assert(is_addable<std::string>::value, "std::string should be addable");
    // static_assert(!is_addable<void>::value, "void should not be addable");
    // std::cout << std::boolalpha;
    // std::cout << "int is addable: " 
    //           << is_addable<int>::value << "\n";          // true
    // std::cout << "double is addable: " 
    //           << is_addable<double>::value << "\n";       // true
    // std::cout << "std::string is addable: " 
    //           << is_addable<std::string>::value << "\n";  // true
    // std::cout << "void is addable: " 
    //           << is_addable<void>::value << "\n";   // false

    // Example usage of Sum
    constexpr int sum1 = Sum<1, 2, 3, 4, 5>::value;
    constexpr int sum2 = Sum<666, 888, 999>::value;
    return 0;
}