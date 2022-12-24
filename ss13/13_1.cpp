#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

// 再帰関数を用いる深さ優先探索
std::vector<bool> seen;
void dfs(const Graph& G, int v){
    seen[v] = true;
    // vから行ける各頂点について
    for(auto next_v: G[v]){
        if(seen[next_v]) continue; // next_vが探索済みならば探索しない
        dfs(G,next_v); // 再帰的に探索
    }
}

int main(void) {
    // 頂点数N,辺の数M
    int N,M;
    // グラフの入力受取
    std::cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; ++i){
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
    }
    // 探索
    seen.assign(N,false); 
    for(int v = 0; v < N; ++v) {
        if(seen[v]) continue;
        dfs(G,v);
    }
}
