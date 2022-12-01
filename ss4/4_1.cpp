#include<iostream>

int sum(int N){
    if(N == 0) return 0;
    return N + sum(N - 1);
}

int main(void)
{
    std::cout <<"sum(2) = "<<sum(2)<<std::endl;
    std::cout <<"sum(10) = "<<sum(10)<<std::endl;
}
