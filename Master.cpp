/*
 * Master.cpp
 *
 *  Created on: 16 апр. 2017 г.
 *      Author: diman-pro
 */


#include "MasterGen.h"

namespace Generator{
	namespace Collection{
		string Master::operator()(SysType t,bool& atom){
			if (iterator>maxIterator)
				throw FailGenerator();
			iterator++;
			auto rand=System::Rand;
			bool flag=false;
			string res="";
			while (true){
				try{
					SysType ind=rand(_gen.size());
					RecursiveGen* tmp=dynamic_cast<RecursiveGen*>(_gen[ind]);
					if (tmp!=nullptr){
						if (t==1 || t==0)
							continue;
						res+=(*tmp)(t,atom,*this);
						break;
					}
					res+=(*_gen[ind])(t,atom);
					break;
				}catch(FailGenerator&){
					if (flag){
						iterator--;
						throw FailGenerator();
					} else
						flag=true;
				}
			}
			iterator--;
			return res;
		}
		string Master::left(SysType right,SysType n,bool&atom){
			if (iterator>maxIterator || n==1||n==0)
				throw FailGenerator();
			iterator++;
			bool flag=false;
			string res;
			auto rand=System::Rand;

			while (true){
				try{
					SysType ind=rand(_gen.size());
					iLFGen* tmp=dynamic_cast<iLFGen*>(_gen[ind]);
					if (tmp!=nullptr){
						res+=(*tmp).left(right,n,atom,*this);
						break;
					}
				}catch(FailGenerator&){
					if (flag){
						iterator--;
						throw FailGenerator();
					} else
						flag=true;
				}
			}

			iterator--;
			return res;
		}
		string Master::right(SysType left,SysType n,bool&atom){
			if (iterator>maxIterator || n==1||n==0)
				throw FailGenerator();
			iterator++;
			bool flag=false;
			string res;
			auto rand=System::Rand;

			while (true){
				try{
					SysType ind=rand(_gen.size());
					iLFGen* tmp=dynamic_cast<iLFGen*>(_gen[ind]);
					if (tmp!=nullptr){
						res+=(*tmp).right(left,n,atom,*this);
						break;
					}
				}catch(FailGenerator&){
					if (flag){
						iterator--;
						throw FailGenerator();
					} else
						flag=true;
				}
			}

			iterator--;
			return res;
		}
		string Master::operator()(SysType t){
			while(true)
				try{
					bool atom=true;
					return this->operator ()(t,atom);
				}catch(FailGenerator&)
				{}
		}

	}
}

