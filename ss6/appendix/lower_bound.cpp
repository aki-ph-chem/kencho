#include<iostream>
#include<vector>
#include<algorithm>

// std::lower_boundを使ってみる 

int main(void){
    std::vector<int> vec = {1,1,2,2,4,500,6,8,8,10,15};
    int index_lower = 0;
    // イテレータを返す: vec[i] >= 500となるiを探索する 
    auto position = std::lower_bound(vec.begin(),vec.end(),500);
    // イテレータの指す添字を得る
    index_lower   = std::distance(vec.begin(),position);
    // 結果を表示
    std::cout << "vec[" << index_lower << "] = " << *position << "\n";
}
