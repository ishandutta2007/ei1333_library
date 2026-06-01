template <typename T>
T ceil_div(T n, T d) {
  return n / d + ((n ^ d) >= 0 && n % d != 0);
}
