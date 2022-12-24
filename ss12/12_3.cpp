#include<iostream>
#include<vector>

// ヒープソート

// ヒープの構築
// i番目の頂点を根とする部分木についてヒープの条件を満たすようにする。
// aのうち0番目からN-1番目までの部分a[0:N]について考える 
void Heapify(std::vector<int> &a,int i,int N){
    int child1 = i*2 + 1; // 左の子
    // 子がいないときは終了
    if(child1 >= N) return; 
    // 左の子と右の子を比較して右の方が大きければ ++child1 
    if(child1 + 1 < N && a[child1+1] > a[child1]) child1++;
    // 逆転がなければ終了
    if(a[child1] <= a[i]) return;
    std::swap(a[i],a[child1]);
    // 再帰的に構築
    Heapify(a,child1,N);
}

void H_sort(std::vector<int> &a) {
    int N = (int)a.size();
    // まずa全体をヒープにする
    for(int i = N/2 -1; i >= 0; --i){
	Heapify(a,i,N);
    }
    // ヒープから最大値をpopして、配列に後ろから挿入し、崩れたヒープを再構築する
    for(int i = N-1; i > 0; --i) {
        std::swap(a[0],a[i]);
	Heapify(a,0,i);
    }
}

int main(void){
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for(int i = 0; i < N; i++) std::cin >> a[i];
    H_sort(a);

    for(int i = 0; i< N; i++){
        std::cout << a[i] <<",";
    }
    std::cout << std::endl;
}
