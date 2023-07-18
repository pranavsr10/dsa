#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Expression {
public:
    struct Operator {
        char symbol;
        int weight;
    };

private:
    vector<Operator> operators;

public:
    void add(char op) {
        operators.push_back({op, weight(op)});
    }

    Operator getHighestPrecedenceOperator() {
        auto it = max_element(operators.begin(), operators.end(),
            [](const Operator& op1, const Operator& op2) {
                return op1.weight < op2.weight;
            });

        Operator highest = *it;
        operators.erase(it);
        return highest;
    }

    bool empty() const {
        return operators.empty();
    }

private:
    int weight(char op) {
        unordered_map<char, int> weights{
            {'+', 2}, {'-', 1}, {'*', 4}, {'/', 5}, {'%', 3},
            {'U', 7}, {'u', 6}
        };

        return weights[op];
    }
};

int main() {
    string expression;
    cout << "Enter the Expression: ";
    getline(cin, expression);

    Expression obj;
    string operators = "+-*/%Uu";

    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];
        if (operators.find(c) != string::npos) {
            if (c == '+' || c == '-') {
                if (expression[i - 1] == '+') {
                    obj.add('U');
                    obj.add('+');
                }
                else if (expression[i - 1] == '-') {
                    obj.add('u');
                    obj.add('-');
                }
            }
            else {
                obj.add(c);
            }
        }
    }

    while (!obj.empty()) {
        Expression::Operator highest = obj.getHighestPrecedenceOperator();
        cout << "Operator with highest precedence: " << highest.symbol << endl;
    }

    return 0;
}
