#include <iostream>
#include <vector>
#include <string>

template<class T>
void chmin(T& a, T b) {
    if(a > b) {
       a = b; 
    }
}

const int INF = 1 << 29;

int main(void) {
    // 入力
    std::string S,T; 
    std::cin >> S >> T;
    // dp table
    std::vector<std::vector<int>> dp(S.size() + 1, std::vector<int>(T.size() + 1, INF)); 
    // 初期条件
    dp[0][0] = 0; 
    // dp loop
    for(int i = 0; i <= S.size(); ++i){
        for(int j = 0; j<= T.size(); ++j){
            // 変更操作
            if(i > 0 && j > 0) {
                if(S[i - 1] == T[j - 1]) {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            // 削除操作(Sのi文字を削除)
            if(i > 0) chmin(dp[i][j], dp[i - 1][j] + 1); 
            // 挿入操作(Tのj文字を削除)
            if(j > 0) chmin(dp[i][j], dp[i][j - 1] + 1); 
        }
    } 
    // 結果を出力
    std::cout << dp[S.size()][T.size()] << std::endl; 
}
