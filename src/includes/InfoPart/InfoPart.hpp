#ifndef _INFO_PART_
#define _INFO_PART_

#include <string>
#include <iostream>

struct InfoPart {
  std::string subscr;       // номер абонемента
  std::string bookName;     // название книги
  std::string lendDate;     // дата выдачи книги
  std::string retDate;      // дата возврата
  std::string recDate;      // дата фактического возврата


  /**
   * Конструктор по умолчанию
   */
  InfoPart();


  /**
   * Конструктор, содержащий все параметры информационной части
   * @param subscr        номер абонемента
   * @param bookName      название книги
   * @param lendDate      дата выдачи
   * @param retDate       дата возврата
   * @param recDate       дата фактического возврата
   */
  InfoPart(const std::string& subscr,
           const std::string& bookName,
           const std::string& lendDate,
           const std::string& retDate,
           const std::string& recDate
  );


  /**
   * Возвращает true, если информационные части одинаковы
   * @param other         сравниваемая информационная часть
   */
  bool operator==(InfoPart* other) const;
};


/**
 * Выводит информационную часть узла
 * @param out         поток вывода
 * @param data        информационная часть узла
 */
std::ostream& operator<<(std::ostream& out, InfoPart* data);

#endif
