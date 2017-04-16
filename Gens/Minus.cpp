/*
 * Minus.cpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#include "Minus.h"
#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string Minus::operator()(SysType n,bool&atom,Gen&g){
			string res;
			System::Random& r=System::Rand;
			SysType k1,k2;
			k2=r(n);
			k1=n+k2;
#ifdef ControlOverflow
			if ((k1-n)!=k2)
				throw FailGenerator();
#endif
			res+=g(k1,atom);
			res+=" - ";
			Parenthesis skob;
			bool b;
			res+=skob(k2,b,g);
			atom=false;
			return res;
		}
		string Minus::right(SysType left,SysType n,bool&atom,Gen&g){
			SysType right=left-n;
			string res=" - ";
			Parenthesis skob;
			bool b;
			res+=skob(right,b,g);
			atom=false;
			return res;
		}
		string Minus::left(SysType right,SysType n,bool&atom,Gen&g){
			SysType left=right+n;
#ifdef ControlOverflow
			if ((left-n)!=right)
				throw FailGenerator();
#endif
			Parenthesis skob;
			string res;
			bool b;
			res+=skob(left,b,g);
			res+=" - ";
			atom=false;
			return res;
		}
		string Minus::operator()(SysType n,bool&atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}


