/*
 * Parenthesis.cpp
 *
 *  Created on: 12 апр. 2017 г.
 *      Author: diman-pro
 */

#include "Parenthesis.h"
#include "../MasterGen.h"

namespace Generator{
	namespace Collection{
		string Parenthesis::operator()(SysType n,bool& atom,Gen&g){
			string res;
			bool b=false;
			res=g(n,b);
			if (!b)
				res="("+res+")";
			atom=true;
			return res;
		}
		string Parenthesis::operator()(SysType n,bool& atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}


