#include "unity/unity.h"
#include "stack.h"
#include <stdlib.h>

/* Функция для инициализации тестового окружения */
void setUp(void) {
}

/* Функция для очистки после тестов */
void tearDown(void) {
}

/* Тест: Инициализация стека */
void test_initStack(void) {
    Stack stack;
    initStack(&stack);
    TEST_ASSERT_TRUE(isEmpty(&stack));
}

/* Тест: Добавление элемента */
void test_push(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    TEST_ASSERT_FALSE(isEmpty(&stack));
    TEST_ASSERT_EQUAL(10, getTop(&stack)->data);
}

/* Тест: Удаление элемента */
void test_pop(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    pop(&stack);
    TEST_ASSERT_EQUAL(10, getTop(&stack)->data);
    pop(&stack);
    TEST_ASSERT_TRUE(isEmpty(&stack));
}

/* Тест: Уничтожение стека */
void test_destroyStack(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    destroyStack(&stack);
    TEST_ASSERT_TRUE(isEmpty(&stack));
}

/* Тест: Поиск по индексу */
void test_searchByIndex(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    Node* result = searchByIndex(&stack, 1);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(20, result->data);
    result = searchByIndex(&stack, 5);
    TEST_ASSERT_NULL(result);
}

/* Тест: Обход стека */
void test_traverseStack(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Перехват вывода
    char buffer[100];
    freopen("/dev/null", "a", stdout);
    traverseStack(&stack);
    fclose(stdout);
}

/* Тест: Поиск по значению */
void test_searchByValue(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Поиск существующего элемента
    Node* result = searchByValue(&stack, 20);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(20, result->data);

    // Поиск несуществующего элемента
    result = searchByValue(&stack, 40);
    TEST_ASSERT_NULL(result);

    // Поиск в пустом стеке
    destroyStack(&stack);
    result = searchByValue(&stack, 10);
    TEST_ASSERT_NULL(result);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_initStack);
    RUN_TEST(test_push);
    RUN_TEST(test_pop);
    RUN_TEST(test_destroyStack);
    RUN_TEST(test_searchByValue);
    RUN_TEST(test_searchByIndex);
    RUN_TEST(test_traverseStack);

    return UNITY_END();
}
