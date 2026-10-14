// ЛР 1.8, варіант 4: моделювання > та лічильника +1 за таблицею 16.
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Порівняння знакових 32-бітових чисел: знак, потім біти від старшого.
int bitGreater(int32_t nA, int32_t nB)
{
    uint32_t nBitsA = (uint32_t)nA;
    uint32_t nBitsB = (uint32_t)nB;
    uint32_t nSignMask = UINT32_C(1) << 31;
    int nSignA = (nBitsA & nSignMask) != 0;
    int nSignB = (nBitsB & nSignMask) != 0;
    if (nSignA != nSignB)
    {
        return !nSignA;
    }
    for (int nBit = 30; nBit >= 0; --nBit)
    {
        uint32_t nMask = UINT32_C(1) << nBit;
        int nBitA = (nBitsA & nMask) != 0;
        int nBitB = (nBitsB & nMask) != 0;
        if (nBitA != nBitB)
        {
            return nBitA;
        }
    }
    return 0; // Рівні числа: відношення > хибне.
}

// Інвертуємо молодші одиниці й перший нуль. Не використовуємо додавання.
// Повертаємо успіх; для INT32_MAX знакового результату +1 не існує.
int bitIncrement(int32_t nValue, int32_t *pnResult)
{
    uint32_t nBits = (uint32_t)nValue;
    if (pnResult == NULL || nValue == INT32_MAX)
    {
        return 0;
    }
    for (int nBit = 0; nBit < 32; ++nBit)
    {
        uint32_t nMask = UINT32_C(1) << nBit;
        int nOldBit = (nBits & nMask) != 0;
        nBits = nBits ^ nMask;
        if (!nOldBit)
        {
            break;
        }
    }
    // int32_t - 32-бітовий тип без padding, у додатковому коді.
    // Копіюємо подання; навіть на етапі формування результату немає +1.
    memcpy(pnResult, &nBits, sizeof(nBits));
    return 1;
}

#ifndef LAB_TEST
int main(void)
{
    const int32_t VALUES_A[] = {88, 34, 23};
    const int32_t VALUES_B[] = {88, 2, 57};
    const int32_t COUNTER_VALUES[] = {63, -18, 92};
    int32_t nResult = 0;
    for (int nIndex = 0; nIndex < 3; ++nIndex)
    {
        printf("%" PRId32 " > %" PRId32 ": %d\n", VALUES_A[nIndex],
               VALUES_B[nIndex], bitGreater(VALUES_A[nIndex], VALUES_B[nIndex]));
    }
    for (int nIndex = 0; nIndex < 3; ++nIndex)
    {
        if (bitIncrement(COUNTER_VALUES[nIndex], &nResult))
        {
            printf("increment(%" PRId32 ") = %" PRId32 "\n",
                   COUNTER_VALUES[nIndex], nResult);
        }
    }
    if (!bitIncrement(INT32_MAX, &nResult))
    {
        puts("increment(INT32_MAX): результат поза діапазоном int32_t");
    }
    return 0;
}
#endif
