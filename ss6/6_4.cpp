#include<iostream>
#include<vector>
#include<algorithm> 

const int INF = 2000000;
int main(){
    int N,K;
    std::cin >> N >> K;
    std::vector<int> a(N),b(N);
    for(int i=0; i < N; i++) std::cin >> a[i];
    for(int i=0; i < N; i++) std::cin >> b[i];
    int min_value = INF;
    std::sort(b.begin(), b.end());

    for(int i=0; i < N; i++){
        // _b >= K - a[i]( _b + a[i] >= K) を満たす最小の添字i探す
        // a[i] + _b >= Kとなる_bをa[i]ごとにさがしておく(O(longN))   
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);
        int val = *iter;

        if(a[i] + val < min_value ){
            min_value = a[i] + val;
        }
    }

    std::cout << min_value << std::endl;
}
