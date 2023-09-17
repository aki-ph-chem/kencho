## ss2

### 計算量

- 一般に一秒間に実行可能なステップ数は $10^9$ 回ほどであることが知られている。
- アルゴリズムの実行時間のうち最悪なケースにおける計算量を<b>最悪計算量</b>という。
- 平均的なケースにおける計算量を<b>平均計算量</b>という。

### ランダウの $O$ 記号 

- 定義

$T(N),P(N)$をそれぞれ非負の整数で定義された関数であるとする。
このとき$T(N) = O(P(N))$ であるとはある正の実数 $c$ と非負な整数 $N_0$ が存在して $N_0$ 以上の任意の整数 $N$ に対して

$$
\left| \frac{T(N)}{P(N)} \right| \leq c \tag{1}
$$

が成立することをいう。

- 例: $T(N) = 3N^2 + 5N + 100$

この場合では

$$
\frac{3N^2 + 5N + 100}{N^2} = 3 + \frac{5}{N} + \frac{100}{N^2} 
$$

であるが、

$$
\frac{5}{N} + \frac{100}{N^2} \leq 1 
$$

であるので

$$
\frac{3N^2 + 5N + 100}{N^2} \leq 4
$$

と評価できるので

$$
T(N) = O(N^2) 
$$

#### 例:最近点問題 

正の数 $N$ と $N$ 個の座標値 $(x_i, y_i) \quad (i = 0,1,\dots,N - 1)$ に対して最も短い二点間の距離

まず、全部の点同士の距離を計算するアルゴリズムが思い浮かぶ

```C++
double result = std::pow(10,4);
for(std::size_t i=0; i<N; ++i) {
    for(std::size_t j=0; j<N; ++j) {
            double min_tmp =  dist(x_array[i], y_array[i], x_array[j], y_array[j]);
            if(result > min_tmp ) {
                result = min_tmp;
            }
    }
}
```

しかし、同じ点の間の距離はゼロであることと距離の対称性より点 $i$ に対しする $j$ は $j = i+1, i + 2, \dots, N - 1$だけでよいため以下のように
すればよい。

```C++
double result = std::pow(10,4);
for(std::size_t i=0; i<N; ++i) {
    for(std::size_t j=i+1; j<N; ++j) {
            double min_tmp =  dist(x_array[i], y_array[i], x_array[j], y_array[j]);
            if(result > min_tmp ) {
                result = min_tmp;
            }
    }
}
```

このとき

- $i = 0$ のとき $j = 1,2,\dots,N-1$ ($N - 1$ 回) 
- $i = 1$ のとき $j = 2,3,\dots,N-1$ ($N - 2$ 回) 
- $\dots$
- $i = N - 2$ のとき$j = N - 1$ (1 回) 
- $i = N - 1$ のとき(0 回) 

であるので時間計算量 $T(N)$ は

$$
\begin{align}
T(N) &= (N - 1) + (N - 2) + (N - 3) + \dots + 2 + 1 + 0 \\
     &= \frac{1}{2}(N^2 - N)
\end{align}
$$

となるため $O(\frac{1}{2}(N^2 - N)) = O(N^2)$ である。

### $\Omega$ 記法

$O$ は"上から抑えて"評価する考えかたであったが、逆に下から抑えて評価する方法として $\Omega$ 記法がある。

- 定義

$T(N),P(N)$をそれぞれ非負の整数で定義された関数であるとする。
このとき$T(N) = \Omega(P(N))$ であるとはある正の実数 $c$ と非負な整数 $N_0$ が存在して $N_0$ 以上の任意の整数 $N$ に対して

$$
\left| \frac{T(N)}{P(N)} \right| \geq c \tag{2}
$$

が成立することをいう。

### $\Theta$ 記法

- 定義

$T(N)$ が $T(N) = O(P(N))$ かつ $T(N) = \Omega(P(N))$ と評価できるとき

$$
T(N) = \Theta(P(N)) \tag{3}
$$

であるという。
