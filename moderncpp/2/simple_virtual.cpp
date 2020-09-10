#include <iostream>
struct Base {
    virtual void foo() {std::cout << "Base" << std::endl;}
};
struct SubClass1 : Base {
    virtual void foo() {std::cout << "SubClass1" << std::endl;}
    virtual void bar(int i) {std::cout << "SubClass1 bar " << i<< std::endl;}
};

struct SubClass2 : SubClass1 {
    void foo() {std::cout << "SubClass2" << std::endl;}
    void bar(double i) {std::cout << "SubClass2 bar " << i << std::endl;}
};
struct SubClass3 : SubClass2 {
    void foo() {std::cout << "SubClass3" << std::endl;}
};

int main() {
    SubClass1 *s1 = new SubClass1();
    SubClass1 *s2 = new SubClass2();
    SubClass2 *s3 = new SubClass3();

    s1->foo();
    s2->foo();
    s3->foo();

    double i = 1.0;
    int j = 2;
    s1->bar(i);
    s2->bar(i);
    s3->bar(i);

    s3->bar(j); //cannot see SubClass1 bar(int i)
    s1=s3;
    s1->bar(j); //can use SubClass1 bar(int i)
}
