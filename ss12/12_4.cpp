#include<iostream>
#include<vector>
// バケットソート

const int MAX = 100000;
void B_sort(std::vector<int> &a){
    int N = (int)a.size();
    std::vector<int> num(MAX,0);
    // 各要素の個数をカウントする(度数分布) 
    for(int i = 0; i < N; i++){
	++num[a[i]];
    }
    std::vector<int> sum(MAX,0);
    // numの累積和を取る
    for(int v = 1; v < MAX; v++){
	sum[v] = sum[v-1] + num[v] ;
    }
    std::vector<int> a2(N);
    // sumを元にソート 
    for(int i = N-1; i >= 0; i--){
	a2[--sum[a[i]]] = a[i];
    }
    a = a2;
}

int main(){
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for(int i = 0; i < N; i++) std::cin >> a[i];
    B_sort(a);
    for(int i = 0; i < N; i++) std::cout << a[i];
    std::cout << std::endl; 
}
