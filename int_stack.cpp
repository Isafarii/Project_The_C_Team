#include "int_stack.hpp"

<<<<<<< HEAD
#include <cstlib>
=======
#include <cstdlib>
>>>>>>> upstream/main

void int_stack_init(int_stack_t* stk, int capacity) {
    stk->head = nullptr;
    stk->size = 0;
    stk->capacity = capacity;
}

int int_stack_push(int_stack_t *stk, int value) {
    if (stk->size >= stk->capacity) {
        printf("Stack is at full capacity.\n");
        return 0; 
    }
    int_entry_t* newEntry = new int_entry_t;
    if (newEntry) {
        newEntry->value = value;
        newEntry->next = stk->head;
        stk->head = newEntry;
        stk->size++;
        return 1;
    }
    return 0;
}

void int_stack_print_top(int_stack_t *stk) {
    int top_value;
    if (int_stack_top(stk, &top_value)) {
        printf("%d", top_value);
    } else {
        printf("Stack is empty\n");
    }
}

int int_stack_greater_than(int_stack_t *stk) {
    if (stk->size < 2) {
        return 0;
    }
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value > top_value ? -1 : 0);
}

int int_stack_and(int_stack_t *stk) {
    if (stk->size < 2) {
        return 0;
    }
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, (top_value != 0) && (next_to_top_value != 0) ? -1 : 0);
}

int int_stack_or(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, (top_value != 0) || (next_to_top_value != 0) ? -1 : 0);
}

int int_stack_pop(int_stack_t* stk, int* top_value) {
    if (stk->size == 0) {
        return 0; // fail
    }
    int_entry_t* entry = stk->head;
    *top_value = entry->value;
    stk->head = entry->next;
    delete entry;
    stk->size--;
    return 1; // success
}

int int_stack_top(int_stack_t* stk, int* top_value) {
    if (stk->size == 0) {
        return 0; // fail
    }
    *top_value = stk->head->value;
    return 1; // success
}

<<<<<<< HEAD
int int_stack_dup(int_stack_t *stk) {
    if (stk->size < 1)
        return 0;
    int top_value;
    int_stack_top(stk, &top_value);
    return int_stack_push(stk, top_value); 
}
=======
>>>>>>> upstream/main

int int_stack_swap(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value); 
}

int int_stack_over(int_stack_t *stk) {
    if (stk->size < 2) 
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_top(stk, &next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, next_to_top_value);
}

int int_stack_rot(int_stack_t *stk) {
    if (stk->size < 3) 
        return 0;
    int top_value, next_to_top_value, third_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_pop(stk, &third_to_top_value);
    int_stack_push(stk, next_to_top_value);
    int_stack_push(stk, top_value);
    return int_stack_push(stk, third_to_top_value);
}

int int_stack_drop(int_stack_t *stk) {
    if (stk->size < 1) 
        return 0;
    int top_value;
    int_stack_pop(stk, &top_value);
    return 1;
}

<<<<<<< HEAD
int int_stack_two_dup(int_stack_t *stk) {
    if (stk->size < 2) 
        return 0;
    int top_value, next_to_top_value;
    int_stack_over(stk);
    int_stack_over(stk);
    return 1;
}

=======
int int_stack_dup(int_stack_t *stk) {
    std::cout << "Attempting to duplicate. Current stack size: " << stk->size << std::endl;
    if (stk->size < 1) {
        std::cout << "Error: Not enough elements to duplicate." << std::endl;
        return 0;
    }
    int top_value;
    if (int_stack_top(stk, &top_value)) {
        std::cout << "Duplicating value: " << top_value << std::endl;
        int result = int_stack_push(stk, top_value);
        std::cout << "New stack size: " << stk->size << std::endl;
        return result;
    } else {
        std::cout << "Error: Failed to access top element." << std::endl;
        return 0;
    }
}


>>>>>>> upstream/main
int int_stack_two_over(int_stack_t *stk) {
    if (stk->size < 4)
        return 0;
    int top_value, next_to_top_value, third_to_top_value, fourth_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_pop(stk, &third_to_top_value);
    int_stack_pop(stk, &fourth_to_top_value);
    int_stack_push(stk, fourth_to_top_value);
    int_stack_push(stk, third_to_top_value);
    int_stack_push(stk, next_to_top_value);
    int_stack_push(stk, top_value);
    int_stack_push(stk, fourth_to_top_value);
    return int_stack_push(stk, third_to_top_value);
}

int int_stack_two_drop(int_stack_t *stk) {
    if (stk->size < 2) 
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return 1; 
}

int int_stack_two_swap(int_stack_t *stk) {
    if (stk->size < 4) {
        return 0;
    }
    int top_value, next_to_top_value, third_to_top_value, fourth_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    int_stack_pop(stk, &third_to_top_value);
    int_stack_pop(stk, &fourth_to_top_value);
    int_stack_push(stk, third_to_top_value);
    return int_stack_push(stk, fourth_to_top_value);
}

int int_stack_add(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, top_value + next_to_top_value);
}

int int_stack_sub(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value - top_value);
}

int int_stack_mul(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
    return int_stack_push(stk, next_to_top_value * top_value);
}

int int_stack_div(int_stack_t *stk) {
    if (stk->size < 2)
        return 0;
    int top_value, next_to_top_value;
    int_stack_pop(stk, &top_value);
    int_stack_pop(stk, &next_to_top_value);
<<<<<<< HEAD
    return int_stack_push(stk, next_to_top_value / top_value);
}

=======
    if (top_value == 0) {
        std::cout << "Divide by zero error." << std::endl;
        int_stack_push(stk, next_to_top_value);  // Restore the popped value
        int_stack_push(stk, top_value);
        return 0;
    }
    return int_stack_push(stk, next_to_top_value / top_value);
}


>>>>>>> upstream/main
void int_stack_print(int_stack_t* stk, std::ostream& os) {
    int_entry_t* entry = stk->head;
    int pos = 0;
    if (stk->size == 0) {
        os << "empty stack\n";
    }

    while (entry != nullptr) {
        os << pos << ": " << entry->value << std::endl;
        entry = entry->next;
        pos++;
    }
    os << std::endl;
}

int int_stack_size(int_stack_t* stk) {
    return stk->size;
}

int int_stack_capacity(int_stack_t* stk) {
    return stk->capacity;
<<<<<<< HEAD
}

=======
}
>>>>>>> upstream/main
