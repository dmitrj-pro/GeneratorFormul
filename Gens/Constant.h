/*
 * Constant.h
 *
 *  Created on: 11 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_CONSTANT_H_
#define GENERATOR_GENS_CONSTANT_H_

#include "../iGen.h"
#include "../Sys.h"

using std::string;

namespace Generator{
	namespace Collection{
		class Constant:public Generator::Gen{
			public:
				virtual string operator()(SysType t,bool & atom){
					atom=true;
					return System::ToString<SysType>(t);
				}
				virtual string operator()(SysType t){
					return System::ToString<SysType>(t);
				}
		};
	}
}

#endif /* GENERATOR_GENS_CONSTANT_H_ */
