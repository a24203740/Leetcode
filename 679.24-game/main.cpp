#include "../includes.hpp"

class Solution {
public:
  bool judgePoint24(vector<int> &cards) {
    vector<double> cardValues;
    for(auto card : cards) {
      cardValues.push_back(static_cast<double>(card));
    }
    array<int, 3> operations;
    char operationsChars[] = {'+', '-', '*', '/'};
    // array<array<int, 3>, 6> orderings = {{
    //   {0, 1, 2},
    //   {0, 2, 1},
    //   {1, 0, 2},
    //   {1, 2, 0},
    //   {2, 0, 1}, // same as 0, 2, 1
    //   {2, 1, 0}
    // }};
    auto iterate = [&](array<int, 3> &op) -> bool {
      int i = 0;
      while(i < 3) {
        op[i]++;
        if(op[i] >= 4 && i != 2) {
          op[i] = 0;
          i++;
        }
        else break;
      }
      return op[2] < 4;
    };
    auto performOperation = [&](double a, double b, int op) -> double {
      if (a == -1e9 || b == -1e9) return -1e9; // Invalid operation
      switch(op) {
        case 0: return a + b; // +
        case 1: return a - b; // -
        case 2: return a * b; // *
        case 3: return (b != 0) ? a / b : -1e9;
      }
      return 0;
    };
    auto calculate = [&](const array<int, 3> &op) -> bool {
      {
        double tp = performOperation(cardValues[0], cardValues[1], op[0]);
        tp = performOperation(tp, cardValues[2], op[1]);
        tp = performOperation(tp, cardValues[3], op[2]);
        if (abs(tp - 24) < 1e-4) return true;
        // cout << "1: " << tp << endl;
      }
      {
        double tp = performOperation(cardValues[0], cardValues[1], op[0]);
        double tp2 = performOperation(cardValues[2], cardValues[3], op[2]);
        tp = performOperation(tp, tp2, op[1]);
        if (abs(tp - 24) < 1e-4) return true;
        // cout << "2: " << tp << endl;
      }
      {
        double tp = performOperation(cardValues[1], cardValues[2], op[1]);
        tp = performOperation(cardValues[0], tp, op[0]);
        tp = performOperation(tp, cardValues[3], op[2]);
        if (abs(tp - 24) < 1e-4) return true;
        // cout << "3: " << tp << endl;
      }
      {
        double tp = performOperation(cardValues[1], cardValues[2], op[1]);
        tp = performOperation(tp, cardValues[3], op[2]);
        tp = performOperation(cardValues[0], tp, op[0]);
        if (abs(tp - 24) < 1e-4) return true;
        // cout << "4: " << tp << endl;
      }
      {
        double tp = performOperation(cardValues[2], cardValues[3], op[2]);
        tp = performOperation(cardValues[1], tp, op[1]);
        tp = performOperation(cardValues[0], tp, op[0]);
        if (abs(tp - 24) < 1e-4) return true;
        // cout << "5: " << tp << endl;
      }
      return false; 
    };
    sort(cardValues.begin(), cardValues.end());
    do {
      operations = {0, 0, 0}; // Reset operations
      do {
        // for(int i = 0; i < 4; i++) {
        //   // cout << cards[i] << " ";
        //   if (i < 3) {
        //     // cout << operationsChars[operations[i]] << " ";
        //   }
        // }
        // // cout << endl;
        bool res = calculate(operations);
        if (res) {
          // cout << "Found a solution!" << endl;
          return true;
        }
      }while (iterate(operations));
    }while (next_permutation(cardValues.begin(), cardValues.end()));
    return false;
  }
};
