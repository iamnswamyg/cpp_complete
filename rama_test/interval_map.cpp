#include <map>
#include <iostream>
#include <limits>
#include <iomanip>

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
    if (keyEnd <= keyBegin) {
        return;
    }

    auto itrStart = m_map.lower_bound(keyBegin);
    auto itrEnd = m_map.lower_bound(keyEnd);

    if (itrStart == m_map.begin() && (itrEnd == m_map.end() || itrEnd->first > keyEnd)) {
        // Special case: New interval covers the entire range
        m_map.clear();
        m_map.insert({keyBegin, val});
        m_map.insert({keyEnd, m_valBegin});
    } else {
        auto last = std::prev(itrEnd);

        if (last->first == keyEnd) {
            last->second = val;
        } else if (last->first > keyEnd) {
            m_map.insert({keyEnd, last->second});
        }

        auto first = std::prev(itrStart);
        if (first->first < keyBegin) {
            m_map.insert({keyBegin, val});
        }

        m_map.erase(std::next(first), itrEnd);
    }

    // Handle intervals with the default value ('A')
    auto prevIter = m_map.lower_bound(keyBegin);
    if (prevIter != m_map.begin()) {
        prevIter = std::prev(prevIter);
    }

    if (prevIter->second == m_valBegin) {
        prevIter->second = val;
    }
}


// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

   
		
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
int main()
{
    // instance of interval_map class
    interval_map<int,char> m('A');
    // calling of assign() function  
    m.assign(1, 3, 'B');
    // loop for maping key and its corresponding value
    for (int i = -2; i <= 5; ++i)
        std::cout << std::setw(2) << i << ' ' << m[i] << '\n';
}


/*
int main()
{
    interval_map<int, char> map('A'); // Initialize with a default value

    // Edge Case 1: Empty Interval
    map.assign(1, 1, 'B'); // Should do nothing

     for (int i = -2; i <= 5; ++i)
        std::cout << std::setw(2) << i << ' ' << map[i] << '\n';

    
    std::cout<<"--------------------"<<std::endl;
    map.assign(5, 10, 'C');
    map.assign(15, 20, 'D');
    for (int i = -2; i <= 25; ++i)
        std::cout << std::setw(2) << i << ' ' << map[i] << '\n';
}
  

 int main()
{
    // instance of interval_map class
    interval_map<int,char> m('A');
    // calling of assign() function  
    m.assign(5, 10, 'C');
    m.assign(15, 20, 'D');
    // loop for maping key and its corresponding value
    for (int i = -2; i <= 20; ++i)
        std::cout << std::setw(2) << i << ' ' << m[i] << '\n';
}*/