/*
 * Divide.cpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#include "Divide.h"
#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string Divide::operator()(SysType n,bool&atom,Gen&g){
			string res;
			//console<<n<<" ";
			System::Random& r=System::Rand;
			SysType k1,k2;
			k2=n==0?1:r((n<0)?((-1)*n/2):n/2);
			//console<<k2<<" ";
			k2=k2==0?1:k2;
			//console<<k2<<" ";
			k1=k2*n;
#ifdef ControlOverflow
		if (k1/n!=k2)
			throw FailGenerator();
#endif
			//console<<k1<<"\n ";
			Parenthesis skob;
			bool b;
			res+=skob(k1,b,g);
			res+=" / ";
			res+=skob(k2,b,g);
			atom=false;
			return res;
		}
		string Divide::right(SysType left,SysType n,bool&atom,Gen&g){
			SysType k2;
			if (left==0)
				throw FailGenerator();
			if (n==0)
				throw FailGenerator();
			k2=left/n;
			if (k2==0)
				throw FailGenerator();
			Parenthesis skob;
			bool b;
			string res=" / ";
			res+=skob(k2,b,g);
			atom=false;
			return res;
		}
		string Divide::left(SysType right,SysType n,bool&atom,Gen&g){
			if (right==0)
				throw FailGenerator();
			if (n==0)
				throw FailGenerator();
			SysType k1=right*n;
#ifdef ControlOverflow
			if ((k1/n)!=right)
				throw FailGenerator();
#endif
			Parenthesis skob;
			bool b;
			string res=skob(k1,b,g)+" / ";
			atom=false;
			return res;
		}
		string Divide::operator()(SysType n,bool&atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}


