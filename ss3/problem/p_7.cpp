#include <iostream>
#include <string>
#include <vector>

//O(N2^N)

/*
長さNの文字列には隙間がN-1箇所あるのでそれぞれについて+を入れる、入れないという二つの選択肢
があるので、選択肢が2^(N-1)通りある。

部分和問題と同様にbit全探索を用いる
 */


int main(void) {
    std::string s;
    std::cin >> s;
    int N = s.size();
    // bit全探索
    
    // N - 1　箇所の隙間に+を入れるかどうかを全て試す 
    // res: 結果 
    long long res = 0;
    for(int bit = 0; bit < (1<<(N-1)); ++bit) {
        // tmp: +と+の間の値
        long long tmp = 0;
        for(int i = 0; i < N -1; ++i) {
            tmp *= 10;
            tmp += s[i] - '0'; 

            // +を挿入するとき答えをtmpに加算してtmpに0初期化
            if(bit & (1<<i)) {
                res += tmp;
                tmp = 0;
            }
        }
        // 最後の+から残りの部分を答えに加算
        tmp *= 10;
        tmp += s.back() - '0';
        res += tmp;
    }

    std::cout << res << std::endl;
}
