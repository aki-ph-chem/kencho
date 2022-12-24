#include <iostream>
#include <vector>
#include <queue>

// グラフ
using Graph = std::vector<std::vector<int>> ;

// グラフGにおいて、頂点sを始点とした探索
void search(const Graph& G, int s){
    int N = (int)G.size();
    // グラフ探索のためのデータ構造
    std::vector<bool> seen(N,false); // 全頂点を未訪問にする
    // queueをsatckに変えると深さ優先探索になる
    std::queue<int> todo; // 空の状態
    // 初期条件                    
    seen[s] = true; // sは探索済みとする 
    todo.push(s); // todoはsのみを含む状態とする
    // todoが空になるまで探索を行う
    while(!todo.empty()){
        // todoから頂点を取り出す
        int v = todo.front();
        todo.pop();
        // vから辿れる頂点を全て調べる
        for(auto x: G[v]){
            // 探索済みの頂点は探索しない
            if(seen[x]) continue; 
            // 新たな頂点xを探索済みとしてtodoに挿入
            seen[x] = true;
            todo.push(x);
        }
    }
}

int main(void){
}

