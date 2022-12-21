#include <iostream>

// 各頂点x(値がx)の親をpar[x]とする。

// 経路圧縮を行わない場合の根の取得(O(\alpha(N)))
int root_0(int x){
    if (par[x] == -1) return x; // xが根ならばpar[x] = -1としている
    else return root(par[x]);
}

// 経路圧縮の工夫ありの場合の根取得
int root_1(int x){
    if(par[x] == -1) return x;
    else return par[x] = root(par[x]);
}
