#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <armadillo>

namespace gaia {
namespace dr1 {

auto constexpr serverAddr = "http://cdn.gea.esac.esa.int/Gaia/gaia_source/csv/";

enum class fields : int { // TODO: Make it work as index
	SOLUTION_ID = 0,
	SOURCE_ID,
	RANDOM_INDEX,
	REF_EPOCH,
	RA,
	RA_ERROR,
	DEC,
	DEC_ERROR,
	PARALLAX,
	PARALLAX_ERROR,
	PMRA,
	PMRA_ERROR,
	PMDEC,
	PMDEC_ERROR,
	RA_DEC_CORR,
	RA_PARALLAX_CORR,
	RA_PMRA_CORR,
	RA_PMDEC_CORR,
	DEC_PARALLAX_CORR,
	DEC_PMRA_CORR,
	DEC_PMDEC_CORR,
	PARALLAX_PMRA_CORR,
	PARALLAX_PMDEC_CORR,
	PMRA_PMDEC_CORR,
	ASTROMETRIC_N_OBS_AL,
	ASTROMETRIC_N_OBS_AC
};

auto loadFileFromServer(std::string const& filename) -> arma::mat;
auto gaiaDR1FileList() -> std::vector<std::string>;
auto updateGaiaDR1FileList() -> void;

} // namespace curl
} // namespace gaia

