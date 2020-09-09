#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

int main() {
    //only works in C++17
//    auto [x, y, z] = f();
//    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}
