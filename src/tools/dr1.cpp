#include "dr1.h"

namespace gaia {
namespace dr1 {

/**
 * Download file specified by url and return decompressed csv filename.
 */
auto loadFileFromServer(std::string const& filename) -> arma::mat {

	// Create tmp filename
	char tmp[] = "/tmp/gaia.XXXXXX";
	int r = mkstemp(tmp);
	std::string fname(tmp + std::string(".csv.gz"));

	// Invoke wget to obtain file
	std::string cmd("wget " + std::string(serverAddr) + filename + " -O " + fname +
	                " && gunzip " + fname);
	r = system(cmd.c_str());

	// Load csv file into TODO: file format
	std::string csvFile(fname.substr(0, fname.size()-3));
	arma::mat m;
	m.load(csvFile);

	return m;
}


void updateGaiaDR1FileList() {
	std::string cmd(std::string("rm gaiaDR1_file_list.txt;") +
	                std::string("curl -s http://cdn.gea.esac.esa.int/Gaia/gaia_source/csv/") +
	                std::string(" | awk -F '<a href=\"' '{print $2}' | awk -F '\">' '{print $1}'") +
	                std::string(" | grep csv.gz > gaiaDR1_file_list.txt")
	);
	int r = system(cmd.c_str());
}


auto gaiaDR1FileList() -> std::vector<std::string> {
	std::ifstream fileList("gaiaDR1_file_list.txt", std::ifstream::in);
	std::vector<std::string> files;
	std::string fname;
	while (std::getline(fileList, fname)) {
		files.push_back(fname);
	}
	return files;
}

} // namespace dr1
} // namespace gaia

