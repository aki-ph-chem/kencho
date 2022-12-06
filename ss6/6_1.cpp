#include<iostream>
#include<vector>

int bin_search(int key,const std::vector<int>& array){
    int left = 0, right = (int)array.size() -1;
    while(right >= left) {
	int mid = left + (right - left)/2 ;
	if(array[mid] == key) return mid;
	else if (array[mid] > key) right = mid -1;
	else if (array[mid] < key) left = mid + 1;
    }
    return -1;
}

int main(){
    const std::vector<int> a = {3,5,8,10,14,17,21,39};

    std::cout << bin_search(10,a) << std::endl;
    std::cout << bin_search(3,a)  << std::endl;
    std::cout << bin_search(39,a) << std::endl;

    std::cout << bin_search(-100,a) << std::endl;
    std::cout << bin_search(9,a)    << std::endl;
    std::cout << bin_search(100,a)  << std::endl;

    return 0;
}
