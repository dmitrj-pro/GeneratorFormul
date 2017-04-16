/*
 * iLFGen.h
 *
 *  Created on: 13 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_ILFGEN_H_
#define GENERATOR_ILFGEN_H_

#include "iRecursiveGen.h"

namespace Generator{
	class iLFGen:public RecursiveGen{
		public:
			virtual string operator()(SysType)=0;
			virtual string operator()(SysType,bool&)=0;
			virtual string operator()(SysType,bool&,Gen&)=0;
			virtual string left(SysType,SysType,bool&,Gen&)=0;
			virtual string right(SysType,SysType,bool&,Gen&)=0;
	};
}



#endif /* GENERATOR_ILFGEN_H_ */
