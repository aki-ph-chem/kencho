#include<iostream>


int GCD(int m,int n){
    if( n == 0) return m;
    return GCD(n, m % n);
}

int main(void){

    std::cout << GCD(51, 15) << std::endl;
    std::cout << GCD(15, 51) << std::endl;
    std::cout << GCD(100, 50) << std::endl;
}
