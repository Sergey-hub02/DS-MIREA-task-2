#ifndef _LIST_H_
#define _LIST_H_

#include "../Node/Node.hpp"

struct List {
  unsigned size;      // размер списка
  Node* header;       // указатель на начальный элемент списка


  /**
   * Конструктор по умолчанию
   */
  List();


  /**
   * Деструктор для освобождения памяти
   */
  ~List();


  /**
   * Добавляет элемент в начало списка
   * @param node        добавляемый элемент
   */
  void push(Node* node);


  /**
   * Создаёт список на length элементов
   * @param length        длина, создаваемого списка
   */
  void read(const unsigned& length);
};


/**
 * Выводит список на экран
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list);

#endif
