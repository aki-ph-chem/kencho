#include<iostream>
#include<vector>

bool p(int index,int key,const std::vector<int>& array){
    if(array[index] >= key) return true;
    else return false;
}

// 一般化された二分探索
int binary_search(int key,std::vector<int>& array){
    int left = 0,right = array.size();

    while(right - left > 1){
	int mid = left + (right - left)/2; 
	if(p(mid,key,array)) right = mid;
	else left = mid;
    }
    return right;
}

int main(void){
    std::vector<int> a = {1,3,4,20, 22,23,30,40}; 

    std::cout << p(3,30,a) << std::endl;
    std::cout << p(1,30,a) << std::endl;
    std::cout << p(4,4,a) << std::endl;

    std::cout << binary_search(20,a) << std::endl;
    std::cout << binary_search(30,a) << std::endl;
    std::cout << binary_search(22,a) << std::endl;
    std::cout << binary_search(23,a) << std::endl;

    return 0;
}
