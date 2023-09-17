<!-- ドラフト -->
## ソート

ソートには色々なものがある

### 挿入ソート

- 分割統治法による
- 一番シンプル
- 時間計算量: $O(N^2)$ 

### マージソート 

- 複雑 
- 時間計算量: $O(NlogN)$

### クリックソート

- 分割統治法による
- 時間計算量: $O(N^2)$

### ヒープソート

- ヒープを使う
- 時間計算量: $O(NlogN)$

### バケットソート

- 配列の $array$ の要素が 0以上 $A$ 未満の整数のときのみ適用可で時間計算量は $O(N + A)$ 
- アイディア: num[x]: 配列 $array$ の中に値 $x$ を持つ要素が何個あるか