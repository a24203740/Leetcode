#include "../includes.hpp"

using movieID = pair<int, int>; // movie, shop
using moviePrice = pair<int, int>; // price, shop
using rentedMovie = tuple<int, int, int>; // price, shop, movie
using movieInfo = tuple<int, bool, bool, bool>; // price, rented, markedAsRented, markedAsOnShelf
struct hash_pair final {
  template<class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const noexcept {
    return (p.first << 7) ^ 1317 ^ (p.second >> 1);
  }
};

inline movieInfo decode(int val) {
  int price = val >> 3;
  bool rented = (val >> 2) & 1;
  bool markedAsRented = (val >> 1) & 1;
  bool markedAsOnShelf = val & 1;
  return {price, rented, markedAsRented, markedAsOnShelf};
}
inline int encode(const movieInfo &info) {
  auto [price, rented, markedAsRented, markedAsOnShelf] = info;
  return (price << 3) | (rented << 2) | (markedAsRented << 1) | markedAsOnShelf;
}
inline int encode(int price, bool rented, bool markedAsRented, bool markedAsOnShelf) {
  return (price << 3) | (rented << 2) | (markedAsRented << 1) | markedAsOnShelf;
}
class MovieRentingSystem {
public:
  unordered_map<movieID, int, hash_pair> moviePriceMap; // (movie, shop) -> (price, rented, markedAsRented, markedAsOnShelf)
  vector<priority_queue<moviePrice, vector<moviePrice>, greater<moviePrice>>> movieShelf; // movie -> min-heap of (price, shop)
  priority_queue<rentedMovie, vector<rentedMovie>, greater<rentedMovie>> rentedMovies; // min-heap of (price, shop, movie)
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    moviePriceMap.reserve(entries.size() * 3);
    movieShelf.reserve(10001);
    int m = entries.size();
    for (int i = 0; i < m; i++) {
      const auto &entry = entries[i];
      int shop = entry[0], movie = entry[1], price = entry[2];
      movieID id = make_pair(movie, shop);
      int info = encode(price, false, false, true);
      moviePriceMap.emplace(id, info);
      if(movie >= movieShelf.size()) {
        movieShelf.resize(movie + 1);
      }
      movieShelf[movie].emplace(price, shop);
    }
  }

  vector<int> search(int movie) {
    int count = 0;
    vector<int> result; result.reserve(5);
    vector<moviePrice> temp; temp.reserve(5);
    if(movie >= movieShelf.size()) return result;
    auto &pq = movieShelf[movie];
    while (!pq.empty() && count < 5) {
      auto [price, shop] = pq.top(); pq.pop();
      movieID id = make_pair(movie, shop);
      auto& info = moviePriceMap[id];
      auto [curPrice, rented, markedAsRented, markedAsOnShelf] = decode(info);
      if(rented) {
        // lazy removal finalize
        markedAsOnShelf = false;
        info = encode(curPrice, rented, markedAsRented, markedAsOnShelf);
      } else {
        result.push_back(shop);
        temp.emplace_back(price, shop);
        count++;
      }
    }
    for (const auto &item: temp) {
      pq.push(item);
    }
    return result;
  }

  void rent(int shop, int movie) {
    movieID id = make_pair(movie, shop);
    auto& info = moviePriceMap[id];
    auto [p, rented, markedAsRented, markedAsOnShelf] = decode(info);
    rented = true;
    if(!markedAsRented) {
      // the movie is not in rented list
      rentedMovies.emplace(p, shop, movie);
    }
    markedAsRented = true;
    info = encode(p, rented, markedAsRented, markedAsOnShelf);
    // no need to remove the movie from shelf, using lazy removal
  }

  void drop(int shop, int movie) {
    movieID id = make_pair(movie, shop);
    auto &info = moviePriceMap[id];
    auto [p, rented, markedAsRented, markedAsOnShelf] = decode(info);
    rented = false;
    if(!markedAsOnShelf) {
      // the movie is not on shelf (already removed by search), put it back
      movieShelf[movie].emplace(p, shop);
    }
    markedAsOnShelf = true;
    info = encode(p, rented, markedAsRented, markedAsOnShelf);
  }

  vector<vector<int>> report() {
    int count = 0;
    vector<vector<int>> result; result.reserve(5);
    vector<rentedMovie> temp; temp.reserve(5);
    auto &pq = rentedMovies;
    while (!pq.empty() && count < 5) {
      auto [price, shop, movie] = pq.top(); pq.pop();
      movieID id = make_pair(movie, shop);
      auto& info= moviePriceMap[id];
      auto [curPrice, rented, markedAsRented, markedAsOnShelf] = decode(info);
      if(!rented) {
        // lazy removal finalize
        markedAsRented = false;
        info = encode(curPrice, rented, markedAsRented, markedAsOnShelf);
      } else {
        result.push_back(vector<int>{shop, movie});
        temp.emplace_back(price, shop, movie);
        count++;
      }
    }
    for (const auto &item: temp) {
      pq.push(item);
    }
    return result;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
