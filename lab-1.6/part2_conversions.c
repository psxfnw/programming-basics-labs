// ЛР 1.6, частина 2, варіант 4. Таблиця 15.
#include <limits.h>
#include <stdio.h>
#include <string.h>

static void printBytes(const void *pObject, size_t nSize)
{
    // unsigned char має право читати подання об'єкта будь-якого типу.
    const unsigned char *pcBytes = (const unsigned char *)pObject;
    for (size_t nIndex = 0; nIndex < nSize; ++nIndex)
    {
        printf(" %02X", (unsigned)pcBytes[nIndex]);
    }
    putchar('\n');
}

int main(void)
{
    int nSource = 9742;
    float fSource = -3.54e3f;
    unsigned short nShortSource = 34033;
    double fImplicit = nSource;
    int nImplicit = fSource;
    char cImplicit = nShortSource;
    double fExplicit = (double)nSource;
    int nExplicit = (int)fSource;
    char cExplicit = (char)nShortSource;
    double fBytes = 0.0;
    int nBytes = 0;
    char cBytes = 0;
    void *pVoid;

    printf("source: int=%d; float=%.2f; unsigned short=%u\n", nSource,
           fSource, (unsigned)nShortSource);
    printf("implicit: double=%.1f; int=%d; char=%d; byte=%u\n", fImplicit,
           nImplicit, (int)cImplicit, (unsigned)(unsigned char)cImplicit);
    printf("explicit: double=%.1f; int=%d; char=%d; byte=%u\n", fExplicit,
           nExplicit, (int)cExplicit, (unsigned)(unsigned char)cExplicit);
    printf("CHAR_MIN=%d; CHAR_MAX=%d\n", CHAR_MIN, CHAR_MAX);

    // Контрольований аналог обходу типізації: копіювання подання, НЕ числове
    // приведення. Для int -> double спочатку нульове заповнення 8 байтів,
    // потім копіювання 4 байтів int. Це явно обрана модель, а не результат
    // невизначеного читання double* із 4-байтового об'єкта int.
    if (sizeof(int) != 4 || sizeof(float) != 4 || sizeof(double) != 8)
    {
        puts("Для байтового дослідження потрібні розміри int/float/double = 4/4/8.");
        return 1;
    }
    pVoid = &nSource;
    memcpy(&fBytes, pVoid, sizeof(nSource));
    pVoid = &fSource;
    memcpy(&nBytes, pVoid, sizeof(nBytes));
    pVoid = &nShortSource;
    cBytes = *(char *)pVoid; // char дозволено читати перший байт об'єкта.
    printf("bytes int:");
    printBytes(&nSource, sizeof(nSource));
    printf("bytes float:");
    printBytes(&fSource, sizeof(fSource));
    printf("bytes unsigned short:");
    printBytes(&nShortSource, sizeof(nShortSource));
    printf("representation: padded double=%.17e; int=%d; char=%d; byte=%u\n",
           fBytes, nBytes, (int)cBytes, (unsigned)(unsigned char)cBytes);

    // Прямий спосіб з методички (приклади для аналізу, НЕ для виконання):
    // double badDouble = *(double *)(void *)&nSource; // 8 байтів із 4 + aliasing
    // int badInt = *(int *)(void *)&fSource;          // порушення aliasing
    // char firstByte = *(char *)(void *)&nShortSource; // дозволено
    return 0;
}
