#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int count_major(vector<int> &a, int left, int right, int major)
{
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        if (a[i] == major)
            count++;
    }
    return count;
}

int get_majority_element(vector<int> &a, int left, int right)
{
    if (left > right)
        return -1;
    if (left == right)
        return a[left];
    // write your code here
    int mid = (left + right) / 2;
    int leftmajor = get_majority_element(a, left, mid);
    int rightmajor = get_majority_element(a, mid + 1, right);
    if (leftmajor != -1 || rightmajor != -1)
    {
        int rightcount = count_major(a, left, right, rightmajor);
        int leftcount = count_major(a, left, right, leftmajor);
        if (rightcount > (right - left) / 2)
        {
            return rightmajor;
        }
        else if (leftcount > (right - left) / 2)
        {
            return leftmajor;
        }
        else
            return -1;
    }
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
