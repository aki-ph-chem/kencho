#include<iostream>
#include<vector>
// メモ化再帰で解く
// cost配列hをreferenceで受け取る

// 十分に大きな数
const long long INF = 1LL<<60;

template <typename T>
void chmin(T& a, const T b)
{
    if(a > b)
    {
	a = b;
    }
}

long long rec(std::size_t i,const std::vector<long long>& h
	,std::vector<long long>& dp)
{
    if(dp[i] < INF) return dp[i];
    // base case 
    if(i == 0) return 0;
    // 答えをINFで初期化
    long long res = INF;
    // i-1 -> i
    chmin(res, rec(i - 1, h, dp) + std::abs(h[i] - h[i - 1]));
    // i-2 -> i
    if(i > 1)chmin(res, rec(i - 2, h, dp) + std::abs(h[i] - h[i - 2]));

    return dp[i] = res;
}

int main(void)
{
    int N;
    std::cin >> N;

    // dp table
    std::vector<long long> dp(N, INF);

    // costの配列
    std::vector<long long> h(N);
    for(int i=0; i < N; ++i) std::cin >> h[i];

    std:: cout << rec(N - 1, h, dp) << std::endl;
}
