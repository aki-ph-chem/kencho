#include <iostream>
#include <vector>

int main(void) {
    int N;
    std::cin >> N;

    int v;
    std::cin >> v;

    std::vector<int> a(N);
    for(int i = 0; i < N; ++i) std::cin >> a[i];

    int num_v = 0;
    for(int i = 0; i < N; ++i) {
        if(a[i] == v) {
            ++num_v;
        }
    }

    std::cout << num_v << std::endl;
}
