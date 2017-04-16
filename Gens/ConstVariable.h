/*
 * ConstVariable.h
 *
 *  Created on: 13.04.2017
 *      Author: diman-pro
 */

#ifndef CONSTVARIABLE_H_
#define CONSTVARIABLE_H_

#include "../iVariable.h"
#include "Exception.h"
#include <string>

using std::string;

namespace Generator{
	namespace Collection{
		class ConstVariable:public Generator::Variable {
			private:
				SysType _value;
				string _name;
			public:
				ConstVariable(){}
				ConstVariable(const string &name,SysType val):_value(val){
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
					return _value;
				}
				inline virtual SysType SetValue(const string &name,SysType n){
					_name=name;
					_value=n;
					return n;
				}
		};
	}
}



#endif /* CONSTVARIABLE_H_ */
