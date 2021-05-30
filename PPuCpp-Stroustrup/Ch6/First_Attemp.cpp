#include "std_lib_facilities.h"

/* First attempt at writing a calculator with + and -
 */

int main()
{
    cout << "Please enter an expression containing either + or -: ";
    
    int lval;
    int rval;
    char op;
    int res;

    cin >> lval >> op >> rval;

    if(op == '+'){
        res = lval + rval;
    } else if(op == '-'){
        res = lval - rval;
    }

    cout << "Result : " << res << endl;
    return 0;
}