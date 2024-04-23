#include <iostream>
#include <stack>
#include <string>
#include <chrono>
#include <thread>

std::stack<int> dataStack;

void push(int value) {
    dataStack.push(value);
}

int pop() {
    if (dataStack.empty()) {
        std::cerr << "Error: Stack is empty!" << std::endl;
        return 0;
    }
    int value = dataStack.top();
    dataStack.pop();
    return value;
}

void doubleTop() {
    if (dataStack.empty()) {
        std::cerr << "Error: Stack is empty!" << std::endl;
        return;
    }
    int topValue = dataStack.top();
    dataStack.push(2 * topValue);
}

void swapTopTwo() {
    if (dataStack.size() < 2) {
        std::cerr << "Error: Stack does not have enough elements for swap!" << std::endl;
        return;
    }
    int topValue = pop();
    int secondValue = pop();
    push(topValue);
    push(secondValue);
}

void displayStack() {
    std::cout << "Stack: ";
    std::stack<int> tempStack = dataStack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

bool simulateChallenge(int compareValue, int timeLimit) {
    std::cout << "You have " << timeLimit << " seconds to achieve the target value of " << compareValue << " on the stack." << std::endl;
    auto startTime = std::chrono::steady_clock::now();
   
    while (true) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
       
        if (elapsedTime >= timeLimit) {
            std::cout << "Time's up!" << std::endl;
            return false;
        }
       
        if (!dataStack.empty() && dataStack.top() == compareValue) {
            std::cout << "Challenge completed!" << std::endl;
            return true;
        }
       
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void displayRoomDescription(const std::string& description) {
    std::cout << description << std::endl;
}
int targetValue = -1;
//initialize the global targetValue variable. this should be named different than nonglobal 'comparevalue' etc. 
bool compareStack(int compareValue) {
    if(!dataStack.empty() && dataStack.top() == compareValue){
        return true; 
    }
    return false; 
}

void displaySuccessMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void displayChallengeInstructions(const std::string& instructions, int targetValue, int timeLimit) {
    std::cout << "A goblin has appeared and will only grant passage if you can solve this challenge:" << std::endl;
    std::cout << instructions << std::endl;
    std::cout << "You have " << timeLimit << " seconds to complete this challenge." << std::endl;
    
}


void displayFailureMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void displayGameOver() {
    std::cout << "Game over! You were unable to overcome the challenges of the castle. Would you like to try again?" << std::endl;
}

void displayVictory() {
    std::cout << "Congratulations! You have conquered the castle and emerged as the ultimate victor! Thank you for playing Castle Quest." << std::endl;
}

void displayIntroduction() {
    std::cout << "Welcome to Castle Quest!" << std::endl;
    std::cout << "Embark on an epic adventure into the heart of a mysterious castle, where danger and challenges await at every turn." << std::endl;
    std::cout << "In this quest, you'll harness the power of a mystical stack to overcome obstacles, outsmart enemies, and claim victory." << std::endl;
    std::cout << "Are you ready to begin your journey? Let the adventure unfold!" << std::endl;
    std::cout << std::endl;
}



int main() {
    displayIntroduction();

    
    std::cout << "Enter commands (push, pop, double, swap) or 'exit' to quit:" << std::endl;
   
    // Push initial values onto the stack
    //push(5);
    //push(7);
    displayStack();
   
    // Display the first challenge

    //maybe make another function for dynamic changes, otherwise always need to specify 'targetvalue'
    // we can't use '7' in challenge instructions because its not a global targetvalue but an inner variable
    // and i renamed it for clarity/seperation 
    targetValue = 7;
    displayChallengeInstructions("You have 10 seconds to achieve the target value of 7 on the stack.", targetValue, 10);
   
    // Start the challenge timer
    // bool challengeSuccess = simulateChallenge(7, 10);
    // if (!challengeSuccess) {
    //     displayFailureMessage("Challenge failed!");
    //     return 0; // Exit the game if challenge fails
    // }
   
    // Player interaction loop
    std::string command;
    while (true) {
        std::cout << "> ";
        std::cin >> command;
       
        if (command == "push") {
            int value;
            std::cin >> value;
            push(value);
        } else if (command == "pop") {
            pop();
        } else if (command == "double") {
            doubleTop();
        } else if (command == "swap") {
            swapTopTwo();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command! Please enter 'push', 'pop', 'double', 'swap', or 'exit'." << std::endl;
        }
       
        displayStack();
        //check if the stack matches the stack demanded by the entity/enemy
        if (compareStack(targetValue)) {
            displaySuccessMessage("Round success!");
            // If the round is successful, handle what happens next
            break;
        }
        
    }

    return 0;
}
