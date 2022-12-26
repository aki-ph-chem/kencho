#include <iostream>
#include <vector>

// 各頂点vを根とする部分木のサイズsubtree_size[v]を考える(動的計画法)

using Graph = std::vector<std::vector<int>>;

// 木の上での探索
std::vector<int> depth;
std::vector<int> subtree_size;

void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for(auto c : G[v]) {
        if(c == p) continue;
        dfs(G, c, v, d + 1);
    }
    // 帰りがけの時に部分木のサイズを求める
    subtree_size[v] = 1;
    for(auto c : G[v]) {
        if(c == p) continue;
        // 子頂点を根とする部分木のサイズを加算する
        subtree_size[v] += subtree_size[c];
    }
}

int main(void) {
    // 頂点数
    int N;
    std::cin >> N;
    // グラフの入力
    Graph G(N);
    for(int i = 0; i < N - 1; ++i) {
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 探索
    int root = 0;
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root);
    // 結果
    for(int v = 0; v < N; ++v) {
        std::cout << v << ": depth = " << depth[v]
            << ", subtree_size = " << subtree_size[v] << std::endl;
    } 
} 
