#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print (T t) {
    std::cout << "T is intergal!" << std::endl; 
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print(T t) {
    std::cout << "T is floating point!" << std::endl; 
}

// template <typename T>
// typename std::enable_if_t<std::is_integral_v<T>, void>
// myPrint(T t) {
//     std::cout << "T is intergal!" << std::endl; 
// }

// template <typename T>
// typename std::enable_if_t<std::is_floating_point_v<T>, void> 
// myPrint(T t) {
//     std::cout << "T is floatint point!" << std::endl;
// }

template <typename T>
typename std::enable_if_t<std::is_same_v<T, int>, void>
myPrint(T t) {
    std::cout << "T is intergal! " << t << std::endl;
}

template <typename T>
typename std::enable_if_t<std::is_same_v<T, double>, void>
myPrint(T t) {
    std::cout << "T is floating point! " << t << std::endl;
}

template <typename T>
typename std::enable_if_t<std::is_same_v<T, const char *>, void>
myPrint(T t) {
    std::cout << "T is const char *! " << t << std::endl;
}

template <typename T>
typename std::enable_if_t<std::is_same_v<T, std::string>, void>
myPrint(T t) {
    std::cout << "T is const char *! " << t << std::endl;
}

// C++20 Concepts
template <typename T>
concept Intergal = std::is_integral_v<T>;
template <Intergal T>
void conceptPrint(T t) {
    std::cout << "T is intergal! " << t << std::endl;
}

template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;
template <FloatingPoint T>
void conceptPrint(T t) {
    std::cout << "T is floating point! " << t << std::endl;
}

template <typename T>
concept Cstring = std::is_same_v<T, const char *> || std::is_same_v<T, char *>;
template <Cstring T>
void conceptPrint(T t) {
    std::cout << "T is (const char *) or (char *)! " << t << std::endl;
}

template <typename T>
concept String = std::is_same_v<T, std::string>;
template <String T>
void conceptPrint(T t) {
    std::cout << "T is std::string! " << t << std::endl;
}

template <typename T>
requires(!Intergal<T> && !FloatingPoint<T> && !Cstring<T> && !String<T>)
void conceptPrint(T t) {
    std::cout << "T is unknown type! " << std::endl;
    for (auto &item : t) {
        std::cout << item << " ";
    }
}

int main() {
    std::cout << "Concept test: " << std::endl;
    conceptPrint(666);
    conceptPrint(3.14);
    conceptPrint("Hello template!");
    conceptPrint(std::string("Hello template!"));
    conceptPrint(std::vector<int>{1, 2, 3, 4, 5});
    // std::cout << "print test: "<< std::endl;
    // print(666);
    // print(3.14);  

    // std::cout << "Myprint test: " << std::endl;
    // myPrint(666);
    // myPrint(3.14);
    // myPrint("Hello template!");
    // myPrint(std::string("Hello template!"));
    return 0;
}

