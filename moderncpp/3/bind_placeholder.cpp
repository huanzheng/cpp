#include <functional>
#include <iostream>

int foo(int a, int b, int c) {
    ;
}
int main() {
    // bind parameter 1, 2 on function foo, and use std::placeholders::_1 as placeholder
    // for the first parameter.
    auto bindFoo = std::bind(foo, std::placeholders::_1, 1,2);
    // when call bindFoo, we only need one param left
    bindFoo(1);
}
