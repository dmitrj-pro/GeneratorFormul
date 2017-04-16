/*
 * Divide.h
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_DIVIDE_H_
#define GENERATOR_GENS_DIVIDE_H_

#include "../iLFGen.h"

namespace Generator{
	namespace Collection{
		class Divide:public Generator::iLFGen{
			public:
				inline string operator()(SysType n){
					bool atom=false;
					return (*this)(n,atom);
				}
				string operator()(SysType n,bool&atom,Gen&g);
				string operator()(SysType n,bool&atom);
				virtual string right(SysType,SysType,bool&,Gen&);
				virtual string left(SysType,SysType,bool&,Gen&);
		};
	}
}



#endif /* GENERATOR_GENS_DIVIDE_H_ */
