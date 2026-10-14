// ЛР 1.4, варіант 4. Посилання в пункті 8 вимагає C++.
#include <cstdio>

int main()
{
    unsigned short nUnsigned = 0;
    int nInteger = 0;
    float fFloat = 0.0f;
    double fDouble = 0.0;
    unsigned short *pnUnsigned = &nUnsigned;
    int *pnInteger = &nInteger;
    float *pfFloat = &fFloat;
    double *pfDouble = &fDouble;
    void *pVoid = nullptr;
    int& refInteger = nInteger;

    *pnUnsigned = 87;
    *pnInteger = 11239;
    *pfFloat = -532.98987f;
    *pfDouble = 3.9e-41;
    std::printf("unsigned short=%u; int=%d; float=%.9f; double=%.17e\n",
                static_cast<unsigned>(nUnsigned), nInteger, fFloat, fDouble);
    std::printf("sizeof variables: %zu %zu %zu %zu\n", sizeof(nUnsigned),
                sizeof(nInteger), sizeof(fFloat), sizeof(fDouble));
    std::printf("sizeof pointers: %zu %zu %zu %zu; void*=%zu; reference=%zu\n",
                sizeof(pnUnsigned), sizeof(pnInteger), sizeof(pfFloat),
                sizeof(pfDouble), sizeof(pVoid), sizeof(refInteger));
    // Пункт 7: адреса саме змінної-покажчика, а не об'єкта, на який вона вказує.
    pVoid = &pnUnsigned;
    std::printf("void*=&pnUnsigned: %p; value=%u\n", pVoid,
                static_cast<unsigned>(**static_cast<unsigned short **>(pVoid)));
    pVoid = &pnInteger;
    std::printf("void*=&pnInteger: %p; value=%d\n", pVoid,
                **static_cast<int **>(pVoid));
    pVoid = &pfFloat;
    std::printf("void*=&pfFloat: %p; value=%.9f\n", pVoid,
                **static_cast<float **>(pVoid));
    pVoid = &pfDouble;
    std::printf("void*=&pfDouble: %p; value=%.17e\n", pVoid,
                **static_cast<double **>(pVoid));
    std::printf("&nInteger=%p; &refInteger=%p; reference=%d\n",
                static_cast<void *>(&nInteger), static_cast<void *>(&refInteger),
                refInteger); // WATCH_REFERENCE
    return 0;
}
