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
 * Конструктор почти со всеми параметрами
 * @param subscr        номер абонемента
 * @param bookName      название книги
 * @param lendDate      дата выдачи
 * @param retDate        дата возврата
 * @param recDate       дата фактического возврата
 */
Node::Node(const std::string& subscr,
           const std::string& bookName,
           const std::string& lendDate,
           const std::string& retDate,
           const std::string& recDate
) {
  this->data     = new InfoPart(subscr, bookName, lendDate, retDate, recDate);
  this->prev     = nullptr;
  this->next     = nullptr;
}
