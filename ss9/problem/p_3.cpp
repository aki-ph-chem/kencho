#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

/*
 方針:
最初はスタックを空の状態にしておき、括弧列を左から順番に見て行く

左括弧 '(' が来たらスタックに push
右括弧 ')' が来たらもしスタックが空だった場合には「整合しない」と判定スタックが空でなかった場合は、top 要素を pop する (ここで pop した '(' と手元にある ')' が互いに対応します)

以上の処理を終えたとき、もしスタックが空であれば、括弧列は「整合がとれていた」と判定でき、空でなければ「整合しない」と判定できる
 */

// 模範解答
bool check(const std::string& s) {
    std::stack<int> st; // 整合性チェック用のスタック 
    std::vector<std::pair<int,int>> ps; // 一を記録するための値

    for(int i = 0; i < static_cast<int>(s.size()); ++i) {
        if(s[i] == '('){ 
            st.push(i);
        } else {
            if (st.empty()) {
                std::cout << "error" << std::endl;
                return false;
            }

            int t = st.top();
            st.pop();
            ps.push_back({t,i});
        }
    }

    // 結果を出力

    // スタックが空なら左カッコが過剰
    if(!st.empty()) {
        std::cout << "too many (" << std::endl;
        return false;
    }

    // 整合している場合の出力
    std::sort(ps.begin(), ps.end());
    for(int i = 0; i < static_cast<int>(ps.size()); ++i) {
        if(i) std::cout << ", ";
        std::cout << "(" << ps[i].first << "," << ps[i].second << ")";
    }
    std::cout << std::endl;
    return true;
}

int main() {
    auto case_1 = std::string{"((()())())"};
    auto case_2 = std::string{"())"};
    auto case_3 = std::string{"(()"};

    check(case_1);
    check(case_2);
    check(case_3);
}
