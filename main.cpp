#include "int_stack.hpp"

#include <iostream>

#include <sstream>

#include <string>

#include <cstdlib>

int main() {
int_stack_t stack;
int_stack_init( &stack, 100); //initalize with 100

std::string input;
std::cout << "Forth Interpreter. Type \"quit \" to exit.\n";

while (true) {
    std::cout << ">> ";
    std::getline(std::cin, input);

    if (input == "quit") {
        break;
    }


    std::istringstream iss(input);
    std::string token;
    bool input_done = false; 

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        int_stack_push(&stack, std::stoi(token));
        input_done = true;
        } else {
            if (token == "+") {
                int_stack_add( &stack);
            } else if (token == "-") {
                int_stack_sub( &stack);
            } else if (token == "*") {
                int_stack_mul( &stack);
            } else if (token == "/") {
                int_stack_div( &stack);
            } else if (token == "dup") {
                int_stack_dup( &stack);
            } else if (token == "swap") {
                int_stack_swap( &stack);
            } else if (token == "drop") {
                int_stack_drop( &stack);
            } else if (token == "over") {
                int_stack_over( &stack);
            } else if (token == "rot") {
                int_stack_rot( &stack);
            } else {
                std::cout << "Unknown command: " << token << "\n";
                }
            }
        }
        if(input_done){
            std::cout << "Stack:";
            int_stack_print(&stack,std::cout);
            std::cout << std::endl;
        }
        else {
            std::cout << "Please try valid input";
        }
    }
    return 0;
}