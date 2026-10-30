#include <iostream>
int len_till_point(const char* str)
{
    int len = 0;
    int i = 0;
    while (str[i] != '.' && str[i] != '\0')
    {
        len++;
        i++;
    }

    return len;
}

inline int sign(const char* str) { return str[0] != '-'; }

int compare_whole_part(const int& len, const int& sgn, const char* const str1,
                       const char* const str2)
{
    for (int i = 0; i < len; i++)
    {
        if (str1[i] > str2[i])
        {
            if (sgn == 1)
            {
                std::cout << "greater" << std::endl;
                return 0;
            }
            else
            {
                std::cout << "less" << std::endl;
                return 0;
            }
        }
        else if (str1[i] < str2[i])
        {
            if (sgn == 1)
            {
                std::cout << "less" << std::endl;
                return 0;
            }
            else
            {
                std::cout << "greater" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

int compare_decimial_part(const int& len_till_point1,
                          const int& len_till_point2, const int& sgn,
                          const char* str1, const char* str2)
{
    bool reached_end1 = false;
    bool reached_end2 = false;

    str1 += len_till_point1;
    str2 += len_till_point2;

    if (str1[0] == '.')
    {
        str1++;
    }
    if (str2[0] == '.')
    {
        str2++;
    }

    while (!(reached_end1 && reached_end2))
    {
        if (str1[0] == '\0')
        {
            reached_end1 = true;
        }
        if (str2[0] == '\0')
        {
            reached_end2 = true;
        }

        if (reached_end1 && !reached_end2) // virtual zeros for 1st
        {
            if (str2[0] > '0')
            {
                if (sgn == 1)
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
                else
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
            }
        }

        if (!reached_end1 && reached_end2) // virtual zeros for 2nd
        {
            if (str1[0] > '0')
            {
                if (sgn == 1)
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
                else
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
            }
        }

        if (!reached_end1 && !reached_end2)
        {
            if (str1[0] > str2[0])
            {
                if (sgn == 1)
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
                else
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
            }
            else if (str1[0] < str2[0])
            {
                if (sgn == 1)
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
                else
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
            }
        }
        if (!reached_end1)
        {
            str1++;
        }
        if (!reached_end2)
        {
            str2++;
        }
    }
    return 1;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    const char* str1 = argv[1];
    const char* str2 = argv[2];

    int sign1 = sign(str1);
    int sign2 = sign(str2);

    if (str1[0] == '+' || str1[0] == '-')
    {
        str1++;
    }
    if (str2[0] == '+' || str2[0] == '-')
    {
        str2++;
    }

    int len_till_point1 = len_till_point(str1);
    int len_till_point2 = len_till_point(str2);

    // compare if different signs
    if (sign1 == 1 && sign2 == 0)
    {
        std::cout << "greater" << std::endl;
        return 0;
    }
    else if (sign1 == 0 && sign2 == 1)
    {
        std::cout << "less" << std::endl;
        return 0;
    }

    // compare if different whole part

    if (len_till_point1 != len_till_point2)
    {
        if ((len_till_point1 > len_till_point2) == (sign1 == 1))
        {
            std::cout << "greater" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "less" << std::endl;
            return 0;
        }
    }

    if (!compare_whole_part(len_till_point1, sign1, str1, str2))
    {
        return 0;
    }
    if (!compare_decimial_part(len_till_point1, len_till_point2, sign1, str1,
                               str2))
    {
        return 0;
    }

    std::cout << "equal" << std::endl;
}