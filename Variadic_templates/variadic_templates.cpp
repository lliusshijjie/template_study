#include <iostream>

static int x = 2, y = 3;

void add() { x += 2; }
void sub() { y -= 2; }
void mul() { x *= 2; }
void divide() { y /= 2; }

template<typename... Args>
void call_all(Args... args) {
    // 正确的一元右折叠：逐个调用函数指针
    (args(), ...);
}

int main() {
    std::cout << "before call_all: " << "x = " << x << " y = " << y << std::endl;
    call_all(add, sub, mul, divide);  // 现在可以正确编译和运行
    
    std::cout << "after call_all: " << "x = " << x << " y = " << y << std::endl;
    return 0;
}