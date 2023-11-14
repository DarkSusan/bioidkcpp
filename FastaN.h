//
// Created by maks on 26/05/23.
//

#ifndef BIOCPP_FASTAN_H
#define BIOCPP_FASTAN_H
#include <filesystem>
#include <iostream>
#include <fstream>
#include <tuple>
#include "biocpp.h"
#include "RecordN.h"

using namespace std::filesystem;

namespace biocpp {
	class FastaN {
	
	protected:
		int record_num = 0;
		float mean_record_len;
		path file_path;
		std::string fasta_content_type;
		std::ifstream file_handle;
	public:
		FastaN(std::string file_path);
		
		std::string get_content_type();
		
		std::string get_file_name();
		
		int get_record_num();
		
		float get_mean_record_len();
		
		RecordN get_next_record();
	};
};

#endif //BIOCPP_FASTAN_H
