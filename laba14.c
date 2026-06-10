#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct room {
    char name[50];
    int level;
    int number;
    int resolution;
};

struct Node {
    struct room data;
    struct Node* next;
};

void add(struct Node** head, struct room r) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = r;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void print(struct Node* head) {
    int count = 1;
    struct Node* current = head;
    
    while (current != NULL) {
        printf("%d. %s | ур.%d | №%d | размер %d\n", 
               count, current->data.name, current->data.level, 
               current->data.number, current->data.resolution);
        current = current->next;
        count++;
    }
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    
    int n;
    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        printf("N = ");
        scanf("%d", &n);
    }
    
    char* names[] = {"Темница", "Пещера", "Лес", "Замок", "Башня"};
    
    struct Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        struct room r;
        strcpy(r.name, names[rand() % 5]);
        r.level = rand() % 10 + 1;
        r.number = rand() % 100 + 1;
        r.resolution = rand() % 50 + 10;
        add(&head, r);
    }
    
    print(head);
    freeList(head);
    
    return 0;
}