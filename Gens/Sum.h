/*
 * Sum.h
 *
 *  Created on: 11 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_SUM_H_
#define GENERATOR_GENS_SUM_H_

#include "../iLFGen.h"


namespace Generator{
	namespace Collection{
		class Sum:public Generator::iLFGen{
			public:
				string operator()(SysType n,bool&);
				string operator()(SysType n){
					bool t=false;
					return (*this)(n,t);
				}
				string operator()(SysType n,bool&,Gen&g);
				virtual string right(SysType left,SysType n,bool&atom,Gen&g);
				virtual string left(SysType right,SysType n,bool&atom,Gen&g);
		};
	}
}


#endif /* GENERATOR_GENS_SUM_H_ */
