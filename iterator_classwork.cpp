#include <vector>
#include <Windows.h>
using namespace std;

template <class T>
class InIterator :public std::iterator <std::input_iterator_tag, T> {
private: InIterator(T* p);
	   T* ptr;
public: 
	InIterator(const InIterator& it) {
		ptr = it.ptr;
	}
	T& operator*() {
		return *ptr;
	}
	InIterator& operator ++() {
		++ptr;
		return *this;
	}
	bool InIterator& operator!=(const InIterator& it) {
		return ptr != it;
	}

	bool InIterator& operator==(const InIterator& it) {
		return ptr == it;
	}
};

template <class T>
class TVector {
protected:
	T* pMem;
	size_t size;
public:
	typedef InIterator <T> iterator;
	typedef InIterator <const T> const_iterator;

	TVector(const TVector& v) {
		pMem = v.pMem;
		size = v.size;
	}
	~TVector() {
		delete[pMem];
	}

	InIterator<T> begin() {
		return InIterator<T>(&pMem[0]);
	}

	InIterator<T> end() {
		return InIterator<T>(&pMem[size - 1] + 1);
	}
};

int main() {
		TVector<int> V(15);
		for(TVector<int>::iterator it = V.begin( ); 
};
