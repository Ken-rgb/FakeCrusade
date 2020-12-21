#ifndef KENSTER_Dataholder_HPP
#define KENSTER_Dataholder_HPP

#include <vector>
#include <Kenster/Swap.hpp>

namespace kenster
{
	template<typename DATATYPE>
	class Dataholder
	{
		public:
			Dataholder(const Dataholder&) = delete;
			Dataholder& operator=(const Dataholder&) = delete;

			Dataholder(const int& const size);
			~Dataholder();


			void add(const DATATYPE& obj);
			void remove(DATATYPE& const obj);

			const int getLength()const;

			DATATYPE& operator[](const int index)const;

#ifdef KENSTER_DEBUG
			void print();
#endif

		private:
			std::vector<DATATYPE>*	_objs;
			int			_length;
	};
}


#include "Dataholder.inl"

#endif // !KENSTER_Dataholder_HPP
