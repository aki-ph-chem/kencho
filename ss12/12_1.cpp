#include <iostream>
#include <vector>

// マージソート

void M_sort(std::vector<int> &a, int left, int right) {
    if(right - left == 1) return;
    // 中点を計算
    int mid = left + (right - left)/2;
    // 再帰的に左側、右側をsort
    M_sort(a, left, mid);
    M_sort(a, mid, right);
    // 配列にコピー 
    std::vector<int> buf;
    for(int i = left; i < mid; i++) buf.push_back(a[i]);
    for(int i = right -1; i >= mid; i--) buf.push_back(a[i]);
    // 併合
    int index_left = 0;
    int index_right = (int)buf.size() -1;
    for(int i = left; i < right; i++){
	if(buf[index_left] <= buf[index_right]) {
	    a[i] = buf[index_left++];
	}
	else {
	    a[i] = buf[index_right--];
	}
    }
}

int main(void) {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for(int i = 0; i < N; i++) std::cin >> a[i];
    M_sort(a,0,N);
    for(int i = 0;i < N;i++){

        std::cout << a[i] << ",";
    }
    std::cout << std::endl;
}
