// False detection -> break right away,  True case -> continue (analysis in detail needed)
#include <iostream>
#include <string>       // string str; getline (cin, str); str.length ();
#include <stack>        // stack <char> s; s.push (c), s.pop (), s.empty (), s.top ();
using namespace std;

int main (void)
{
    while (1)
    {
        string str; getline (cin, str);
        if (str == ".")
            break;

        // for each test case.
        stack <char> s;
        bool balance = true;
        for (unsigned int i = 0; i < str.length (); i++)
        {
            char c = str[i];

            // input branch.
            if ((c == '(') || (c == '[')) {
                s.push (c);
                // cout << c << ' ';
            }
            else if (c == ')') {
                if (!s.empty () && s.top () == '(') {
                    s.pop ();
                    // cout << c << ' ';
                }
                else {
                    balance = false;
                    break;
                }
            }
            else if (c == ']') {
                if (!s.empty () && s.top () == '[') {
                    s.pop ();
                    // cout << c << ' ';
                }
                else {
                    balance = false;
                    break;
                }
            }
        } // end of for.

        // Print result.
        if (s.empty () && balance) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
    
    return 0;
}