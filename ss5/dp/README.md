# 動的計画法のアイディア

- 参考にしたスライド 
https://www.slideshare.net/iwiwi/ss-3578511

## ナップサック問題

### 問題
$n \quad(i = 0,1,\ldots, n - 1)$ 個の品物がある。$i$ 番目の品物の重さは $w_i$ で ,その価値を $v_i$ とする。 
このとき重さの合計が $U$ を超えないような条件での価値の和の最大値を求めよ。
ただし、一つの品物は1個までしか選べないものとする。

### 例

各品物の重さ,価値を(重さ,価値)の形で書くと具体的なケースとして $(2,3),(1,2),(3,4),(2,2)$ で $U = 10$ のとき解は $7$

### 方針

単純な全探索では、品物を1から使うor使わない場合を両方試す

`v,w`を価値、重さの配列として`i`番目以降の品物で重さの総和が`u`を超えないような場合を、`search(v, w, i, u)`として

```C++
int search(std::vector<int>& v, std::vector<int>& w,int i, int u){
    int n = v.size();
    if(i == n){ // もう品物は残っていない
        return 0;
    }else if(u < w[i]){ // この品物は入らない
        return search(v, w, i + 1, u);
    }else{ // 入れない場合と入れる場合の両方を試す
        int res_1 = search(v, w, i + 1, u);
        int res_2 = search(v, w, i + 1, u - w[i]) + v[i];
        return std::max(res_1, res_2);
    }
}
```

と実装する。

この関数を

```C++
search(v, w, 0, U)
```

と呼び出すことで再帰的な探索を実行する。

しかし、この(ナイーブな実装の)ままでは指数時間かかる $(O(2^N))$ 。
そのため、$U$ が大きいとまともに計算できない

## 動的計画法

このタイプの問題の問題をより計算しやすいオーダーに落とす方法には、メモ化をしながら再帰呼出しをする方法と、配列に記録しながら探索を行う漸化式タイプの方法がある。

### メモ化再帰

そこで、 $i,u$ の値が同じならば`search(v,w,i,u)`の値は同じであることに着目する(同じ計算は二度としないようにする)

この場合では記録するための配列`std::vector<std::vector<int>> memo` をとして、`search(v, w, memo, i, u)`を

```C++
int search(std::vector<int>& v, std::vector<int>& w, std::vector<std::vector<int>>& memo,int i, int u){
    int n = v.size();
    // 既に計算していたら配列から取り出してreturn
    if(memo[i][u])return memo[i][u];
    if(i == n){ // もう品物は残っていない
        return 0;
    }else if(u < w[i]){ // この品物は入らない
        return memo[i][u] = search(v, w,memo, i + 1, u);
    }else{ // 入れない場合と入れる場合の両方を試す
        int res_1 = search(v, w, memo, i + 1, u); // 入れない場合
        int res_2 = search(v, w, memo, i + 1, u - w[i]) + v[i]; // 入れる場合
        return memo[i][u] = std::max(res_1, res_2);
    }
}
```

と実装して、

```C++
search(v, w, memo, 0, U)
```

と呼び出すことで再帰的な探索を行う。

### 漸化式とforループ

漸化式とは $n$ 番目の状態と $n+1$ 番目の状態を結ぶ関係式である。
漸化式を用いたアイディアでは(品物の数,重さ)の二次元配列に $i$ が大きい方から埋めていく。
二次元配列を埋めていく際には、一度計算したケース(既に埋めた配列)の値を利用しながら進めていく。

ここでは漸化式として

$i + 1 \rightarrow i$ と後退させる場合は

$$
dp_{i,u} = \text{max} \{dp_{i+1,u}, dp_{i + 1, u - w_i} + v_i\}
$$


を考え

```C++
// 埋めていいる表
int dp[MAX_N + 1][MAX_U + 1];
// 対象の配列
int v[N] = {2, 1, 3, 2};
int w[N] = {3, 2, 4, 2};
// 探索
/*
dp[N - 1][0]からスタートして、個数は減らしながら,重さは増やしながら探索を行う。 
最終的にdp[0][U]を目指す
 */
int do_dp(int U){
    for(int u = 0; u <= U; ++u)dp[N][u] = 0; // 境界条件
                                             
    for(int i = N - 1; i >= 0; --i){
        for(int u = 0; u <= U; ++u){
            if(u < w[i]){ 
                // uが小さくのでiを選ばない
                dp[i][u] = dp[i + 1][u];
            }else{
                // iを選ぶ場合と入れない場合の両方を試す
                dp[i][u] = std::max(dp[i + 1][u], dp[i + 1][u - w[i]] + v[i]);
            }
        }
    }
    return dp[0][U];
}
```

と実装する。

$i \rightarrow i + 1$ と前進させる場合は、漸化式

$$
dp_{i + 1,u} = \text{max} \{dp_{i,u}, dp_{i, u - w_i} + v_i\}
$$

を考え

```C++
#include <iostream>
#define MAX_N 100
#define MAX_U 100
#define N 4
//　方法2: 漸化式とループ

// 埋めていいる表
int dp[MAX_N + 1][MAX_U + 1];
// 対象の配列
int v[N] = {2, 1, 3, 2};
int w[N] = {3, 2, 4, 2};
// 探索
int do_dp(int U){
    for(int u = 0; u <= U; ++u)dp[N][u] = 0; // 境界条件
    // dpループ     
    /* 
      dp_3_0.cppではdp[N - 1][0]からスタートして
      個数を減らしながら探索していたがここでは
      dp[0][0]をからスタートして個数を増やしながら探索する
    */
    for(int i = 0; i < N; ++i){
        for(int u = 0; u <= U; ++u){
            if(u < w[i]){ 
                // uが小さくのでiを選ばない
                dp[i + 1][u] = dp[i][u];
            }else{
                // iを選ぶ場合と入れない場合の両方を試す
                dp[i + 1][u] = std::max(dp[i][u], dp[i][u - w[i]] + v[i]);
            }
        }
    }
    return dp[N][U];
}
```

と実装する。
