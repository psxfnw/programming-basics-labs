// ЛР 1.5, частина 1, варіант 4. Обидва набори таблиці 10.
#include <stdio.h>

static void evaluate(double fA, double fB, double fC, double fD)
{
    int nRelation1 = fA != fB;
    int nRelation2 = fC < fD;
    int nInnerNot = !nRelation1;
    int nConjunction = nInnerNot && nRelation2;
    int nResult = !(!(fA != fB) && (fC < fD));
    printf("A=%g B=%g C=%g D=%g\n", fA, fB, fC, fD);
    printf("A!=B: %d; !(A!=B): %d; C<D: %d; &&: %d; результат: %d\n",
           nRelation1, nInnerNot, nRelation2, nConjunction, nResult);
}

int main(void)
{
    int nA = 66;
    double fB = 12.9;
    int nC = 62;
    int nD = 59;
    double fA2 = 3.56;
    double fB2 = 89.45;
    int nC2 = 15;
    double fD2 = 56.2;
    evaluate(nA, fB, nC, nD);
    evaluate(fA2, fB2, nC2, fD2);
    return 0;
}
