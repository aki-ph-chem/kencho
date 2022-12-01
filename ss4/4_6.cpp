#include<iostream>


int fibo(int N){
    std::cout << "fibo(" << N << ") を呼び出しました" << std::endl;
    if( N == 0) return 0;
    else if( N == 1) return 1;
    int result = fibo(N-1) + fibo(N-2) ;
    std::cout << N << "項目 = " << result << std::endl;

    return result;
}

int main(void){

    fibo(6);
}




