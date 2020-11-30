#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
    double x;
    double y;
};

Point read_point() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}

struct Rectangle {
    Point p1;
    Point p2;
};

Rectangle read_rect() {
    Rectangle r;
    r.p1 = read_point();
    r.p2 = read_point();
    return r;
}

void normalize(Rectangle* n_rec) {
    Point min;
    Point max;
    //Левая нижняя точка
    min.x = (n_rec->p1.x < n_rec->p2.x) ? n_rec->p1.x : n_rec->p2.x;
    min.y = (n_rec->p1.y < n_rec->p2.y) ? n_rec->p1.y : n_rec->p2.y;
    //Правая верхняя
    max.x = (n_rec->p1.x > n_rec->p2.x) ? n_rec->p1.x : n_rec->p2.x;
    max.y = (n_rec->p1.y > n_rec->p2.y) ? n_rec->p1.y : n_rec->p2.y;
    n_rec->p1 = min;
    n_rec->p2 = max;
}

Rectangle intersection(Rectangle rc1, Rectangle rc2) {
    Rectangle inter;
    inter.p1.x = (rc1.p1.x > rc2.p1.x) ? rc1.p1.x : rc2.p1.x;
    inter.p1.y = (rc1.p1.y > rc2.p1.y) ? rc1.p1.y : rc2.p1.y;
    inter.p2.x = (rc1.p2.x < rc2.p2.x) ? rc1.p2.x : rc2.p2.x;
    inter.p2.y = (rc1.p2.y < rc2.p2.y) ? rc1.p2.y : rc2.p2.y;
    return inter;
}

double solve(Rectangle rec) {
    if (rec.p1.y > rec.p2.y || rec.p1.x > rec.p2.x) {
        return 0;
    }
    else {
        double dx = rec.p2.x - rec.p1.x;
        double dy = rec.p2.y - rec.p1.y;
        return dx * dy;
    }
}

int main() {
    Rectangle rec1 = read_rect();
    Rectangle rec2 = read_rect();
    normalize(&rec1);
    normalize(&rec2);
    Rectangle answer = intersection(rec1, rec2);
    cout << fixed << setprecision(6) << solve(answer);
    return 0;
}
