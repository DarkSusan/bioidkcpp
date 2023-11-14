#include <iostream>
#include "biocpp.h"
namespace fs = std::filesystem;
using namespace biocpp;

// Demo code to showcase my lib in working
int main() {
	// Demo of class RecordN and their child RecordA and RecordQ that are used by their respective Fasta family classes
	RecordN record_n("seq name", "ATCG");
	// This family class has all field public as it is more of a data holder than functional class, but still needs a good constructor
	std::cout << "Record name: " << record_n.name << '\n';
	std::cout << "Record seq: " << record_n.sequence << '\n';
	std::cout << "Record len: " << record_n.length << '\n';
	std::cout << "\n\n\n";
	
	// Dome of FastaN class
	FastaN test_fasta("testn.fasta");
	std::cout << "FASTA file name : " << test_fasta.get_file_name() << '\n';
	std::cout << "FASTA file content type: " << test_fasta.get_content_type() << '\n';
	std::cout << "Number of records: " << test_fasta.get_record_num() << '\n';
	std::cout << "Mean length of reacords in file: " << test_fasta.get_mean_record_len() << '\n';
	RecordN record1 = test_fasta.get_next_record();
	std::cout << "Record 1 name: " << record1.name << '\n';
	std::cout << "Record 1 seq: " << record1.sequence << '\n';
	std::cout << "Record 1 length: " << record1.length << '\n';
	RecordN record2 = test_fasta.get_next_record();
	std::cout << "Record 2 name: " << record2.name << '\n';
	std::cout << "Record 2 seq: " << record2.sequence << '\n';
	std::cout << "Record 2 length: " << record2.length << '\n';
	std::cout << "\n\n\n";
	
	// Demo of FastQ class
	// As FastaQ class inherets from FastaN, it has all functions and data as parent class, so I limited demo here to show what this class has different
	FastaQ test_fastq("testq.fastq");
	std::cout << "FASTQ file name: " << test_fastq.get_file_name() << '\n';
	std::cout << "FASTQ file content type: " << test_fastq.get_content_type() << '\n';
	std::cout << "FASTQ mean quality of records: " << test_fastq.get_mean_quality() << '\n';
	RecordQ fastq_record = test_fastq.get_next_record();
	std::cout << "Record 1 name: " << fastq_record.name << '\n';
	std::cout << "Record 1 seq: " << fastq_record.sequence << '\n';
	std::cout << "Record 1 quality: " << fastq_record.mean_quality << '\n';
}
