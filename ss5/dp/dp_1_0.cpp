#include <iostream>
#include <vector>

// 全探索 (O(2^N))
// i番目以降の品物で、重さの総和がu以下となるように選ぶ
int search(std::vector<int>& v, std::vector<int>& w,int i, int u){
    int n = v.size();
    if(i == n){ // もう品物は残っていない
        return 0;
    }else if(u < w[i]){ // この品物は入らない
        return search(v, w, i + 1, u);
    }else{ // 入れない場合と入れる場合の両方を試す
        int res_1 = search(v, w, i + 1, u);
        int res_2 = search(v, w, i + 1, u - w[i]) + v[i];
        return std::max(res_1, res_2);
    }
}

int main(void){
    std::vector<int> v = {2,1,3,2};
    std::vector<int> w = {3,2,4,2};
    std::cout << search(v,w,0,10) << std::endl;
}
