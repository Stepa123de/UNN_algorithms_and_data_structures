//
// Created by Стёпа on 02.12.2022.
//

#ifndef UNTITLED4_EXPRESSIONVALIDATION_H
#define UNTITLED4_EXPRESSIONVALIDATION_H


#include <string>
#include <iostream>
#include "Table.h"

class ExpressionValidation {
public:
    bool ExpVal(const std::string& str) const
    {
        bool isLastSign = false;
        bool isLastSk = false;
        bool isLastCl = false;
        int bracketsNum = 0;
        
        for(char c:str)
        {
            if ((c <= 'z' && c >= 'a' )||(c <= '9' && c >= '0'))
            {
                if (isLastCl) return false;
                   isLastSign = false;
                   isLastSk = false;
                   isLastCl = false;
            }
            else
            {
                if (c == '(')
                {
                    isLastSk = true;
                    isLastCl = false;
                    bracketsNum++;
                }
                else if (c == ')')
                {
                    bracketsNum--;
                    isLastCl = true;
                    if (bracketsNum < 0 ) return false;
                    if (isLastSk == true) return false;
                }
                else
                {
                    if(isLastSign) return false;
                    isLastSign = true;
                    isLastCl = false;
                    isLastSk = false;
                }
            }
        }
        return !(bracketsNum != 0);
    }

};


#endif //UNTITLED4_EXPRESSIONVALIDATION_H
