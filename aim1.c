#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50  // Adjust as needed

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordEntry;

int compare_words(const void *a, const void *b) {
    const WordEntry *w1 = (const WordEntry *)a;
    const WordEntry *w2 = (const WordEntry *)b;
    return strcmp(w1->word, w2->word);
}

int main() {
    char filename[100];
    FILE *fp;
    int i, j, num_words = 0, num_unique_words = 0;
    WordEntry *word_list = NULL;

    // Get filename from user
    printf("Enter the filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read filename.\n");
        return 1;
 }
    filename[strcspn(filename, "\n")] = '\0';  // Remove trailing newline from filename

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file \"%s\".\n", filename);
        return 1;
    }

    // Dynamically allocate memory for word list
    word_list = malloc(sizeof(WordEntry) * 100);  // Initial allocation
    if (word_list == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    // Read and process words
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) == 1) {
        // Remove punctuation and lowercase
        for (i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
            if (!isalnum(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        // Check if word already exists in the list
        int found = 0;
        for (j = 0; j < num_words; j++) {
            if (strcmp(word_list[j].word, word) == 0) {
                word_list[j].count++;
          found = 1;
                break;
            }
        }

        // If not found, add it to the list and potentially reallocate
        if (!found) {
            if (num_words == 100) {  // Reachability check
                word_list = realloc(word_list, 2 * num_words * sizeof(WordEntry));
                if (word_list == NULL) {
                    fprintf(stderr, "Error: Memory allocation failed.\n");
                    fclose(fp);
                    free(word_list);
                    return 1;
                }
            }
            strcpy(word_list[num_words].word, word);
            word_list[num_words].count = 1;
            num_words++;
            num_unique_words++;
        }
    }

    fclose(fp);

    // Sort the word list alphabetically using qsort
    qsort(word_list, num_words, sizeof(WordEntry), compare_words);

    // Print word frequencies
    printf("Word frequencies:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
    }

    // Free memory
    free(word_list);

    return 0;
}
