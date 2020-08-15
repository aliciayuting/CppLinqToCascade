#include "cpplinq.hpp"

int computes_a_sum()
{
  using namespace cpplinq;
  int ints[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 4};
  auto result = from_array(test.csv) >> where([](int i) { return i % 2 == 0; }) // Keep only even numbers
                >> sum()                                                        // Sum remaining numbers
      ;
  return result;
}