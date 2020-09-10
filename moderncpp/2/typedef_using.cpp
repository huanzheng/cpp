#include <iostream>
#include <vector>

//template is not a type, it is used to generate type
//typedef is to alias type
template<typename T, typename U>
class MagicType {
public:
    T dark;
    U magic;
};

// not allowed
//template<typename T>
//typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

typedef int (*process)(void *);
using NewProcess = int(*)(void *);
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
    TrueDarkMagic<bool> you;
}
