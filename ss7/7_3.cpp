#include<iostream>
#include<vector>

int main(void){

    // 入力
    int N;
    std::cin >> N;
    std::vector<long long> A(N),B(N);
    for(int i = 0; i < N; ++i) std::cin >> A[i] >> B[i];

    // 貪欲法

    long long sum = 0;
    for(int i = N -1; i >= 0; --i){
	A[i] += sum;
	long long amari = A[i] % B[i];
	long long D     = 0;
	if(amari != 0) D = B[i] - amari; 
	sum += D;
    }

    std::cout << sum << std::endl;
}
