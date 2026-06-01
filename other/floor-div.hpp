template <typename T>
T floor_div(T n, T d) {
  return n / d - ((n ^ d) < 0 && n % d != 0);
}
