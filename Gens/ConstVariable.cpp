/*
 * ConstVariable.cpp
 *
 *  Created on: 13.04.2017
 *      Author: diman-pro
 */

#include "ConstVariable.h"
#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string ConstVariable::operator()(SysType n,bool&atom,Gen&g){
			string res;
			System::Random& r=System::Rand;
			atom=true;
			if (n==_value)
				return _name;
			Parenthesis skob;
			Master& tmp=dynamic_cast<Master&>(g);
			if (r(2)==0){
				res=tmp.left(_value,n,atom);
				res+=_name;
				atom=false;
			}else{
				res=_name;
				res+=tmp.right(_value,n,atom);
				atom=false;
			}
			return res;
		}
		string ConstVariable::operator()(SysType n,bool&atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}


