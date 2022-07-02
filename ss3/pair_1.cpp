#include<iostream>
#include<vector>

// 項数Nの数列 a_iから何個かを選んで和がWになるか否かを判定
// ビット演算を用いる 

using std::cout;
using std::endl;
using std::cin ;
using std::vector ;

int main(){

    int N,W;
    cin >> N >> W;
    vector<int> a(N);
    bool exist = false;

    for(int i = 0; i < N ; i++) cin >> a[i];

    // bit: 0 ~ 2^N - 1
    for(int bit = 0; bit < (1 << N); ++bit){

	int sum = 0;
	// i: 0 ~ N
	for(int i= 0; i < N;i++){

	    if(bit & (1 << i)) sum += a[i];
	    if(sum == W) exist = true;
	}
    }
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}


