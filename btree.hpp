#ifndef _BTREE_HPP
#define _BTREE_HPP

#include <iostream>
#include<queue>

template <typename T>
struct Node {
  T key;
  Node<T>* left;
  Node<T>* right;
  Node<T>* parent;
};

template <typename T>
class Btree {
private:
  Node<T>* root;
  unsigned count;

  void insert(T k, Node<T>* p, Node<T>* &n);
  Node<T>* find(T k, Node<T>* n);
  void display(Node<T>* n, unsigned lvl);
  void destroy(Node<T>* n);
  Node<T>* minimum(Node<T>* n);
  Node<T>* maximum(Node<T>* n);
  Node<T>* predecessor(Node<T>* n);
  Node<T>* successor(Node<T>* n);
  
public:
  Btree();
  ~Btree();

  void insert(T k);
  void remove(T k);
  bool find(T k);
  void display();
  void imprimirPorNiveles();
  void imprimirPorNiveles(Node<T>* n);

  /****/
  void test();
  /****/
};

//IMPLEMENTATION-------------------------------

template <typename T>
Btree<T>::Btree() {
  root = nullptr;
  count = 0;
}

template <typename T>
Btree<T>::~Btree() {
  destroy(root);
}

template <typename T>
void Btree<T>::destroy(Node<T>* n) {
  if(n != nullptr){
    destroy(n->left);
    destroy(n->right);
    //std::cout << "Destroying " << n->key << "\n";
    delete n;
  }
}

template <typename T>
void Btree<T>::insert(T k, Node<T>* p, Node<T>* &n) {
  if(n == nullptr){
    Node<T>* newnode = new Node<T>;
    newnode->key = k;
    newnode->left = nullptr;
    newnode->right = nullptr;
    newnode->parent = p;
    n = newnode;
    count++;
    //std::cout << "me: " << n->key << " ";
    //if(n->parent != nullptr)
    //  std::cout << "p: " << n->parent->key << "\n";
  }else{
    if(k < n->key){
      insert(k, n, n->left);
    }else if(k > n->key){
      insert(k, n, n->right);
    }
  }
}

template <typename T>
void Btree<T>::insert(T k) {
  insert(k, nullptr, root);
}

template <typename T>
Node<T>* Btree<T>::find(T k, Node<T>* n) {
  if(n == nullptr)
    return nullptr;
  else if(n->key == k)
    return n;
  else{
    if(k < n->key)
      return find(k, n->left);
    else
      return find(k, n->right);
  }
}

template <typename T>
bool Btree<T>::find(T k) {
  if(find(k, root) != nullptr)
    return true;
  else
    return false;
}

template <typename T>
void Btree<T>::display(Node<T>* n, unsigned lvl) {
  if(n != nullptr){
    display(n->left, lvl+1);
    std::cout << n->key << "(" << lvl << ") ";
    display(n->right, lvl+1);
  }
}

template <typename T>
void Btree<T>::display() {
  display(root, 0);
  std::cout << "\n";
}

template <typename T>
Node<T>* Btree<T>::minimum(Node<T>* n) {
  if(n != nullptr){
    if(n->left == nullptr)
      return n;
    else
      return minimum(n->left);
  }
  return nullptr;
}

template <typename T>
Node<T>* Btree<T>::maximum(Node<T>* n) {
  if(n != nullptr){
    if(n->right == nullptr)
      return n;
    else
      return maximum(n->right);
  }
  return nullptr;
}

template <typename T>
Node<T>* Btree<T>::successor(Node<T> *node) {
  if(node == maximum(root))
    return nullptr;
  if(node->right != nullptr)
    return minimum(node->right);
  Node<T> *p = node->parent;
  while(p != nullptr && node == p->right){
    node = p;
    p = node->parent;
  }
  return p;
}

template <typename T>
Node<T>* Btree<T>::predecessor(Node<T> *node) {
  if(node == minimum(root))
    return nullptr;
  if(node->left != nullptr)
    return maximum(node->left);
  Node<T> *p = node->parent;
  while(p != nullptr && node == p->left){ //mientras que sea hijo izquierdo
    node = p;
    p = node->parent;
  }
  return p;
}

template <typename T>
void Btree<T>::remove(T k) {
  Node<T>* target = find(k, root);
  if(target != nullptr){
    Node<T>* p = target->parent;
    if(target->left == nullptr && target->right == nullptr){ //No children
      if(p->left == target)
	p->left = nullptr;
      else
	p->right = nullptr;
      delete target;
      count--;
    }else if(target->right == nullptr){ //only left child
      if(p->left == target)
	p->left = target->left;
      else
	p->right = target->left;
      delete target;
      count--;
    }else if(target->left == nullptr){ //only right child
      if(p->left == target)
	p->left = target->right;
      else
	p->right = target->right;
      delete target;
      count--;
    }else{ //two children
      Node<T>* s = successor(target);
      T c = s->key;
      remove(c);
      target->key = c;
      count--;
    }
  }
}


template <typename T>
void Btree<T>::test() {
  Node<T>* n = minimum(root);
  std::cout << n->key << "\n";
}


template<typename T>
void Btree<T>::imprimirPorNiveles(){

    imprimirPorNiveles(root);

}

template<typename T>
void Btree<T>::imprimirPorNiveles(Node<T>* n){
    std::queue<Node<T>*> myqueue;
    myqueue.push(n);
    while(myqueue.size() > 0){
        std::cout<<myqueue.front()->key<<"\t";
        if(myqueue.front()->left != nullptr){
          myqueue.push(myqueue.front()->left);
        }
        if(myqueue.front()->right != nullptr){
          myqueue.push(myqueue.front()->right);
        }
        
        myqueue.pop();
    }
    std::cout << std::endl;
}

#endif