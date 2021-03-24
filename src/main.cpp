#include "./includes/List/List.hpp"

using namespace std;

int main() {
  unsigned length;

  cout << "Введите длину списка: ";
  cin >> length;

  cout << endl;

  List list;
  list.read(length);

  cout << list.size << endl;
  cout << list << endl;
  return 0;
}
