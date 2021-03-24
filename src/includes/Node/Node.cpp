#include "./Node.hpp"

/**
 * Конструктор по умолчанию
 */
Node::Node() {
  this->data     = new InfoPart();
  this->prev     = nullptr;
  this->next     = nullptr;
}

/**
 * Конструктор, создающий узел, содержащий только информационную часть
 * @param data        информационная часть узла
 */
Node::Node(InfoPart* data) {
  this->data     = data;
  this->prev     = nullptr;
  this->next     = nullptr;
}
