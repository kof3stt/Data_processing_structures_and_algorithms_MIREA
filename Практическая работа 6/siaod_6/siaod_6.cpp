#include <iostream>
using namespace std;

int print_numbers(int n)
{
    if (n == 0)
    {
        return 0;
    }
    print_numbers(n / 10);
    cout << n % 10 << " ";
}

int main()
{
    system("chcp 1251");
    int n;
    cout << " Введите десятичное число число: \n";
    cin >> n;
    print_numbers(n);
}