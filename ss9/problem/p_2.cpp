#include <cwchar>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

// 解けなかった
int calc_rev_porland(const std::string& rev_porland) {
    std::vector<char> p_vec;
    for(auto& c: rev_porland) {
        if(c != ' ') {
            p_vec.push_back(c);
        }
    }

    int result = 0;
    for(std::size_t i = 1; i < p_vec.size() - 1; ++i) {
        int n_1 = p_vec[i - 1] - '0';
        int n_2 = p_vec[i] - '0';
        char op = p_vec[i + 1];
        switch(op) {
            case '+':
                result += n_1 + n_2;
                break;
            case '-':
                result += n_1 - n_2;
            case '*':
                result += n_1 * n_2;
            case '/':
                result += n_1 / n_2;
            default:
                break;
        }
    }

    return 3;
}

// 模範解答
// ただし計算式の中は一桁の整数のみ
double calc(const std::string &exp) {
    std::stack<double> st;
    for (auto c: exp) {
        if (c >= '0' && c <= '9') {
            // '7' のような文字リテラルを 7 のような数値に変換
            double add = c - '0';
            st.push(add);
        } else {
            // 演算子の場合は演算を実施する
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();

            // 演算の実施結果をスタックに積む
            if (c == '+') st.push(b + a);
            else if (c == '-') st.push(b - a);
            else if (c == '*') st.push(b * a);
            else st.push(b / a);
        }
    }
    return st.top();
}

double calc_vec(const std::string &exp) {
    std::vector<double> st;
    for(auto c: exp) {
        if( c >= '0' && c <= '9') {
            double add = c - '0';
            st.push_back(add);
        } else {
            double a = st.back();
            st.pop_back();
            double b = st.back();
            st.pop_back();

            switch(c) {
                case '+':
                    st.push_back(b + a);
                    break;

                case '-':
                    st.push_back(b - a);
                    break;

                case '*':
                    st.push_back(b * a);
                    break;

                case '/':
                    st.push_back(b / a);
                    break;
            }
        }
    }
    return st.back();
}

double calc_vec_space(const std::string &exp) {
    std::vector<double> st;
    for(auto c: exp) {
        if( c >= '0' && c <= '9') {
            double add = c - '0';
            st.push_back(add);
        } else if( c == ' ') {
            continue;
        } else {
            double a = st.back();
            st.pop_back();
            double b = st.back();
            st.pop_back();

            switch(c) {
                case '+':
                    st.push_back(b + a);
                    break;

                case '-':
                    st.push_back(b - a);
                    break;

                case '*':
                    st.push_back(b * a);
                    break;

                case '/':
                    st.push_back(b / a);
                    break;
            }
        }
    }
    return st.back();
}

//桁の大きな数でやるにはどうすればよいのだろうか?

int main(void) {
    std::string rev_porland_1 = "34+12-*";
    //calc_rev_porland(rev_porland_1);

    std::cout << calc(rev_porland_1) << std::endl;
    std::cout << calc_vec(rev_porland_1) << std::endl;

    std::string rev_porland_space = "3 4 + 1 2 - *";
    std::cout << calc_vec_space(rev_porland_1) << std::endl;
}
