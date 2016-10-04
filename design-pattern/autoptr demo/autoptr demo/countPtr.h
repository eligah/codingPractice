
template<typename T>
class CountPtr {
private: T* ptr;
		 long* count;
public:
	CountPtr(T *p = 0) :ptr(p), count(new long(1)){}
	CountPtr(const  CountPtr<T>& pt) :ptr(pt.ptr), count(pt.count){
		++*count;
	}

	~CountPtr(){
		dispose();
	}
	T& operator*(){
		return *ptr;
	}
	T* operator->(){
		return ptr;
	}
	CountPtr<T>& operator=(const CountPtr<T>& p){
		if (this != &p) {
			dispose();
			ptr = p.ptr;
			count = p.count;
			++*count;
		}

	}
private:
	void dispose(){
			if (--*count == 0){
				delete ptr;
				delete  count;
			}
}

};

