#include <iostream>
#include <vector>
// 頂点s,tに対してpath, s-tが存在するか

// グラフ
using Graph = std::vector<std::vector<int>>;

std::vector<int> seen;
void dfs(const Graph& G, int v) {
    seen[v] = true; // vを訪問済みにする
    // vからいける各頂点v_nextについて
    for(auto next_v : G[v]) {
        if(seen[next_v]) continue;
        dfs(G, next_v); // 再帰的に探索
    } 
}

int main(void) {
    // 頂点数N, 辺の数Mと調べる頂点s,t
    int N, M, s, t; 
    std::cin >> N >> M >> s >> t; 
    // グラフの入力受取
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
    }
    // 頂点sをスタートした探索
    seen.assign(N,false);
    dfs(G, s);
    // tに辿り着けるかどうか
    if(seen[t]) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl; 
}
