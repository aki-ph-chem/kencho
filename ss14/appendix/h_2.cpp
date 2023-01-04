#include <iostream>
#include <vector>
#include <queue>

// std::priority_queueでヒープを実装する(1)

int main(void) {
    // ヒープ
    std::priority_queue<std::pair<long long ,int>, 
        std::vector<std::pair<long long, int>>, 
        // デフォルトではstd::less
        std::greater<std::pair<long long, int>>> q;
    // 値を挿入 
    std::vector<long long> a = {1, 2, 3, 4}; 
    for(int i = 0; i < a.size(); ++i){
        q.push(std::make_pair(a[i], i));
    }
}
