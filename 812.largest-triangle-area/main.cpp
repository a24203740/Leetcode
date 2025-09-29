#include "../includes.hpp"
#include <cmath>

struct Point {
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {}
};
class Solution {
public:
  bool isCollinear(Point &p1, Point &p2, Point &p3) {
    if(p2.x == p1.x && p3.x == p2.x) return true;
    if(p2.y == p1.y && p3.y == p2.y) return true;
    return (p2.y - p1.y) * (p3.x - p2.x) ==
           (p3.y - p2.y) * (p2.x - p1.x);
  }
  double area(const vector<vector<double>>& length, int i, int j, int k) {
    double a = length[i][j];
    double b = length[j][k];
    double c = length[k][i];
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }
  double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();
    vector<Point> pts;
    vector<vector<double>> length(n, vector<double>(n, 0));
    for (auto &p : points) {
      pts.emplace_back(p[0], p[1]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        length[i][j] = sqrt(pow(pts[i].x - pts[j].x, 2) +
                            pow(pts[i].y - pts[j].y, 2));
        length[j][i] = length[i][j];
      }
    }
    double maxArea = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (!isCollinear(pts[i], pts[j], pts[k])) {
            double a = area(length, i, j, k);
            maxArea = max(maxArea, a);
          }
        }
      }
    }
    return maxArea;
  }
};
