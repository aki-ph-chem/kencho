#include <iostream>
#include <vector>

// UnionFindの応用: グラフの連結成分の個数を求める

struct UnionFind {
    std::vector<int> par, siz;

    // コンストラクタ
    UnionFind(int n): par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x) {
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]); }

    // xとyが同じグループに属するかの判定
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループの併合
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) std::swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};

int main(void){
    // N: グラフの頂点数、M; グラフの辺の数
    int N,M;
    std::cin >> N >> M; 

    // UnionFindを要素数Nで初期化
    UnionFind uf(N);

    // 各辺に対する処理
    for(int x = 0; x < M; ++x) {
        int a,b;
        std::cin >> a >> b;
        uf.unite(a, b);
    }

    // 集計
    int res = 0;
    for(int x = 0; x < N; ++x) {
        if(uf.root(x) == x) ++res;
    }
    std::cout << res << std::endl;
}
