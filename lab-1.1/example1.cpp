// ЛР 1.1. Приклад 1 з методички. Кузьменко Віталій Юрійович.
#include <cmath>
#include <cstdio>

const float LEFT = 0.0f;
const float RIGHT = 4.0f;
const float TABUL = 0.1f;

float fun1(float farg)
{
    float ftemp = 0.0f;
    for (int ni = 1; ni <= 5; ni = ni + 1)
    {
        ftemp = ftemp + std::sqrt((farg + ni) / ni);
    }
    return ftemp;
}

float fun2(float farg)
{
    return std::log(2.0f * farg * farg) + 3.0f * std::sin(farg);
}

int main()
{
    float fx = LEFT;
    float fy = 0.0f;
    int nStep = 0;
    // Збережено накопичення float з прикладу: похибку видно у fx.
    while (fx <= RIGHT)
    {
        if (fx <= 2.0f)
        {
            fy = fun1(fx);
        }
        else
        {
            fy = fun2(fx);
        }
        std::printf("%2d x=%.9f y=%.9f branch=%d\n", nStep, fx, fy,
                    fx <= 2.0f ? 1 : 2); // WATCH_TABULATION
        fx = fx + TABUL;
        nStep = nStep + 1;
    }
    return 0;
}
