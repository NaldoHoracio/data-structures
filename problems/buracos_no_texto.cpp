//
// Created by ehstos on 10/02/17.
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, buraco;
    cin >> n;//Lendo n;
    char nome[101];

    for (int i = 0; i < n; ++i) {
        buraco = 0;
        scanf("%s", nome);
        for (int j = 0; nome[j] ; ++j) {
            if(nome[j] == 'A' || nome[j] == 'D' || nome[j] == 'O' || nome[j] == 'P' || nome[j] == 'Q' || nome[j] == 'R') buraco++;
            else if(nome[j] == 'B') buraco += 2;
            /*
            switch (nome[j])
            {
                case  'A': buraco++;
                    break;
                case 'B': buraco += 2;
                    break;
                case 'D': buraco++;
                    break;
                case 'O': buraco++;
                    break;
                case 'P': buraco++;
                    break;
                case 'Q': buraco++;
                    break;
                case 'R': buraco++;
                    break;
                default: buraco += 0;
                    break;
            }*/

        }
        printf("%d\n", buraco);
    }
    return 0;
}