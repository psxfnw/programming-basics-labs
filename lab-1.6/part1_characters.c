// ЛР 1.6, частина 1, варіант 4. Таблиця 14.
#include <stdio.h>

static void show(const char *szName, unsigned char cValue)
{
    printf("%s: code=%u (0x%02X)", szName, (unsigned)cValue, (unsigned)cValue);
    if (cValue >= 0x20 && cValue <= 0x7e)
    {
        printf("; symbol='%c'\n", cValue);
    }
    else
    {
        puts("; керуючий символ (не виводимо як графічний знак)");
    }
}

int main(void)
{
    const char LETTER = 'S';
    const char DIGIT = '6';
    const char QUESTION = '?';
    const char NEWLINE = '\n';
    char cLetter = LETTER;
    char cDigit;
    char cQuestion;
    unsigned char cCode1;
    unsigned char cCode2;
    unsigned char cCode3;
    cDigit = DIGIT;
    cQuestion = QUESTION;
    cCode1 = 0x11;
    cCode2 = 0x4f;
    cCode3 = 0x2c;
    show("'S'", (unsigned char)cLetter);
    show("'6'", (unsigned char)cDigit);
    show("'?'", (unsigned char)cQuestion);
    show("0x11", cCode1);
    show("0x4f", cCode2);
    show("0x2c", cCode3);
    show("\\n", (unsigned char)NEWLINE);
    printf("'S' > '6': %d; 'S' == 0x53: %d\n", cLetter > cDigit, cLetter == 0x53);
    return 0;
}
