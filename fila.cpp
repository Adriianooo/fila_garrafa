#include "fila.h"
#include <ctime>

garrafa1 garrafavazia() {
	garrafa1 padrao;
	padrao.marca_agua = '0';
	padrao.estante = 0;
	padrao.prateleira = 0;
	padrao.gaveta = 0;

	return padrao;

}

Fila Create() {
	Fila queue;
	queue.frontA = 0;
	queue.rearA = 0;
	queue.countA = 0;

	queue.frontB = 0;
	queue.rearB = 0;
	queue.countB = 0;

	return queue;

};

int SizeA(const Fila& queue)
{
	return sizeof(queue.filaA) / sizeof(queue.filaA[0]);
}

int SizeB(const Fila& queue)
{
	return sizeof(queue.filaB) / sizeof(queue.filaB[0]);
}

bool IsEmptyA(const Fila& queue)
{
	return queue.countA == 0;

}

bool IsEmptyB(const Fila& queue)
{
	return queue.countB == 0;

}

int CountA(const Fila& queue)
{
	return queue.countA;
}

int CountB(const Fila& queue)
{
	return queue.countB;
}

bool EnqueueA(Fila& queue, garrafa1 elem) {
	if (queue.countA == SizeA(queue)) {
		return false;
	}

	queue.filaA[queue.rearA] = elem;
	queue.rearA = (queue.rearA + 1) % SizeA(queue);
	++queue.countA;

	return true;
}

bool EnqueueB(Fila& queue, garrafa1 elem) {
	if (queue.countB == SizeB(queue)) {
		return false;
	}

	queue.filaB[queue.rearB] = elem;
	queue.rearB = (queue.rearB + 1) % SizeB(queue);
	++queue.countB;

	return true;
}

garrafa1  DequeueA(Fila& queue)
{
	if (IsEmptyA(queue)) {
		return garrafavazia();
	}

	garrafa1 value = queue.filaA[queue.frontA];
	queue.filaA[queue.frontA] = garrafavazia();

	queue.frontA = (queue.frontA + 1) % SizeB(queue);

	--queue.countA;

	return value;
}

garrafa1  DequeueB(Fila& queue)
{
	if (IsEmptyB(queue)) {
		return garrafavazia();
	}

	garrafa1 value = queue.filaB[queue.frontB];
	queue.filaB[queue.frontB] = garrafavazia();

	queue.frontB = (queue.frontB + 1) % SizeB(queue);

	--queue.countB;

	return value;
}

garrafa1 FrontA(const Fila& queue)
{
	if (IsEmptyA(queue)) {
		return garrafavazia();
	}
	else {
		return queue.filaA[queue.frontA];

	}
}

garrafa1 FrontB(const Fila& queue)
{
	if (IsEmptyB(queue)) {
		return garrafavazia();
	}
	else {
		return queue.filaB[queue.frontB];

	}
}
garrafa1 DequeueAny(Fila& queue)
{
	if (IsEmptyA(queue) && IsEmptyB(queue)) {
		return garrafavazia();
	}
	if (IsEmptyA(queue))
	{
		return DequeueB(queue);
	}
	if (IsEmptyB(queue))
	{
		return DequeueA(queue);
	}
	else {
		if (FrontA(queue).tempo < FrontB(queue).tempo) {
			return DequeueA(queue);
		}
		else {
			return DequeueB(queue);
		}
	}
}



