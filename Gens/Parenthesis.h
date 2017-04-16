/*
 * Parenthesis.h
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_PARENTHESIS_H_
#define GENERATOR_GENS_PARENTHESIS_H_

#include "../iRecursiveGen.h"
#include "Exception.h"

namespace Generator{
	namespace Collection{
		class Parenthesis:public Generator::RecursiveGen{
			public:
				string operator()(SysType n,bool&);
				inline string operator()(SysType n){
					bool b=false;
					return (*this)(n,b);
				}
				string operator()(SysType n,bool&,Gen&g);
		};
	}
}



#endif /* GENERATOR_GENS_PARENTHESIS_H_ */
