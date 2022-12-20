#include<iostream>
#include<vector>

using Graph = std::vector<std::vector<int>> ;
int main(void){
    int N, M;
    std::cin >> N >> M;

    Graph G(N);
    for(int i = 0; i < M; ++i){
	int a,b;
        std::cin >> a >> b;
	G[a].push_back(b);
        // 無向グラフの場合は以下も
	// G[b].push_back(a);
    }
}
