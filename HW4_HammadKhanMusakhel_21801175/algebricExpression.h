//
// Created by Hammad Khan Musakhel on 5/22/20.
//

#ifndef HW4_ALGEBRICEXPRESSION_H
#define HW4_ALGEBRICEXPRESSION_H
#include <iostream>
//#include <bits/stdc++.h>
#include "Stack.h"
#include "string"

using namespace std;


class algebricExpression{

public:

    string infix2prefix( const string exp); //infix to prefix
    double evaluatePrefix( const string exp);//evaluation

    static bool checkOperator( char ch);
    bool checkOperand(char ch);
    string convert2postfix( string exp);
    int priority( char op);

};


#endif //HW4_ALGEBRICEXPRESSION_H
