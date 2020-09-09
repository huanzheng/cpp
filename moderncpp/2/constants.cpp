#include <iostream>
#include <type_traits>

void no_void_implicit_cast() {
    //do not allow implicit cast of void* to other
    void *nulptr = 0;
    //char *ch = nullptr; //this will fail
    char *ch = static_cast<char*>(nulptr);
}

void use_nullptr() {
    char *ch = nullptr;
}
void foo(char*) {
    std::cout<<"char*"<<std::endl;
}
void foo(int) {
    std::cout<<"int"<<std::endl;
}

void no_NULL_but_nullptr() {
//    foo(NULL); //doesnot compile call to 'foo' is ambiguous
#define NULL 0
    foo(0);
    foo(nullptr);
}

void compare() {
    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl;
}

int main() {
    no_void_implicit_cast();
    no_NULL_but_nullptr();
    compare();
}
