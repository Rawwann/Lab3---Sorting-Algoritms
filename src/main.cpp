#include <iostream>

#include "linkedlist.h"
using namespace std;

int main() {
  LinkedList l;

  l.append(40);
  l.append(20);
  l.append(50);
  l.append(10);
  l.append(30);

  cout << "Original List: ";
  l.display();
  cout << "\n============================================\n";

  l.bubbleSort();

  cout << "Bubble Sort: ";
  l.display();
  cout << "\n============================================\n";

  l.selectionSort();

  cout << "Selection Sort: ";
  l.display();
  cout << "\n============================================\n";

  int result = l.binarySearch(30);

  if (result != -1) {
    cout << "Found at index: " << result << endl;
  } else {
    cout << "Not found" << endl;
  }

  return 0;
}
