#include <iostream>
#include <vector>
// ワーシャル・フロイド法

const long long INF = 1LL << 60;

int main(void) {
    // N: 頂点数, M: 辺数
    int N, M;
    std::cin >> N >> M; 
    // dp配列
    std::vector<std::vector<long long>> dp(N, std::vector<long long>(N, INF));
    // dpの初期化
    for(int e = 0; e < M; ++e) {
        int a, b;
        long long w;
        std::cin >> a >> b >> w;
        dp[a][b] = w;
    }
    for(int v = 0; v < N; ++v) dp[v][v] = 0;
    // ワーシャル・フロイド法 dp遷移
    for(int k = 0; k < N; ++k) 
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
    // 結果の出力
    // dp[v][v] < 0なら負閉路が存在する
    bool exist_negative_cycle = false;
    for(int v = 0; v < N; ++v) {
        if(dp[v][v] < 0) exist_negative_cycle = true;
    }
    if(exist_negative_cycle) {
        std::cout << "negative cycle" << std::endl;
    }
    // 負閉路がない場合に結果を出力 
    else {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(j) std::cout << " ";
                if(dp[i][j] < INF/2) std::cout << dp[i][j]; 
                else std::cout << "INF";
            }
            std::cout << std::endl;
        }
    }
}
