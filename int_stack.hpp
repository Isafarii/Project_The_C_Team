#ifndef INT_STACK_HPP
#define INT_STACK_HPP

#include <iostream>

struct int_entry_t {
    int value;
    struct int_entry_t* next;
};

struct int_stack_t {
    int_entry_t* head;
    int size;
    int capacity; 
};

void int_stack_init(int_stack_t* stk, int capacity);
int int_stack_push(int_stack_t* stk, int value);
void int_stack_print_top(int_stack_t* stk);
int int_stack_equal(int_stack_t* stk);
int int_stack_less_than(int_stack_t* stk);
int int_stack_greater_than(int_stack_t* stk);
int int_stack_and(int_stack_t* stk);
int int_stack_or(int_stack_t* stk);
int int_stack_pop(int_stack_t* stk, int* top_value);
int int_stack_top(int_stack_t* stk, int* top_value);
int int_stack_dup(int_stack_t* stk);
int int_stack_swap(int_stack_t* stk);
int int_stack_over(int_stack_t* stk);
int int_stack_rot(int_stack_t* stk);
int int_stack_drop(int_stack_t* stk);
int int_stack_two_dup(int_stack_t* stk);
int int_stack_two_over(int_stack_t* stk);
int int_stack_two_drop(int_stack_t* stk);
int int_stack_two_swap(int_stack_t* stk);
int int_stack_add(int_stack_t* stk);
int int_stack_sub(int_stack_t* stk);
int int_stack_mul(int_stack_t* stk);
int int_stack_div(int_stack_t* stk);
void int_stack_print(int_stack_t* stk, std::ostream& os);
int int_stack_size(int_stack_t* stk);
int int_stack_capacity(int_stack_t* stk);

#endif