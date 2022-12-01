#include<iostream>

int fibo(int N)
{
    if(N == 0) return 0;
    else if(N == 1) return 1;
    return  fibo(N - 1) + fibo(N - 2);
}

int main(void)
{
    std::cout << "fibo(6) = " << fibo(6)<< std::endl;
}
