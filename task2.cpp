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

    int arr_len = num(argv[1]);

    int* arr = new int[arr_len];
    // fill array
    for (int i = 0; i < arr_len; i++)
    {
        std::cin >> arr[i];
    }

    int shift;
    std::cin >> shift;

    // normalize shift
    shift = (shift < 0) ? ((shift % arr_len) + arr_len) : (shift % arr_len);

    if (shift > 0)
    {
        int tmp;
        int tmp1 = arr[0];
        bool ord = false;

        for (int i = 0; i < shift; i++)
        {
            for (int j = 0; j < arr_len; j++)
            {
                if (!ord)
                {
                    tmp = arr[(j + i + 1) % arr_len];
                    arr[(j + i + 1) % arr_len] = tmp1;
                    ord = true;
                }
                else
                {
                    tmp1 = arr[(j + i + 1) % arr_len];
                    arr[(j + i + 1) % arr_len] = tmp;
                    ord = false;
                }
            }
        }
    }
    // print array vertically and horizontally
    for (int i = 0; i < arr_len; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    for (int i = 0; i < arr_len; i++)
    {
        if (i == arr_len - 1)
        {
            std::cout << arr[i];
        }
        else
        {
            std::cout << arr[i] << ' ';
        }
    }
    std::cout << '\n';

    delete[] arr;
}