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
  ++list.size;
}
