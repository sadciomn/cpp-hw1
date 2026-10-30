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

void arr_reverse(int* const arr, const int& start, const int& end)
{
    int tmp;

    for (int l = start, r = end - 1; l < r; l++, r--)
    {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
    }
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
        arr_reverse(arr, 0, arr_len);
        arr_reverse(arr, 0, shift);
        arr_reverse(arr, shift, arr_len);
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