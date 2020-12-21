#ifndef BOOK_ACTIONMAP_HPP
#define BOOK_ACTIONMAP_HPP

#include <SFML-Kenster/Action.hpp>
#include <vector>

#include <unordered_map> //unordered_map

namespace kenster
{
	template<typename T = int>
	class ActionMap
	{
	public:
		ActionMap(const ActionMap<T>&) = delete;
		ActionMap<T>& operator=(const ActionMap<T>&) = delete;

		ActionMap() = default;

		void map(const T& key, const Action& action);
		const Action& get(const T& key)const;

	private:
		//T = key book enum,
		std::unordered_map<T, Action> _map;
	};
}

//template

namespace kenster
{

	template<typename T>
	void ActionMap<T>::map(const T& key, const Action& action)
	{
		_map.emplace(key, action);
	}

	template<typename T>
	const Action& ActionMap<T>::get(const T& key)const
	{
		return _map.at(key);
	}
}


#endif
