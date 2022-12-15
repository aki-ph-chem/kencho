#include <iostream>
#define SIZE 1024

// フィボナッチ数列asメモ探索
long long memo_for_fib[SIZE]; 
long long fib_memo(long long n){
    if(n == 1)return 1;
    if(n == 2)return 1;

    if(memo_for_fib[n])return memo_for_fib[n];
    else{
        return memo_for_fib[n] = fib_memo(n - 1) + fib_memo(n - 2);
    }
}

// フィボナッチ数列as動的計画 
long long fib_as_dp[SIZE]; 
long long fib_dp(long long n){
    fib_as_dp[1] = 1;
    fib_as_dp[2] = 1;
    for(long long i = 3; i <= n; ++i){
        fib_as_dp[i] = fib_as_dp[i - 1] + fib_as_dp[i - 2];
    }
    return fib_as_dp[n]; 
}

int main(void){
    const long long n = 10;
    for(long long i = 0; i < SIZE; ++i){
        memo_for_fib[i] = 0;
    }
    for(long long i = 1; i < n; ++i){
        std::cout << fib_memo(i) <<" ";
    }
    std::cout << "\n";

    // dpテーブルの初期化
    for(long long i = 0; i < SIZE; ++i){
        fib_as_dp[i] = 0;
    }
    for(long long i = 1; i < n; ++i){
        std::cout << fib_dp(i) <<" ";
    }
}
