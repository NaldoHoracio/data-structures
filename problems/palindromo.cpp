#include <bits/stdc++.h>

using namespace std;

//Macro para maior valor entre dois numeros
#define max_value(a, b) ((a) > (b)) ? (a):(b)

int max_sub_palindrome(char *input, int begin_seq, int end_seq)
{
	//Melhor caso possivel - input tem 1 caracter
	if(begin_seq == end_seq)
	{
		return 1;
	}
	//Caso 2 - seq com apenas dois caracteres e eles sao iguais
	else if(input[begin_seq] == input[end_seq] && (begin_seq + 1) == end_seq)
	{
		return 2;
	}
	//Caso 3 - begin e end s�o iguais
	//Ent�o a maior subsequencia eh dada
	//Pela maior sub seq sem os extremos mais 2 (begin and last) 
	else if(input[begin_seq] == input[end_seq])
	{
		return (max_sub_palindrome(input, begin_seq+1, end_seq-1) + 2);
	}
	//Se nao for nenhum dos casos acima
	//Entao a maior subsequencia eh
	//A maior valor entre as sequencias que come�am em begin_seq e terminam valor end_seq -1 ^
	//E come�am em begin_seq+1 e terminam em end_seq
	else{
		return max_value(max_sub_palindrome(input, begin_seq, end_seq-1),
			max_sub_palindrome(input, begin_seq+1, end_seq));
	}
}

void string_reverse(char *input, char *output)
{
	int size = strlen(input);
	int current = size - 1;
	while(current >= 0)
	{
		output[size - current - 1] = *(input+current);
		current-=1;
	}
	output[size] = '\0';
}

int main()
{
	int numb_case;//Var numero de casos na entrada

	//cout << "Digite o numero de casos:" << endl;
	cin >> numb_case;//Lendo o numero de casos
	getchar();//Limpando buffer para nao influenciar na leitura de caracteres

	//cout << "Digite uma sequencia:" << endl;
	char input[1024];//Entrada
	char input_aux[1024];
	int cont_space_begin = 0, cont_space_end = 0;
	//string input_str;
	//char aux;

	for (int cont_n_seq = 0; cont_n_seq < numb_case; ++cont_n_seq)
	{
		
		cin.getline(input,1024);//Le a entrada mesmo com espa�o e exclui o \n da cadeia de caracter
		
		int size_seq = strlen(input);//Para cada valor lido pega o tamanho da sequencia

		//Conta o numero de espacos no comeco da string ate o primeiro caracter
		for(int i = 0; input[i] == ' '; i++)
		{
			cont_space_begin++;
		}

		//Inverte a string para contar o numero de espacos no fim da string
		string_reverse(input,input_aux);

		//Conta o numero de espacos no comeco da string ate o primeiro caracter
		//Aqui input_aux e input invertida
		for(int j = 0; input_aux[j] == ' '; j++)
		{
			cont_space_end++;
		}

		//Quando o size_seq e igual ao num de espacos a string e vazia
		if(size_seq == cont_space_begin)
		{
			cout << "0" << endl;
		}
		//A string nao e vazia
		else if(size_seq != cont_space_begin && (cont_space_begin != 0 || cont_space_end != 0))
		{
			if(max_sub_palindrome(input,0,size_seq-1) > cont_space_begin)
			{
				cout << "" << max_sub_palindrome(input,0,size_seq-1) - 2*cont_space_end << endl;
			}
			else{
				cout << "" << cont_space_begin << endl;
			}
		}
		else if(size_seq != cont_space_begin && (cont_space_begin == 0 && cont_space_end == 0))
		{
			cout << "" << max_sub_palindrome(input,0,size_seq-1) << endl;
		}

    	//cout << "Numero de espacos no comeco:" << cont_space_begin << endl;
    	//cout << "Input:" << input << endl;
    	//cout << "Numero de espacos no fim:" << cont_space_end << endl;
    	//cout << "Input aux:" << input_aux << endl;

    	//Imprime a maior sub seq palindroma
		//cout << "Max size palindrome sequence: " << max_sub_palindrome(input, 0, size_seq-1) << endl;
		//cout << "" << max_sub_palindrome(input, 0, size_seq-1) << endl;		

	}

	return (0);
}