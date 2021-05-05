#ifndef COUNTER_HPP
#define COUNTER_HPP
#include <type_traits>

namespace euler
{
  typedef bool(*int_condition)(std::size_t);
  /* for convenience, an arithmetic_sequence_generator_n takes in the n 
     previous values and outputs a new value in a sequence. The canonical
     use case is generating the Fibonacci numbers */
  
  typedef std::size_t(*arithmetic_sequence_generator_1)(std::size_t);
  typedef std::size_t(*arithmetic_sequence_generator_2)(std::size_t, std::size_t);
  
  template<std::size_t Max, std::size_t i, int_condition cond, std::size_t cnt=0>
  typename std::enable_if<i == Max, std::size_t>::type
  count_if()
  {
    return cnt;
  }

  template<std::size_t Max, std::size_t i, int_condition cond, std::size_t cnt=0>
  typename std::enable_if<i < Max, std::size_t>::type
  count_if()
  {
    if constexpr (cond(i)) {
      return count_if<Max, i+1, cond, cnt+1>();
    } else {
      return count_if<Max, i+1, cond, cnt>();
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


  template<std::size_t Max, std::size_t i, int_condition cond, arithmetic_sequence_generator_1 gen, std::size_t cnt=0>
  typename std::enable_if<!(i <= Max), std::size_t>::type
  sum_if_sequence()
  {
    return cnt;
  }

  template<std::size_t Max, std::size_t i, int_condition cond, arithmetic_sequence_generator_1 gen, std::size_t cnt=0>
  typename std::enable_if<i <= Max, std::size_t>::type
  sum_if_sequence()
  {
    if constexpr (cond(i)) {
      return sum_if_sequence<Max, gen(i), cond, gen, cnt+i>();
    } else {
      return sum_if_sequence<Max, gen(i), cond, gen, cnt>();
    }
  }

  template<std::size_t Max, std::size_t i, std::size_t iprev, int_condition cond, arithmetic_sequence_generator_2 gen, std::size_t cnt=0>
  typename std::enable_if<!(i <= Max), std::size_t>::type
  sum_if_sequence_2()
  {
    return cnt;
  }

  template<std::size_t Max, std::size_t i, std::size_t iprev, int_condition cond, arithmetic_sequence_generator_2 gen, std::size_t cnt=0>
  typename std::enable_if<i <= Max, std::size_t>::type
  sum_if_sequence_2()
  {
    if constexpr (cond(i)) {
      return sum_if_sequence_2<Max, gen(i, iprev), i, cond, gen, cnt+i>();
    } else {
      return sum_if_sequence_2<Max, gen(i, iprev), i, cond, gen, cnt>();
    }
  }

} // namespace euler



#endif
