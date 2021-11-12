#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Segment
{
    int start, end;
};

bool compare(Segment &a, Segment &b)
{
    return a.end < b.end;
}
vector<int> optimal_points(vector<Segment> &segments)
{

    sort(segments.begin(), segments.end(), compare);

    vector<int> points;
    int point = segments[0].end;
    points.push_back(point);

    for (int i = 1; i < segments.size(); ++i)
    {
        if (point < segments[i].start || point > segments[i].end)
        {
            point = segments[i].end;
            points.push_back(point);
        }
    }

    return points;
}

int main()
{
    unsigned int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i)
    {
        cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i)
    {
        cout << points[i] << " ";
    }
}