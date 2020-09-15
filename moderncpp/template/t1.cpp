#include <iostream>

void g(int& i) {
    i++;
}
template<class A1> void f(A1 const& a1)
{
    std::cout << "A1 const& a1" << std::endl;
    return g(a1);
}
template<class A1> void f(A1& a1)
{
    std::cout << "A1 & a1" << std::endl;
    return g(a1);
}

int main() {
    int&& a = 1;
    g(a);
    std::cout << a << std::endl;

    f(a); //without second template, it will fail
    std::cout << a << std::endl;

    //f(1);//error, but g(1) also error, so it's ok
    return 0;
}

