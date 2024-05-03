#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};
    
int ort(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0)
        return 0; 
    return (val > 0) ? 1 : 2; 
}


int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}


Point findPivot(vector<Point>& points) {
    Point pivot = points[0];
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].y < pivot.y || (points[i].y == pivot.y && points[i].x < pivot.x)) {
            pivot = points[i];
        }
    }
    return pivot;
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    Point pivot = findPivot(points);

    
    sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {
        int o = ort(pivot, a, b);
        if (o == 0)
            return (distSq(pivot, a) < distSq(pivot, b));
        return (o == 2);
    });

    
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

  
    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && ort(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    return hull;
}

void printPoints(vector<Point>& points) {
    for (const auto& p : points) {
        cout << "(" << p.x << "," << p.y << ")\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> points[i].x >> c >> points[i].y >> c;
    }

  
    vector<Point> convexPoints = convexHull(points);

    
    sort(convexPoints.begin(), convexPoints.end(), [](const Point& a, const Point& b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

   
    printPoints(convexPoints);
    
    return 0;
}