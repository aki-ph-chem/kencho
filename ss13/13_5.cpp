#include <iostream>
#include <vector>
#include <algorithm>

using Graph = std::vector<std::vector<int>>;

// トポロジカルソート

std::vector<int> seen;
std::vector<int> order;

void rec(const Graph& G, int v) {
    seen[v] = true;
    for(auto next_v : G[v]) {
        if(seen[next_v]) continue;
        rec(G, next_v);
    }
    // v-outを記録する
    order.push_back(v);
}

int main(void) {
    // グラフの入力
    int N,M;
    std::cin >> N >> M; 
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
    }
    // 探索
    seen.assign(N, false); // 初期では全頂点が未訪問
    order.clear(); // トポロジカルソート順
    for(int v = 0; v < N; ++v) {
        if(seen[v]) continue;
        rec(G, v);
    }
    // 逆順に
    std::reverse(order.begin(), order.end());
    // 出力
    for(auto v : order) std::cout << v << " -> "; 
    std::cout << std::endl;
}
