# 動的計画法

## カエル飛び 

```mermaid
graph LR
    0--h01-->1--h12-->2--h23-->3--h34-->4
    0--h02-->2
    1--h13-->3
    2--h24-->4
```

- dp[i]: $i$におけるコスト 
    - dp[0] = 0 : $i$ = 0でのコストは0 

コストの更新の方法には以下の二通りの方法がある。

### 貰う形式と配る形式

- 貰う形式
    - $i-1,i-2$から$i$への遷移を考え小さい方を採用する
    - dp[i] = std::min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-1])) 
```mermaid
graph LR
    i-1-->i
    i-2-->i
```
- 配る形式

    - $i$から$i+1,i+2$への遷移を考える。それぞれの遷移を行う際に$i$との比較を行い小さい方を採用する。
```mermaid
graph LR
    i-->i+1
    i-->i+2
```

```mermaid
graph LR
    i+1-->i+2
    i+1-->i+3
```


### 緩和

まず配列dpを全て十分に大きな値INFで初期化しておき$i$を増やしてながらdp[i]を更新していく。

このような一度"大きな値で初期化"されたものを小さな値へ更新していく様子から緩和という。

## ナップザック問題 

- dp[i][w] : $0,1,..,i-1$までの品物の中から何個か選び、重さを$w$以下にしている状態

## 編集距離

- dp[i][j]: Sの最初の$i$文字とTの最初の$j$文字との間との間の編集距離
    - 初期条件: dp[0][0] = 0
- 配列dp[i][j]において
    - 右下への移動($(i-1,j-1)$ -> $(i,j)$): Sの文字の$i$文字目の(コストが1ならば変更され、コストが0ならば変更されない)変更 
    - 下への移動($(i-1,j)$ -> $(i,j)$): Sの$i$文字目の削除
    - 右への移動($(i,j-1)$ -> $(i,j)$): Sへの$i$文字目の挿入(Tの$i$文字目の削除)

## 区間

- dp[i]: 区間$[0,i)$についていくつかの区間に分割する最小コスト 
    - dp[0] = 0
    - 区間$[0,i)$に区間$[j,i)$を追加したときの緩和: chmin(dp[i], dp[j] + cp[i][j])
