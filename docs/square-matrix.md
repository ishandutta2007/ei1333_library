---
title: Square Matrix(正方行列)
documentation_of: //math/matrix/square-matrix.hpp
---

固定サイズの正方行列を扱うための構造体です。

サイズ `N` はコンパイル時に決まります。要素の型 `T` は、利用する演算に必要な加算、減算、乗算などを持つ必要があります。

# コンストラクタ

```cpp
(1) SquareMatrix< T, N >()
(2) SquareMatrix< T, N >(const array<array<T, N>, N>& A)
```

1. 零行列を作ります。
2. 二次元配列 `A` で初期化します。

## 計算量

- $O(N^2)$

# size

```cpp
size_t size() const
```

行列のサイズ `N` を返します。

## 計算量

- $O(1)$

# operator[]

```cpp
(1) array<T, N>& operator[](int k)
(2) const array<T, N>& operator[](int k) const
```

$k$ 行目を返します。

## 制約

- $0 \leq k \lt N$

## 計算量

- $O(1)$

# add_identity

```cpp
static SquareMatrix add_identity()
```

加法単位元である零行列を返します。

## 計算量

- $O(N^2)$

# mul_identity

```cpp
static SquareMatrix mul_identity()
```

乗法単位元である単位行列を返します。

## 計算量

- $O(N^2)$

# 四則演算

```cpp
(1) SquareMatrix& operator+=(const SquareMatrix& B)
(2) SquareMatrix& operator-=(const SquareMatrix& B)
(3) SquareMatrix& operator*=(const SquareMatrix& B)
(4) SquareMatrix operator+(const SquareMatrix& B) const
(5) SquareMatrix operator-(const SquareMatrix& B) const
(6) SquareMatrix operator*(const SquareMatrix& B) const
```

行列同士の加算、減算、乗算を行います。

## 計算量

- 加算、減算: $O(N^2)$
- 乗算: $O(N^3)$

# 累乗

```cpp
(1) SquareMatrix& operator^=(uint64_t k)
(2) SquareMatrix operator^(uint64_t k) const
```

行列の $k$ 乗を求めます。

## 計算量

- $O(N^3 \log k)$
