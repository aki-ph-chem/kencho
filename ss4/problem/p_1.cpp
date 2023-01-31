#include <iostream>

// トリボナッチ数列
long long tri(long long n) {
    if(n == 0) {
        return 0;
    }else if(n == 1) {
        return 0;
    }else if(n == 2) {
        return 1;
    }else {
        return tri(n - 1) + tri(n - 2) + tri(n - 3);
    } 
}

int main(void) {
    for(long long i = 0; i < 10; ++i) {
        std::cout << "tri(" << i << ") = " << tri(i) << std::endl; 
    }
}
