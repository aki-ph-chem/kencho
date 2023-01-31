#include <iostream>
#include <vector>

// トリボナッチ数列をdp的に

long long tri(long long n, std::vector<long long>& v) {
    v[0] = 0, v[1] = 0, v[2] = 1;
    if(n > 2){
        for(long long i = 3; i <= n; ++i) {
            v[i] = v[i - 1] + v[i - 2] + v[i - 3]; 
        }
    }
    return v[n];
}

int main(void) {
    int N;
    std::cin >> N;
    std::vector<long long> v(N);
    for(long long i = 0; i < N; ++i) {
        std::cout << "tri(" << i << ") = " << tri(i ,v) << std::endl;
    }
}
