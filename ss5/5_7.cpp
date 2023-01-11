#include<iostream>
#include<vector>

template<typename T>
void chmax(T& a,T b)
{
    if(a < b)
    {
	a = b;
    }
}

int main(void){
    int N; long long W;
    std::cin >> N >> W;
    // weight and value 
    std::vector<long long> weight(N),value(N);
    for(int i=0; i<N ; ++i) std::cin >> weight[i] >> value[i];
    // dp table
    std::vector<std::vector<long long>> dp(N+1,std::vector<long long>(W+1,0));
    // dp loop
    for(int i=0; i<N; ++i){
	for(int w = 0; w <= W; ++w){
	    if(w - weight[i] >= 0){
	        // i番目の品を選ぶ
		chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
	    } 
	    // i番目の品を選ばない
	    chmax(dp[i + 1][w], dp[i][w]);
	}
    }
    // result
    std::cout << dp[N][W] << std::endl;
}
