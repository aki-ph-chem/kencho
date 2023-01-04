#include <iostream>
#include <vector>
#include <queue>

// std::priority_queueでヒープを実装する(1)

// lessのまま
using QL = std::priority_queue<std::pair<long long, int>,
      std::vector<std::pair<long long, int>>,
      std::less<std::pair<long long, int>>>;

// greaterに変更
using QG = std::priority_queue<std::pair<long long, int>,
      std::vector<std::pair<long long, int>>,
      std::greater<std::pair<long long, int>>>;

int main(void) {
    std::vector<long long> array = {1, 2, 3, 4,5,6}; 
    QL ql_0;
    QG qg_0;

    for(int i = 0; i < array.size(); ++i){
        ql_0.push(std::make_pair(array[i], i));
        qg_0.push(std::make_pair(array[i], i));
    }

    std::cout << "ql_0" << "\n";
    while(!ql_0.empty()) {
        std::cout <<"ql_0 = " << ql_0.top().second << "\n";
        ql_0.pop();
    }

    std::cout << "qg_0" << "\n";
    while(!qg_0.empty()) {
        std::cout <<"qg_0 = " << qg_0.top().second << "\n";
        qg_0.pop();
    }
}
