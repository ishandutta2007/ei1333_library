---
title: Matrix(行列)
documentation_of: //math/matrix/matrix.hpp
---

行列を扱うための構造体です。

要素の型 `T` は、加算、減算、乗算、除算、比較など、利用する演算に必要な操作を持つ必要があります。

# コンストラクタ

```cpp
(1) Matrix< T >()
(2) Matrix< T >(const vector<vector<T> >& A)
(3) Matrix< T >(size_t n, size_t m)
(4) Matrix< T >(size_t n)
```

1. 空の行列を作ります。
2. 二次元配列 `A` で初期化します。
3. $n \times m$ の零行列を作ります。
4. $n \times n$ の零行列を作ります。

## 計算量

- (1) $O(1)$
- (2) $O(nm)$
- (3) $O(nm)$
- (4) $O(n^2)$

# size

```cpp
size_t size() const
```

正方行列のサイズを返します。

## 制約

- 行列が空、または正方行列である

## 計算量

- $O(1)$

# height / width

```cpp
(1) size_t height() const
(2) size_t width() const
```

1. 行数を返します。
2. 列数を返します。

## 制約

- `width()` を呼ぶとき、行列が空でない

## 計算量

- $O(1)$

# operator[]

```cpp
(1) vector<T>& operator[](int k)
(2) const vector<T>& operator[](int k) const
```

$k$ 行目を返します。

## 制約

- $0 \leq k \lt height()$

## 計算量

- $O(1)$

# I

```cpp
static Matrix I(size_t n)
```

$n \times n$ の単位行列を返します。

## 計算量

- $O(n^2)$

# 四則演算

```cpp
(1) Matrix& operator+=(const Matrix& B)
(2) Matrix& operator-=(const Matrix& B)
(3) Matrix& operator*=(const Matrix& B)
(4) Matrix operator+(const Matrix& B) const
(5) Matrix operator-(const Matrix& B) const
(6) Matrix operator*(const Matrix& B) const
```

行列同士の加算、減算、乗算を行います。

## 制約

- 加算、減算では、行列のサイズが一致する
- 乗算では、左辺の列数と右辺の行数が一致する

## 計算量

- 加算、減算: $O(nm)$
- 乗算: $O(nmp)$

# 累乗

```cpp
(1) Matrix& operator^=(long long k)
(2) Matrix operator^(long long k) const
```

行列の $k$ 乗を求めます。

## 制約

- 行列が正方行列である
- $0 \leq k$

## 計算量

- $O(n^3 \log k)$

# determinant

```cpp
T determinant()
```

行列式を返します。

## 制約

- 行列が正方行列である
- `T` は除算をサポートしている

## 計算量

- $O(n^3)$
