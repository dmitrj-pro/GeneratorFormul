/*
 * Triple.h
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_TRIPLE_H_
#define GENERATOR_GENS_TRIPLE_H_

#include "../iRecursiveGen.h"

namespace Generator{
	namespace Collection{
		class Triple:public Generator::RecursiveGen{
			public:
				inline string operator()(SysType n){
					bool atom=false;
					return (*this)(n,atom);
				}
				string operator()(SysType n,bool&atom,Gen&g);
				string operator()(SysType n,bool&atom);
		};
	}
}



#endif /* GENERATOR_GENS_TRIPLE_H_ */
