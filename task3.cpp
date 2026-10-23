#include <iostream>

int pow(int a, int b)
{
    int tmp = a;
    for (int i = 1; i < b; i++)
    {
        a *= tmp;
    }
    return (b == 0) ? 1 : a;
}

int strlen(const char* a)
{
    int aCount = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != '+' and a[i] != '-')
        {
            aCount += 1;
        }
    }
    return aCount;
}

int num(const char* a)
{
    int len = strlen(a);
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num += (a[i] - 48) * pow(10, (len - i - 1));
    }
    return num;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    double res = 0;
    int size = num(argv[1]);
    double* arr = new double[size];

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        double tmp;
        std::cin >> tmp;
        res += arr[i] * tmp;
    }
    std::cout << res << std::endl;

    delete[] arr;
}