template <typename T, int BufSize>
class buffer_t {
public:
    T& alloc();
    void free(T& item);
private:
    T data[BufSize];
};

int main() {
buffer_t<int, 100> buf; // 100 as template parameter
}
