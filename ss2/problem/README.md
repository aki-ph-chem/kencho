## 章末問題


1. 以下の $T_i(N) \quad (i = 1,2,3,4,5)$ のをランダウの $O$ 記法で示せ。

$$
\begin{align}
&T_1(N) = 1000N \\
&T_2(N) = 5N^2 + 10N + 7 \\
&T_3(N) = 4N^2 + 3N\sqrt{N}\\
&T_4(N) = N\sqrt{N} + 5N \log{N}\\
&T_5(N) = 2^N + N^{2019}\\
\end{align}
$$

$$
\begin{align}
&T_1(N): O(N) \\
&T_2(N): O(N^2) \\
&T_3(N): O(N^2) \\
&T_4(N): O(N\sqrt{N}) \\
&T_5(N): O(2^N) \\
\end{align}
$$

2. 以下の手続きの計算量をランダウの $O$ 記号を用いて表せ。なおこの手続きは $N$ 個から3個を列挙する手続きである。

```C++
for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j) {
        for(int k = j + 1; k < N; ++k) {
        }
    }
}
```

$N$ 個から 3個を選ぶので時間計算量 $T(N)$ は

$$
\begin{align}
T(N) &= \binom{N}{3}\\ 
     &= \frac{1}{6}N(N - 1)(N - 2) \\
     &= \frac{1}{6}(N^3 - 3N^2 + 2N)
\end{align}
$$

であるので ランダウの $O$ 記法では $O(N^3)$ で表現できる。

