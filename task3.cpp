#include <iostream>

int num(const char* a)
{
    int num = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        num = num * 10 + (a[i] - '0');
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