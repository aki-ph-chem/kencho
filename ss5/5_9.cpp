#include <iostream>
#include <vector>

// 区間分割問題

const long long INF = 1LL << 60;

template<class T>
void chmin(T& a, T b) {
    if(a > b){
        a = b;
    }
}

int main(void) {
    // データの受取
    int N;
    std::cin >> N;
    std::vector<std::vector<long long>> c(N + 1, std::vector<long long>(N+1));
    for(int i = 0; i < N + 1; ++i) {
        for(int j = 0; j < N + 1; ++j) {
            std::cin >> c[i][j];
        }
    }

    // dp table
    std::vector<long long> dp(N + 1, INF);
    dp[0] = 0;

    // dp loop
    for(int i = 0; i <=N; ++i) {
        // j < i
        for(int j = 0; j < i; ++j) {
            // [0,i)に[j,i)を追加
            chmin(dp[i], dp[j] + c[j][i]);
        }
    } 
    std::cout << dp[N]<< std::endl;
}
