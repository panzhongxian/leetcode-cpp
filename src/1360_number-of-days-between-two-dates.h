#include "base.h"
#include <time.h>

typedef struct tm tm;
class Solution {
public:
  int daysBetweenDates(string date1, string date2) {
    tm t1, t2;
    memset(&t1, 0, sizeof(tm));
    memset(&t2, 0, sizeof(tm));
    strptime(date1.c_str(), "%Y-%m-%d", &t1);
    strptime(date2.c_str(), "%Y-%m-%d", &t2);
    cout << "year:" << t2.tm_year << endl;
    cout << static_cast<int64_t>(mktime(&t2)) << endl;
    return (mktime(&t2) - mktime(&t1)) / 24 / 3600;
  }
};
