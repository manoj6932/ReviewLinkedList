
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void delete(struct node *head, int data) {
    if (head == NULL) {
        return;
    }

    if (head->data == data) {
        head = head->next;
        free(head);
        return;
    }

    struct node *curr = head;
    while (curr->next != NULL && curr->next->data != data) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        return;
    }

    struct node *temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf('%d ', head->data);
        head = head->next;
    }
    printf('\n');
}

void main() {
    struct node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    print_list(head);

    delete(head, 3);
    print_list(head);
}
