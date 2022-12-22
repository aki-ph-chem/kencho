#include<iostream>
#include<vector>

// クイックソート 

void Q_sort(std::vector<int> &a, int left, int right) {
    if(right - left <= 1) return;
    // 今回は中点をpivotとする
    int pivot_index = (left + right)/2;
    // pivotの値
    int pivot = a[pivot_index];
    // pivotと右端をswap
    std::swap(a[pivot_index],a[right - 1]);
    int i = left;
    // a[i] >= pivotなら++j, 
    // a[i] < pivotならa[i]とa[j]を交換して++i
    for(int j = left; j < right -1; j++) {
	if(a[j] < pivot){
            std::swap(a[i++],a[j]);
	}
    }
    // 最後にa[i]とpivotを交換
    std::swap(a[i],a[right -1]);
    // 再帰的に左半分、右半分をsort
    Q_sort(a,left,i);
    Q_sort(a,i+1,right);
}

int main(void){
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for(int i=0; i < N; i++) std::cin >> a[i];
    Q_sort(a,0,N);
    for(int i=0; i < N; i++){
        std::cout << a[i] << ",";
    }
    std::cout << std::endl;
}
