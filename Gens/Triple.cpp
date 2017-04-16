/*
 * Triple.cpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */


#include "Triple.h"
#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string Triple::operator()(SysType n,bool&atom,Gen&g){
			string res;
			Parenthesis skob;
			res+=" ? ";
			res+=skob(n,atom,g);
			res+=" : ";
			res+=skob(n,atom,g);
			atom=false;
			return res;
		}
		string Triple::operator()(SysType n,bool& atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}

