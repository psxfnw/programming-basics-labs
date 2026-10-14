// ЛР 1.2, частина 2, варіант 4. Таблиця 3.
#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const float FLOAT_INITIAL = 765.23e29f;
    const double DOUBLE_INITIAL = 9876.456e201;
    float fFloat1 = FLOAT_INITIAL;
    float fFloat2;
    float fFloat3;
    double fDouble1;
    double fDouble2 = DOUBLE_INITIAL;
    int nFloatRangeError;
    int nDoubleRangeError;

    fFloat2 = -123456789086.9f;
    // Рядки дозволяють дослідити underflow без обрізаних компілятором літералів.
    errno = 0;
    fFloat3 = strtof("76.5e-400", NULL);
    nFloatRangeError = errno == ERANGE;
    errno = 0;
    fDouble1 = strtod("-0.435e-432", NULL);
    nDoubleRangeError = errno == ERANGE;

    printf("float: max=%.9e; min normal=%.9e; min positive=%.9e; digits=%d\n",
           FLT_MAX, FLT_MIN, FLT_TRUE_MIN, FLT_DIG);
    printf("double: max=%.17e; min normal=%.17e; min positive=%.17e; digits=%d\n",
           DBL_MAX, DBL_MIN, DBL_TRUE_MIN, DBL_DIG);
    printf("765.23e29 -> %.9e\n", fFloat1);
    printf("-123456789086.9 -> %.9f\n", fFloat2);
    printf("76.5e-400 -> %.9e; ERANGE=%d\n", fFloat3, nFloatRangeError);
    printf("-0.435e-432 -> %.17e; ERANGE=%d; signbit=%d\n", fDouble1,
           nDoubleRangeError, signbit(fDouble1) != 0);
    printf("9876.456e201 -> %.17e\n", fDouble2);
    printf("Похибка float2 відносно long double: %.9f\n",
           (double)((long double)fFloat2 - (-123456789086.9L)));
    printf("sizeof(float)=%zu; sizeof(double)=%zu\n", sizeof(fFloat1), sizeof(fDouble2));
    return 0;
}
