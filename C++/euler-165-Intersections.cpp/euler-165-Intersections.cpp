#include <iostream>
#include <set>
#include <utility>
#include <cstdlib>

using namespace std;

#define fst first
#define snd second

using Point = pair<double, double>;

double cross(const Point& a, const Point& b, const Point& c) {
    return (b.fst - a.fst) * (c.snd - b.snd) - (b.snd - a.snd) * (c.fst - b.fst);
}

Point solve(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    if (cross(p1, p2, p3) * cross(p1, p2, p4) < 0 && cross(p3, p4, p1) * cross(p3, p4, p2) < 0) {
        double pa = p1.snd - p2.snd, pb = p2.fst - p1.fst, pc = p1.fst * p2.snd - p2.fst * p1.snd;
        double qa = p3.snd - p4.snd, qb = p4.fst - p3.fst, qc = p3.fst * p4.snd - p4.fst * p3.snd;
        double xa = pb * qc - qb * pc, xb = pc * qa - qc * pa, xc = pa * qb - qa * pb;
        return {xa / xc, xb / xc};
    }
    return {-1, -1};
}

int main(int argc, char* argv[]) {
    // Check if the required command-line argument is provided
    if (argc != 2) {
        cout << "Usage: ./euler-165-Intersections <value_of_n>" << endl;
        return 0;
    }

    // Parse the command-line argument
    char* endptr;
    int n = strtol(argv[1], &endptr, 10);

    // Check for input errors
    if (*endptr != '\0' || n < 1) {
        cout << "Error: Invalid input. Please enter a valid number" << endl;
        return 0;
    }

    int s[n * 4 + 10];
    Point p[n * 2 + 10];

    s[0] = 290797;
    for (int i = 0; i < n * 4; ++i)
        s[i + 1] = (long long)s[i] * s[i] % 50515093;
    for (int i = 1; i <= n * 2; ++i)
        p[i] = {s[2 * i - 1] % 500, s[2 * i - 0] % 500};

    set<pair<double, double>> S;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto x = solve(p[i * 2 + 1], p[i * 2 + 2], p[j * 2 + 1], p[j * 2 + 2]);
            S.insert(x);
        }
    }
    cout << S.size() - 1 << endl;

    return 0;
}
