/*
 * Sys.h
 *
 *  Created on: 7 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef SYS_H_2
#define SYS_H_2

#include<sstream>
#include <cstdlib>
#include <ctime>


#include <mutex>


using std::ostringstream;
using std::string;

namespace System{

	template<typename T>
	inline string ToString(T N) {
		if (N==0)
			return "0";
		ostringstream os;
		os<<N;
		return os.str();
	}

	class Random{
		private :
			std::mutex mut;
			int count=0;
		public:
			Random(){
				srand(time(nullptr));
			}
			Random(const Random&r){}
			Random(Random&&r){}
			Random& operator=(const Random& r){ return *this;}
			Random& operator=(Random&& r){ return *this;}
			int operator()(){
				mut.lock();
				auto res=rand()+count++;
				mut.unlock();
				return res;
			}
			int operator()(size_t t){
				return t!=0?this->operator ()()%t:t;
			}
	};

	extern Random Rand;
}

#endif /* SYS_H_ */
