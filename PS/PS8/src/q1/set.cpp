#include <iostream>
#include "set.h"


template<typename T>
Set<T>::Set() {
	capacity = 10;
	items = new T[capacity];
	size = 0;
}
template<typename T>
void Set<T>::add(T item){
	for (int i = 0; i < size; i++){
		if (items[i] == item){
			return;
		}
        }
        if (size == capacity){
		capacity *= 2;
		T* newItems = new T[capacity];
		for (int i = 0; i < size; i++){
			newItems[i] = items[i];
		}
		delete[] items;
		items = newItems;
	}
	items[size] = item;
	size++;
}
template<typename T>
int Set<T>::getSize() const{
        return size;
}
template<typename T>
T* Set<T>::getArray() const{
	T* array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = items[i];
	}
	return array;
}
