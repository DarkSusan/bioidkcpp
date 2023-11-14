//
// Created by maks on 13/06/23.
//

#ifndef BIOCPP_RECORDN_H
#define BIOCPP_RECORDN_H
#include "biocpp.h"

using namespace std;

namespace biocpp {
	
	class RecordN {
	public:
		string name;
		string sequence;
		int length;
		
		RecordN(string name, string seq);
	
	};
	
} // biocpp

#endif //BIOCPP_RECORDN_H
