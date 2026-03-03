// This is a simple console-based inventory management system 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// data model
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void remove_newline(char *str);

int main(void) {
    // initial states
    int size = 0, capacity = 2;
    Product *details = malloc(capacity * sizeof(Product));
    if (details == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    int productNum;
    printf("How many products details do you want to enter?: ");
    scanf("%d", &productNum);
    getchar(); // clear the buffer

    printf("Enter the details below:\n");
    for (int i = 0; i < productNum; i++) {

        if (size == capacity) {
            int new_capacity = capacity * 2;
            Product *temp = realloc(details, new_capacity * sizeof(Product));
            if (!temp) {
                printf("Reallocation of memory failed.\n");
                free(details);
                return 1;
            }

            details = temp;
        }

        printf("Name of the product: ");
        fgets(details[i].name, MAX_NAME_LENGTH, stdin);
        remove_newline(details[i].name);

        printf("Quantity: ");
        scanf("%d", &details[i].quantity);
        getchar(); // clear the buffer

        printf("Price: $");
        scanf("%f", &details[i].price);
        getchar();

        size++;
    }

    // printf the details
    printf("\nProduct details:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s", details[i].name);
        printf("Quantity: %d\n", details[i].quantity);
        printf("Price: $%.2f / qty\n", details[i].price);
    }
    printf("\n");

    free(details);
    return 0;
}

void remove_newline(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}