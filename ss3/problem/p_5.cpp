#include <iostream>
#include <vector>

int step(std::vector<int>& a) {
    int num_step = 0;
    for(;;){
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] % 2 == 0){
                a[i] /= 2;
            }else{
                return num_step;
            } 
        } 
        ++num_step;
    }
}

int main(void) {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for(int i = 0; i < N; ++i) std::cin >> a[i];

    int num_step = 0;
    num_step = step(a);

    std::cout << num_step << std::endl;
}
