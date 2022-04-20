#pragma once
#include "Resource.h"
#include <cstring>

template < typename T >
class ResourceManager {
private:
	Resource<T>* RList[100];
	int max;
public:
	ResourceManager();

	int AddResource(const char* path, const char* name);

	int FindResource(const char* name);

	T& GetResource(const char* name);

	void ReleaseAll();

	~ResourceManager();
};

template<typename T>
inline ResourceManager<T>::ResourceManager()
	:max(0)
{
	memset(RList, 0, sizeof(RList));
}

template<typename T>
inline int ResourceManager<T>::AddResource(const char* path, const char* name)
{
	RList[max] = new Resource<T>(path, name);
	return ++max;
}

template<typename T>
inline int ResourceManager<T>::FindResource(const char* name)
{
	for (int i = 0; i < max; i++) {
		if (strcmp(RList[i]->GetName(), name) == 0) {
			return i;
		}
	}
	return -1;
}

template<typename T>
inline T& ResourceManager<T>::GetResource(const char* name)
{
	int idx = FindResource(name);
	return RList[idx];
}

template<typename T>
inline void ResourceManager<T>::ReleaseAll()
{
	for (int i = 0; i < max; i++) {
		delete RList[i];
	}
}

template<typename T>
inline ResourceManager<T>::~ResourceManager()
{
}
