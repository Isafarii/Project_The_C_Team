#include "gtest/gtest.h"
#include "int_stack.hpp"  

TEST(IntStackTest, Initialization) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    EXPECT_EQ(stack.size, 0);
    EXPECT_EQ(stack.capacity, 10);
    EXPECT_EQ(stack.head, nullptr);
}

TEST(IntStackTest, PushAndPop) {
    int_stack_t stack;
    int_stack_init(&stack, 5);

    int_stack_push(&stack, 10);
    EXPECT_EQ(stack.size, 1);
    EXPECT_EQ(stack.head->value, 10);

    int top_value;
    int_stack_pop(&stack, &top_value);
    EXPECT_EQ(top_value, 10);
    EXPECT_EQ(stack.size, 0);
    EXPECT_EQ(stack.head, nullptr);
}

TEST(IntStackTest, Top) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 20);
}