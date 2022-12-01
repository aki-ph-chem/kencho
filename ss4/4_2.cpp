#include<iostream>

int sum(int N){
    std::cout << "sum("<< N <<") is called"<<std::endl;
    if(N == 0) return 0;
    int result = N + sum(N - 1);
    std::cout <<"sum("<< N <<") = "<< result << std::endl;

    return result;
}

int main(void)
{
    sum(10);
}
