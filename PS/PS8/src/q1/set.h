#ifndef SET_H
#define SET_H

template <typename T>
class Set{
public:
	Set();
	void add(T item);
	int getSize() const;
	T* getArray() const;
private:
	T* items;
	int size;
	int capacity;
};

#endif
