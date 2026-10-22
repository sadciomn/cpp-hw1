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
    int arrLen = num(argv[1]);
    int k;
    std::cin >> k;
    int* arr = new int[arrLen];

    if (k > 0)
    {
        for (int i = 0; i < arrLen; i++, k++)
        {
            int index = (k % arrLen);
            arr[index] = i + 1;
        }
    }
    else if (k < 0)
    {
        k += arrLen;
        for (int i = 0; i < arrLen; i++, k++)
        {
            int index = (k % arrLen);
            arr[index] = i + 1;
        }
    }
    else
    {
        for (int i = 0; i < arrLen; i++)
        {
            arr[i] = i + 1;
        }
    }
    for (int i = 0; i < arrLen; i++)
    {
        std::cout << i << ' ';
    }
}