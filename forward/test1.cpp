#include <iostream>
#include <utility>
#include <type_traits>

void process(int& x) {
    std::cout << "int& " << std::endl;
}

void process(int&& x) {
    std::cout << "int&& " << std::endl;
}

template <typename T>
T&& myForward(typename std::remove_reference_t<T>& t) noexcept {
    return static_cast<T&&> (t);
}

template <typename T>
T&& myForward(typename std::remove_reference_t<T>&& t) noexcept{
    return static_cast<T&&> (t);
}

template <typename T>
void func(T&& t) {
    // 没有使用完美转发
    std::cout << "without perfect forwarding: ";
    process(t);

    // 使用完美转发
    std::cout << "with perfect forwarding: ";
    process(myForward<T>(t));
    process(std::forward<T>(t));


}

int main() {
    int x = 10;
    func(x); 
    func(10); 

    return 0;
} 