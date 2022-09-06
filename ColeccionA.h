#ifndef COLECCIONA_H
#define COLECCIONA_H

#include <sstream>
#include <string>

using namespace std;

template <class T>
class ColeccionA;
template <class T>
class NodoA;
template <class T>
class IteradorA;
template <class T>
class IteradorArregloA;
template <class T>
class IteradorListaA;
template <class T>
class ListaA;
template <class T>
class ArregloA;

template <class T>
class ColeccionA {
public:
	ColeccionA();
	virtual ~ColeccionA();
	virtual void agregarElemento(T*) = 0;
	virtual IteradorA<T>* obtenerIterador() const = 0;

};

template <class T>
class IteradorA {
public:
	IteradorA();
	virtual ~IteradorA();
	virtual bool masElementos() const = 0;
	virtual T* proximoElemento() = 0;

};

template <class T>
class ArregloA : public ColeccionA<T> {
public:
	ArregloA(int);
	virtual ~ArregloA();
	virtual void agregarElemento(T*);
	virtual IteradorA<T>* obtenerIterador() const;

	friend class IteradorArregloA<T>;

private:
	int n;
	int k;
	T** elementos;

};

template <class T>
class NodoA {
public:
	NodoA(T*, NodoA<T>*);
	virtual ~NodoA();
	virtual T* obtenerDato() const;
	virtual NodoA<T>* obtenerSiguiente() const;
private:
	T* dato;
	NodoA<T>* siguiente;

};

template <class T>
class ListaA : public ColeccionA<T> {   
public:
	ListaA();
	virtual ~ListaA();
	virtual void agregarElemento(T*);
	virtual IteradorA<T>* obtenerIterador() const;

private:
	NodoA<T>* primero;

};

template <class T>
class IteradorArregloA : public IteradorA<T> {
public:
	IteradorArregloA(const ArregloA<T>&);
	virtual ~IteradorArregloA();
	virtual bool masElementos() const;
	virtual T* proximoElemento();
private:
	ArregloA<T>* a;
	int i;

};

template <class T>
class IteradorListaA : public IteradorA<T> {
public:
	IteradorListaA(NodoA<T>*);
	virtual ~IteradorListaA();
	virtual bool masElementos() const;
	virtual T* proximoElemento();
private:
	NodoA<T>* cursor;

};

template <class T>
ColeccionA<T>::ColeccionA() {
}

template <class T>
ColeccionA<T>::~ColeccionA() {
}

template <class T>
NodoA<T>::NodoA(T* l, NodoA<T>* s)
	: dato(l), siguiente(s) {

}

template <class T>
NodoA<T>::~NodoA() {
	//Completar
}

template <class T>
T* NodoA<T>::obtenerDato() const {
	return dato;
}

template <class T>
NodoA<T>* NodoA<T>::obtenerSiguiente() const {
	return siguiente;
}

template <class T>
ListaA<T>::ListaA() : primero(NULL) {

}

template <class T>
ListaA<T>::~ListaA() {
	//Completar
}

template <class T>
IteradorA<T>* ListaA<T>::obtenerIterador() const {
	return new IteradorListaA<T>(primero);
}

template <class T>
//Agregar al inicio
void ListaA<T>::agregarElemento(T* l) {
	primero = new NodoA<T>(l, primero);
}

template <class T>
ArregloA<T>::ArregloA(int n) : n(n), k(0)
, elementos(new T*[n]) {
	for (int i = 0; i < n; i++) {
		elementos[i] = NULL;
	}
}

template <class T>
ArregloA<T>::~ArregloA() {
	//Completar
}

template <class T>
IteradorA<T>* ArregloA<T>::obtenerIterador() const {
	return new IteradorArregloA<T>(*this);
}

template <class T>
void ArregloA<T>::agregarElemento(T* l) {
	elementos[k++] = l;
}

template <class T>
IteradorA<T>::IteradorA() {

}

template <class T>
IteradorA<T>::~IteradorA() {

}

template <class T>
IteradorArregloA<T>::IteradorArregloA(const ArregloA<T>& a)
	: a((ArregloA<T>*) & a), i(0) {

}

template <class T>
IteradorArregloA<T>::~IteradorArregloA() {
	//Completar
}

template <class T>
bool IteradorArregloA<T>::masElementos() const {
	return i < a->k;
}

template <class T>
T* IteradorArregloA<T>::proximoElemento() {
	return a->elementos[i++];
}

template <class T>
IteradorListaA<T>::IteradorListaA(NodoA<T>* primero)
	: cursor(primero) {

}

template <class T>
IteradorListaA<T>::~IteradorListaA() {
	//Completar
}

template <class T>
bool IteradorListaA<T>::masElementos() const {
	return cursor != NULL;
}

template <class T>
T* IteradorListaA<T>::proximoElemento() {
	T* tmp;
	tmp = cursor->obtenerDato();
	cursor = cursor->obtenerSiguiente();
	return tmp;
}







#endif /* COLECCIONA_H */