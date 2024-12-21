#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define NUM_OPERATIONS 1000000  // Количество операций для бенчмарка

// Функция для измерения времени выполнения push
void benchmarkPush() {
    Stack stack;
    initStack(&stack);

    clock_t start = clock();

    // Пушим элементы в стек
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        push(&stack, i);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  // Время в секундах
    printf("Time taken for %d push operations: %f seconds\n", NUM_OPERATIONS, time_taken);
}

// Функция для измерения времени выполнения pop
void benchmarkPop() {
    Stack stack;
    initStack(&stack);

    // Сначала заполняем стек
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        push(&stack, i);
    }

    clock_t start = clock();

    // Попаем элементы из стека
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        pop(&stack);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  // Время в секундах
    printf("Time taken for %d pop operations: %f seconds\n", NUM_OPERATIONS, time_taken);
}

int main() {
    benchmarkPush();
    benchmarkPop();

    return 0;
}
