/*
 * Variable.h
 *
 *  Created on: 13.04.2017
 *      Author: diman-pro
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_


#include "iRecursiveGen.h"

namespace Generator{
	class Variable:public RecursiveGen{
		public:
			virtual string operator()(SysType)=0;
			virtual string operator()(SysType,bool&)=0;
			virtual string operator()(SysType,bool&,Gen&)=0;

			virtual string Name()const =0;
			virtual SysType Value()const =0;
			virtual SysType SetValue(const string &name,SysType n)=0;
	};
}

#endif /* VARIABLE_H_ */
