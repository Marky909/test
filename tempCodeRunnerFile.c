#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
typedef struct Node {
    int info;
    struct Node *next;
} NodeType;

NodeType *first = NULL, *last = NULL;

// Function prototypes
void insert_at_first(int item);
void insert_at_end(int item);
void insert_given_position(int item);
void delete_first();
void delete_last();
void delete_nth_node();
void info_sum();
void count_nodes();
void display();

int main() {
    int choice, item;
    
    while (1) {
        printf("\nMenu for program\n");
        printf("1. Insert first\n");
        printf("2. Insert at given position\n");
        printf("3. Insert at last\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete nth node\n");
        printf("7. Info sum\n");
        printf("8. Count nodes\n");
        printf("9. Display items\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert_at_first(item);
                break;
            case 2:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert_given_position(item);
                break;
            case 3:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert_at_end(item);
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_nth_node();
                break;
            case 7:
                info_sum();
                break;
            case 8:
                count_nodes();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to insert at the beginning
void insert_at_first(int item) {
    NodeType *newnode = (NodeType *)malloc(sizeof(NodeType));
    newnode->info = item;
    newnode->next = first;
    first = newnode;
    if (last == NULL) {
        last = newnode;
    }
}

// Function to insert at the end
void insert_at_end(int item) {
    NodeType *newnode = (NodeType *)malloc(sizeof(NodeType));
    newnode->info = item;
    newnode->next = NULL;

    if (first == NULL) {
        first = last = newnode;
    } else {
        last->next = newnode;
        last = newnode;
    }
}

// Function to insert at a given position
void insert_given_position(int item) {
    int pos, i;
    NodeType *newnode, *temp;

    printf("Enter position of node to insert: ");
    scanf("%d", &pos);

    newnode = (NodeType *)malloc(sizeof(NodeType));
    newnode->info = item;
    newnode->next = NULL;

    if (pos == 1) {
        newnode->next = first;
        first = newnode;
        if (last == NULL) {
            last = newnode;
        }
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == NULL) {
            last = newnode;
        }
    }
}

// Function to delete first node
void delete_first() {
    if (first == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    NodeType *temp = first;
    first = first->next;
    free(temp);

    if (first == NULL) {
        last = NULL;
    }
}

// Function to delete last node
void delete_last() {
    if (first == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    if (first->next == NULL) {
        free(first);
        first = last = NULL;
        return;
    }

    NodeType *temp = first;
    while (temp->next != last) {
        temp = temp->next;
    }

    free(last);
    last = temp;
    last->next = NULL;
}

// Function to delete nth node
void delete_nth_node() {
    int pos, i;
    NodeType *temp, *hold;

    if (first == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }

    printf("Enter position of node to be deleted: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_first();
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    hold = temp->next;
    temp->next = hold->next;
    free(hold);

    if (temp->next == NULL) {
        last = temp;
    }
}

// Function to display the sum of node values
void info_sum() {
    NodeType *temp = first;
    int sum = 0;

    while (temp != NULL) {
        sum += temp->info;
        temp = temp->next;
    }

    printf("Sum of all node values: %d\n", sum);
}

// Function to count nodes
void count_nodes() {
    NodeType *temp = first;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total nodes: %d\n", count);
}

// Function to display the linked list
void display() {
    NodeType *temp = first;

    if (first == NULL) {
        printf("Empty linked list\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}
