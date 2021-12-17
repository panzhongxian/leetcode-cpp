#include "base.h"
typedef base::BiDirListNode<pair<int, int>> BiDirListNode;

class DoubleLinkedList {
 public:
  DoubleLinkedList(int capacity) {
    head = new BiDirListNode;
    tail = new BiDirListNode;
    head->next = tail;
    tail->prev = head;
    this->capacity = capacity;
    length = 0;
  }

  BiDirListNode* GetTail() {
    if (length == 0) {
      return nullptr;
    }
    return tail->prev;
  }

  bool IsFull() { return capacity == length; }

  // return whethe it is full;
  void PushHead(BiDirListNode* node) {
    node->next = head->next;
    node->prev = head;
    head->next = node;
    node->next->prev = node;

    if (length == capacity) {
      auto prev_prev = tail->prev->prev;
      prev_prev->next = tail;
      delete tail->prev;
      tail->prev = prev_prev;
    } else {
      length++;
    }
  }
  void MoveToHead(BiDirListNode* node) {
    auto prev = node->prev;
    auto next = node->next;
    next->prev = prev;
    prev->next = next;
    length--;
    PushHead(node);
  }

 private:
  BiDirListNode* head;
  BiDirListNode* tail;
  int capacity;
  int length;
};

class LRUCache {
 public:
  LRUCache(int capacity) { list = new DoubleLinkedList(capacity); }

  int get(int key) {
    if (kv.count(key) == 0) {
      return -1;
    } else {
      list->MoveToHead(kv[key]);
      return kv[key]->val.second;
    }
  }

  void put(int key, int value) {
    if (kv.count(key) > 0) {
      list->MoveToHead(kv[key]);
      kv[key]->val.second = value;
      return;
    }

    if (list->IsFull()) {
      auto tail_node = list->GetTail();
      kv.erase(kv.find(tail_node->val.first));
    }
    cout << "PushHead" << endl;
    auto new_node = new BiDirListNode(pair<int, int>(key, value));
    list->PushHead(new_node);
    kv[key] = new_node;
  }

 private:
  DoubleLinkedList* list;
  map<int, BiDirListNode*> kv;
};
