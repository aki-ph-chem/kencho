#include<iostream>
#include<vector>

void fibo(const std::size_t N, std::vector<long long>& vec){
    vec.at(0) = 0, vec.at(1) = 1;
    for(std::size_t i = 2; i < N + 1; ++i){
	vec.at(i) = vec.at(i - 1) + vec.at(i - 2);
    }
}

std::vector<long long> res(50);

int main(void){
    fibo(6,res);
    std::cout << "i =  "<< 6 <<": " << res.at(6) << std::endl; 

}
