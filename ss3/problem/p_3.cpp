#include <iostream>
#include <vector>

constexpr int INF = 1 << 30;

int main(void) {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for(int i = 0; i < N; ++i) std::cin >> a[i];

    int min = INF;
    int min_2 = INF;
    for(int i = 0; i < N; ++i) {
        if(a[i] < min) {
            min_2 = min; 
            min = a[i];
        }else if(a[i] < min_2){
            min_2 = a[i];
        }
        // 最小値、二番目に小さい値の更新される様子
        //std::cout << min << " " << min_2 << std::endl;
    }

    std::cout << min_2 << std::endl;
}
