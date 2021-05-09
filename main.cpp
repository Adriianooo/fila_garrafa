//Adriano Pinheiro Fernandes TIA:32055161

#include "fila.h"
#include <ctime>
#include <iostream>

using namespace std;

void registro(Fila& queue,  char marca1, int estante1, int prateleira1, int gaveta1) {
	garrafa1 modelo1;
	modelo1.marca_agua = marca1;
	modelo1.estante = estante1;
	modelo1.prateleira = prateleira1;
	modelo1.gaveta = gaveta1;
	modelo1.tempo = time(nullptr);
	if (modelo1.marca_agua == 'A' || modelo1.marca_agua == 'B') {
		if (modelo1.marca_agua == 'A') {
			if (EnqueueA(queue, modelo1)) {
				cout << "Registro finalizado.";
			}
			else {
				cout << "Não há mais espaço para essa marca";

			}
		}
		else {
			if (EnqueueB(queue, modelo1)) {
				cout << "Registro finalizado.";
			}
			else {
				cout << "Não há mais espaço para essa marca";
			}
		}
	}
	else {
		cout << "Marca não disponível. logo, vamos cancelar o registro.";
	}
}

void venda(Fila& queue) {
	char marca;
	garrafa1 modelo2;
	cout << "Digite a marca que deseja, ou digite C para incluir qualquer marca: ";
	cin >> marca;
	while (marca != 'A' && marca != 'B' && marca != 'C') {
		cout << "Comando inválido.\n Digite novamente a marca que deseja, ou digite C para qualquer marca:";
		cin >> marca;
	}
	if (marca == 'A') {
		modelo2 = DequeueA(queue);
	}
	else if (marca == 'B') {
		modelo2 = DequeueB(queue);
	}
	else if (marca == 'C') {
		modelo2 = DequeueAny(queue);
	}
	if (modelo2.marca_agua != '0') {
		struct tm data;
		localtime_s(&data, &modelo2.tempo);
		cout << "\nGarrafa vendida:\nMarca: " << modelo2.marca_agua << "\nEstante: " << modelo2.estante << "\nPrateleira: " << modelo2.prateleira << "\nGaveta: " << modelo2.gaveta << "\nData de armazenamento: " << data.tm_mday << "/" << data.tm_mon << "/" << (data.tm_year + 1900) << " " << data.tm_hour << "h" << data.tm_min << "m" << data.tm_sec << "s\n";
	}
	else {
		cout << "Não há mais garrafas no estoque.\n";
	}
	
}

int main()
{
	setlocale(LC_ALL, "");
	Fila queue = Create();
	int estante, prateleira, gaveta;
	char marcaagua;
	int valor = -1;

	while (valor != 0){
		cout << "\nDigite:\n1 - Registrar garrafa\n2 - Realizar venda\n0 - Sair do programa\n";
		cin >> valor;
		if (valor == 1) {
			cout << "Digite a marca da água (A ou B): ";
			cin >> marcaagua;
			while (marcaagua != 'A' && marcaagua != 'B') {
				cout << "Comando inválido;\nDigite a marca da água: ";
				cin >> marcaagua;
			}
			cout << "Digite o número da estante: ";
			cin >> estante;
			cout << "Digite o número da prateleira: ";
			cin >> prateleira;
			cout << "Digite o número da gaveta: ";
			cin >> gaveta;
			registro(queue, marcaagua, estante, prateleira, gaveta);
		}
		if (valor == 2) {
			venda(queue);
		}
	}
}

