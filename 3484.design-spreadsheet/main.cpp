#include "../includes.hpp"
#include <charconv>
#include <string_view>

class Spreadsheet {
public:
  array<vector<int>,26> cells;
  Spreadsheet(int rows) {
    cells.fill(vector<int>(rows+1,0));
  }

  void setCell(const string& cell, int value) {
    int code = cell[0] - 'A';
    int offset = stoi(cell.substr(1));
    cells[code][offset] = value; 
  }

  void resetCell(const string& cell) {
    setCell(cell, 0);
  }

  int getValue(const string& formula) {
    string_view sv = formula;
    string_view lop = sv, rop = sv;
    size_t plus = sv.find("+");
    lop = lop.substr(0, plus);
    lop.remove_prefix(1);
    rop = rop.substr(plus+1);
    int lopval = 0, ropval = 0;
    if(isalpha(lop[0])) {
      int code = lop[0] - 'A';
      int offset;
      from_chars(lop.data() + 1, lop.data() + lop.size(), offset);
      lopval = cells[code][offset];
    }
    else {
      from_chars(lop.data(), lop.data() + lop.size(), lopval);
    }
    if(isalpha(rop[0])) {
      int code = rop[0] - 'A';
      int offset;
      from_chars(rop.data() + 1, rop.data() + rop.size(), offset);
      ropval = cells[code][offset];
    }
    else {
      from_chars(rop.data(), rop.data() + rop.size(), ropval);
    }
    return lopval + ropval;

  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
