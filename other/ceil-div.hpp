template <typename T>
T ceil_div(T n, T d) {
  static_assert(is_integral<T>::value and is_signed<T>::value,
                "template parameter T must be signed integral type");
  return n / d + ((n ^ d) >= 0 && n % d != 0);
}
