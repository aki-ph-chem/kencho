#include<iostream>
#include<vector>

// 配る形式で書く動的計画法

template <typename T>
void chmin(T& a, const T b)
{
    if(a > b)
    {
	a = b;
    }
}

// 十分に大きな数
const long long INF = 1LL<<60;

int main(void)
{
    int N;
    std::cin >> N;
    // costの配列
    std::vector<long long> h(N);
    for(int i=0; i < N; ++i) std::cin >> h[i];

    // dp table
    std::vector<long long> dp(N,INF);

    dp[0] = 0;
    /*

     i -> i+1とi -> i+2 を比較する

     */
    for(int i = 0; i < N; ++i)
    {
	// i+1がNを飛び越えないようにする
	if( i + 1 < N )
	{
	    chmin(dp[i + 1]
		    ,dp[i] + std::abs(h[i] - h[i + 1]));
	}
	// i+2がNを飛び越えないようにする
	if(i + 2 < N)
	{
	    chmin(dp[i + 2]
		    ,dp[i] + std::abs(h[i] - h[i + 2]));
	}
    }

    std::cout << dp[N-1] << std::endl;
}
