#include <iostream>
#include <vector>

// 各a[i]を2で割れる回数をカウントしてその最小値を求める

int how_many_times(int N) {
    int exp = 0;
    while(N % 2 == 0) N /= 2, ++exp;
    return exp;
}

constexpr int INF = 1<<30;

int main(void) {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for(int i = 0; i < N; ++i) std::cin >> a[i];

    // 2で何回割るかの最小値を求める
    int result = INF;
    for(auto i: a) {
        result = std::min(result, how_many_times(i));
    }

    std::cout << result << std::endl;
}
