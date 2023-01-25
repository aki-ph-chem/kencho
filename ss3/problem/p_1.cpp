#include <iostream>
#include <vector>

int main(void) {
    int N;
    std::cin >> N;

    int v;
    std::cin >> v;

    std::vector<int> a(N);
    for(int i = 0; i < N; ++i) std::cin >> a[i];
    

    int found_id = -1;
    for(int i = 0; i < N; ++i) {
        if(a[i] == v) {
            found_id = i;
        }
    }

    std::cout << found_id << std::endl;
}
