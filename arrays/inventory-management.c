// This is a simple console-based inventory system 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define INITIAL_ARRAY_CAPACITY 2
#define INITIAL_ARRAY_SIZE 0

// data model
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void remove_newline(char *str);

int main(void) {
    // initial states
    int size = INITIAL_ARRAY_SIZE, capacity = INITIAL_ARRAY_CAPACITY;
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

    // dynamic insertion
    while (productNum > 0) {

        // resize array if needed
        if (size == capacity) {
            int new_capacity = capacity * 2;
            Product *temp = realloc(details, new_capacity * sizeof(Product));
            if (!temp) {
                printf("Reallocation of memory failed.\n");
                free(details);
                return 1;
            }
            details = temp;
            capacity = new_capacity;
        }

        // take input into details[size]
        printf("Name of the product: ");
        fgets(details[size].name, MAX_NAME_LENGTH, stdin);
        remove_newline(details[size].name);

        printf("Quantity: ");
        scanf("%d", &details[size].quantity);
        getchar();

        printf("Price: $");
        scanf("%f", &details[size].price);
        getchar();

        // increment size after insertion
        size++;
        productNum--;
    }

    // print the details
    printf("\nProduct details:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", details[i].name);
        printf("Quantity: %d\n", details[i].quantity);
        printf("Price: $%.2f/qty\n", details[i].price);
        printf("Total price: $%.2f\n\n", details[i].quantity * details[i].price);
    }

    // calculate the total stock value
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += details[i].quantity * details[i].price;
    }

    printf("The total stock is valued at: $%.2f\n", sum);

    free(details);
    return 0;
}

void remove_newline(char *str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}
