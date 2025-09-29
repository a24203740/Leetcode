#include "../includes.hpp"
#include <charconv>

class Solution {
public:
  int compareVersion(string version1, string version2) {
    string_view v1(version1), v2(version2);
    int v1n, v2n;
    bool v1e = false, v2e = false;
    while (!v1e || !v2e) {
      int v1v, v2v;
      if (v1e) {
        v1v = 0;
      } else {
        size_t v1s = v1.find('.');
        string_view dv1 = v1.substr(0, v1s);
        from_chars(dv1.begin(), dv1.end(), v1v);
        //cout << "v1: " << endl;
        //cout << dv1 << " " << v1v << endl;
        if (v1s != string::npos) {
          v1.remove_prefix(v1s + 1);
          //cout << "new v1 " << v1 << endl;
        } else
          v1e = true;
      }
      if (v2e) {
        v2v = 0;
      } else {
        size_t v2s = v2.find('.');
        string_view dv2 = v2.substr(0, v2s);
        from_chars(dv2.begin(), dv2.end(), v2v);
        //cout << "v2: " << endl;
        //cout << dv2 << " " << v2v << endl;
        if (v2s != string::npos) {
          v2.remove_prefix(v2s + 1);
          //cout << "new v2 " << v2 << endl;
        } else
          v2e = true;
      }
      if (v1v > v2v)
        return 1;
      else if (v1v < v2v)
        return -1;
    }
    return 0;
  }
};
