#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;

    Point(): x(0), y(0) {};
    Point(int x1, int y1): x(x1), y(y1) {};

    void print() {
        std::cout << x << " " << y << std::endl;
    }
};

bool myless (const Point left, const Point right) {
    return (left.x < right.x) || (left.x == right.x && left.y < right.y);
}

void point_sort(std::vector<Point>& vect) {

        for (int i = 1; i < vect.size(); ++i) {
            int j = 0;
            Point tmp = vect[i];
            for (j = i; j > 0 && myless(tmp, vect[j-1]); --j)
                vect[j] = vect[j-1];
            vect[j] = tmp;
    }
}

int main() {
    size_t n;
    Point point;

    std::cin >> n;

    std::vector<Point> point_vect;

    for (size_t i = 0; i < n; i++) {
        std::cin >> point.x >> point.y;
        point_vect.push_back(point);
    }

    point_sort(point_vect);

    for (size_t i = 0; i < point_vect.size(); i++)
        point_vect[i].print();

    return 0;
};
