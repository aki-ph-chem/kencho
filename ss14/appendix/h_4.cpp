#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <string>

struct Permission {
    int read;
    int write;
    int exec;

    Permission(int read, int write, int exec)
        : read(read), write(write), exec(exec) 
    {}

    // greater
    bool operator > (const Permission& other) const {
        return read < other.read;
    }

    // less
    bool operator < (const Permission& other) const {
        return read > other.read;
    }
};

// greaterに変更
using QG = std::priority_queue<
    Permission,
    std::vector<Permission>,
    std::greater<Permission>>;

int main(void) {
    auto array = std::array<long long,6>{1, 2, 3, 4, 5, 6}; 
    QG qg_0;

    for(std::size_t i = 0; i < array.size(); ++i){
        qg_0.push(Permission(array[i], 2 *(-array[i]), 2 * array[i] + 1));
    }

    std::cout << "std::greater" << "\n";
    while(!qg_0.empty()) {
        auto v = qg_0.top();
        std::cout << "v: read = " << v.read << " v: write = " << v.write;
        std::cout << " v: exec = " << v.exec << std::endl;
        qg_0.pop();
    }
}
