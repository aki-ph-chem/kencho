#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <string>

struct Coordinate3D {
    int x;
    int y;
    int z;

    Coordinate3D(int x, int y, int z)
        : x(x), y(y), z(z) 
    {}

    // greater
    bool operator > (const Coordinate3D& other) const {
        return x < other.x;
    }

    // less
    bool operator < (const Coordinate3D& other) const {
        return x > other.x;
    }
};

// greaterに変更
using QG = std::priority_queue<
    Coordinate3D,
    std::vector<Coordinate3D>,
    std::greater<Coordinate3D>>;

int main(void) {
    auto array = std::array<long long,6>{1, 2, 3, 4, 5, 6}; 
    QG qg_0;

    for(std::size_t i = 0; i < array.size(); ++i){
        qg_0.push(Coordinate3D(array[i], 2 *(-array[i]), 2 * array[i] + 1));
    }

    std::cout << "std::greater" << "\n";
    while(!qg_0.empty()) {
        auto v = qg_0.top();
        std::cout << "v: x = " << v.x << " v: y = " << v.y;
        std::cout << " v: z = " << v.z << std::endl;
        qg_0.pop();
    }
}
