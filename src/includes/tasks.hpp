#ifndef _TASKS_H_
#define _TASKS_H_

#include "./List/List.hpp"

/**
 * Вставляет новый узел в список после последнего узла с таким же
 * номером абонента(дата фактического возврата еще не заполнена)
 *
 * @param list        список, в который нужно вставить элемент
 * @param node        узел, который нужно вставить
 */
void task1(List& list, Node* node);


#endif
