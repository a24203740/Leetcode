#include "../includes.hpp"
#include <cctype>

using ll = long long;
using wordlistIndex = size_t;
const ll BASE = 53; // alphabet and period (.)
// 53^7 < 2^64
class Solution {
public:
  ll hash(const string &s) {
    if (s.empty())
      return 0;

    ll h = 0;
    for (char c : s) {
      ll val = 0;
      if (c == '.')
        val = 53;
      else if (islower(c))
        val = c - 'a' + 1;
      else if (isupper(c))
        val = c - 'A' + 1 + 26;
      h = h * BASE + val;
    }
    return h;
  }
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    auto strToLower = [](string &s) {
      for (char &c : s)
        c = tolower(c);
    };
    auto strToVoweless = [](string &s) {
      for (char &c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
          c = '.';
    };
    auto createIfNotExist = [](unordered_map<ll, wordlistIndex> &m, ll h, wordlistIndex it) {
      if (m.count(h) == 0) {
        m.emplace(h, it);
      }
      return;
    };
    unordered_map<ll, wordlistIndex> exact, caseCorrection, vowelCorrection;
    vector<string> ans;
    ans.reserve(queries.size());
    wordlistIndex n = wordlist.size();
    for (wordlistIndex it = 0; it < n; it++) {
      string& word = wordlist[it];

      string lowerWord = word;
      strToLower(lowerWord);

      // replace vowels and match is also case insensitive
      string vowelWord = lowerWord;
      strToVoweless(vowelWord);

      ll hashVal = hash(word);
      ll hashValLower = hash(lowerWord);
      ll hashValVowel = hash(vowelWord);

      createIfNotExist(exact, hashVal, it);
      createIfNotExist(caseCorrection, hashValLower, it);
      createIfNotExist(vowelCorrection, hashValVowel, it);
    }
    for (string &query : queries) {
      ll hashVal = hash(query);
      if (exact.count(hashVal)) {
        wordlistIndex it = exact[hashVal];
        ans.push_back(wordlist[it]);
        continue;
      }

      strToLower(query); // we don't need original query anymore so just modify it, avoid copy
      ll hashValLower = hash(query);
      if (caseCorrection.count(hashValLower)) {
        wordlistIndex it = caseCorrection[hashValLower];
        ans.push_back(wordlist[it]);
        continue;
      }

      strToVoweless(query);
      hashValLower = hash(query);
      if (vowelCorrection.count(hashValLower)) {
        wordlistIndex it = vowelCorrection[hashValLower];
        ans.push_back(wordlist[it]);
        continue;
      }

      ans.push_back("");
    }
    return ans;
  }
};
