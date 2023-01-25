#include <iostream>
#include <vector>

// O(N^2)

int main(void) {
    int N,K; 
    std::cin >> N >> K; 

    int num_set = 0;
    for(int x = 0; x <= K; ++x) {
        for(int y = 0; y <= K; ++y) {
            int z  = N - (x + y); 
            if(0 <= z && z <= K) {
                ++num_set;
                // 組み合わせを出力
                // std::cout << x << " " << y << " " << z << std::endl;
            } 
        }
    }

    std::cout << num_set << std::endl;
}
