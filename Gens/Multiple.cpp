/*
 * Multiple.cpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#include "Multiple.h"
#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string Multiple::operator()(SysType n,bool&atom,Gen&g){
			string res;
			System::Random& r=System::Rand;
			SysType k1,k2;
			SysType countTry=0;
			while(true){
				countTry++;
				if (countTry>=(n/(r(n)+1)))
					throw FailGenerator();
				k1=r(n/2)+1;
				k2=n/k1;
				if (k1*k2==n)
					break;
			}
#ifdef ControlOverflow
			if ((n/k2)!=k1)
				throw FailGenerator();
#endif
			Parenthesis skob;
			bool b;
			res+=skob(k1,b,g);
			res+=" * ";
			res+=skob(k2,b,g);
			atom=false;
			return res;
		}
		string Multiple::left(SysType right,SysType n,bool&atom,Gen&g){
			if (right==0)
				throw FailGenerator();
			SysType k=n/right;
			if (k*right!=n)
				throw FailGenerator();
			string res;
			Parenthesis skob;
			bool b;
			res+=skob(k,b,g);
			res+=" * ";
			atom=false;
			return res;
		}
		string Multiple::right(SysType left,SysType n,bool&atom,Gen&g){
			if (left==0)
				throw FailGenerator();
			SysType k=n/left;
			if ((k*left)!=n)
				throw FailGenerator();
			string res=" * ";
			Parenthesis skob;
			bool b;
			res+=skob(k,b,g);
			atom=false;
			return res;
		}
		string Multiple::operator()(SysType n,bool& atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}


