// ЛР 1.1. Приклад 2: посилання C++ та ініціалізація масивів.
#include <cstdio>

void swap(int& num1, int& num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void init(int mas[], int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        mas[i] = i + 100;
    }
}

int main()
{
    int a = 5;
    int b = 6;
    const int N1 = 10;
    int mas1[N1] = {};
    const int N2 = 100;
    int mas2[N2] = {};
    swap(a, b);
    init(mas1, N1);
    init(mas2, N2);
    std::printf("a=%d b=%d\n", a, b); // WATCH_ARRAYS
    for (int i = 0; i < N1; i = i + 1)
    {
        std::printf("mas1[%d]=%d\n", i, mas1[i]);
    }
    for (int i = 0; i < N2; i = i + 1)
    {
        std::printf("mas2[%d]=%d\n", i, mas2[i]);
    }
    return 0;
}
