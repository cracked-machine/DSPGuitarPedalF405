/*
 * BoundedVector.hpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */

#ifndef RESOURCEMANAGER_BOUNDEDVECTOR_HPP_
#define RESOURCEMANAGER_BOUNDEDVECTOR_HPP_

#include <vector>
#include <iostream>
#include <ResourceManager.hpp>


template <class Tp>
struct NAlloc {
    typedef Tp value_type;
    NAlloc() = default;
    template <class T> NAlloc(const NAlloc<T>&, int test)
	{
    	std::cout << test << std::endl;
    }

    Tp* allocate(std::size_t n)
    {
        n *= sizeof(Tp);

        if((usedmem + n) > maxthresholdmem) {
        	// try to stop the impending disaster
        	std::cout << "FAILED:" << usedmem << "(used mem) + "
        			<< n << "(requested mem) > "
					<< maxthresholdmem << "(total sys mem)" << std::endl;
        	return nullptr;
        }
        else {
            usedmem = usedmem + n;
            std::cout << "SUCCESS: allocating " << n << " bytes. Used Mem = " << usedmem << std::endl;
        	return static_cast<Tp*>(::operator new(n));
        }
    }

    void deallocate(Tp* p, std::size_t n)
    {
        std::cout << "deallocating " << n*sizeof*p << " bytes\n";
        ::operator delete(p);
    }
};
template <class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) { return true; }
template <class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) { return false; }



template<class T>
class BoundedVector
{
public:
	BoundedVector(size_t pCapacity_limit);
	bool push_back(T pItem);
	auto begin();
	auto end();

	typename std::vector<T, NAlloc<T>>::iterator iterator;
	auto size();
	auto empty();


private:
	size_t capacity_limit;
	std::vector<T, NAlloc<T>> v1{1};
	bool fatalerror = false;


};

template<class T>
auto BoundedVector<T>::end()
{
	return v1.end();
}

template<class T>
auto BoundedVector<T>::size()
{
	return v1.size();
}

template<class T>
auto BoundedVector<T>::empty()
{
	return v1.empty();
}

template<class T>
auto BoundedVector<T>::begin()
{
	return std::begin(v1);
}

template<class T>
BoundedVector<T>::BoundedVector(size_t pCapacity_limit)
{
	this->capacity_limit = pCapacity_limit;

	std::cout << "Reserving " << sizeof(T) * this->capacity_limit <<" bytes (" <<
			this->capacity_limit << " * " << sizeof(T) << " bytes)" << std::endl;

	if(this->capacity_limit < v1.max_size())
	{

		v1.reserve(this->capacity_limit);

		//std::cout << "Success! Vector size: " << v1.size() << " Capacity: " << v1.capacity() << std::endl;
	}
	else
	{
		std::cout << "Fail! Request exceeds vector max size on this arch: " << v1.max_size()  << std::endl;
		fatalerror = true;
	}

}

template<class T>
bool BoundedVector<T>::push_back(T pItem)
{
	if(fatalerror)
	{
		std::cout << "You cannot push to a vector that was not initialised successfully!" << std::endl;
		return false;
	}

	if(v1.size() < this->capacity_limit)
	{
		v1.push_back(pItem);
		std::cout << "Vector size: " << v1.size() << " Capacity: " << v1.capacity() << std::endl;

		return true;
	}
	else
	{
		std::cout << "Vector is full" << std::endl;
		return false;
	}

}


#endif /* RESOURCEMANAGER_BOUNDEDVECTOR_HPP_ */
