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


/**
 * Изменяет значение поля фактической даты возврата по указанной книге, указанного абонемента
 *
 * @param list        список, в котором происходит изменение
 * @param subscr      номер абонемента
 * @param bookName    название книги
 * @param newRecDate  новая фактическая дата возврата
 */
void task2(List& list, const std::string& subscr, const std::string& bookName, const std::string& newRecDate);


/**
 * Удаляет узлы, в которых дата возврата и дата фактического возврата совпадают
 * @param list        список, в котором происходит удаление
 */
void task3(List& list);


#endif
