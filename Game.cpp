#include "int_stack.hpp"


#include <vector> //for multiple value challenges

#include <algorithm> //reverse

#include <iostream>

#include <stack>

#include <string>

#include <chrono>

#include <thread>

#include "functions.hpp"

std::vector < int > targetValueVector; //new
std::stack < int > dataStack;

void push(int value) {
  dataStack.push(value);
}

// void init_prompt(const std::vector<int>& values){
//     prompt_values = values;
//     std:count << "Put these numbers";
//     for (int x : values) {
//         std:cout << value << " ";

//     }
//     std:cout << std::endl;
// }


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

void pushOp(std::stack<int>& stack, const std::vector<int>& values){
  for (int val: values){
    stack.push(val); 
  }
}

std::vector<Entity> initializeEntities() {
    return {
        {"Goblin", "Push the numbers 3 and 1 onto the stack in this order!", pushOp, {1, 3}},
        {"Beast", "Push the number 5 onto the stack!", pushOp, {5}},
        {"Wizard", "Push the numbers 2 and 2 onto the stack in this order!", pushOp, {2, 2}}
    };
}




void displayStack() {
  std::cout << "Stack: ";
  std::stack < int > tempStack = dataStack;
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
    auto elapsedTime = std::chrono::duration_cast < std::chrono::seconds > (currentTime - startTime).count();

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

void displayRoomDescription(const std::string & description) {
  std::cout << description << std::endl;
}
//int targetValue = -1;
//initialize the global targetValue variable. this should be named different than nonglobal 'comparevalue' etc. 
bool compareStack(const std::vector<int>& requiredValues) {
    std::stack<int> tempStack(dataStack); // Make a copy of the actual stack to manipulate and check
    for (auto it = requiredValues.rbegin(); it != requiredValues.rend(); ++it) {
        if (tempStack.empty() || tempStack.top() != *it) {
            return false; // The stack is empty
        }
        tempStack.pop();
    }
    return tempStack.empty(); // make sure its empty
}


void initTargetValueVector(const std::vector < int > & order) {
  targetValueVector = order;
}

void displaySuccessMessage(const std::string & message) {
  std::cout << message << std::endl;
}

void displayChallengeInstructions(const std::string & instructions, int targetValue, int timeLimit) {
  std::cout << "A goblin has appeared and will only grant passage if you can solve this challenge:\n" << std::endl;
  std::cout << instructions << std::endl;
  std::cout << "You have " << timeLimit << " seconds to complete this challenge.\n" << std::endl;
  std::cout << "Clear any remaining stack values first.\n" << std::endl;


}

void displayFailureMessage(const std::string & message) {
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

  bool newChallengeNeeded = true;
  Entity currentEntity;


  srand(time(NULL));
  std::vector<Entity> entities = initializeEntities();




  displayIntroduction();

  
  //displayChallengeInstructions(testInstructions, testTargetValue, testTimeLimit);
  std::cout << "Enter commands (push, pop, double, swap) or 'quit' to exit:" << std::endl;

  // targetValueVector = {
  //   7,
  //   5
  // }; //the demanded 'stack' 

  // Start the challenge timer
  // bool challengeSuccess = simulateChallenge(7, 10);
  // if (!challengeSuccess) {
  //     displayFailureMessage("Challenge failed!");
  //     return 0; // Exit the game if challenge fails
  // }

  // Player interaction loop
  std::string command;
  while (true) {
    if (newChallengeNeeded)  {
      currentEntity = entities[rand() % entities.size()];
      displayChallengeInstructions(currentEntity.description, currentEntity.requiredValues.back(), 10);
      newChallengeNeeded = false;
    }

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
    } else if (command == "quit") {
      break;
    } else {
      std::cout << "Invalid command! Please enter 'push', 'pop', 'double', 'swap', or 'exit'." << std::endl;
    }

    displayStack();
    //check if the stack matches the stack demanded by the entity/enemy

    //'targetValue'

   if (compareStack(currentEntity.requiredValues)) {
    displaySuccessMessage("\nRound success!\n");
    newChallengeNeeded = true; 
   }
  

  }
  return 0;
}
