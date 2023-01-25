#include <iostream>
#include <vector>

constexpr int INF = 1 << 30;

int main(void) {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for(int i = 0; i < N; ++i) std::cin >> a[i];

    int min = INF;
    int max = -INF;

    for(int i = 0; i < N; ++i) {
        if(a[i] < min){
            min = a[i];
        }

        if(a[i] > max){
            max = a[i];
        }
    }

    int res = max - min;
    std::cout << res << std::endl;
}

