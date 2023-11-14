//
// Created by maks on 13/06/23.
//

#ifndef BIOCPP_FASTAQ_H
#define BIOCPP_FASTAQ_H
#include "biocpp.h"
#include "RecordQ.h"

using namespace biocpp;
using namespace std;

namespace biocpp {
	class FastaQ : public FastaN {
	private:
		float mean_quality;
	
	public:
		FastaQ(string file_path);
		
		float get_mean_quality();
		
		RecordQ get_next_record();
		
	};
};


#endif //BIOCPP_FASTAQ_H
