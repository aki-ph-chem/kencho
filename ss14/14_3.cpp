#include <iostream>
#include <vector>
#include <queue>
// ダイクストラ法: ヒープを用いた実装

const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w):to(to), w(w) {}
};

using Graph = std::vector<std::vector<Edge>>;

// 緩和
template<class T> bool chmin(T& a, T b) {
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
    // グラフの受取
    Graph G(N);
    for(int i = 0; i < M; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
    // ダイクストラ法
    std::vector<long long> dist(N, INF);
    dist[s] = 0;
    // (d[v], v)のペアを要素とするヒープを作る
    std::priority_queue<std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>> que;
    que.push(std::make_pair(dist[s], s));
    // ダイクストラの反復
    while(!que.empty()) {
        // v: 使用済みでない頂点のうちd[v]が最小の頂点
        int v = que.top().second; 
        // d: vに対するキーの値
        long long d = que.top().first;
        que.pop();
        // dが"ゴミ"かの判定
        if(d > dist[v]) continue;
        // 頂点vを始点とした緩和
        for(auto e: G[v]) {
            if(chmin(dist[e.to], dist[v] + e.w)) {
                // 更新があるならばヒープに新たに挿入
                que.push(std::make_pair(dist[e.to], e.to));
            }
        }
    }
    // 結果の出力
    for(int v = 0; v < N; ++v) {
        if(dist[v] < INF) std::cout << dist[v] << std::endl;
        else std::cout << "INF" << std::endl;
    }
}
