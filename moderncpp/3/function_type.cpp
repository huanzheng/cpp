#include <functional>
#include <iostream>

int foob(int para) {
    return para;
}

using foo = void(int);  // function pointer
void functional(foo f) {
    f(1);
}

int main() {
    /* lack of link library
    // std::function wraps a function that take int paremeter and returns int value
    std::function<int(int)> func = foob;

    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
        return 1+value+important;
    };
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;




*/
    auto f = [](int value) {
        std::cout << value << std::endl;
    };
    functional(f);  // call by function pointer
    f(1);           // call by lambda expression
    return 0;
}
