#include <iostream>
using namespace std;

typedef struct _fish {
    int r;
    int c;
    int dir;
    bool alive;
} fish;

fish A;
fish B;

int main (void)
{
    fish C;

    cout << A.r << ", " << A.c << ", " << A.dir << ", " << A.alive << endl;
    cout << B.r << ", " << B.c << ", " << B.dir << ", " << B.alive << endl;
    cout << C.r << ", " << C.c << ", " << C.dir << ", " << C.alive << endl;

    C = A;
    cout << C.r << ", " << C.c << ", " << C.dir << ", " << C.alive << endl;

    fish D = {1, 2, 3, true};
    cout << D.r << ", " << D.c << ", " << D.dir << ", " << D.alive << endl;
    return 0;
}