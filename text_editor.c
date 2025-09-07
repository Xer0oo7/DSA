#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[50];
    struct Node *next;
} Node;

// Insert a new word at the end of linked list
Node* insertEnd(Node *head, char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Display all words
void displayList(Node *head) {
    printf("\nWords stored in linked list:\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->word);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Find and replace word
void findAndReplace(Node *head, const char *findWord, const char *replaceWord) {
    int found = 0;
    while (head != NULL) {
        if (strcmp(head->word, findWord) == 0) {
            strcpy(head->word, replaceWord);
            found = 1;
        }
        head = head->next;
    }
    if (found)
        printf("\nAll occurrences of '%s' replaced with '%s'\n", findWord, replaceWord);
    else
        printf("\nWord '%s' not found!\n", findWord);
}

int main() {
    Node *head = NULL;
    char sentence[200], *token;

    printf("Enter a line of text: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; // Remove trailing newline

    // Split sentence into words and store in linked list
    token = strtok(sentence, " ");
    while (token != NULL) {
        head = insertEnd(head, token);
        token = strtok(NULL, " ");
    }

    displayList(head);

    // Get word to find and replace
    char findWord[50], replaceWord[50];
    printf("\nEnter word to find: ");
    scanf("%s", findWord);
    printf("Enter replacement word: ");
    scanf("%s", replaceWord);

    findAndReplace(head, findWord, replaceWord);
    displayList(head);

    return 0;
}