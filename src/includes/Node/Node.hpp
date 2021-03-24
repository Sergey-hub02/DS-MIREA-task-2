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
   * Конструктор почти со всеми параметрами
   * @param subscr        номер абонемента
   * @param bookName      название книги
   * @param lendDate      дата выдачи
   * @param retDate        дата возврата
   * @param recDate       дата фактического возврата
   */
  Node(const std::string& subscr,
       const std::string& bookName,
       const std::string& lendDate,
       const std::string& retDate,
       const std::string& recDate
  );
};

#endif
