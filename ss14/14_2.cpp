#include <iostream>
#include <vector>
// ダイクストラ: 単純な実装

const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w): to(to), w(w) {}
};

using Graph = std::vector<std::vector<Edge>>;

template<class T>
bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main(void) {
    // N: 頂点, M: 変数, s: 始点
    int N, M, s;
    std::cin >> N >> M >> s; 
    // グラフ
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w; 
        G[a].push_back(Edge(b, w));
    }
    // ダイクストラ
    std::vector<bool> used(N, false);
    std::vector<long long> dist(N,INF);
    dist[s] = 0;
    for(int iter = 0; iter < N; ++iter) {
        // 使用済みでない頂点のうちdist値が最小の頂点を探索する
        long long min_dist = INF;
        int min_v = -1;
        for(int v = 0; v < N; ++v) {
            if(!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        // もし見つからなかったら終了
        if(min_v == -1)  break;
        // min_vを始点とした各辺の緩和を行う
        for(auto e: G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        } 
        // min_vを使用済みとする
        used[min_v] = true;
    }
    // 出力
    for(int v = 0; v < N; ++v) {
        if(dist[v] < INF) std::cout << dist[v] << std::endl;
        else std::cout << "INF" << std::endl;
    }
}
