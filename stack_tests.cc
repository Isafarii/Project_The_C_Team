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

TEST(IntStackTest, GreaterThan) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_greater_than(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, -1);
}

TEST(IntStackTest, And) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_and(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, -1);
}

TEST(IntStackTest, Or) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_or(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, -1);
}

TEST(IntStackTest, Swap) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_swap(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 10);
}

TEST(IntStackTest, Over) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_over(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 20);
}

TEST(IntStackTest, Rot) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);

    int_stack_rot(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 10);
}

TEST(IntStackTest, Drop) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);

    int_stack_drop(&stack);
    EXPECT_EQ(stack.size, 0);
}

TEST(IntStackTest, Dup) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);

    int_stack_dup(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 10);
}

TEST(IntStackTest, TwoOver) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);
    int_stack_push(&stack, 40);

    int_stack_two_over(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 20);
}

TEST(IntStackTest, TwoDrop) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_two_drop(&stack);
    EXPECT_EQ(stack.size, 0);
}

TEST(IntStackTest, TwoSwap) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);
    int_stack_push(&stack, 40);

    int_stack_two_swap(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 30);
}

TEST(IntStackTest, Add) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_add(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 30);
}

TEST(IntStackTest, Sub) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_sub(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 10);
}

TEST(IntStackTest, Mul) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_mul(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 200);
}

TEST(IntStackTest, Div) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    int_stack_div(&stack);
    int top_value;
    int_stack_top(&stack, &top_value);
    EXPECT_EQ(top_value, 2);
}

TEST(IntStackTest, Print) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    
    testing::internal::CaptureStdout();  // Redirect stdout for testing
    int_stack_print(&stack, std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0: 20\n1: 10\n\n");
}

TEST(IntStackTest, Size) {
    int_stack_t stack;
    int_stack_init(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);

    EXPECT_EQ(int_stack_size(&stack), 2);
}

TEST(IntStackTest, Capacity) {
    int_stack_t stack;
    int_stack_init(&stack, 5);

    EXPECT_EQ(int_stack_capacity(&stack), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
