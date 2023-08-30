#include<iostream>
#include<vector>

void I_Sort(std::vector<int> &a){
    int N = (int)a.size();
    for(int i = 1; i < N ;i++){
        // 挿入する値v
        int v = a[i];
        // vを挿入する場所j
        int j = i;
        for(; j > 0; --j){
            if( a[j-1] > v){
                a[j] = a[j-1];
            }
            else break;
        }
        a[j] = v;
    }
}

int main(){
    int N;
    std::cin >> N;
    std::vector<int> a(N);

    for(int i = 0; i < N ;i++) std::cin >> a[i];

    I_Sort(a);
    for(int k = 0; k < N ; k++){
        std::cout << a[k] ;
    }

    std::cout << std::endl;
}
