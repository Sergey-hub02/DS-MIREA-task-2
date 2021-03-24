#include "./includes/tasks.hpp"

using namespace std;

int main() {
  unsigned length;

  cout << "Введите длину списка: ";
  cin >> length;

  cout << endl;

  List list;
  list.read(length);

  cout << endl << endl;

  // Здесь начинается управление с помощью текстового меню

  unsigned userChoice;
  
  cout << "Выберите действие:" << endl
       << "  1) Вывести список;" << endl
       << "  2) Найти элемент по заданному значению;" << endl
       << "  3) Вставить новый узел в список после последнего узла с таким же номером абонента;" << endl
       << "  4) Изменить значение поля фактической даты возврата по указанной книге, указанного абонемента;" << endl
       << "  5) Удалить узлы, в которых дата возврата и дата фактического возврата совпадают;" << endl
       << "  6) Определить количество книг, заданного абонемента;" << endl
       << "  7) Выйти из программы." << endl;
  
  cout << endl << "Ваш выбор (1-7): ";
  cin >> userChoice;

  while (userChoice != 7) {
    if (userChoice == 1) {
      cout << endl << "Список:" << endl << list;
    }
    else if (userChoice == 2) {
      string value;

      cout << endl << "Введите значение, по которому будет происходить поиск: ";
      cin >> value;

      Node* foundNode = list.find(value);

      if (foundNode == nullptr) {
        cout << endl << "Значение " << value << " не было найдено в списке!" << endl;
      }
      else {
        cout << endl << "Узел, содержащий значение " << value << ":" << endl << foundNode->data << endl;
      }
    }
    else if (userChoice == 3) {
      string subscr;

      cout << endl << "Введите номер абонемента: ";
      cin >> subscr;

      Node* node = new Node();
      node->data->subscr = subscr;

      task1(list, node);

      cout << endl << "Список после добавления:" << endl << list << endl;
    }

    cout << endl << "Ваш выбор: ";
    cin >> userChoice;
  }

  cout << endl << "Ну всё. До новых встреч! Пока!" << endl;
  return 0;
}
