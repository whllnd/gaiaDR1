#include "tools/dr1.h"

int main() {
	auto files = gaia::dr1::gaiaDR1FileList();
	auto m = gaia::dr1::loadFileFromServer(files[0]);
	m.col(gaia::dr1::SOLUTION_ID).print("m:");
}
