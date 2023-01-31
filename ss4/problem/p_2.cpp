#include <iostream>
#include <vector>

// メモ化したトリボナッチ数列

long long tri(long long n, std::vector<long long>& v){
    if(n == 0) {
        return 0;
    }else if(n == 1) {
        return 0;
    }else if(n == 2) {
        return 1;
    }

    if(v[n] != -1) {
        return v[n];
    }else {
        return v[n] = tri(n - 1, v) + tri(n - 2, v) + tri(n - 3, v);
    } 
}


int main(void) {
    int N;
    std::cin >> N;
    std::vector<long long> v(N,-1);
    for(long long i = 0; i < N; ++i) {
        std::cout << "tri(" << i << ") = " << tri(i ,v) << std::endl;
    }
} 
