// ЛР 1.8, завдання 2: усі форми вибору та повторення.
#include <stdio.h>

int main(void)
{
    int nSumFor = 0;
    int nSumWhile = 0;
    int nSumDo = 0;
    int nMonth = 1;
    for (int nMode = -1; nMode <= 2; ++nMode)
    {
        // Складений оператор, неповна та альтернативна форми if.
        if (nMode > 0)
        {
            printf("if: %d додатне\n", nMode);
        }
        if (nMode % 2 == 0)
        {
            printf("if/else: %d парне\n", nMode);
        }
        else
        {
            printf("if/else: %d непарне\n", nMode);
        }
        // switch потрібний тут саме для дослідження охоронної форми вибору.
        switch (nMode)
        {
            case 0:
                puts("switch: режим 0");
                break;
            case 1:
                puts("switch: режим 1");
                break;
            default:
                puts("switch: типовий режим");
                break;
        }
    }
    for (int nIndex = 1; nIndex <= 5; ++nIndex)
    {
        nSumFor = nSumFor + nIndex;
    }
    while (nMonth <= 5)
    {
        nSumWhile = nSumWhile + nMonth;
        nMonth = nMonth + 1;
    }
    nMonth = 1;
    do
    {
        nSumDo = nSumDo + nMonth;
        nMonth = nMonth + 1;
    }
    while (nMonth <= 5);
    printf("sum for=%d while=%d do-while=%d\n", nSumFor, nSumWhile, nSumDo);
    return 0;
}
