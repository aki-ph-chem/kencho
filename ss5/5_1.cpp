#include<iostream>
#include<vector>

// 動的計画法
// 十分に大きな数値
const long long INF = 1LL<< 60;
int main(void)
{
    int N;
    std::cin >> N;
    // costの配列
    std::vector<long long> h(N);
    for(std::size_t i = 0; i < N; ++i) std::cin >> h[i];
    // dpをINFで初期化
    std::vector<long long> dp(N,INF);
    dp[0] = 0;
    for(std::size_t i = 1; i < N; ++i){
	if(i == 1) dp[i] = std::abs(h[i] - h[i - 1]);
	else dp[i] = std::min(
	      dp[i - 1] + abs(h[i] - h[i - 1])
	    , dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    std::cout << dp[N - 1] << std::endl;
}
