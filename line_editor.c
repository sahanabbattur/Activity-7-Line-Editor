#include <stdio.h>
#include <string.h>
#include <ctype.h>

char lines[100][256];
int lineCount = 0;

void insertLine()
{
    int position;

    if (lineCount == 100)
    {
        printf("Document is full!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    getchar();

    for (int i = lineCount; i >= position; i--)
        strcpy(lines[i], lines[i - 1]);

    printf("Enter text: ");
    fgets(lines[position - 1], 256, stdin);

    lineCount++;
    printf("Line inserted successfully!\n");
}

void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("\n===== DOCUMENT =====\n");

    for (int i = 0; i < lineCount; i++)
        printf("%d. %s", i + 1, lines[i]);
}

void deleteLine()
{
    int position;

    if (lineCount == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number!\n");
        return;
    }

    for (int i = position - 1; i < lineCount - 1; i++)
        strcpy(lines[i], lines[i + 1]);

    lineCount--;
    printf("Line deleted successfully!\n");
}

void saveFile()
{
    FILE *fp = fopen("document.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to save file!\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
        fputs(lines[i], fp);

    fclose(fp);
    printf("Document saved successfully!\n");
}

void loadFile()
{
    FILE *fp = fopen("document.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    lineCount = 0;

    while (lineCount < 100 &&
           fgets(lines[lineCount], 256, fp) != NULL)
    {
        lineCount++;
    }

    fclose(fp);
    printf("Document loaded successfully!\n");
}

void searchWord()
{
    char word[100];
    int found = 0;

    getchar();

    printf("Enter word to search: ");
    fgets(word, sizeof(word), stdin);

    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Word found in line %d\n", i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("Word not found!\n");
}

void countWords()
{
    int words = 0;

    for (int i = 0; i < lineCount; i++)
    {
        int inWord = 0;

        for (int j = 0; lines[i][j] != '\0'; j++)
        {
            if (isspace((unsigned char)lines[i][j]))
                inWord = 0;
            else if (!inWord)
            {
                words++;
                inWord = 1;
            }
        }
    }

    printf("Total lines: %d\n", lineCount);
    printf("Total words: %d\n", words);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== SIMPLE LINE EDITOR =====\n");
        printf("1. Insert Line\n");
        printf("2. Display Document\n");
        printf("3. Delete Line\n");
        printf("4. Save Document\n");
        printf("5. Load Document\n");
        printf("6. Search Word\n");
        printf("7. Count Lines and Words\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertLine(); break;
            case 2: displayDocument(); break;
            case 3: deleteLine(); break;
            case 4: saveFile(); break;
            case 5: loadFile(); break;
            case 6: searchWord(); break;
            case 7: countWords(); break;
            case 8: printf("Exiting Editor!\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}