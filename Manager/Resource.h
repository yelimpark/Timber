#pragma once
#include <cstring>
#include <SFML/Graphics.hpp>

template < typename T >
class Resource {
private:
	const char* path;
	char* name;
	T* object;

public:
	Resource(const char * path, const char * name);

	char* GetName();

	~Resource();
};

template<typename T>
inline Resource<T>::Resource(const char* path, const char* name)
	:path(path)
{
	this->name = new char[strlen(name)];
	strcpy_s(this->name, strlen(this->name), name);
	object = new T();
	object->loadFromFile(path);
}

template<typename T>
inline char* Resource<T>::GetName()
{
	return name;
}

template<typename T>
inline Resource<T>::~Resource()
{
	delete[]name;
	delete object;
}
