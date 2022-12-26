#include <iostream>
#include <vector>
using Graph = std::vector<std::vector<int>>;

// 根なし木の根を決めてどうなるかみる(木はサイクルがないのでdfsが少し簡単になる(seenがいらない))

// 木の上での探索の基本形

// v:現在探索中の頂点、p: vの親 (vが根のときはp = -1) 
void dfs_0(const Graph& G, int v, int p = -1) {
    for(auto c : G[v]) {
        if(c == p) continue; // 探索が逆流するのを防ぐ
        // cはvの各頂点を動く
        dfs_0(G, c, v);
    }
}

// 根なし木を根付き木にしたときの各頂点の深さを求める
// d: 頂点vの深さ、
std::vector<int> depth; // 結果を格納する配列
                        
void dfs_1(const Graph& G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for(auto c : G[v]) {
        if(c == p) continue; // 探索が親方向に逆流するのを防ぐ
        dfs_1(G, c, v, d + 1);                   
    }
}
