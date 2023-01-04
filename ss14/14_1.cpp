#include <iostream>
#include <vector>

// ベルマン・フォード法

// 無限大を表す値 
const long long INF = 1LL << 60; 
// 辺を表す型
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w): to(to), w(w) {}
};
// グラフ
using Graph = std::vector<std::vector<Edge>>;
// 緩和を実施する関数
template<class T> bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main(void){
    // 頂点数、辺数、始点
    int N, M, s;
    std::cin >> N >> M >> s;
    // グラフの受取
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    // ベルマン・フォード法
    bool exist_negative_cycle = false; // 負経路があるかどうか
    std::vector<long long> dist(N, INF);
    dist[s] = 0;
    for(int iter = 0; iter < N; ++iter) {
        bool update = false; // 更新が発生するかを表すフラグ
        for(int v = 0; v < N; ++v) {
            // dist[v] == INFのときは頂点vからの緩和を行わない
            if(dist[v] == INF) continue;
            for(auto e: G[v]) {
                // 緩和処理を行い、更新されたらupdateをtrueにする
                if(chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }
        // 更新が行われなかったら既に最短路が求められている
        if(!update) break;
        // N回目の反復で更新が行われたならば、負閉路を持つ
        if(iter == N - 1 && update) exist_negative_cycle = true;
    }

    // 結果を出力
    if(exist_negative_cycle) std::cout << "NEGATIVE CYCLE" << std::endl; 
    else {
        for(int v = 0; v < N; ++v) {
            if(dist[v] < INF) std::cout << dist[v] << std::endl;
            else std::cout << "INF" << std::endl;
        }
    }
}
