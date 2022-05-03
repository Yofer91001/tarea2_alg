#include "btree.hpp"
#include <string>

int main() {
  Btree<int> mytree;

  mytree.insert(3);
  mytree.insert(6);
  mytree.insert(5);
  mytree.insert(2);

  mytree.display();

  // int a = 5;
  // if(mytree.find(a))
  //   std::cout << a << " is in the array.\n";
  // else
  //   std::cout << a << " is not in the array.\n";

  //mytree.test();

  mytree.remove(3);
  mytree.display();

  mytree.imprimirPorNiveles();
  
  return 0;
}
