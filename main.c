#include <stdio.h>
#include "stack.h"  // Заголовочный файл для стека

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("After pushing elements:\n");
    traverseStack(&stack);

    pop(&stack);

    printf("After popping an element:\n");
    traverseStack(&stack);

    Node* searchResult = searchByValue(&stack, 20);
    if (searchResult != NULL) {
        printf("Found element with value 20.\n");
    } else {
        printf("Element with value 20 not found.\n");
    }

    Node* topElement = getTop(&stack);
    if (topElement != NULL) {
        printf("Top element: %d\n", topElement->data);
    }

    return 0;
}
