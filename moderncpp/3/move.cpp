#include <iostream>
#include <utility>  // std::move
#include <vector>   // std::vector
#include <string>   // std::string
class A {
public:
    int *pointer;
    A():pointer(new int(1)) { 
        std::cout << "construct" << pointer << std::endl; 
    }
    A(A& a):pointer(new int(*a.pointer)) { 
        std::cout << "copy" << pointer << std::endl; 
    } // meaningless object copy
    A(A&& a):pointer(a.pointer) { 
        a.pointer = nullptr;
        std::cout << "move" << pointer << std::endl; 
    }
    ~A(){ 
        std::cout << "destruct" << pointer << std::endl; 
        delete pointer; 
    }
};
// avoid compiler optimization
A return_rvalue(bool test) {
    A a,b;
    if(test) return a; // equal to static_cast<A&&>(a);
    else return b;     // equal to static_cast<A&&>(b);
}



void move() {
    std::string str = "Hello world.";
    std::vector<std::string> v;
    
    // use push_back(const T&), copy
    v.push_back(str);
    // "str: Hello world."
    std::cout << "str: " << str << std::endl;
    
    // use push_back(const T&&), no copy
    // the string will be moved to vector, and therefore std::move can reduce copy cost
    v.push_back(std::move(str));
    // str is empty now
    std::cout << "str: " << str << std::endl;
    
}


int main() {
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;


    std::cout<< "~~~~~~~~~~~~~" << std::endl;
    return_rvalue(false);
    std::cout << "destruct before" << std::endl;
    std::cout<< "~~~~~~~~~~~~~" << std::endl;
    A obj2 = std::move(obj);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;

    std::cout<< "~~~~~~~~~~~~~" << std::endl;

//    move();

    return 0;
}

