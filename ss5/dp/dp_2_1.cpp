#include <iostream>
#include <vector>

// 方法1 :メモ化再帰
// 既に計算したケースを配列に保存する
// 探索
int search(std::vector<int>& v, std::vector<int>& w, std::vector<std::vector<int>>& memo,int i, int u){
    int n = v.size();
    // 既に計算していたら配列から取り出してreturn
    if(memo[i][u])return memo[i][u];
    if(i == n){ // もう品物は残っていない
        return 0;
    }else if(u < w[i]){ // この品物は入らない
        return memo[i][u] = search(v, w,memo, i + 1, u);
    }else{ // 入れない場合と入れる場合の両方を試す
        int res_1 = search(v, w, memo, i + 1, u);
        int res_2 = search(v, w, memo, i + 1, u - w[i]) + v[i];
        return memo[i][u] = std::max(res_1, res_2);
    }
}

int main(void){
    const int N = 11;
    const int U = 11;
    std::vector<std::vector<int>> memo(N,std::vector<int>(U,0)); 
    std::vector<int> v = {2,1,3,2};
    std::vector<int> w = {3,2,4,2};
    std::cout << search(v,w,memo,0,10) << std::endl;
}
