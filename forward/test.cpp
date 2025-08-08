#include <iostream>
#include <utility>

template <typename T>
void check_reference(T&& t) {
    std::cout << std::boolalpha;
    std::cout << "T 是左值引用：" << std::is_lvalue_reference_v<T> << std::endl;
    std::cout << "T 是右值引用：" << std::is_rvalue_reference_v<T> << std::endl;
    std::cout << "t 是左值引用：" << std::is_lvalue_reference_v<decltype(t)> << std::endl;
    std::cout << "t 是右值引用：" << std::is_rvalue_reference_v<decltype(t)> << std::endl;
}

void process(int& x) {
    std::cout << "int& " << std::endl;
}

void process(int&& x) {
    std::cout << "int&& " << std::endl;
}

template <typename T>
void wrapper(T&& t) {
    // process(t);
    process(std::forward<T>(t));
}

int main() {
    system("chcp 65001");
    // std::cout << std::boolalpha;

    // int a = 10;
    // std::cout << "a 是左值引用：" << std::is_lvalue_reference_v<decltype(a)> << std::endl;
    // std::cout << "(a) 是左值引用：" << std::is_lvalue_reference_v<decltype((a))> << std::endl;
    // int &b = a;
    // std::cout << "b 是左值引用：" << std::is_lvalue_reference_v<decltype(b)> << std::endl;

    // int &&c = 20;
    // std::cout << "c 是右值引用：" << std::is_rvalue_reference_v<decltype(c)> << std::endl;

    // int a = 10;
    // check_reference(a);
    // std::cout << std::endl;

    // check_reference(10);
    // std::cout << std::endl;

    // check_reference((a));
    // std::cout << std::endl;

    // int &&b = 20;
    // check_reference(b);
    // std::cout << std::endl;

    // check_reference(std::move(b));

    int x = 10;
    std::cout << "x: " << std::endl; 
    wrapper(x);

    std::cout << "10: " << std::endl;
    wrapper(10);
    return 0;
}

