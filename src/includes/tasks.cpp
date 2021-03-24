#include "./tasks.hpp"

/**
 * Вставляет новый узел в список после последнего узла с таким же
 * номером абонента(дата фактического возврата еще не заполнена)
 *
 * @param list        список, в который нужно вставить элемент
 * @param node        узел, который нужно вставить
 */
void task1(List& list, Node* node) {
  std::string subscr = node->data->subscr;     // номер абонемента
  Node* lastFound = list.find(subscr);    // последний узел с таким же номером абонемента

  // Если я правильно понимаю (что вряд ли возможно), то мне нужно вставить элемент до lastFound
  // т.к. у меня все новые элементы добавляются в начало, поэтому список получается как бы ревёрснутым
  
  // Опять же нужно использовать трюк Вирта
  InfoPart* temp = lastFound->data;

  lastFound->data = node->data;
  node->data = temp;

  node->next = lastFound->next;

  if (node->next != nullptr) {
    node->next->prev = node;
  }

  lastFound->next = node;

  lastFound->next->prev = lastFound;
  ++list.size;
}


/**
 * Изменяет значение поля фактической даты возврата по указанной книге, указанного абонемента
 *
 * @param list        список, в котором происходит изменение
 * @param subscr      номер абонемента
 * @param bookName    название книги
 * @param newRecDate  новая фактическая дата возврата
 */
void task2(List& list, const std::string& subscr, const std::string& bookName, const std::string& newRecDate) {
  Node* iter = list.getLeftPtr();

  while (iter != nullptr) {
    InfoPart* currentData = iter->data;

    if (currentData->subscr == subscr && currentData->bookName == bookName) {
      currentData->recDate = newRecDate;
      break;
    }

    iter = iter->next;
  }

  return;
}


/**
 * Удаляет узлы, в которых дата возврата и дата фактического возврата совпадают
 * @param list        список, в котором происходит удаление
 */
void task3(List& list) {
  Node* iter = list.getLeftPtr();

  while (iter != nullptr) {
    std::string retDate = iter->data->retDate;
    std::string recDate = iter->data->recDate;

    if (retDate == recDate) {
      Node* temp = iter->next;
      list.remove(iter);
      iter = temp;
      continue;
    }

    iter = iter->next;
  }
}


/**
 * Определяет количество книг, заданного абонемента
 * @param list          список, в котором всё происходит
 * @param subscr        номер абонемента
 */
unsigned task4(const List& list, const std::string& subscr) {
  unsigned countBooks = 0;
  Node* iter = list.getLeftPtr();

  while (iter != nullptr) {
    std::string currentSubscr = iter->data->subscr;

    if (currentSubscr == subscr) {
      ++countBooks;
    }

    iter = iter->next;
  }

  return countBooks;
}
