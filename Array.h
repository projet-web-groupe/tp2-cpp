#ifndef ARRAY_H
#define ARRAY_H
#define PAGE 10

#include <iostream>
#include <cstdlib>

template <class T>
class Array {
  long size;
  long sizeMax;
  T *array;
 public:
  void add(T elm);
  void remove(T elm);
  T* get(long n);
  T* search(T elm);
  long getSize();
  long getIndice(T elm);
  Array();
  ~Array();
};

template <class T>
void Array<T>::add(T elm){
  if(array == NULL && size <= -1){
    array = new T[PAGE];
    size = 1;
    sizeMax = PAGE;
    array[0] = elm;
  }
  else if (array != NULL && size < sizeMax)
    array[size-1] = elm;

  else if (array != NULL && size == sizeMax){
    T * temp = new T[size + 10];
    for(int i = 0 ; i < size ; i++)
      temp[i] = array[i];
    delete[] array;
    array = temp;
    size++;
    array[size-1] = elm;
  }
  else
    std::cout << "Erreur Gestion de l'array" << std::endl;
} 

template <class T>
void Array<T>::remove(T elm){
  if(array != NULL && size != -1){
    for(int i =0 ; i < size-1 ; i++)
      if(array[i] == elm){
	for(int j = i; j < size ; j++)
	  array[j] = array[j+1];
	array[size-1] = NULL;
	size--;
      }
  }
  //Suppression des pages non necessaire sauf la première...
  if(array != NULL && sizeMax != PAGE && (sizeMax/PAGE - size/PAGE) != 0){
    long n = 10*((sizeMax/10 - size/10)+1);
    T * temp = new T[n];
    for(int i = 0 ; i < size ; i++)
      temp[i] = array[i];
    delete[] array;
    array = temp;
  }
}

template <class T>
T* Array<T>::get(long n){
  if(n < getSize())
    return &(array[n]);
  return NULL;
}

template <class T>
long Array<T>::getSize(){
  return size;
}

template <class T>
Array<T>::Array() : array(NULL), size(-1), sizeMax(0){
}

template <class T>
Array<T>::~Array() {
  delete[] array;
}

template <class T>
T* Array<T>::search(T elm){
  for(long i = 0 ; i < size ; i++)
    if(array[i] == elm)
      return &(array[i]);
  return NULL;
}

template <class T>
long Array<T>::getIndice(T elm){
  for(long i = 0 ; i < size ; i++)
    if(array[i] == elm)
      return i;
  return -1;
}

#endif
