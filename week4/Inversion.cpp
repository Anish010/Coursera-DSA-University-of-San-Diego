#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> arr, size_t mid, size_t l, size_t r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> a(n1);
    vector<int> b(n2);

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            inv += n1 - i;
            j++;
        }
        k++;
    }

    if (j >= n2)
    {
        while (i < n1)
        {
            arr[k] = a[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j < n2)
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    return inv;
}
long long get_number_of_inversions(vector<int> a, vector<int> b, size_t left, size_t right)
{
    long long number_of_inversions = 0;
    if (left < right)
    {
        size_t ave = left + (right - left) / 2;
        number_of_inversions += get_number_of_inversions(a, b, left, ave);
        number_of_inversions += get_number_of_inversions(a, b, ave, right);
        // write your code here

        number_of_inversions += merge(a, ave, left, right);
    }

    return number_of_inversions;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
