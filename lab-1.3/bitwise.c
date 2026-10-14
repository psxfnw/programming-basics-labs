// ЛР 1.3, варіант 4: N=4, операція в таблиці 7 - додавання.
#include <limits.h>
#include <stdio.h>

static void printBits(int nValue)
{
    unsigned int nBits = (unsigned int)nValue;
    for (int nBit = (int)(sizeof(nBits) * CHAR_BIT) - 1; nBit >= 0; --nBit)
    {
        putchar((nBits & (1u << nBit)) ? '1' : '0');
    }
}

static void show(const char *szOperation, int nValue)
{
    printf("%s = %d = ", szOperation, nValue);
    printBits(nValue);
    putchar('\n');
}

int main(void)
{
    const int N = 4;
    int nNot = 18 + N;
    int nAnd1 = 89 + N;
    int nAnd2 = 122 + N;
    int nOr1 = 134 + N;
    int nOr2 = 65 + N;
    int nXor1 = 34 + N;
    int nXor2 = 78 + N;
    int nLeft = 907 + N;
    int nRight = -95 + N;
    int nShift = N + 1;
    show("~22", ~nNot);
    show("93 & 126", nAnd1 & nAnd2);
    show("138 | 69", nOr1 | nOr2);
    show("38 ^ 82", nXor1 ^ nXor2);
    show("911 << 5", nLeft << nShift);
    // У C17 правий зсув від'ємного int залежить від реалізації.
    // На перевіреному GCC це арифметичний зсув із заповненням одиницями.
    show("-91 >> 5", nRight >> nShift);
    return 0;
}
