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
    // std::cout << "cas 1 (" << size <<"|"<<sizeMax << ")\n" << std::endl;
    array = (T*) malloc(10*sizeof(T));
    size = 1;
    sizeMax = 10;
    array[0] = elm;
  }
  else if (array != NULL && size < sizeMax){
    //std::cout << "cas 2\n" << size <<"|"<<sizeMax << ")\n"  << std::endl;
    size++;
    array[size-1] = elm;
  }
  else if (array != NULL && size == sizeMax){
    //std::cout << "cas 3\n" << size <<"|"<<sizeMax << ")\n"  << std::endl;
    array =(T*) realloc(array,(size +10)*sizeof(T));
    size++;
    sizeMax += 10;
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
	for(int j = i; j < size-1 ; j++)
	  array[j] = array[j+1];
	size--;
      }
  }
  //Suppression des pages non necessaire sauf la première...
  if(array != NULL && sizeMax != 10 && (sizeMax - size) == 10){
    long n = 10*(sizeMax/10 - 1);
    // std::cout << "true ("<<n<<")\n";
    T * temp = (T*) malloc(n*sizeof(T));
    sizeMax = n;
    for(int i = 0 ; i < size ; i++)
      temp[i] = array[i];
    free(array);
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
Array<T>::Array() : size(-1), sizeMax(0),array(NULL){
  // std::cout << "construction de la list\n";  
}

template <class T>
Array<T>::~Array() {
  free(array);
  // std::cout << "destruction de la list\n";
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
