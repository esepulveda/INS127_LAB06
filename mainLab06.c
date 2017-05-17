
#include "funcionesLab06.h"

/* Integrantes:
				Esteban Sepulveda
				Claudio Vasquez
	Profesor: Tomas Lara 
*/	


int main(int argc, char const *argv[])
{
	nodo *raiz=NULL;
	int datos[]={9,78,6,3,7,9,5,88,10,0,1,34,22,4,2,8,45,32,65,42},i,nodoB;
	for (i=0;i<19;i++){
		raiz=insertarNodo(raiz,datos[i]);
	}
	printf("\nPre-orden\n");
	preOrden(raiz);
	nodo *nodoMenor=buscarMenor(raiz);
	nodo *nodoMayor=buscarMayor(raiz);
	printf("\nEl nodo menor es: %d",nodoMenor->ptrInfo->valor);
	printf("\nEl nodo mayor es: %d",nodoMayor->ptrInfo->valor);
	int nivelA=nivel(raiz);
	printf("\nEl nivel del arbol es: %d", nivelA);
	printf("\nIngrese un nodo a eliminar: ");
	scanf("%d",&nodoB);
	remover(raiz,nodoB);
	printf("\n\n");
	preOrden(raiz);

	return 0;
}