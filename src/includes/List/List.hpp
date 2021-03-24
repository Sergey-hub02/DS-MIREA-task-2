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
   * Удаляет указанный элемент из списка
   * @param node        удаляемый элемент
   */
  void remove(Node* node);


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
   * Возвращает указатель на node, если такое узел есть в списке
   * @param node        элемент, указатель которого нужно вернуть
   */
  Node* find(Node* node) const;


  /**
   * Возвращает указатель на самый первый элемент списка (может понадобиться для итерации справа налево)
   */
  Node* getRightPtr() const;


  /**
   * Возвращает указатель на последний элемент списка (может понадобиться для итерации слева направо)
   */
  Node* getLeftPtr() const;
};


/**
 * Выводит список на экран
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list);

#endif
