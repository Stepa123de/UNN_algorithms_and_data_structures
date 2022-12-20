#include <iostream>
#include "PostfixExpression.h"
int main() {
    //5a+7b*(10c/2sin(5))
    std::string s = "5+2";
    PostfixExpression ans = PostfixExpression(s);
    std::cout << ans.GetStrAns() << std::endl;
    std::cout << ans.GetTrueAns() << std::endl;
    //4 7 y * + 4 x cot * tan -
    //4 7 y * + 4 x ctg * tg -
    return 0;
}
