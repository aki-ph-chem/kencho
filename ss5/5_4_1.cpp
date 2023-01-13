#include<iostream>
#include<vector>
// 単純な再帰で解く
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

long long rec(int i,const std::vector<long long>& h)
{
    // 足場0のコストは0
    if(i == 0) return 0;

    // 答えを格納する定数をINFで初期化
    long long res = INF;

    // i-1 -> i
    chmin(res, rec(i - 1,h) + std::abs(h[i] - h[i - 1]));
    // i-2 -> i
    if(i > 1)chmin(res, rec(i - 2,h) + std::abs(h[i] - h[i - 2]));

    return res;
}

int main(void)
{
    int N;
    std::cin >> N;
    // costの配列
    std::vector<long long> h(N);
    for(std::size_t i=0; i < N; ++i) std::cin >> h[i];

    std:: cout << rec(N - 1,h) << std::endl;
}
