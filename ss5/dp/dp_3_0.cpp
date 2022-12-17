#include <iostream>
#define MAX_N 100
#define MAX_U 100
#define N 4
//　方法2: 漸化式とループ

// 埋めていいる表
int dp[MAX_N + 1][MAX_U + 1];
// 対象の配列
int v[N] = {2, 1, 3, 2};
int w[N] = {3, 2, 4, 2};
// 探索
int do_dp(int U){
    for(int u = 0; u <= U; ++u)dp[N][u] = 0; // 境界条件
                                             
    for(int i = N - 1; i >= 0; --i){
        for(int u = 0; u <= U; ++u){
            if(u < w[i]){ 
                // uが小さくのでiを選ばない
                dp[i][u] = dp[i + 1][u];
            }else{
                // iを選ぶ場合と入れない場合の両方を試す
                dp[i][u] = std::max(dp[i + 1][u], dp[i + 1][u - w[i]] + v[i]);
            }
        }
    }
    return dp[0][U];
}

int main(void){
    std::cout << do_dp(10) << std::endl;
}
