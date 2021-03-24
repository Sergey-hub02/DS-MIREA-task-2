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
void List::pushFront(Node* node) {
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
 * Вставляет элемент после элемента под индексом index
 * @param index         индекс элемента, после которого нужно вставить элемент
 * @param node          элемент, который нужно вставить
 */
void List::insertAfter(const unsigned& index, Node* node) {
  ;
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

    this->pushFront(node);

    std::cout << std::endl;
  }
}


/**
 * Возвращает указатель на элемент, который содержит в себе значение value
 * @param value         значение, по которому осуществляется поиск
 */
Node* List::find(const std::string& value) const {
  // поиск лучше осуществлять справа налево, т.к., если подумать, то в именно в таком порядке добавлялись элементы
  // но в 1-м задании варианта нужно искать последнее вхождение
  // поэтому всё выше сказанное не имеет смысла))
  Node* iter = this->getFirstPtr();

  while (iter != nullptr) {
    InfoPart* currentData = iter->data;   // информационная часть текущего узла

    if (currentData->subscr == value ||
        currentData->bookName == value ||
        currentData->lendDate == value ||
        currentData->retDate == value ||
        currentData->recDate == value
    ) {
      break;
    }

    iter = iter->next;
  }

  return iter;
}


/**
 * Возвращает указатель на последний элемент списка (может понадобиться для итерации)
 */
Node* List::getLastPtr() const {
  Node* iter = this->header;
  while (iter->next != nullptr) {
    iter = iter->next;
  }

  return iter;
}


/**
 * Возвращает указатель на первый элемент списка (может понадобиться для итерации)
 */
Node* List::getFirstPtr() const {
  Node* copyHeader = this->header;
  return copyHeader;
}


/**
 * Выводит список на экран
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list) {
  // Вывод списка слева направо
  Node* iter = list.getFirstPtr();


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
