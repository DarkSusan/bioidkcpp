//
// Created by maks on 13/06/23.
//

#ifndef BIOCPP_RECORDQ_H
#define BIOCPP_RECORDQ_H
#include "biocpp.h"

using namespace biocpp;
using namespace std;

namespace biocpp {
	
	class RecordQ : public RecordN {
	public:
		string quality_sequence;
		float mean_quality;
		
		RecordQ (string name, string seq, string quality_seq, float quality_mean);
	
	};
	
} // biocpp

#endif //BIOCPP_RECORDQ_H
