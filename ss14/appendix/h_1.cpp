#include <iostream>
#include <vector>
#include <queue>

// std::priority_queueの簡単な例

int main(void) {
    int a[] = {1,3,4,5,7}; 
    std::priority_queue<int> q;
    for(size_t i = 0; i < sizeof(a)/sizeof(int); ++i) {
        q.push(a[i]);
    }

    while(!q.empty()) {
        std::cout <<"q = " << q.top() << "\n";
        q.pop();
    }
}

