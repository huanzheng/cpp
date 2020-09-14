#include <iostream>
#include <utility>  // std::move
#include <vector>   // std::vector
#include <string>   // std::string
#define USE_MOVE_CONSTRUCTOR
class A {
public:
    int *pointer;
    A():pointer(new int(1)) { 
        std::cout << "construct" << pointer << std::endl; 
    }
    A(const A& a):pointer(new int(*a.pointer)) { 
        std::cout << "copy" << pointer << std::endl; 
    } // meaningless object copy
#ifdef USE_MOVE_CONSTRUCTOR
    A(A&& a):pointer(a.pointer) { 
        a.pointer = nullptr;
        std::cout << "move" << pointer << std::endl; 
    }

    A& operator=(A&& a) {
        this->pointer = a.pointer;
        a.pointer = nullptr;
        std::cout << "move assignment" << pointer << std::endl; 
        return *this;
    }
#endif
    void const dodo() {
        std::cout<< "dodo" << std::endl;
    }
    ~A(){ 
        std::cout << "destruct" << pointer << std::endl; 
        delete pointer; 
    }
};
// avoid compiler optimization
A return_rvalue(bool ab) {
    A a;
    A b;
    if (ab)
        return a;
    else
        return b;
}

//this may accept rvalue
void only_accept_lvalue(A &a)
{
    A obj = std::move(a);
 //   a.dodo();
    std::cout<< "lllllllll" << std::endl;
    int b = 0;
    int c = b;
    return;
}
//this may accept rvalue
void only_accept_lvalue(A &&a)
{
    if (std::is_same<decltype(a), decltype(std::move(a))>::value) {
        std::cout << "a is rvalue " <<  std::endl;
    } else {
        std::cout << "a is lvalue " << std::endl;
    }

    //A obj = std::move(a);
    //A obj = a;
    a.dodo();
    std::cout<< "rrrrrrrrrrr" << std::endl;
    int b = 0;
    int c = b;
    return;
}
void only_accept_rvalue(A &&)
{
    std::cout<< "rrrrrrrrrrr" << std::endl;
    int b = 0;
    int c = b;
    return;
}

void lvalue(A a) {
}

int main() {
    A obj = return_rvalue(true);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;

 //   A&& obj2 = std::move(obj);
 //   only_accept_lvalue(obj2);

    //only_accept_lvalue(std::move(obj));
    only_accept_rvalue(std::move(obj));
    //only_accept_lvalue(A());
    std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;


   // lvalue(std::move(obj));
    std::cout << "~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    return 0;
}

