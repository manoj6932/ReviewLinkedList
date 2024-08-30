
#include <stdio.h>
#include <stdlib.h>

char test1;
int s_Buffer[10]={0};
struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
head = newNode;
    }
    else {
        struct Node temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node head) {
    struct Node temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int *ptr;
	*ptr = 12;
    
    char*buffer= (char*) calloc(50, sizeof(char));
    sprintf(buffer, "HELLO TEST");
    printf("Data : %s\r\n", buffer);

    for(int index = 0; index < 100; index++)
    {
        s_Buffer[index]=index;
    }
            
    struct Node* head = NULL;
    head->data = 7;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    display(head);
    free(head);
    display(head);

    return 0;
}
