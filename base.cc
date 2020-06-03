#include "base.h"

namespace base {
template ostream &operator<<<int>(ostream &os, const vector<int> &v);
template ostream &operator<<<vector<int>>(ostream &os,
                                          const vector<vector<int>> &v);
}  // namespace base
