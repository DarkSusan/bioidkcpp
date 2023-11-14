//
// Created by maks on 26/05/23.
//

#include "FastaN.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "RecordN.h"

using namespace std::filesystem;
using namespace biocpp;

biocpp::FastaN::FastaN(std::string file_path) {
	this->file_path = path(file_path);
	this->fasta_content_type = this->file_path.extension().string().erase(0, 1);
	std::ifstream fasta_file(path(file_path).generic_string());
	std::string line;
	int record_len = 0;
	float record_len_sum = 0;
	int record_num = 0;
	bool first_record = true;
	while (!fasta_file.eof()) {
		getline(fasta_file, line);
		int record_start = line.find('>');
		if (record_start != std::string::npos) {
			if (first_record) {
				record_num++;
				first_record = false;
				continue;
			}
			record_len_sum += record_len;
			record_len = 0;
			record_num++;
		} else {
			record_len = record_len + line.length();
		}
	}
	record_len_sum += record_len;
	this->file_handle.open(this->file_path);
	this->mean_record_len = record_len_sum/record_num;
	this->record_num = record_num;
};

int FastaN::get_record_num() {
	return this->record_num;
}

std::string FastaN::get_file_name() {
	return this->file_path.stem();
}

float FastaN::get_mean_record_len() {
	return this->mean_record_len;
}

std::string FastaN::get_content_type() {
	return this->fasta_content_type;
}

RecordN FastaN::get_next_record() {
	if (this->file_handle.eof()) {
		std::cout << "There are no more records to read\n";
		RecordN record("", "");
		return record;
	}
	std::string record_seq;
	std::string record_name;
	getline(this->file_handle, record_name);
	record_name.erase(0, 1);
	getline(this->file_handle, record_seq);
	
	RecordN record(record_name, record_seq);
	
	if (this->file_handle.eof()) {
		std::cout << "You reached end of file, no more record to read\n";
	}
	
	return record;
}
