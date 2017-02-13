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


auto updateGaiaDR1FileList() -> void { // TODO: Check before deleting
	std::string cmd("rm gaiaDR1_file_list.txt;" \
	                "curl -s http://cdn.gea.esac.esa.int/Gaia/gaia_source/csv/" \
	                " | awk -F '<a href=\"' '{print $2}' | awk -F '\">' '{print $1}'" \
	                " | grep csv.gz > gaiaDR1_file_list.txt"
	);
	int r = system(cmd.c_str());
}


auto gaiaDR1FileList() -> std::vector<std::string> {
	std::ifstream fileList("gaiaDR1_file_list.txt", std::ifstream::in);
	if (!fileList.good()) {
		fileList.close();
		updateGaiaDR1FileList();
		fileList.open("gaiaDR1_file_list.txt", std::ifstream::in);
	}
	std::vector<std::string> files;
	for (std::string fname; std::getline(fileList, fname); ) {
		files.push_back(fname);
	}
	return files;
}

} // namespace dr1
} // namespace gaia

