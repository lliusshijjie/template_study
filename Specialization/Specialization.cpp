#include <iostream>

// 全特化
template <typename T>
void print(T t) {
    std::cout << "t = " << t << std::endl;
}

template <>
void print<std::string>(std::string s) {
    std::cout << "s = " << s << std::endl;
}

// 全特化
template <>
void print<const char*>(const char* ptr) {
    std::cout << "*ptr = " << ptr << std::endl;
}

// 通用模板(必须写在最前面)
template <typename T, typename U>
struct Mypair {
    static const char* name() {
        return "Generic";
    }
};

// 偏特化
template <typename T>
struct Mypair<T, T> {
    static const char* name() {
        return "Same Types";
    }
};

// 偏特化
template <typename T, typename U> 
struct Mypair<T, U*> {
    static const char* name() {
        return "Pointer";
    } 
};

int main() {

    std::cout << "Full specializetion: " << std::endl;
    print(666.666);
    print(std::string("Hello Template!"));
    print("Hello Template!");
// #if 0
//     auto s1 = Mypair<int, double>::name();
//     auto s2 = Mypair<int, int>::name();
//     auto s3 = Mypair<int, int*>::name();
//     std::cout << "s1 = " << s1 << std::endl;
//     std::cout << "s2 = " << s2 << std::endl;
//     std::cout << "s3 = " << s3 << std::endl;
// #else 
//     print(520.1314);
    
//     std::string s = "Hello Template!";
//     print("Hello Template!");  
//     print(s);                

// #endif
    return 0;
}
