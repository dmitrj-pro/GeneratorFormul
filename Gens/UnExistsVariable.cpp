/*
 * UnExistsVariable.cpp
 *
 *  Created on: 16 апр. 2017 г.
 *      Author: diman-pro
 */


/*
 * ConstVariable.cpp
 *
 *  Created on: 13.04.2017
 *      Author: diman-pro
 */

#include "UnExistsVariable.h"
#include "Parenthesis.h"
#include "../MasterGen.h"
#include "Triple.h"

namespace Generator{
	namespace Collection{
		string UnExistsVariable::operator()(SysType n,bool&atom,Gen&g){
			string res="(";
			System::Random& r=System::Rand;
			Master& tmp=dynamic_cast<Master&>(g);
			if (r(2)==0){
				res+="("+tmp.left(r(30),r(30),atom);
				res+=_name+" )";
			} else {
				res+="("+_name;
				res+=tmp.right(r(30),r(30),atom)+")";
			}
			switch(r(5)){
				case 0:
					res+=">";
					break;
				case 1:
					res+="==";
					break;
				case 2:
					res+="<";
					break;
				case 3:
					res+=">=";
					break;
				case 4:
					res+="<=";
					break;
			}
			Generator::Collection::Constant cons;
			res+=cons(r(n));
			Triple tr;
			res+=tr(n,atom,g);
			res+=")";
			atom=true;
			return res;
		}
		string UnExistsVariable::operator()(SysType n,bool&atom){
			Master m;
			return this->operator ()(n,atom, m);
		}
	}
}




