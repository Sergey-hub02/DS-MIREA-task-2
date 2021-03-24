#include "./List.hpp"

/**
 * Конструктор по умолчанию
 */
List::List() {
  this->size = 0;
  this->header = nullptr;
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

    ++this->size;
    return;
  }

  // список не пуст, поэтому применяем трюк Вирта
  InfoPart* temp = this->header->data;

  this->header->data = node->data;
  node->data = temp;

  node->next = this->header->next;

  if (node->next != nullptr) {
    node->next->prev = node;
  }

  this->header->next = node;

  this->header->next->prev = this->header;
  this->header->prev = nullptr;

  ++this->size;
  return;
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

    std::cout << "Ввдедите дату фактического возврата: ";
    std::cin >> recDate;

    InfoPart* nodeData = new InfoPart(subscr, bookName, lendDate, retDate, recDate);
    Node* node = new Node(nodeData);

    this->push(node);

    std::cout << std::endl;
  }
}


/**
 * Выводит список на экран
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list) {
  // Вывод списка слева направо
  Node* iter = list.header;


  while (iter->next != nullptr) {   // должен остановиться на самом последнем элементе
    out << iter->data << std::endl << std::endl;
    iter = iter->next;
  }

  out << iter->data << std::endl << std::endl;

  // Вывод списка справа налево
  while (iter != nullptr) {
    out << iter->data << std::endl << std::endl;
    iter = iter->prev;
  }

  out << std::endl;
  return out;
}
