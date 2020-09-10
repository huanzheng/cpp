#include <iostream>

template<typename T>
auto print_type_info(const T& t) {
    /*only works after C++17
     * if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }*/
    return 0;
}
int main() {
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}
