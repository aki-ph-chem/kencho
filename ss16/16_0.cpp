#include <iostream>
#include <vector> 

// フォード・ファルカーソン法

struct Graph {

    struct Edge {
        // rev: 逆辺(to, from)がG[to]の中で何番目か
        // cap: 各辺(from, to)の容量
        int rev, from, to, cap; 
        Edge(int r, int f, int t, int c)
            :rev(r), from(f), to(t), cap(c) {}
    };

    // 近接リスト
    std::vector<std::vector<Edge>> list;

    //コンストラクタ、N: 頂点数 
    Graph(int N = 0) : list(N) {}

    // グラフの頂点数の取得
    std::size_t size(void) {
        return list.size();
    } 

    //[]演算子をオーバーロードしてG.list[v]をG[v]と書けるようにする
    std::vector<Edge> &operator [] (int i) {
        return list[i];
    }

    // 辺e = (u, v)の逆辺 (v, u)を取得する
    // 辺 e = (u, v)の逆辺(v, u)をG[v][e.rev]で取得
    Edge& redge(const Edge& e) {
        return list[e.to][e.rev];
    } 

    // 辺 e = (u, v)に流量fのflowを流す
    // 辺 e = (u, v)に流量はfだけ減少する
    // 逆辺 (v, u)の流量はfだけ増加する
    void run_flow(Edge &e, int f) {
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点 fromからtoへの容量capの辺を張る
    // このときtoからfromへの容量0の辺を張る
    void add_edge(int from, int to, int cap) {
        int from_rev = (int)list[from].size();
        int to_rev = (int)list[to].size();
        list[from].push_back(Edge(to_rev, from, to, cap));
        list[to].push_back(Edge(from_rev, to, from, 0));
    } 
};

struct FordFulkerson {
    static const int INF = 1 << 30;

    std::vector<int> seen;

    // コンストラクタ
    FordFulkerson(void) {} 
    
    // 残余グラフ上でs-t pathを見つける (DFS)
    // 返り値はs-t path上での容量の最小値
    // f: sからvへ到達した過程の各辺の容量の最小値
    int fodfs(Graph &G, int v, int t, int f) {
        // 終端tに到達したらreturn
        if(v == t) return f;
        // 深さ優先探索
        seen[v] = true; 
        for(auto &e: G[v]) {
            if(seen[e.to]) continue;
            // 容量0の辺は存在しない
            if(e.cap == 0 ) continue; 
            // s-t pathを探す
            // 見つかった場合flowはパスの最小容量
            // 見つからなかった場合 f = 0
            int flow = fodfs(G, e.to, t, std::min(f, e.cap)); 
            // s-t pathが見つからなかった場合次の辺を試す 
            if(flow == 0) continue;
            // 辺eに容量 flowのフローを流す
            G.run_flow(e, flow);
            // s-t pathが見つけたらpath上の最小容量を返す
            return flow; 
        }
        // s-t pathが見つからなかったことを意味する
        return 0;
    } 

    // グラフGのs-t間の最大流量を求める
    // ただしreturn時にGは残余グラフとなる
    int solve(Graph &G, int s, int t) {
        int res = 0;
        // 残余グラフ上でs-tパスがなくなるまで反復
        while(true) {
            // ループのたびにseenをリセットする
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t ,INF);
            // s-tパスが見つからなければ終了
            if(flow == 0) return res;
            res += flow;
        }
        // 
        return 0; 
    }
};

int main(void) {
    // N: 頂点数、M: 辺数
    int N, M;
    std::cin >> N >> M; 
    Graph G(N);
    // グラフを受け取る
    for(int i = 0; i < M; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        // 容量cの辺(u, v)を張る
        G.add_edge(u, v, c);
    } 
    // フォード・ファルカーソン法
    FordFulkerson ff;
    int s = 0, t = N - 1;
    std::cout << ff.solve(G, s, t) << std::endl; 
}
