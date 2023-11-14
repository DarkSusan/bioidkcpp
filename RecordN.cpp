//
// Created by maks on 13/06/23.
//

#include "RecordN.h"
#include "biocpp.h"

namespace biocpp {
	RecordN::RecordN(std::string name, std::string seq) {
		this->name = name;
		this->sequence = seq;
		this->length = seq.length();
	}
} // biocpp