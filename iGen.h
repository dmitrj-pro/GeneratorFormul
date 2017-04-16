/*
 * iGen.h
 *
 *  Created on: 11 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_IGEN_H_
#define GENERATOR_IGEN_H_

#include <string>

#define SysType long long

#define ControlOverflow

using std::string;


namespace Generator{
	class Gen{
		public:
			virtual ~Gen(){}
			virtual string operator()(SysType, bool&)=0;
			virtual string operator()(SysType)=0;
	};
}


#endif /* GENERATOR_IGEN_H_ */
