#include <iostream>
#include <vector>
#include <map>


template<typename... Ts> class Magic
{
};

template<typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << std::endl;
}

int main() {
    class Magic<int,
            std::vector<int>,
            std::map<std::string,
            std::vector<int>>> darkMagic;
    class Magic<> nothing;

    magic();      // 0
    magic(1);     // 1
    magic(1, ""); // 2
    return 0;
}
