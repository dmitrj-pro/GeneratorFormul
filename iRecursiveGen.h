/*
 * iRecursiveRand.h
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_IRECURSIVEGEN_H_
#define GENERATOR_IRECURSIVEGEN_H_

#include "iGen.h"

namespace Generator{
	class RecursiveGen:public Gen{
		public:
			virtual string operator()(SysType)=0;
			virtual string operator()(SysType,bool&)=0;
			virtual string operator()(SysType,bool&,Gen&)=0;
	};
}


#endif /* GENERATOR_IRECURSIVEGEN_H_ */
