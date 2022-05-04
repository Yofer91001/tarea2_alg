#include "btree.hpp"
#include <string>

int main() {
  Btree<int> mytree;

  mytree.insert(1);
  mytree.insert(2);
  mytree.insert(3);
  mytree.insert(4);
  mytree.insert(5);
  mytree.insert(6);
  mytree.insert(7);
  mytree.insert(8);
  mytree.insert(9);
  mytree.insert(10);
  mytree.display();
  mytree.imprimirPorNiveles();

  // int a = 5;
  // if(mytree.find(a))
  //   std::cout << a << " is in the array.\n";
  // else
  //   std::cout << a << " is not in the array.\n";

  //mytree.test();
  Btree<int> mytree1;
  mytree1.insert(5);
  mytree1.insert(4);
  mytree1.insert(7);
  mytree1.insert(2);
  mytree1.insert(9);
  mytree1.insert(8);
  mytree1.insert(3);
  mytree1.display();
  mytree1.imprimirPorNiveles();

  Btree<int> mytree2;
  mytree2.insert(10);
  mytree2.insert(9);
  mytree2.insert(11);
  mytree2.insert(8);
  mytree2.insert(12);
  mytree2.insert(7);
  mytree2.insert(13);
  mytree2.display();
  mytree2.imprimirPorNiveles();

  Btree<int> mytree3;
  mytree3.insert(10);
  mytree3.insert(2);
  mytree3.insert(15);
  mytree3.insert(8);
  mytree3.insert(12);
  mytree3.insert(1);
  mytree3.insert(7);
  mytree3.insert(14);
  mytree3.display();
  mytree3.imprimirPorNiveles();

  Btree<std::string> mytree4;
  mytree4.insert("Grumpy");
  mytree4.insert("Dopey");
  mytree4.insert("Bashful");
  mytree4.insert("Doc");
  mytree4.insert("Sleepy");
  mytree4.insert("Happy");
  mytree4.insert("Sneezy");
  mytree4.display();
  mytree4.imprimirPorNiveles();
  
  Btree<std::string> mytree5;
  mytree5.insert("Bashful");
  mytree5.insert("Doc");
  mytree5.insert("Dopey");
  mytree5.insert("Grumpy");
  mytree5.insert("Happy");
  mytree5.insert("Sleepy");
  mytree5.insert("Sneezy");
  mytree5.display();
  mytree5.imprimirPorNiveles();

  return 0;
}
