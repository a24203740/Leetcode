#include "../includes.hpp"

using ll = long long;
using HASHED = long long;
using RATE = int;
constexpr ll mypow(int a, int b) {
  if(b == 0) return 1;
  return a * mypow(a, b - 1);
}
constexpr ll MAX = mypow(27, 9);

HASHED myhash (const string& s) {
  ll num = MAX;
  HASHED res = 0;
  for (char c : s) {
    res += (c - 'a' + 1) * num;
    num /= 27;
  }
  return res;
}
class FoodRatings {
public:
  unordered_map<HASHED, size_t> cousine_map;
  vector<map<int, set<HASHED>>> rating_map; // cousine_index -> m: rating -> m: (food_hash)
  unordered_map<HASHED, tuple<int, size_t, size_t>> food_rating_map; // food_hash -> (rating, cousine_index, food_index)
  vector<string> foods_list;
  vector<string> cousine_list;

  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    for (size_t i = 0; i < foods.size(); i++) {
      HASHED c = myhash(cuisines[i]);
      auto corr_map_it = cousine_map.find(c);
      if (corr_map_it == cousine_map.end()) {
        corr_map_it = cousine_map.emplace(c, rating_map.size()).first;
        rating_map.emplace_back();
      }
      auto& corr_map = rating_map[corr_map_it->second];
      HASHED h = myhash(foods[i]);
      auto corr_set = corr_map.find(ratings[i]);
      if (corr_set == corr_map.end()) {
        corr_set = corr_map.emplace(ratings[i], set<HASHED>()).first;
      }
      corr_set->second.emplace(h);

      food_rating_map.emplace(h, make_tuple(ratings[i], corr_map_it->second, i));
    }
    foods_list = std::move(foods);
    cousine_list = std::move(cuisines);
  }

  void changeRating(const string& food, int newRating) {
    HASHED h = myhash(food);
    auto [oldRating, corr_map_idx, food_idx] = food_rating_map[h];
    // cout << oldRating << " " << newRating << endl;
    if (oldRating == newRating) return;
    food_rating_map[h] = make_tuple(newRating, corr_map_idx, food_idx);
    auto& corr_map = rating_map[corr_map_idx];
    auto& corr_set = corr_map[oldRating];

    auto new_set_it = corr_map.find(newRating);
    if (new_set_it == corr_map.end()) {
      new_set_it = corr_map.emplace(newRating, set<HASHED>()).first;
    }
    auto& new_set = new_set_it->second;
    corr_set.erase(h);
    new_set.emplace(h);
    if (corr_set.empty()) {
      corr_map.erase(oldRating);
    }
  }

  string highestRated(const string& cuisine) {
    HASHED c = myhash(cuisine);
    auto& corr_map = rating_map[cousine_map[c]];
    auto largest_rating_set = corr_map.rbegin()->second;
    auto corr_food_hashed = *largest_rating_set.begin();
    size_t corr_food_it;
    std::tie(std::ignore, std::ignore, corr_food_it) = food_rating_map[corr_food_hashed];
    return foods_list[corr_food_it];
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
