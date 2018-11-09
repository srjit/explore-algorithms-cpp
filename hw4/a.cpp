#include <utility>      // std::pair, std::get
#include <iostream>     // std::cout

int main () {
  std::pair <int,char> foo (10,'x');

  std::get<0>(foo) = 50;

  std::cout << "foo contains: ";
  std::cout << foo[0] << " and " << foo[1] << '\n';

  return 0;
}
