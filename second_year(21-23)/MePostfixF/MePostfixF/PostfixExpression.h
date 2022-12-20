//
// Created by Стёпа on 02.12.2022.
//

#ifndef UNTITLED4_POSTFIXEXPRESSION_H
#define UNTITLED4_POSTFIXEXPRESSION_H


#include <string>
#include "TStack.h"

#include "ExpressionValidation.h"

class PostfixExpression {
private:
    //std::string in, out = "";
    TStack<std::string> strIn,strOut,ramStack;
    Table<std::string, int> table = Table<std::string,int>(12);

    void tabelInit() {
        std::string keys[] = {"(", ")", "+", "-", "*", "/", "^","sin","cos","tg","ctg"};
        int values[] = {0, 1, 2, 2, 3, 3, 4,5,5,5,5};
       for (int i = 0; i < 11; i++) {
            table.Add(keys[i], values[i]);
        }
    }

    enum charVars {
        num, simv, non,cl
    };

    void creatStack(std::string s)
    {
        charVars last = non;
        std::string lastString = "";
        for (char c: s) {
            if (c <= 'z' && c >= 'a') {
                if (last == num) {
                    strIn.Push(lastString);
                    strIn.Push("*");
                    lastString = "";
                }
                lastString += c;
                last = simv;
            } else {
                if (c <= '9' && c >= '0' || c == '.') {
                    if (last == simv) {
                        strIn.Push("*");
                        strIn.Push(lastString);
                        lastString = "";
                    }
                    lastString += c;
                    last = num;
                } else {
                    if (last != non) strIn.Push(lastString);
                    if (c == '(' && last == num) strIn.Push("*");
                    lastString = c;
                    strIn.Push(lastString);
                    lastString = "";
                    last = non;
                    
                }
            }
        }
        if (last != non) strIn.Push(lastString);

    }

public:
    PostfixExpression(std::string s)
    {
        bool check = (ExpressionValidation().ExpVal(s));
        if (!check)throw "ExpressionValidation == False";
        tabelInit();
        creatStack(s);
        std::string ist;
        //std::cout << strIn <<std::endl;
        for(int i = 0 ; i < strIn.getSize();i++)
        {
            ist = strIn[i];

            if(!table.isIn(ist))
            {
                strOut.Push(ist);
            }
            else
            {
                if(!strOut.getSize())
                {
                    ramStack.Push(ist);
                }
                else
                {

                    if(ist == ")")
                    {
                        while (ramStack.Top()!="(")
                        {
                            strOut.Push(ramStack.Pop());
                        }
                        ramStack.Pop();
                    }
                    else if(ist == "+" || ist == "-" || ist == "*" || ist == "/" || ist == "^")
                    {
                        while (ramStack.getSize() > 0 && table[ramStack.Top()]>=table[ist])
                        {
                            strOut.Push(ramStack.Pop());
                        }
                        ramStack.Push(ist);
                    }
                    else
                    {
                        ramStack.Push(ist);
                    }
                }
            }
        }
        while(ramStack.getSize() > 0)
        {
            strOut.Push(ramStack.Pop());
        }
        //std::cout << strOut;
    }
    
    std::string GetStrAns()const noexcept {
        std::string out = "";
        for (int i = 0; i < strOut.getSize(); i++)
        {
            out += strOut[i];
            if (i < strOut.getSize() - 1) out += " ";
        }
        return out;
    }

    double GetTrueAns() const noexcept
    {
        TStack<double> ans = TStack<double>(strOut.getSize());
        double a,b;
        for (int i = 0; i < strOut.getSize(); i++) 
        {
            if (!table.isIn(strOut[i]))
            {
                ans.Push(stoi(strOut[i]));
            }
            else 
            {
                if (table[strOut[i]] == 5) //sin cos tg...
                {
                    a = ans.Pop();
                    if (strOut[i] == "cos") ans.Push(cos(a));
                    if (strOut[i] == "sin") ans.Push(sin(a));
                    if (strOut[i] == "tg") ans.Push(tan(a));
                    if (strOut[i] == "ctg") ans.Push(atan(a));
                }
                else 
                {
                    b = ans.Pop();
                    a = ans.Pop();
                    if (strOut[i] == "+") ans.Push(a+b);
                    if (strOut[i] == "-") ans.Push(a-b);
                    if (strOut[i] == "/") ans.Push(a/b);
                    if (strOut[i] == "*") ans.Push(a*b);
                    if (strOut[i] == "^") ans.Push(pow(a,b));

                }
            }
        }
        return ans.Pop();
    }


};


#endif //UNTITLED4_POSTFIXEXPRESSION_H
