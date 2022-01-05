#include "base.h"

#include <unistd.h>
class Foo {
 public:
  Foo() : last_finished_step(0) {}

  void first(function<void()> printFirst) {
    while (last_finished_step != 0) {
      usleep(1000);
    }

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    last_finished_step++;
  }

  void second(function<void()> printSecond) {
    while (last_finished_step != 1) {
      usleep(1000);
    }

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    last_finished_step++;
  }

  void third(function<void()> printThird) {
    while (last_finished_step != 2) {
      usleep(1000);
    }

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    last_finished_step++;
  }

 private:
  int last_finished_step;
};
