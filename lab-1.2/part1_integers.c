// ЛР 1.2, частина 1, варіант 4. Таблиця 2.
#include <limits.h>
#include <stdio.h>

int main(void)
{
    const short SHORT_HEX = 0x1c;
    const int INT_INITIAL = 1024;
    const long long LONG_TOO_LARGE = 4015642735LL;
    const unsigned short UNSIGNED_INITIAL = 438;
    short nShort1 = SHORT_HEX;
    short nShort2;
    short nShort3;
    int nInt1 = INT_INITIAL;
    int nInt2;
    int nInt3;
    long lLong1;
    long lLong2;
    long lLong3;
    unsigned short nUnsigned1 = UNSIGNED_INITIAL;
    unsigned short nUnsigned2;
    unsigned short nUnsigned3;

    nShort2 = -88;
    nShort3 = 0776; // 510 у десятковій системі.
    nInt2 = (int)-61.37; // Відкидання дробової частини до нуля.
    nInt3 = 337752;
    lLong2 = (long)-97.8;
    lLong3 = 2768L;
    nUnsigned2 = (unsigned short)74234;
    nUnsigned3 = (unsigned short)-65;

    printf("short: [%d; %d], sizeof=%zu\n", SHRT_MIN, SHRT_MAX, sizeof(short));
    printf("int: [%d; %d], sizeof=%zu\n", INT_MIN, INT_MAX, sizeof(int));
    printf("long: [%ld; %ld], sizeof=%zu\n", LONG_MIN, LONG_MAX, sizeof(long));
    printf("unsigned short: [0; %u], sizeof=%zu\n", (unsigned)USHRT_MAX,
           sizeof(unsigned short));
    printf("short: 0x1c=%d; -88=%d; 0776=%d\n", nShort1, nShort2, nShort3);
    printf("int: %d; -61.37 -> %d; %d\n", nInt1, nInt2, nInt3);
    if (LONG_TOO_LARGE >= LONG_MIN && LONG_TOO_LARGE <= LONG_MAX)
    {
        lLong1 = (long)LONG_TOO_LARGE;
        printf("long: %ld\n", lLong1);
    }
    else
    {
        // Позадіапазонне перетворення у signed long залежить від реалізації.
        lLong1 = (long)LONG_TOO_LARGE;
        printf("4015642735: НЕ входить у long; результат цієї реалізації=%ld\n", lLong1);
    }
    printf("long: -97.8 -> %ld; %ld\n", lLong2, lLong3);
    printf("unsigned short: %u; 74234 -> %u; -65 -> %u\n",
           (unsigned)nUnsigned1, (unsigned)nUnsigned2, (unsigned)nUnsigned3);
    printf("Літерали одного значення: 28=%d; 034=%d; 0x1c=%d\n", 28, 034, 0x1c);
    return 0;
}
