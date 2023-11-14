//
// Created by maks on 13/06/23.
//

#include "RecordQ.h"

namespace biocpp {
	RecordQ::RecordQ(std::string name, std::string seq, std::string quality_seq, float quality_mean) : RecordN(name, seq) {
		this->quality_sequence = quality_seq;
		this->mean_quality = quality_mean;
		
	}
} // biocpp