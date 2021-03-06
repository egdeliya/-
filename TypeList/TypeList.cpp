#include <iostream>

// означает, что нет типа
class emptyNode {
	
};

template <typename ...Args>
class typeList {
//говорим,  что head - это тип, который имеет тип emptyNode
	typedef emptyNode _head;
	typedef emptyNode _tail;
};

typedef typeList<> EmptyTypeList;

// делаем специализацию шаблона
template <typename H, typename ...Args>
class typeList<H, Args...> {
public:
	typedef H _head;
	typedef typeList<Args...> _tail;
};

// опять делаем специализацию шаблона
template <typename ...Args>
struct isEmpty<typeList<Args...>> :
// 
	std::integral_constant<bool, 
	// is_same проверяет, что тип _head равен emptyNode
	std::is_same<typename typeList<Args...>::_head, emptyNode>::value &&
	// далее вызываем сами себя от tail, используя при этом поле value, которое у нас есть
	// как наследие integral_constant
	isEmpty<typeList<Args...>::_tail>::value >;

template<typename T, typename TL>
struct add {
};

template<typename T, typename ...Args>
class add<T, typeList<Args...>> {
public:
	typedef typeList<Args..., T> type;
};

template <typename ...Args>
class objList {
public:
	typedef typeList<Args...> _types;
	std::list<void *> _data;

	template <typename T, typename Arg...>
	friend objList<Arg..., T> push(T*, objList<Arg...>);

	template <typename T, typename Arg...>
	friend objList<Args...> pop(objList<Arg...>);
};

template <typename T, typename ...Args>
objList<Args..., T> push(T* pointer, objList<Args...> obj_list) {
	obj_list._data.push_back(pointer);
	objList<Args..., T>* new_list = new objList<Args..., T>(obj_list._data);

	return new_list;
}

template <typename T, typename ...Args>
objList<Args...> pop(objList<Args...> obj_list) {
	obj_list._data.pop_back();
	objList<Args...>* new_list = new objList<Args...>(obj_list._data);

	return new_list;
}

int main() {
	typeList<int, int> list;
	std::cout << std::integral_constant<int, 4>::value;
	system("pause");
	return 0;
}
