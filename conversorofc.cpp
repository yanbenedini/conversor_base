#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//Funcao para converter numero para decimal
string converter_decimal(string numero, int base_) {
    int soma = 0;
    float mult;
    string soma_str;
    for (int i = numero.length() - 1, n = 0; n < numero.length() && i >= 0; i--, n++) {
        	int digito;
            if (isdigit(numero[i])) { //Testa se o numero[i] eh um digito ente 0 e 9
				digito = numero[i] - '0';// Convertendo o caractere em um número inteiro
			} else {
				switch (numero[i]) {
				case 'A':
					digito = 10;
					break;
				case 'B':
					digito = 11;
					break;
				case 'C':
					digito = 12;
					break;
				case 'D':
					digito = 13;
					break;
				case 'E':
					digito = 14;
					break;
				case 'F':
					digito = 15;
					break;
				default:
					break;
				}
			}
        	int mult = (digito * pow(base_, n));
			soma += mult;
            
            soma_str = to_string(soma);
    }
    return soma_str;
}

//Funcao para converter um numero decimal para hexadecimal:
string decimalParaHexadecimal(string numero) {
    int numero_int;
    numero_int = stoi(numero);
    if (numero_int == 0) return "0";
    
    string hexadecimal = "";
    while (numero_int > 0) {
        int resto = numero_int % 16;
        if (resto < 10)
            hexadecimal = to_string(resto) + hexadecimal;
        else
            hexadecimal = char(resto - 10 + 'A') + hexadecimal;
        numero_int /= 16;
    }
    return hexadecimal;
}

// Funcao para converter um numero decimal para binario, ternario ou octal:
string decimalParaBOT(string numero, int bot) {
    int numero_int = stoi(numero);
    if (numero_int == 0) return "0";
    
    string result = "";
    while (numero_int > 0) {
        result = to_string(numero_int % bot) + result;
        numero_int /= bot;
    }
    return result;
}


int main(){

    //Criando as variaveis:
    bool valid = false;
	string str_numero;
	int base1;
    int base2;
	//Fazendo as perguntas para o leitor:
	cout << "Qual algarismo voce deseja mudar de base?: \n";
	cin >> str_numero;
    
    //Testando se o numero inserido eh valido ou nao
    while (valid == false) {
        for (int i = str_numero.length() - 1; i >= 0; i--) {
            if (!isdigit(str_numero[i]) && str_numero[i] != 'A' && str_numero[i] != 'B' && str_numero[i] != 'C' && str_numero[i] != 'D' && str_numero[i] != 'E' && str_numero[i] != 'F') {
                cout << "Um dos caracteres inseridos para a conversao nao eh valido para essa base, por favor tente novamente: \n";
                cout << "Qual algarismo voce deseja mudar de base?: \n";
                valid = false;
                cin >> str_numero;
                i = str_numero.length();
            } else {
                valid = true;
            }
        }
    }
        
    cout << "E em qual base esta esse algarismo?: \n";
	cout << "2 - Base Binaria   3 - Base Ternaria   8 - Base Octal    10 - Base Decimal     16 - Base Hexadecimal\n";
	cin >> base1;

    //Testando se as bases inseridas sao validas ou nao
    while (base1 != 2 && base1 != 3 && base1 != 8 && base1 != 10 && base1 != 16) {
		cout << "informacao invalida, tente novamente...\n";
		cin >> base1;
	}

    cout << "Para qual base voce deseja transformar esse numero?: \n";
	cout << "2 - Base Binaria   3 - Base Ternaria    8 - Base Octal     10 - Base Decimal     16 - Base Hexadecimal\n";
	cin >> base2;
    
    while (base2 != 2 && base2 != 3 && base2 != 8 && base2 != 10 && base2 != 16) {
		cout << "informacao invalida, tente novamente...\n";
		cin >> base2;
	}

    //Printando os resultados no terminal
    if (base2 == 10) {
        cout << converter_decimal(str_numero, base1) << endl;
    } else if (base2 == 16) {
        str_numero = converter_decimal(str_numero, base1);
        cout << decimalParaHexadecimal(str_numero) << endl;
    } else {
        str_numero = converter_decimal(str_numero, base1);
        cout << decimalParaBOT(str_numero, base2) << endl;
    }

    return 0;
}