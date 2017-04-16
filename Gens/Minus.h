/*
 * Minus.h
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_MINUS_H_
#define GENERATOR_GENS_MINUS_H_

#include "../iLFGen.h"

namespace Generator{
	namespace Collection{
		class Minus:public Generator::iLFGen{
			public:
				inline string operator()(SysType n){
					bool atom=false;
					return (*this)(n,atom);
				}
				string operator()(SysType n,bool&atom,Gen&g);
				string operator()(SysType n,bool&atom);
				virtual string right(SysType left,SysType n,bool&atom,Gen&g);
				virtual string left(SysType right,SysType n,bool&atom,Gen&g);
		};
	}
}

#endif /* GENERATOR_GENS_MINUS_H_ */
