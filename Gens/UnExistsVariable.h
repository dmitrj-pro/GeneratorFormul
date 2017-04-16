/*
 * UnExistsVariable.h
 *
 *  Created on: 16 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_UNEXISTSVARIABLE_H_
#define GENERATOR_GENS_UNEXISTSVARIABLE_H_

#include "../iVariable.h"
#include "Exception.h"
#include <string>

using std::string;

namespace Generator{
	namespace Collection{
		class UnExistsVariable:public Generator::Variable {
			private:
				string _name;
			public:
				UnExistsVariable(){}
				UnExistsVariable(const string &name){
					_name=name;
				}
				inline string operator()(SysType n){
					bool atom=false;
					return (*this)(n,atom);
				}
				string operator()(SysType n,bool&atom,Gen&g);
				string operator()(SysType n,bool&atom);
				inline virtual string Name()const{
					return _name;
				}
				inline virtual SysType Value()const{
					throw FailGenerator();
				}
				inline virtual SysType SetValue(const string &name,SysType n){
					_name=name;
					return n;
				}
		};
	}
}



#endif /* GENERATOR_GENS_UNEXISTSVARIABLE_H_ */
