#include <iostream>
#include <type_traits>
#include <vector>

// 判断一个类是否有成员函数 foo 的 SFINAE 实现
template <typename T>
class has_foo {
private:
    typedef char yes[1];
    typedef char no[2];

    template <typename U, void(U::*)()>
    struct SFINAE {};

    template <typename U>
    static yes& test(SFINAE<U, &U::foo>*);

    template <typename U>
    static no& test(...);

public:
    static constexpr bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

template <typename T>
typename std::enable_if_t<has_foo<T>::value, void>
call_foo(T t) {
    t.foo();
}

class WithFoo {
public:
    void foo() {
        std::cout << "WithFoo::foo called!" << std::endl;
    }
};

class WithoutFoo {};




int main() {
    WithFoo wf;
    call_foo(wf);
    return 0;
}