#ifndef _NODE_H_
#define _NODE_H_

#include "../InfoPart/InfoPart.hpp"

struct Node {
  Node* prev;               // указатель на предыдущий элемент списка
  Node* next;               // указатель на следующий элемент списка
  InfoPart* data;           // информационная часть узла


  /**
   * Конструктор по умолчанию
   */
  Node();

  /**
   * Конструктор, создающий узел, содержащий только информационную часть
   * @param data        информационная часть узла
   */
  Node(InfoPart* data);
};

#endif
