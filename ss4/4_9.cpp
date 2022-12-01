#include<iostream>
#include<vector>

// 項数Nの数列 {a_n} から何個かを足してWを作ることができるかを判定する(SS3の問題の再掲)

bool func(int i, int w, const std::vector<int> &a){
    if(i == 0){
	if( w == 0) return true;
	else return false;
    }
    // a[i]を選ばない
    if (func(i -1, w, a)) return true;
    // a[i]を選ぶ
    if (func(i -1, w - a[i-1],a)) return true;

    return false;
}

int main(){
    int N,W;
    std::cin >> N >> W;
    std::vector<int> a(N);
    for( int i = 0; i < N; i++) std::cin >> a[i];

    if(func(N, W, a)) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}

