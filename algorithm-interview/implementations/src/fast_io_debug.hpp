#pragma once

#include <iostream>

inline void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

#ifdef LOCAL
  #define debug(value) (std::cerr << #value << " = " << (value) << '\n')
#else
  #define debug(value) ((void)0)
#endif
