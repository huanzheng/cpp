#include <iostream>                                                                                                    
#include <string>   // std::string 

#define G 3
#define F 1

/**
 * F=1 G=3 causes g() modifies a local value; but compiler does not report error
 * F=2 G=3 f is const T&, but g is T&
 * */

#if G == 1
void g(int i) {
    i++;
}
#elif G == 2
void g(const int i) {
    int j = i;
    j++;
}
#elif G == 3
void g(int& i) {
    i++;
    std::cout << "i:"  << i << std::endl;
}
#elif G == 4
void g(const int& i) {
    int j = i;
    j++;
}
#endif




#if F == 1
template<typename T>
void f(T t) {
    g(t);
}
#elif F == 2
template<typename T>
void f(const T& t) {
    g(t);
}
#elif F == 3
template<typename T>
void f(T& t) {
    g(t);
}
#endif


int main() {
    int a = 0;
    f(a);
    std::cout << a << std::endl;
    const int b = 1;
    f(b);
    std::cout << b << std::endl;


    int& c = a;
    f(c);
    std::cout << a << std::endl;

    const int& d = a;
    f(d);
    std::cout << a << std::endl;

    return 0;
}
