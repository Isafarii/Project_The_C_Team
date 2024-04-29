#include <string>
#include <functional>
#include <vector>
#include <stack>
struct Entity {
    std::string name;
    std::string description;
    std::function<void(std::stack<int>&, const std::vector<int>&)> operation;
    std::vector<int> requiredValues;
};

