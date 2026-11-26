#include "linkedlist.h"

#include <iostream>
using namespace std;

Node::Node() {
  next = nullptr;
  prev = nullptr;
  data = 0;
}

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  tail = nullptr;
}

void LinkedList::append(int data) {
  Node* current = new Node;
  current->data = data;

  if (head == nullptr && tail == nullptr) {
    head = current;
    tail = current;
  } else {
    tail->next = current;
    current->prev = tail;
    tail = current;
  }
}

void LinkedList::display() {
  if (head == nullptr) {
    return;
  }
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->next != nullptr) {
      cout << "<->";
    }
    temp = temp->next;
  }
}

int LinkedList::getCount() {
  Node* temp = head;
  int count = 0;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

void LinkedList::swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

void LinkedList::bubbleSort() {
  /* Bubble Sort: compares adjacent elements, and swaps them if they are in the
   wrong order until the entire list is sorted.
    Pass 1:
    Before: [4]──[2]──[5]──[1]──[3]
    After:  [2]──[4]──[1]──[3]──[5]
                                 ^sorted
*/
  if (head == nullptr) return;

  bool swapped;

  do {
    swapped = false;
    Node* current = head;
    while (current->next != nullptr) {
      if (current->data > current->next->data) {
        swap(current->data, current->next->data);
        swapped = true;
      }
      current = current->next;
    }
  } while (swapped);
}

void LinkedList::selectionSort() {
  /*Selection:Find the minimum of the rest, put it in place
Before: [4]──[2]──[5]──[1]──[3]
After:  [1]──[2]──[5]──[4]──[3]
         ^sorted*/
  Node* current = head;
  while (current != nullptr) {
    Node* minNode = current;
    Node* temp = current->next;
    while (temp != nullptr) {
      if (temp->data < minNode->data) {
        minNode = temp;
      }
      temp = temp->next;
    }

    if (minNode != current) {
      int value = current->data;
      current->data = minNode->data;
      minNode->data = value;
    }
    current = current->next;
  }
}

Node* LinkedList::getNodeAt(int index) {
  Node* current = head;
  for (int i = 0; i < index; i++) {
    if (current == nullptr) return nullptr;
    current = current->next;
  }
  return current;
}

int LinkedList::binarySearch(int target) {
  /*
   Search for 4 in [1, 2, 3, 4, 5]:
   Step 1: low=0, high=4, mid=2 → 3 < 4 → low = 3
   Step 2: low=3, high=4, mid=3 → 4 == 4 → return 3
   [1]  [2]  [3]  [4]  [5]
              M         (discard left)
                   L,M   H  (found)
*/
  int low = 0;
  int high = getCount() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    Node* middle = getNodeAt(mid);

    if (middle->data == target) {
      return mid;
    }

    else if (middle->data < target) {
      low = mid + 1;
    }

    else {
      high = mid - 1;
    }
  }

  return -1;
}