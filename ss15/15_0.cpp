#include <iostream>
#include <vector>
#include <algorithm>
// クラスカル法の実装: UnionFindを使う

// UnionFindの実装
struct UnionFind {
    // par: 各頂点の親頂点の番号
    // siz: 各頂点の属する根付き木の頂点数
    std::vector<int> par,siz;

    // コンストラクタ
    UnionFind(int n): par(n,-1), siz(n,1){} 

    //根を求める 
    int root(int x) {
        if(par[x] == -1)return x; // xが根ならxを返す
        else return par[x] = root(par[x]);
    }

    // xとyが同じグループの属するかどうか(つまり、根が一致するかどうか)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループを併合する
    bool unite(int x, int y) {
        // 根まで移動する
        x = root(x); y = root(y);
        // 既に同じグループならば何もしない
        if(x == y)return false;
        // union by size (y側のサイズが小さくなるようにする)
        if(siz[x] < siz[y]) std::swap(x,y);
        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

// 辺e = (u,v)を{w(e), {u, v}}で表現する
using Edge = std::pair<int, std::pair<int, int>>; 

int main(void) {
    // 頂点数: N, 辺数: M 
    int N, M;
    std::cin >> N >> M;  
    // 辺集号
    std::vector<Edge> edges(M);
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[i] = Edge(w, std::make_pair(u, v));
    }
    // 各辺を辺の重さの小さい順にソート
    std::sort(edges.begin(), edges.end());
    // クラスカル法
    long long res = 0;
    UnionFind uf(N);
    for(int i = 0; i < M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // 辺(u, v)の追加によってサイクルが形成されるときは追加しない
        if(uf.issame(u, v)) continue;
        // 辺(u, v)を追加する
        res += w;
        uf.unite(u, v);
    }
    std::cout << res << std::endl;
}
