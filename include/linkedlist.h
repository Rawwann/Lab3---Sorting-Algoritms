#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node {
 public:
  int data;
  Node* prev;
  Node* next;
  Node();
};

class LinkedList {
 private:
  Node* head;
  Node* tail;

 public:
  LinkedList();
  ~LinkedList();
  void append(int data);
  void display();
  int getCount();
  void swap(int& x, int& y);
  void bubbleSort();
  void selectionSort();
  Node* getNodeAt(int index);
  int binarySearch(int target);
};

#endif