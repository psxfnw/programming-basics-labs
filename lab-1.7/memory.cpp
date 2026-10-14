// ЛР 1.7. Блоки, час існування, static, ::, new/delete.
#include <cstdio>
#include <cstring>
#include <new>

int nGlobal = 45;
static int nStaticGlobal = 10;

static void leakDemo()
{
    int *pnLost = new (std::nothrow) int(111);
    if (pnLost == nullptr)
    {
        return;
    }
    std::printf("leak before overwrite: &pointer=%p pointer=%p value=%d\n",
                static_cast<void *>(&pnLost), static_cast<void *>(pnLost), *pnLost);
    pnLost = nullptr; // WATCH_LEAK_LOST: втрачено останню адресу об'єкта.
    {
        int *pnLocal = new (std::nothrow) int(222);
        if (pnLocal != nullptr)
        {
            std::printf("leak local: &pointer=%p pointer=%p value=%d\n",
                        static_cast<void *>(&pnLocal), static_cast<void *>(pnLocal),
                        *pnLocal); // WATCH_LEAK_LOCAL
        }
        // Навмисно немає delete: після блоку ім'я зникає, об'єкт у купі лишається.
    }
    int *pnOverwrite = new (std::nothrow) int(333);
    if (pnOverwrite == nullptr)
    {
        return;
    }
    std::printf("leak overwrite first: pointer=%p value=%d\n",
                static_cast<void *>(pnOverwrite), *pnOverwrite);
    pnOverwrite = new (std::nothrow) int(444); // WATCH_LEAK_OVERWRITE
    if (pnOverwrite != nullptr)
    {
        std::printf("leak overwrite second: pointer=%p value=%d\n",
                    static_cast<void *>(pnOverwrite), *pnOverwrite);
        delete pnOverwrite;
        pnOverwrite = nullptr;
    }
    std::puts("Навмисно втрачено 3 об'єкти int. Окремий процес завершується.");
    // Інші помилки для пояснення (не виконуємо): delete двічі, *p після delete,
    // delete замість delete[] для масиву; вони спричиняють невизначену поведінку.
}

int main(int argc, char *argv[])
{
    if (argc == 2 && std::strcmp(argv[1], "--leak-demo") == 0)
    {
        leakDemo();
        return 0;
    }
    // Блок 1, автоматичні об'єкти: існують до виходу з main.
    int nValue = 1;
    int nOther;
    int nGlobal = 10; // Перекриває глобальне ім'я.
    nOther = 2;
    nStaticGlobal = nStaticGlobal + 5;
    ::nGlobal = ::nGlobal * 2;
    std::printf("global local=%d global=%d static=%d; static address=%p\n",
                nGlobal, ::nGlobal, nStaticGlobal,
                static_cast<void *>(&nStaticGlobal)); // WATCH_GLOBAL
    {
        // Блок 1.1, static живе весь час, видимий лише в цьому блоці.
        static int nStaticBlock = 3;
        int nValue = 10;
        nStaticBlock = nStaticBlock + nOther;
        nValue = nValue + 1;
        std::printf("block 1.1 value=%d static=%d; address=%p\n", nValue,
                    nStaticBlock, static_cast<void *>(&nValue)); // WATCH_BLOCK1
        {
            // Блок 1.1.1: бачить nOther і nStaticBlock, перекриває nValue.
            int nValue = 100;
            nOther = nOther + 1;
            nValue = nValue + nOther;
            nStaticBlock = nStaticBlock + 1;
            std::printf("block 1.1.1 value=%d other=%d static=%d; address=%p\n",
                        nValue, nOther, nStaticBlock,
                        static_cast<void *>(&nValue)); // WATCH_INNER
        }
        std::printf("block 1.1 restored value=%d static=%d\n", nValue, nStaticBlock);
    }
    {
        // Блок 1.2: послідовний до 1.1, має власний nValue.
        int nValue = 20;
        nValue = nValue + nOther;
        std::printf("block 1.2 value=%d address=%p\n", nValue,
                    static_cast<void *>(&nValue)); // WATCH_BLOCK2
    }
    std::printf("main restored value=%d other=%d address=%p\n", nValue, nOther,
                static_cast<void *>(&nValue));
    for (int i = 0; i < 5; i = i + 1)
    {
        static int iA = 0;
        int iB = 0; // У C++17 int має автоматичний час існування без auto.
        iA = iA + 1;
        iB = iB + 1;
        std::printf("loop i=%d iA=%d iB=%d &iA=%p &iB=%p\n", i, iA, iB,
                    static_cast<void *>(&iA), static_cast<void *>(&iB)); // WATCH_LOOP
    }
    int *pnFirst = new (std::nothrow) int;
    if (pnFirst == nullptr)
    {
        return 1;
    }
    *pnFirst = 25;
    std::printf("heap first: &pointer=%p pointer=%p value=%d\n",
                static_cast<void *>(&pnFirst), static_cast<void *>(pnFirst),
                *pnFirst); // WATCH_HEAP1
    delete pnFirst;
    pnFirst = nullptr;
    int *pnSecond = new (std::nothrow) int(50);
    if (pnSecond == nullptr)
    {
        return 1;
    }
    std::printf("heap second: first=%p second=%p value=%d\n",
                static_cast<void *>(pnFirst), static_cast<void *>(pnSecond),
                *pnSecond); // WATCH_HEAP2
    delete pnSecond;
    pnSecond = nullptr;
    int *pnSaved = nullptr;
    {
        int *pnLocal = new (std::nothrow) int(75);
        if (pnLocal == nullptr)
        {
            return 1;
        }
        pnSaved = pnLocal;
        std::printf("heap delayed inside: local=%p value=%d\n",
                    static_cast<void *>(pnLocal), *pnLocal); // WATCH_DELAYED_IN
    }
    // Локальний покажчик зник, але збережений покажчик ще адресує живий об'єкт.
    std::printf("heap delayed outside: saved=%p value=%d\n",
                static_cast<void *>(pnSaved), *pnSaved); // WATCH_DELAYED_OUT
    delete pnSaved;
    pnSaved = nullptr;
    std::printf("heap freed: first=%p second=%p saved=%p\n",
                static_cast<void *>(pnFirst), static_cast<void *>(pnSecond),
                static_cast<void *>(pnSaved)); // WATCH_FREED
    return 0;
}
