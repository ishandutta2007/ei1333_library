---
documentation_of: //string/z-algorithm.hpp
---

## 概要

文字列 $S$ が与えられたとき, それぞれの $i$ について $S$ と $S[i, \|S\|]$ の最長共通接頭辞の長さを記録した配列を線形時間で構築する.

具体例を以下に示す. 例えば $i = 5$ のときの最長共通接頭辞は "aaa", つまり $3$ 文字である.

<pre>
aaabaaaab
921034210
</pre>

## 使い方

* `ZAlgorithm()`: 空文字列で初期化する.
* `ZAlgorithm(s)`: 文字列 `s` で初期化する.
* `add(c)`: 文字列の末尾に `c` を追加する.
* `get(k)`: 現時点の文字列の  $S$ と $S[i, \|S\|]$ の最長共通接頭辞の長さを返す
* `get()`: 現時点の文字列の $S$ とすべての $i$ についての$S[i, \|S\|]$ の最長共通接頭辞の長さを返す.

## 計算量

* 全体で $O(\|S\|)$
