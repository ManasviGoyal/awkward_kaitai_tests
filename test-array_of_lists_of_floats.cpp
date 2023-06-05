#include <fstream>
#include <iostream>
#include <src-array_of_lists_of_floats/array_of_lists_of_floats.h>

int main() {
  std::cout << "BEGINS" << std::endl;

  std::ifstream infile("data/array_of_lists_of_floats.raw", std::ifstream::binary);

  kaitai::kstream ks(&infile);

  array_of_lists_of_floats_t points = array_of_lists_of_floats_t(&ks);

  std::cout << "ENDS" << std::endl;
}
