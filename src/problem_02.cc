#include "utils.hpp"
#include "counter.hpp"
#include <iostream>

constexpr std::size_t fibonacci(std::size_t i, std::size_t iprev)
{
  return i + iprev;
}

int main(int argc, char **argv)
{
  constexpr std::size_t max = 4'000'000;
  std::cout << "Sum of even Fibonacci numbers up to and including 4,000,000 is " << euler::sum_if_sequence_2<max, 2, 1, euler::is_even, fibonacci>() << '\n';

  return 0;
}
  
