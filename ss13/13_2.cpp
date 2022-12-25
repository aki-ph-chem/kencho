#include <iostream>
#include <vector>
#include <queue>
// 幅優先探索: 最短距離 
using Graph = std::vector<std::vector<int>>;

// 入力: グラフGと探索の始点 s
// 出力: sから各頂点への最短距離を表す配列
std::vector<int> bfs(const Graph& G, int s) {
    int N = (int)G.size(); // 頂点数
    std::vector<int> dist(N,-1); // 全頂点を未訪問に初期化
    std::queue<int> queue;
    // 初期条件(頂点0を初期頂点とする)
    dist[0] = 0;
    queue.push(0); // 全頂点を訪問予定とする
    // bfs開始 (キューが空になるまで探索を行う)
    while(!queue.empty()) {
        // キューの先頭の値を取り出す
        int v = queue.front();
        queue.pop();
        // vから辿れる頂点をすべて調べる
        for(auto x: G[v]) {
            // 既に訪問済みの頂点は探索しない
            if(dist[x] != -1) continue;
            // 新たな頂点xについて距離情報を更新してキューを更新
            dist[x] = dist[v] + 1;
            queue.push(x);
        }
    }
    return dist;
} 

int main(void) {
    // 頂点数: N 辺の数: M
    int N, M;
    std::cin >> N >> M;
    // グラフ入力: ここでは無向グラフ
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 頂点0と始点とするBFS
    std::vector<int> dist = bfs(G,0); 
    // 結果の出力
    for(int v = 0; v < N; ++v) {
        std::cout << v << " " << dist[v] << std::endl;
    }
}
