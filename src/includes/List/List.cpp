#include "./List.hpp"

/**
 * Конструктор по умолчанию
 */
List::List() {
  this->size = 0;
  this->header = nullptr;
  this->header->next = nullptr;
  this->header->prev = nullptr;
}

/**
 * Деструктор для освобождения памяти
 */
List::~List() {
  while (this->header != nullptr) {
    Node* temp = this->header->next;
    delete this->header;
    this->header = temp;
  }
}


/**
 * Добавляет элемент в начало списка
 * @param node        добавляемый элемент
 */
void List::push(Node* node) {
  if (this->header == nullptr) {        // список пустой
    this->header = node;
    this->header->next = nullptr;
    this->header->prev = nullptr;
  }

  // список не пуст, поэтому применяем трюк Вирта
  Node* temp = this->header;

  this->header->subscr = node->subscr;
  this->header->bookName = node->bookName;
  this->header->lendDate = node->lendDate;
  this->header->retDate = node->retDate;
  this->header->recDate = node->recDate;

  node->subscr = temp->subscr;
  node->bookName = temp->bookName;
  node->lendDate = temp->lendDate;
  node->retDate = temp->retDate;
  node->recDate = temp->recDate;

  node->next = this->header->next;
  this->header = node;

  this->header->prev = nullptr;
  node->prev = this->header;
}


/**
 * Создаёт список на length элементов
 * @param length        длина, создаваемого списка
 */
void List::read(const unsigned& length) {
  for (unsigned i = 0; i < length; ++i) {
    std::string subscr;
    std::string bookName;
    std::string lendDate;
    std::string retDate;
    std::string recDate;

    std::cout << "Введите номер абонемента: ";
    std::cin >> subscr;

    std::cout << "Введите название книги: ";
    std::cin >> bookName;

    std::cout << "Введите дату выдачи: ";
    std::cin >> lendDate;

    std::cout << "Введите дату возврата: ";
    std::cin >> retDate;

    std::cout << "Введите дату фактического возврата: ";
    std::cin >> recDate;

    std::cout << std::endl;

    Node* node = new Node(subscr, bookName, lendDate, retDate, recDate);

    this->push(node);
  }
}


/**
 * Выводит список на экран
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list) {
  Node* iter = list.header;

  out << "[ " << iter->subscr;
  iter = iter->next;

  while (iter != nullptr) {
    out << ", " << iter->subscr;
    iter = iter->next;
  }

  out << " ]" << std::endl;

  iter = iter->prev;
  out << "[ " << iter->subscr;

  iter = iter->prev;
  while (iter != nullptr) {
    out << ", " << iter->subscr;
    iter = iter->next;
  }

  out << " ]";

  return out;
}
