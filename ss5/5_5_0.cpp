#include<iostream>
#include<vector>

// メモ化再帰

template<typename T>
void chmin(T& a, const T b)
{
    if(a > b){
	a = b;
    }
}

const long long INF = 1LL<<60;

std::size_t N;
std::vector<long long> h;
std::vector<long long> dp;

long long rec(int i)
{
    if(dp[i] < INF) return dp[i];
    // base case
    if(i == 0) return 0;
    // 答えをINFで初期化
    long long res = INF;
    // i-1 -> i
    chmin(res, rec(i-1) + std::abs(h[i] - h[i-1]));
    // i-1 -> i
    if(i > 1)chmin(res, rec(i-2) + std::abs(h[i] - h[i-2]));
    return dp[i] = res;
}

int main(void)
{
    std::cin >> N;
    // hのサイズをNに変更
    h.resize(N);
    for(int i=0; i < N; ++i) std::cin >> h[i];
    // dp tableをINFで初期化
    dp.assign(N,INF);

    // 結果 
    std::cout << rec(N -1) << std::endl;
}
