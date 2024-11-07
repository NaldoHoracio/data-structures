//
// Created by santoseh on 2/10/17.
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Cv ,Ce, Cs, Fv, Fe, Fs;
    cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;

    int Pc, Pf;

    Pc = 3*Cv + Ce;
    Pf = 3*Fv + Fe;

    if( Pc > Pf) cout << "C" << endl;
    else if( Pc == Pf )
    {
        if(Cs > Fs) cout << "C" << endl;
        else if(Cs == Fs) cout << "=" << endl;
        else cout << "F" << endl;
    }
    else cout << "F" << endl;

    return 0;
}

