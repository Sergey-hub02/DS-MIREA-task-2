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
  void pushFront(Node* node);


  /**
   * Вставляет элемент после элемента под индексом index
   * @param index         индекс элемента, после которого нужно вставить элемент
   * @param node          элемент, который нужно вставить
   */
  void insertAfter(const unsigned& index, Node* node);


  /**
   * Создаёт список на length элементов
   * @param length        длина, создаваемого списка
   */
  void read(const unsigned& length);


  /**
   * Возвращает указатель на элемент, который содержит в себе значение value
   * @param value         значение, по которому осуществляется поиск
   */
  Node* find(const std::string& value) const;


  /**
   * Возвращает указатель на последний элемент списка (может понадобиться для итерации)
   */
  Node* getLastPtr() const;


  /**
   * Возвращает указатель на первый элемент списка (может понадобиться для итерации)
   */
  Node* getFirstPtr() const;
};


/**
 * Выводит список на экран
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list);

#endif
