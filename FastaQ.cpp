//
// Created by maks on 13/06/23.
//

#include "FastaQ.h"
#include "RecordQ.h"
#include <tuple>

using namespace biocpp;
using namespace std;

FastaQ::FastaQ(std::string file_path) : FastaN(file_path) {
	bool quality_line = false;
	float quality_sum = 0.0;
	string line;
	while (!this->file_handle.eof()) {
		getline(this->file_handle, line);
		if (quality_line) {
			float quality = 0.0;
			int len = line.length();
			for (int i = 0; i < len; i++) {
				char character = line[i];
				quality = quality + int(character);
			}
			quality = quality/len;
			quality_sum = quality_sum + quality;
			quality_line = false;
			continue;
		}
		int quality_marker = line.find('+');
		if (quality_marker != std::string::npos) {
			quality_line = true;
		}
	}
	this->mean_quality = quality_sum/this->record_num;
	this->file_handle.clear();
	this->file_handle.seekg(0);
}

float FastaQ::get_mean_quality() {
	return this->mean_quality;
}

RecordQ FastaQ::get_next_record() {
	if (this->file_handle.eof()) {
		std::cout << "There are no more records to read\n";
		RecordQ record("", "", "", 0.0);
		return record;
	}
	
	std::string record_seq;
	std::string record_name;
	std::string line;
	float mean_q = 0.0;
	getline(this->file_handle, record_name);
	record_name.erase(0, 1);
	getline(this->file_handle, record_seq);
	getline(this->file_handle, line);
	getline(this->file_handle, line);
	int len = line.length();
	for (int i = 0; i < len; i++) {
		char character = line[i];
		mean_q = mean_q + int(character);
	}
	mean_q = mean_q/len;
	RecordQ record(record_name, record_seq, line, mean_q);
	
	if (this->file_handle.eof()) {
		std::cout << "You reached end of file, no more record to read\n";
	}
	return record;
}