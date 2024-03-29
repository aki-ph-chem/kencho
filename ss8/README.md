<!-- ドラフト -->
## 配列、連結リスト、ハッシュテーブル

### ハッシュテーブル

 $M$ を正の整数として $0$ 以上 $M$ 未満な整数 $x$ に対して以下の３つのクエリを高速に処理することを考える

1. $x$ をデータ構造に挿入する
2. $x$ をデータから削除する
3. $x$ をデータ構造に含まれるか否かの判定を行う

ここで $x$ を添え字とするbool値の配列 $T$ を考える

この配列によるデータ構造ではデータ $x$ の挿入、削除、検索がすべて $O(1)$ で実行できる。
このような配列 $T$ を`バケット`という。

この`バケット`は格納できる値は $0$ 以上 $M$ 未満な整数であるが、これを他の多くのデータ型の値を格納できるデータ構造が`ハッシュテーブル`という。 
ハッシュテーブルでは、あるデータ型の値 $x$ に対して $0$ 以上 $M$ 未満の値を返す関数(`ハッシュ関数`) $0 \le h(x) < M$ を考える。 

すべての異なるある型の値 $x,y$ に対して $h(x) \ne h(y)$となるとき $h(x)$ を`完全ハッシュ関数`という。
しかし、完全ハッシュ関数を実現することは困難でハッシュ値が衝突してしまう可能性がある。
この場合に対応する方法は色々な方法があるが、良く用いられる方法には衝突したハッシュ値ごとに連結リストで管理する方法がある。
