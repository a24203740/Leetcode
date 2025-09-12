#include "../includes.hpp"

using languageSet = bitset<512>;
class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    int people = languages.size();
    vector<vector<int>> djmat(people, vector<int>(people));
    vector<languageSet> knownLanguages(people);
    for(int i = 0; i < people; ++i) {
      knownLanguages[i].reset();
      for(int lang : languages[i]) {
        knownLanguages[i].set(lang);
      }
    }
    int teachPeople = 1e9;
    bitset<512> relationPeople;
    for(const auto &edge: friendships) {
      int u = edge[0] - 1, v = edge[1] - 1;
      if((knownLanguages[u] & knownLanguages[v]).any()) continue;
      relationPeople.set(u);
      relationPeople.set(v);
    }
    vector<int> langTeach(n + 1);
    for (int i = 0; i < people; ++i) {
      if(!relationPeople.test(i)) continue;
      for(int lang = 1; lang <= n; ++lang) {
        if(!knownLanguages[i].test(lang)) {
          langTeach[lang]++;
        }
      }
    }
    for(int lang = 1; lang <= n; ++lang) {
      teachPeople = min(teachPeople, langTeach[lang]);
    }
    return teachPeople == 1e9 ? 0 : teachPeople;
  }
};
