
all: constants constexpr ifinitial initializer_list structured_binding auto decltype returnauto if_constexpr range_loop typedef_using variadic_template variadic_recursive_template

clean:
	rm constants constexpr ifinitial initializer_list structured_binding auto decltype returnauto if_constexpr range_loop typedef_using variadic_template variadic_recursive_template
constants: constants.cpp
	clang++ constants.cpp -std=c++14 -o constants
constexpr: constexpr.cpp
	clang++ constexpr.cpp -std=c++14 -o constexpr
ifinitial: if_initial.cpp
	clang++ if_initial.cpp -std=c++14 -o ifinitial
initializer_list: initializer_list.cpp
	clang++ initializer_list.cpp -std=c++14 -o initializer_list
structured_binding: structured_binding.cpp
	clang++ structured_binding.cpp -std=c++14 -o structured_binding
auto: auto.cpp
	clang++ auto.cpp -std=c++14 -o auto
decltype: decltype.cpp
	clang++ decltype.cpp -std=c++14 -o decltype
returnauto: returnauto.cpp
	clang++ returnauto.cpp -std=c++14 -o returnauto
if_constexpr: if_constexpr.cpp
	clang++ if_constexpr.cpp -std=c++14 -o if_constexpr
range_loop: range_loop.cpp
	clang++ range_loop.cpp -std=c++14 -o range_loop
typedef_using: typedef_using.cpp
	clang++ typedef_using.cpp -std=c++14 -o typedef_using
variadic_template: variadic_template.cpp
	clang++ variadic_template.cpp -std=c++14 -o variadic_template
variadic_recursive_template: variadic_recursive_template.cpp
	clang++ variadic_recursive_template.cpp -std=c++14 -o variadic_recursive_template

