#include <iostream>
#include "counter.hpp"


constexpr bool divisible_by_3_or_5(std::size_t i)
{
  return i % 3 == 0 or i % 5 == 0;
}


int main(int argc, char **argv)
{
  constexpr std::size_t max = 1000, min = 3;
  std::cout << "Count is " << euler::sum_if<max, min, divisible_by_3_or_5>() << '\n';
  return 0;
}
