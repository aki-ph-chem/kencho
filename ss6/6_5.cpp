#include <iostream>
#include <vector>
#include <algorithm>

// アルゴリズムをいまいち理解していない

const long long  INF = 1LL<<60;

int main(void){
    // 入力
    int N;
    std::cin >> N;
    std::vector<long long> h(N), s(N);
    for(int i = 0; i < N; ++i)std::cin >> h[i] >> s[i];
    // 二分探索
    long long left = 0, right = INF;
    while(right - left > 1){
        long long mid = (left + right)/2; 
        // 判定
        bool ok = true;
        std::vector<long long> t(N,0); // 各風船を割るまでの時間制限
        for(int i = 0; i < N; ++i){
            // midが初期高度より低かったらfalse
            if(mid < h[i]) ok = false; 
            else t[i] = (mid - h[i]) / s[i];
        }
        // 時間制限が差し迫っている順にsort
        std::sort(t.begin(), t.end());
        for(int i = 0; i < N; ++i){
            if(t[i] < i) ok = false; // 時間切れ発生
        }

        if(ok) right = mid; 
        else left = mid;
    }
    std::cout << right << std::endl;
}
