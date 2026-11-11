#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double SumNegative(const double a[], int n, int i = 0);

int FindMinIndex(const double a[], int n, int i = 1, int minIndex = 0);
int FindMaxIndex(const double a[], int n, int i = 1, int maxIndex = 0);

double ProductBetween(const double a[], int left, int right);

int FindNextEven(const double a[], int n, int start);
int FindMinEven(const double a[], int n, int start, int minIndex);

void SortEvenElements(double a[], int n, int start = 0);
void PrintArray(const double a[], int n, int i = 0);

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Incorrect array size!" << endl;
        return 1;
    }

    double* a = new double[n];

    // Введення масиву
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "\nOriginal array:" << endl;
    PrintArray(a, n);

    // 1. Сума від'ємних елементів
    cout << "\nSum of negative elements: "
        << SumNegative(a, n) << endl;

    // 2. Добуток елементів між мінімальним і максимальним
    int minIndex = FindMinIndex(a, n);
    int maxIndex = FindMaxIndex(a, n);

    int left = min(minIndex, maxIndex);
    int right = max(minIndex, maxIndex);

    cout << "Product between min and max: "
    << ProductBetween(a, left + 1, right) << endl;

    // 3. Сортування парних елементів
    SortEvenElements(a, n);

    cout << "\nModified array:" << endl;
    PrintArray(a, n);
    return 0;
}

// Рекурсивна сума від'ємних елементів
double SumNegative(const double a[], int n, int i)
{
    if (i >= n)
        return 0;

    double sum = 0;

    if (a[i] < 0)
        sum = a[i];

    return sum + SumNegative(a, n, i + 1);
}

// Пошук індексу мінімального елемента
int FindMinIndex(const double a[], int n, int i, int minIndex)
{
    if (i >= n)
        return minIndex;

    if (a[i] < a[minIndex])
        minIndex = i;

    return FindMinIndex(a, n, i + 1, minIndex);
}

// Пошук індексу максимального елемента
int FindMaxIndex(const double a[], int n, int i, int maxIndex)
{
    if (i >= n)
        return maxIndex;

    if (a[i] > a[maxIndex])
        maxIndex = i;

    return FindMaxIndex(a, n, i + 1, maxIndex);
}

// Рекурсивний добуток елементів між мінімальним і максимальним
double ProductBetween(const double a[], int left, int right)
{
    if (left >= right)
        return 1;

    return a[left] * ProductBetween(a, left + 1, right);
}

// Пошук наступного парного елемента
int FindNextEven(const double a[], int n, int start)
{
    if (start >= n)
        return -1;

    if (fmod(a[start], 2.0) == 0)
        return start;

    return FindNextEven(a, n, start + 1);
}

// Пошук найменшого парного елемента
int FindMinEven(const double a[], int n, int start, int minIndex)
{
    if (start >= n)
        return minIndex;

    if (fmod(a[start], 2.0) == 0 && a[start] < a[minIndex])
        minIndex = start;

    return FindMinEven(a, n, start + 1, minIndex);
}

// Рекурсивне сортування парних елементів
void SortEvenElements(double a[], int n, int start)
{
    int first = FindNextEven(a, n, start);

    if (first == -1)
        return;

    int minIndex = FindMinEven(a, n, first + 1, first);

    double temp = a[first];
    a[first] = a[minIndex];
    a[minIndex] = temp;

    SortEvenElements(a, n, first + 1);
}

// Рекурсивне виведення масиву
void PrintArray(const double a[], int n, int i)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(8) << fixed << setprecision(2) << a[i];

    PrintArray(a, n, i + 1);
}