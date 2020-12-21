#include <algorithm>
#include <cassert>


namespace kenster
{

//private:
//	DATATYPE*	_objs;
//	int			_length;
	template<typename DATATYPE>// something something length
	Dataholder<DATATYPE>::Dataholder(const int& const size)
	{
		_objs = new std::vector<DATATYPE>;
		_objs->reserve(size);
		_length = 0;
	}

	template<typename DATATYPE>
	Dataholder<DATATYPE>::~Dataholder()
	{
		delete _objs;
	}

	template<typename DATATYPE>
	void Dataholder<DATATYPE>::add(const DATATYPE& obj)
	{
		_objs->emplace_back(obj);
		_length++;
	}

	template<typename DATATYPE> //delete due swap obj out of bound
	void Dataholder<DATATYPE>::remove(DATATYPE& const obj)
	{
		_length--;
		SWAP(obj, _objs[_length]);
	}

	template<typename DATATYPE>
	const int Dataholder<DATATYPE>::getLength()const
	{
		return _length;
	}

	template<typename DATATYPE>
	DATATYPE& Dataholder<DATATYPE>::operator[](const int index)const
	{
		assert(index >= 0 && index < _length);
		//std::vector<DATATYPE>& vr = *_objs; //create a reference
		return _objs->operator[](index);
	}

#ifdef KENSTER_DEBUG
	template<typename DATATYPE>// think about a better way to test you stuff
	void Dataholder<DATATYPE>::print()
	{
		std::cout << typeid(DATATYPE).name() << std::endl;
		for (int i = 0; i < _length; i++)
			std::cout << "index " << i << " " << _objs[i] << std::endl;
		std::cout << std::endl;
	}
#endif //KENSTER_DEBUG
}


//----------------------------------------------------this is my back up. it is made with array, the one above should be the attempt with vector
//#include <algorithm>
//#include <cassert>
//
//
//namespace kenster
//{
//
//	//private:
//	//	DATATYPE*	_objs;
//	//	int			_length;
//	template<typename DATATYPE>// something something length
//	Dataholder<DATATYPE>::Dataholder(const int& const length)
//	{
//		_objs = new DATATYPE[length];
//		_length = 0;
//	}
//
//	template<typename DATATYPE>
//	Dataholder<DATATYPE>::~Dataholder()
//	{
//		delete[] _objs;
//	}
//
//	template<typename DATATYPE>
//	void Dataholder<DATATYPE>::add(const DATATYPE& obj)
//	{
//		_objs[_length++] = obj;
//	}
//
//	template<typename DATATYPE> //delete due swap obj out of bound
//	void Dataholder<DATATYPE>::remove(DATATYPE& const obj)
//	{
//		_length--;
//		SWAP(obj, _objs[_length]);
//	}
//
//	template<typename DATATYPE>
//	const int Dataholder<DATATYPE> ::getLength()const
//	{
//		return _length;
//	}
//
//	template<typename DATATYPE>
//	DATATYPE& Dataholder<DATATYPE>::operator[](const int index)const
//	{
//		assert(index >= 0 && index < _length);
//		return _objs[index];
//	}
//
//#ifdef KENSTER_DEBUG
//	template<typename DATATYPE>// think about a better way to test you stuff
//	void Dataholder<DATATYPE>::print()
//	{
//		std::cout << typeid(DATATYPE).name() << std::endl;
//		for (int i = 0; i < _length; i++)
//			std::cout << "index " << i << " " << _objs[i] << std::endl;
//		std::cout << std::endl;
//	}
//#endif //KENSTER_DEBUG
//}