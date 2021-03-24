#include "./InfoPart.hpp"


/**
 * Конструктор по умолчанию
 */
InfoPart::InfoPart() {
  this->subscr = "";
  this->bookName = "";
  this->lendDate = "";
  this->retDate = "";
  this->recDate = "";
}


/**
 * Конструктор, содержащий все параметры информационной части
 * @param subscr        номер абонемента
 * @param bookName      название книги
 * @param lendDate      дата выдачи
 * @param retDate       дата возврата
 * @param recDate       дата фактического возврата
 */
InfoPart::InfoPart(const std::string& subscr
                 , const std::string& bookName
                 , const std::string& lendDate
                 , const std::string& retDate
                 , const std::string& recDate
) {
  this->subscr = subscr;
  this->bookName = bookName;
  this->lendDate = lendDate;
  this->retDate = retDate;
  this->recDate = recDate;
}


/**
 * Возвращает true, если информационные части одинаковы
 * @param other         сравниваемая информационная часть
 */
bool InfoPart::operator==(InfoPart* other) const {
  return (
    this->subscr == other->subscr &&
    this->bookName == other->bookName &&
    this->lendDate == other->lendDate &&
    this->retDate == other->retDate &&
    this->recDate == other->recDate
  );
}


/**
 * Выводит информационную часть узла
 * @param out         поток вывода
 * @param data        информационная часть узла
 */
std::ostream& operator<<(std::ostream& out, InfoPart* data) {
  out << "Номер абонемента: " << data->subscr << std::endl;
  out << "Название книги: " << data->bookName << std::endl;
  out << "Дата выдачи: " << data->lendDate << std::endl;
  out << "Дата возврата: " << data->retDate << std::endl;
  out << "Дата фактического возврата: " << data->recDate;
  return out;
}
