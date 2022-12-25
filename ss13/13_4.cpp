#include <iostream>
#include <vector>
// graph
using Graph = std::vector<std::vector<int>>;

// 二部グラフ判定問題
std::vector<int> color;
bool dfs(const Graph& G, int v, int cur = 0) {
    color[v] = cur; 
    for(auto next_v: G[v]) {
        // 隣接頂点が全て色確定していた場合
        if(color[next_v] != -1) {
            // 同じ色が隣接した場合は二部グラフでない
            if(color[next_v] == cur) return false;
            // 色が確定した場合には探索しない
            continue;
        }
        // 隣接頂点の色を変えて再帰的に探索
        // falseが返ってきたらfalseを返す
        if(!dfs(G, next_v, 1 - cur)) return false; 
    }
    return true;
}

int main(void) {
    // 頂点数と辺数
    int N, M;    
    std::cin >> N >> M; 
    // グラフの受取
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 探索
    color.assign(N, -1);
    bool is_bi = true;
    for(int v = 0; v < N; ++v) {
        if(color[v] != -1) continue; // vが探索済みなら探索しない
        if(!dfs(G, v)) is_bi = false;
    }

    if(is_bi) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}
