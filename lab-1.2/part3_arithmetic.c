// ЛР 1.2, частина 3, варіант 4. Таблиця 4.
#include <stdio.h>

int main(void)
{
    int nPositive = -34;
    int nNegative = 98;
    int nAdd1 = 345;
    int nAdd2 = -55;
    int nSub1 = 43;
    int nSub2 = 87;
    int nMul1 = 7;
    int nMul2 = 23;
    int nDiv1 = 18;
    int nDiv2 = 6;
    int nDiv3 = 18;
    int nDiv4 = 5;
    int nMod1 = 19;
    int nMod2 = 4;
    int nReal1 = 81;
    int nReal2 = 10;
    double fFirst = 7.5;
    double fSecond = 2.0;

    printf("+(-34)=%d; -(98)=%d\n", +nPositive, -nNegative);
    printf("345+(-55)=%d; 43-87=%d; 7*23=%d\n",
           nAdd1 + nAdd2, nSub1 - nSub2, nMul1 * nMul2);
    printf("18/6=%d; 18/5=%d; 19%%4=%d\n",
           nDiv1 / nDiv2, nDiv3 / nDiv4, nMod1 % nMod2);
    printf("81/10=%d; (double)81/10=%.2f\n",
           nReal1 / nReal2, (double)nReal1 / nReal2);
    printf("Дійсні: +x=%.2f; -x=%.2f; x+y=%.2f; x-y=%.2f; x*y=%.2f; x/y=%.2f\n",
           +fFirst, -fFirst, fFirst + fSecond, fFirst - fSecond,
           fFirst * fSecond, fFirst / fSecond);
    printf("-18/5=%d; -18%%5=%d\n", -nDiv3 / nDiv4, -nDiv3 % nDiv4);
    return 0;
}
