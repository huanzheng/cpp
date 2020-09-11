
all: thread_basic mutex atomic

clean:
	rm  thread_basic mutex atomic
thread_basic: thread_basic.cpp
	clang++ thread_basic.cpp -std=c++14 -o thread_basic
mutex: mutex.cpp
	clang++ mutex.cpp -std=c++14 -o mutex
atomic: atomic.cpp
	clang++ atomic.cpp -std=c++14 -o atomic
