#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using Interval = std::pair<int,int>;

bool cmp(const Interval& a, const Interval& b){

    return a.second < b.second;
}

int main(void){

    // 入力
    int N;
    std::cin >> N;
    std::vector<Interval> inter(N);
    for(int i = 0; i < N; ++i)
	std::cin >> inter[i].first >> inter[i].second;

    // 区間をソート
    std::sort(inter.begin(),inter.end(),cmp);

    // 貪欲法
    int res = 0;
    int current_end_time = 0;
    for(int i = 0; i < N; ++i){
	if(inter[i].first < current_end_time) continue;

	++res;
	current_end_time = inter[i].second;
    }

    std::cout << res << std::endl;
}
