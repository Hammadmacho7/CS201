//
// Created by Hammad Khan Musakhel on 5/22/20.
//
#include "algebricExpression.h"
#include "string"


string algebricExpression::convert2postfix(string exp) {
    exp = '(' + exp + ')';
    int l = exp.size();
    Stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {

        if (isalpha(exp[i]) || isdigit(exp[i]))
            output += exp[i];


        else if (exp[i] == '(')
            char_stack.push('(');


        else if (exp[i] == ')') {

            while (char_stack.peek() != '(') {
                output += char_stack.peek();
                char_stack.pop();
            }


            char_stack.pop();
        }

            // Operator found
        else {

            if (checkOperator(char_stack.peek())) {
                while (priority(exp[i])
                       <= priority(char_stack.peek())) {
                    output += char_stack.peek();
                    char_stack.pop();
                }
                char_stack.push(exp[i]);
            }
        }
    }
    return output;
}

bool algebricExpression::checkOperand(char ch)
{

    return isdigit(ch);
}

double algebricExpression::evaluatePrefix(const string exp)
{
    Stack<double> stack;

    for (int j = exp.size() - 1; j >= 0; j--) {

        // push operand to Stack
        if (checkOperand(exp[j]))
            stack.push(exp[j] - '0');

        else {

            // operator
            double check = stack.peek();
            stack.pop();
            double check2 = stack.peek();
            stack.pop();


            switch (exp[j]) {

                case '-':
                    stack.push(check - check2);
                    break;
                case '+':
                    stack.push(check + check2);
                    break;
                case '/':
                    stack.push(check / check2);
                    break;
                case '*':
                    stack.push(check * check2);
                    break;

            }
        }
    }

    return stack.peek();
}


int algebricExpression::priority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}



string algebricExpression::infix2prefix(string infix) {

    int l = infix.size();

    // reverse infix
    reverse(infix.begin(), infix.end());


    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = convert2postfix(infix);

    // reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

bool algebricExpression::checkOperator(char ch)
{
    return (!isalpha(ch) && !isdigit(ch));
}