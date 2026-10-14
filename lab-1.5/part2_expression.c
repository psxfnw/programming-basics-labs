// ЛР 1.5, частина 2, варіант 4. Таблиці 12 і 13.
#include <stdio.h>

int main(void)
{
    const int A = 590 + 3; // R-вираз із літералів, термінологія методички.
    int nB = -(140 + 5); // Ініціалізація R-виразом.
    double fC = 9.23;
    double *pfC = &fC;
    int nE;
    int nUnary;
    int nBitLeft;
    int nBitRight;
    double fLeft;
    int nRight;
    int nResult;

    nE = A + 298; // Вираз зі змінною/константою A, «L-вираз» у методичці.
    nUnary = -nB;
    nBitLeft = A ^ nUnary;
    nBitRight = nE >> sizeof(short);
    fLeft = nBitLeft / *pfC;
    nRight = 43 * nBitRight;
    // Дужки задають: унарна і спеціальні, бітові, арифметичні, відношення.
    nResult = ((A ^ (-nB)) / (*pfC)) < (43 * (nE >> sizeof(short)));
    printf("A=%d B=%d *C=%.2f D=43 E=%d sizeof(short)=%zu\n",
           A, nB, *pfC, nE, sizeof(short));
    printf("-B=%d; A^(-B)=%d; E>>sizeof(short)=%d\n",
           nUnary, nBitLeft, nBitRight);
    printf("ліва частина=%.12f; права частина=%d; результат=%d\n",
           fLeft, nRight, nResult);
    return 0;
}
