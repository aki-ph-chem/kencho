#include<iostream>
#include<vector>

// 項数Nの数列 a_i ,b_i からK以下な和の最小値
// 単純な二重ループで求める

using namespace std;
const int INF = 200000;

int main(){

    int N, K;
    cin >> N >> K;
    vector<int> a(N),b(N);

    for(int i=0; i < N; i++) cin >> a[i];
    for(int j=0; j < N; j++) cin >> b[j];

    int min_value = INF;
    //Linear search
    for(int i = 0; i < N; i++){
	for(int j = 0; j < N; j++){
	    // K以下ならスキップ
	    if(a[i] + b[j] < K) continue;
	    // 最小値を更新
	    if(a[i] + b[j] < min_value) min_value = a[i] + b[j];
	}
    }

    cout << min_value << endl;

    return 0;

}

    
