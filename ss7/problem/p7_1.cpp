#include <iostream>
#include <vector>
#include <algorithm>

// 解けなかった
// そもそも題意を誤解していた
class Solution{
    public:
        int pair( std::vector<int>& A,  std::vector<int>& B) {
            // O(NlogN)
            std::sort(A.begin(), A.end());
            std::sort(B.begin(), B.end());

            // O(N^2)
            int result = 0;
            int N = A.size();
            for(int a = 0; a < N; ++a) {
                if(A[a] < B[a]) {
                    result += N - a;
                } else {
                    auto b = a + 1;
                    while(A[a] >= B[b]) {
                        ++b;
                    }
                    result += N - b;
                }
            }
            return result;
        }
};

//模範解答
class SolutionAns {
    public:
        int pair(std::vector<int>& A, std::vector<int>& B) {
            // それぞれソートする
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());

            // B を順に見ていく
            int i = 0;
            int N = A.size();
            for (int j = 0; j < N; ++j) {
                if (A[i] < B[j]) ++i;
            }
            return i;
        }
};

// a_i < b_j となるような組 (a_i, b_j)は何個出来るか?
int main(void) {
    // 入力
    int N;
    std::cin >> N;
    std::vector<int> A(N),B(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> A[i] >> B[i]; 
    }

    Solution s_1;
    std::cout << s_1.pair(A,B) << std::endl;

    SolutionAns s_ans;
    std::cout << s_ans.pair(A,B) << std::endl;
}
