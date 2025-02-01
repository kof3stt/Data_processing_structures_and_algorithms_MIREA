#include "Triangle.h"
#include <algorithm>
#include <iostream>
void generate_permutations(vector <Triangle>& figures,vector <Point> data, int m)
{
    vector <int> temp;
    vector<bool> v(data.size());
    fill(v.end() - m, v.end(), true);
    do {
        for (int i = 0; i < data.size(); ++i) 
        {
            if (v[i]) 
            {
                temp.push_back(i);
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    for (int i = 0; i < temp.size(); i += 3)
    {
        Triangle ABC;
        ABC.A = data[temp[i]];
        ABC.B = data[temp[i+1]];
        ABC.C = data[temp[i+2]];
        figures.push_back(ABC);
    }
}

void output_permutations(vector<Triangle> figures)
{
    for (int i = 0; i < figures.size(); i++)
    {
        cout << "((" << figures[i].A.x << "," << figures[i].A.y << "), (" << figures[i].B.x << "," << figures[i].B.y << "), (" << figures[i].C.x << "," << figures[i].C.y << "))" << endl;
    }
}

bool compare_triangles(Triangle ABC, Triangle CDE)
{
    int total = 0;
    total += check_segments(ABC.A, ABC.B, CDE.A, CDE.B);
    total += check_segments(ABC.A, ABC.B, CDE.A, CDE.C);
    total += check_segments(ABC.A, ABC.B, CDE.B, CDE.C);

    total += check_segments(ABC.A, ABC.C, CDE.A, CDE.B);
    total += check_segments(ABC.A, ABC.C, CDE.A, CDE.C);
    total += check_segments(ABC.A, ABC.C, CDE.B, CDE.C);

    total += check_segments(ABC.B, ABC.C, CDE.A, CDE.B);
    total += check_segments(ABC.B, ABC.C, CDE.A, CDE.C);
    total += check_segments(ABC.B, ABC.C, CDE.B, CDE.C);
    if (total > 0)
    {
        return 1;
    }
    else if (check_inside(ABC, CDE))
    {
        return 1;
    }
    else if (check_inside(CDE, ABC))
    {
        return 1;
    }
    return 0;
}

bool check_segments(Point a, Point b, Point c, Point d)
{
    if (b.x < a.x)
    {
        Point temp = a;
        a = b;
        b = temp;
    }
    if (d.x < c.x)
    {
        Point temp = c;
        c = d;
        d = temp;
    }
    if (b.x < c.x)
    {
        return 0;
    }
    else if ((a.x - b.x == 0 ) and (c.x - d.x == 0))
    {
        if (a.x == c.x)
        {
            if ( (max(a.y,b.y) < min(c.y,d.y)) or (min(a.y, b.y) > max(c.y, d.y)) )
            {
                return 1;
            }
        }
        return 0;
    }
    else if (a.x - b.x == 0)
    {
        double X = a.x;
        double k2 = (c.y - d.y) / (c.x - d.x);
        double b2 = c.y - k2 * c.x;
        double Y = k2 * X + b2;
        if (c.x <= X and d.x >= X and min(a.y, b.y) <= Y and max(a.y, b.y) >= Y)
        {
            return 1;
        }
        return 0;
    }
    else if (c.x - d.x == 0)
    {
        double X = c.x;
        double k1 = (a.y - b.y) / (a.x - b.x);
        double b1 = a.y - k1 * a.x;
        double Y = k1 * X + b1;
        if (a.x <= X and b.x >= X and min(c.y, d.y) <= Y and max(c.y, d.y) >= Y)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        double k1 = (a.y - b.y) / (a.x - b.x);
        double k2 = (c.y - d.y) / (c.x - d.x);
        double b1 = a.y - k1 * a.x;
        double b2 = c.y - k2 * c.x;
        if (k1 == k2)
        {
            return 0;
        }
        double X = (b2 - b1) / (k1 - k2);
        if ((X < max(a.x, c.x)) or (X > min(b.x, d.x)))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

bool check_inside(Triangle Inside, Triangle Outside)
{
    int count = 0;
    Point Z;
    Z.x = Inside.A.x;
    Z.y = Inside.A.y;
    Point inf;
    inf.x = INT_MAX;
    inf.y = Z.y;
    count += check_segments(Z, inf, Outside.A, Outside.B);
    count += check_segments(Z, inf, Outside.A, Outside.C);
    count += check_segments(Z, inf, Outside.B, Outside.C);
    if (count % 2 == 0)
    {
        return 0;
    }
    return 1;
}

void create_set(vector<Triangle>& figures, vector <Triangle>& new_set)
{

    output_permutations(figures);
    cout << "numbers " << size(figures) / sizeof(figures[0]) << endl;
    for (int i = 0; i < figures.size(); i++)
    {
        for (int j = i + 1; j < figures.size(); j++)
        {
            if (compare_triangles(figures[i], figures[j]) == 0)
            {
                new_set.push_back(figures[i]);
                new_set.push_back(figures[j]);
            }
        }
    }
    figures = new_set;
    new_set.clear();
    output_permutations(figures);
}