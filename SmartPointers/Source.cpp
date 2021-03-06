
// наша реализация shared_ptr
template <class T>
class sh_ptr {
	public:
		sh_ptr(T* d_pointer): data_pointer(d_pointer) {
			*counter = 1;
		}
		sh_ptr(sh_ptr& ptr) {
			*ptr.counter++;
			counter = ptr.counter;
			data_pointer = ptr.data_pointer;
		}
		~sh_ptr() {
			*counter--;
			if (*counter == 0 && data_pointer != nullptr) {
				delete(data_pointer);
			}
		}

		template <class M>
		friend class w_ptr;

	private:
		int* counter;
		T* data_pointer;
};

// weak_ptr
template <class T>
class w_ptr {
public:
	w_ptr(T* d_pointer) : data_pointer(d_pointer) {
	}

	w_ptr(w_ptr& ptr) {
		counter = ptr.counter;
		data_pointer = ptr.data_pointer;
	}
	w_ptr(sh_ptr<T>& ptr) {
		counter = ptr.counter;
		data_pointer = ptr.data_pointer;
	}
	~w_ptr() {
		if (*counter == 0 && data_pointer != nullptr) {
			delete(data_pointer);
		}
	}
	sh_ptr<T>& make_shared() {
		
	}
private:
	int* counter;
	T* data_pointer;
};

int main() {
	return 0;
}