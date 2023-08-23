#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';
}

int calculateVowels(char *line) {
    int i, vowels = 0;
    for (i = 0; i < strlen(line); i++) {
        if (isVowel(line[i])) {
            vowels++;
        }
    }
    return vowels;
}

int main() {
    FILE *f = fopen("/Users/bojanangjeleski/CLionProjects/untitled133/SP_primer.txt", "r");

    char currLine[100];
    int lines = 0;
    int totalVowels = 0;
    while (fgets(currLine, 100, f) != NULL) {
        int vowels = calculateVowels(currLine);
        totalVowels += vowels;
        if (vowels > 10) {
            lines++;
        }
    }
    printf("Vkupno %d reda imaat povekje od 10 samoglaski.\n"
           "Vo datotekata ima vkupno %d samoglaski.", lines, totalVowels);
    fclose(f);
    return 0;
}
/*
1.5. Задача 4
Дадена е текстуална датотека SP_primer.txt. Да се напише програма која ќе ја прочита датотеката и на екран ќе го отпечати бројот на редови во кои има повеќе од 10 самогласки, како и вкупниот број на самогласки во датотеката.

Пример
        Ако датотеката SP_primer.txt ја има следнава содржина:

Zdravo, kako si?
Eve, dobro sum. A ti?
I jas dobro. Kako se tvoite? Ima li neshto novo?
Dobri se i tie. Si kupiv avtomobil.
тогаш програмата треба да отпечати:

Vkupno 2 reda imaat povekje od 10 samoglaski.
Vo datotekata ima vkupno 42 samoglaski.*/