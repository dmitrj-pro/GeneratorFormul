/*
 * Sum.cpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#include "Sum.h"
#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string Sum::operator()(SysType n,bool&atom,Gen&g){
			string res;
			System::Random& r=System::Rand;
			SysType k1,k2;
			k1=r(n);
			k2=n-k1;
			res+=g(k1,atom);
			res+=" + ";
			res+=g(k2,atom);
			atom=false;
			return res;
		}
		string Sum::right(SysType left,SysType n,bool&atom,Gen&g){
			string res;
			SysType right=n-left;
			res+=" + ";
			res+=g(right,atom);
			atom=false;
			return res;
		}
		string Sum::left(SysType right,SysType n,bool&atom,Gen&g){
			string res;
			SysType left=n-right;
			res+=g(left,atom);
			res+=" + ";
			atom=false;
			return res;
		}
		string Sum::operator()(SysType n,bool& atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}


