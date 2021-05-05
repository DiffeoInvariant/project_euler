#ifndef COUNTER_HPP
#define COUNTER_HPP
#include <type_traits>

namespace euler {
  typedef bool(*int_condition)(std::size_t);
  
  template<std::size_t Max, std::size_t i, int_condition cond, std::size_t cnt=0>
  typename std::enable_if<i == Max, std::size_t>::type
  count()
  {
    return cnt;
  }

  template<std::size_t Max, std::size_t i, int_condition cond, std::size_t cnt=0>
  typename std::enable_if<i < Max, std::size_t>::type
  count()
  {
    if constexpr (cond(i)) {
      return count<Max, i+1, cond, cnt+1>();
    } else {
      return count<Max, i+1, cond, cnt>();
    }
  }

    template<std::size_t Max, std::size_t i, int_condition cond, std::size_t cnt=0>
    typename std::enable_if<i == Max, std::size_t>::type
    sum_if()
    {
      return cnt;
    }

  template<std::size_t Max, std::size_t i, int_condition cond, std::size_t cnt=0>
  typename std::enable_if<i < Max, std::size_t>::type
  sum_if()
  {
    if constexpr (cond(i)) {
      return sum_if<Max, i+1, cond, cnt+i>();
    } else {
      return sum_if<Max, i+1, cond, cnt>();
    }
  }

} // namespace euler



#endif
