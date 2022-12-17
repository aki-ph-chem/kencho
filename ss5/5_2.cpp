#include<iostream>
#include<vector>

// 緩和を意識した動的計画法

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
    for(long long i = 0; i < N; ++i) std::cin >> h[i];
    // dp table
    std::vector<long long> dp(N,INF);

    dp[0] = 0;
    /*

     i - 1 -> iとi-2 -> i を比較する

     */
    for(int i = 1; i < N; ++i)
    {
	chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
	if(i > 1)
	{
	    chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
	}
    }

    std::cout << dp[N - 1] << std::endl;
}
