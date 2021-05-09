#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include <ctime>


const int tamanho_fila = 5;


struct garrafa1 {
	char marca_agua;
	int estante;
	int prateleira;
	int gaveta;
	time_t tempo;

};

struct Fila {
	int frontA;
	int rearA;
	int countA;

	int frontB;
	int rearB;
	int countB;

	garrafa1 filaA[tamanho_fila];
	garrafa1 filaB[tamanho_fila];

};

Fila Create();

garrafa1 garrafavazia();

int SizeA(const Fila& queue);

int SizeB(const Fila& queue);

int CountA(const Fila& queue);

int CountB(const Fila& queue);

bool IsEmptyA(const Fila& queue);

bool IsEmptyB(const Fila& queue);

bool EnqueueA(Fila& queue, garrafa1 elem);

bool EnqueueB(Fila& queue, garrafa1 elem);

garrafa1 DequeueA(Fila& queue);

garrafa1 DequeueB(Fila& queue);

garrafa1 FrontA(const Fila& queue);

garrafa1 FrontB(const Fila& queue);

garrafa1 DequeueAny(Fila& queue);



#endif

