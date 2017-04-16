/*
 * MasterGen.h
 *
 *  Created on: 11 апр. 2017 г.
 *      Author: diman-pro
 */

#ifndef GENERATOR_GENS_MASTERGEN_H_
#define GENERATOR_GENS_MASTERGEN_H_

#include "iGen.h"
#include "iVariable.h"
#include "iRecursiveGen.h"
#include "iLFGen.h"


#include "Gens/Exception.h"
#include "Gens/Constant.h"
#include "Gens/Sum.h"
#include "Gens/Multiple.h"
#include "Gens/Divide.h"
#include "Gens/Minus.h"
#include "Gens/Triple.h"
#include "Gens/ConstVariable.h"
#include "Gens/UnExistsVariable.h"

#include <vector>
#include "Sys.h"

//#include "../MasterExcecute/Exec.h"
#include "MemoryManager/Memory.h"
//#include "../ProcessManager/MultiThreadOut.h"

using std::vector;

namespace Generator{
	namespace Collection{

		class Master:public Generator::Gen{
			private:
				vector<Generator::Gen*> _gen;
				MemoryManager::Manager mng;
				int iterator=0;
				int maxIterator=20;
			public:
				Master(){
					_gen.push_back(&mng.getMem<Generator::Collection::Constant>());
					_gen.push_back(&mng.getMem<Generator::Collection::Sum>());
					_gen.push_back(&mng.getMem<Generator::Collection::Multiple>());
					_gen.push_back(&mng.getMem<Generator::Collection::Divide>());
					_gen.push_back(&mng.getMem<Generator::Collection::Minus>());
				}
				virtual string operator()(SysType t,bool& atom);
				string left(SysType right,SysType n,bool&atom);
				string right(SysType left,SysType n,bool&atom);
				virtual string operator()(SysType t);
				virtual inline SysType SetValue(const string &name,SysType n){
					ConstVariable* var=&mng.getMem<Generator::Collection::ConstVariable>();
					var->SetValue(name,n);
					_gen.push_back(var);
					return n;
				}
				virtual inline void SetValue(const string &name){
					UnExistsVariable* var=&mng.getMem<Generator::Collection::UnExistsVariable>();
					var->SetValue(name,0);
					_gen.push_back(var);
				}
		};
	}
}

#endif /* GENERATOR_GENS_MASTERGEN_H_ */
