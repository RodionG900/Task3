
#include<cstdlib>
#include<cstring>
#include <iostream>
#include <string>
using namespace std;
struct polynom
{
    int deg;
    int coef;
    polynom *next;
};
typedef polynom *Pointer;
Pointer Head = NULL;
int M = 0;
void input()
{
    Pointer NewEl = NULL;
    int i, k = 0;
    char pol[100], p[100];
    cout << "vvedite polynom: ";
    cin >> pol;
    int N = strlen(pol);
    for (i = 0; i < N; i++)
    {
        if ((i != N - 1) && (pol[i] != 'x') && (pol[i] != '^') && (pol[i] != '+') && (pol[i] != '-'))
        {
            p[k] = pol[i];
            k++;
        }
        else if (pol[i] == 'x')
        {
            p[k] = '\0';
            k = 0;
            NewEl = new polynom;
            NewEl->coef = atof(p);
            NewEl->next = Head;
            Head = NewEl;
            M++;
        }
        else if ((i == N - 1) || (pol[i] == '+') || (pol[i] == '-'))
        {
            if (i == N - 1)
            {
                p[k] = pol[i];
                k++;
            }
            p[k] = '\0';
            k = 1;
            if (NewEl)
                NewEl->deg = atof(p);
            p[0] = pol[i];
        }
    }
}

void diff_output(Pointer &q)
{
    if (q)
    {
        diff_output(q->next);
        q->coef = q->coef * q->deg;
        (q->deg)--;
        if ((q->coef != 0) && (q->deg >= 0))
        {
            if ((q->next != NULL) && (q->coef > 0))
                cout << "+" << q->coef << "x^" << q->deg;
            else
                cout << q->coef << "x^" << q->deg;
        }
    }
}

int main()
{
    input();
    cout << "\nPolynom: ";
    diff_output(Head);
}
