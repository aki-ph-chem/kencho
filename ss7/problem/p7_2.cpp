#include<iostream>
#include <vector>
#include <algorithm>
//#define DEBUG

// x座標でsort
bool cmp_x(const std::pair<int,int>& p_1, const std::pair<int,int>& p_2) {
    return p_1.first < p_2.first;
}

bool operator < (const std::pair<int ,int>& p_1, const std::pair<int ,int>& p_2) {
    return p_1.first < p_2.first && p_1.second < p_2.second;
}

// 解けなかった
class Solution {
    public:
        int pair(std::vector<std::pair<int,int>>& red, std::vector<std::pair<int,int>>& blue) {
            int N = red.size();
            // O(NlogN)
            std::sort(red.begin(), red.end(), cmp_x);
            std::sort(blue.begin(), blue.end(), cmp_x);
#ifdef DEBUG
            for(int i = 0; i < N; ++i) {
                std::cout << " red: " << red[i].first << "," << red[i].second;
                std::cout << " blue: " << blue[i].first << "," << blue[i].second << std::endl;
            }
#endif

            int result = 0;
            // O(N)
            for(int j = 0; j < N; ++j) {
                if(red[result] < blue[j]) {
                    ++result;
                }
            }

            return result;
        }
};

// 模範解答
class SolutionAns {
    public:
        int pair(std::vector<std::pair<int,int>>& red, std::vector<std::pair<int,int>>& blue) {
            int N = red.size();
            std::sort(blue.begin(), blue.end());
            // 赤点が使用済みが否か確認
            std::vector<bool> used(N, false);

            // 青い点を順番に見ていく
            int res = 0;
            for (int i = 0; i < N; ++i) {
                // 使用済みでなく、y 座標最大の赤い点を探す
                int maxy = -1, maxid = -1;
                for (int j = 0; j < N; ++j) {
                    // 使用済みの赤い点は不可
                    if (used[j]) continue;

                    // x 座標, y 座標がより大きい赤い点は不可
                    if (red[j].first >= blue[i].first) continue;
                    if (red[j].second >= blue[i].second) continue;

                    // 最大値を更新
                    if (maxy < red[j].second) {
                        maxy = red[j].second;
                        maxid = j;
                    }
                }

                // 存在しない場合はスキップ
                if (maxid == -1) continue;

                // ペアリングする
                ++res;
                used[maxid] = true;
            }
            return res;
        }
};

int main(void) {
    int N;
    std::cin >> N;
    std::vector<std::pair<int,int>> R;
    std::vector<std::pair<int,int>> B;
    for(int i = 0; i < N; ++i) {
        int r_x,r_y,b_x,b_y;
        std::cin >> r_x >> r_y >> b_x >> b_y;
        R.push_back({r_x, r_y});
        B.push_back({b_x, b_y});
    }

#ifdef DEBUG
            for(int i = 0; i < N; ++i) {
                std::cout << "R: " << R[i].first << "," << R[i].second;
                std::cout << " B: " << B[i].first << "," << B[i].second << std::endl;
            }
#endif

    Solution s_1;
    std::cout << s_1.pair(R, B) << std::endl;

    SolutionAns s_ans;
    std::cout << s_ans.pair(R, B) << std::endl;
}
