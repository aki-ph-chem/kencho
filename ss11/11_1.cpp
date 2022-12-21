#include <iostream>
#include <vector>

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

int main(void){
    UnionFind uf(7); // {0},{1},{2},{3},{4},{5},{6}
    uf.unite(1,2);// {0},{1,2},{3},{4},{5},{6}
    uf.unite(2,3);// {0},{1,2,3},{4},{5},{6}
    uf.unite(5,6);// {0},{1,2,3},{4},{5,6}

    std::cout << uf.issame(1,3) << std::endl;
    std::cout << uf.issame(2,5) << std::endl;

    uf.unite(1,6);// {0},{1,2,3,5,6},{4} 
    std::cout << uf.issame(2,5) << std::endl; 
}

