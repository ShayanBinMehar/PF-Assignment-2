#include <stdio.h>
#include <string.h>

void compressWord(char *word) {
    int len = strlen(word);
    int j = 0;

    for (int i = 0; i < len; i++) {
        word[j++] = word[i];
        while (i + 1 < len && word[i] == word[i + 1]) {
            i++;
        }
    }
    word[j] = '\0';
}

int main() {
    char words[][10] = {"booooook", "coooool", "heeeey"};
    int numWords = sizeof(words) / sizeof(words[0]);
    int totalRemovedChars = 0;

    for (int i = 0; i < numWords; i++) {
        int originalLen = strlen(words[i]);
        compressWord(words[i]);
        int compressedLen = strlen(words[i]);
        totalRemovedChars += originalLen - compressedLen;
        printf("%s ", words[i]);
    }

    printf("\nTotal characters removed: %d\n", totalRemovedChars);

    return 0;
}