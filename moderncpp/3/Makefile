
all: lambda function_type bind_placeholder rvalue_reference move

clean:
	rm lambda function_type bind_placeholder rvalue_reference move
lambda: lambda.cpp
	clang++ lambda.cpp -std=c++14 -o lambda
function_type: function_type.cpp
	clang++ function_type.cpp -std=c++14 -o function_type
bind_placeholder: bind_placeholder.cpp
	clang++ bind_placeholder.cpp -std=c++14 -o bind_placeholder
rvalue_reference: rvalue_reference.cpp
	clang++ rvalue_reference.cpp -std=c++14 -o rvalue_reference
move: move.cpp
	clang++ move.cpp -std=c++14 -o move
