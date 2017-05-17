#include <stdio.h>
#include <stdlib.h>

typedef struct Info{
	int valor;
}info;
typedef struct Nodo{
	struct Nodo *izq;
	struct Nodo *der;
	info *ptrInfo;
}nodo;
info *crearInfo(int num){
	info *newInfo;
	if(newInfo=(info*)malloc(sizeof(info))){
		newInfo->valor=num;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newInfo;
	free(newInfo);
}
nodo *crearNodo(int val){
	nodo *newNodo;
	info *dato=crearInfo(val);
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->ptrInfo=dato;
		newNodo->izq=newNodo->der=NULL;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newNodo;
	free(newNodo);
}
nodo *insertarNodo(nodo *nodoI,int val){
	if (nodoI==NULL){
		return crearNodo(val);
	}
	else if(val<nodoI->ptrInfo->valor){
		nodoI->izq=insertarNodo(nodoI->izq,val);
	}
	else if(val>nodoI->ptrInfo->valor){
		nodoI->der=insertarNodo(nodoI->der,val);
	}
	return nodoI;
}
void preOrden(nodo *nodoR){
	if(nodoR!=NULL){
		printf("%d\t",nodoR->ptrInfo->valor);
		preOrden(nodoR->izq);
		preOrden(nodoR->der);
	}
}

nodo *buscarMenor(nodo *nodoM){
	if (nodoM==NULL || nodoM->izq==NULL){
		return nodoM;
	}else{
		buscarMenor(nodoM->izq);
	}
}

nodo *buscarMayor(nodo *nodoM){
	if(nodoM==NULL || nodoM->der==NULL){
		return nodoM;
	}else{
		buscarMayor(nodoM->der);
	}
}

int nivel (nodo *r){
	if(r != NULL){
		int nivelIzq = 1 + nivel(r -> izq);
		int nivelDer = 1 + nivel(r -> der);
		if (nivelIzq > nivelDer){
			return nivelIzq;
		}
		else{
			return nivelDer;
		}
	}
	return 0;
}

nodo* remover(nodo* arv, int item) {
    if (arv == NULL) 
        return NULL;
    if (item < arv->ptrInfo->valor)
        arv->izq = remover(arv->izq, item);
    else if (item > arv->ptrInfo->valor)
        arv->der = remover(arv->der, item);
    else {
        if ((arv->izq == NULL) && (arv->der == NULL)) { 
            free(arv);
            arv = NULL;
        } else if (arv->izq == NULL) {		   
            nodo* aux = arv;
            arv = arv->der;
            free(aux);
            aux = NULL;
        } else if (arv->der == NULL) {		    
            nodo* aux = arv;
            arv = arv->izq;
            free(aux);
            aux = NULL;
        } else {
            nodo* aux = arv->izq;
            while(aux->der != NULL) {
                aux = aux->der;
            }
            arv->ptrInfo->valor = aux->ptrInfo->valor; aux->ptrInfo->valor = item;
            arv->izq = remover(arv->izq, item);
        }
    }
    return arv;
}