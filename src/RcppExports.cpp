// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// hicData
Rcpp::IntegerMatrix hicData(std::string fileName, std::string chr1, std::string chr2, std::string unit, int resolution);
RcppExport SEXP _FreeHiCLite_hicData(SEXP fileNameSEXP, SEXP chr1SEXP, SEXP chr2SEXP, SEXP unitSEXP, SEXP resolutionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< std::string >::type chr1(chr1SEXP);
    Rcpp::traits::input_parameter< std::string >::type chr2(chr2SEXP);
    Rcpp::traits::input_parameter< std::string >::type unit(unitSEXP);
    Rcpp::traits::input_parameter< int >::type resolution(resolutionSEXP);
    rcpp_result_gen = Rcpp::wrap(hicData(fileName, chr1, chr2, unit, resolution));
    return rcpp_result_gen;
END_RCPP
}
// hicDataHttp
Rcpp::IntegerMatrix hicDataHttp(std::string fileName, std::string chr1, std::string chr2, std::string unit, int resolution);
RcppExport SEXP _FreeHiCLite_hicDataHttp(SEXP fileNameSEXP, SEXP chr1SEXP, SEXP chr2SEXP, SEXP unitSEXP, SEXP resolutionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< std::string >::type chr1(chr1SEXP);
    Rcpp::traits::input_parameter< std::string >::type chr2(chr2SEXP);
    Rcpp::traits::input_parameter< std::string >::type unit(unitSEXP);
    Rcpp::traits::input_parameter< int >::type resolution(resolutionSEXP);
    rcpp_result_gen = Rcpp::wrap(hicDataHttp(fileName, chr1, chr2, unit, resolution));
    return rcpp_result_gen;
END_RCPP
}
// hicDataExtra
Rcpp::List hicDataExtra(const std::string& fileName, bool isHttp, const std::vector<std::string>& pair, const std::string& unit, int resolution);
RcppExport SEXP _FreeHiCLite_hicDataExtra(SEXP fileNameSEXP, SEXP isHttpSEXP, SEXP pairSEXP, SEXP unitSEXP, SEXP resolutionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< bool >::type isHttp(isHttpSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type pair(pairSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type unit(unitSEXP);
    Rcpp::traits::input_parameter< int >::type resolution(resolutionSEXP);
    rcpp_result_gen = Rcpp::wrap(hicDataExtra(fileName, isHttp, pair, unit, resolution));
    return rcpp_result_gen;
END_RCPP
}
// hicDataFragSites
Rcpp::List hicDataFragSites(const std::string& fileName, bool isHttp, const std::vector<std::string>& chromosomes);
RcppExport SEXP _FreeHiCLite_hicDataFragSites(SEXP fileNameSEXP, SEXP isHttpSEXP, SEXP chromosomesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< bool >::type isHttp(isHttpSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type chromosomes(chromosomesSEXP);
    rcpp_result_gen = Rcpp::wrap(hicDataFragSites(fileName, isHttp, chromosomes));
    return rcpp_result_gen;
END_RCPP
}
// hicDataInformation
Rcpp::List hicDataInformation(const std::string& fileName, bool isHttp);
RcppExport SEXP _FreeHiCLite_hicDataInformation(SEXP fileNameSEXP, SEXP isHttpSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< bool >::type isHttp(isHttpSEXP);
    rcpp_result_gen = Rcpp::wrap(hicDataInformation(fileName, isHttp));
    return rcpp_result_gen;
END_RCPP
}
// hicDataSimu
Rcpp::List hicDataSimu(const std::string& fileName, const std::vector<std::string>& chromosomes, const std::string& unit, int resolution, const int& sequenceDepth, const double& countScale, const double& noiseRate, const double& neighborZeroRate);
RcppExport SEXP _FreeHiCLite_hicDataSimu(SEXP fileNameSEXP, SEXP chromosomesSEXP, SEXP unitSEXP, SEXP resolutionSEXP, SEXP sequenceDepthSEXP, SEXP countScaleSEXP, SEXP noiseRateSEXP, SEXP neighborZeroRateSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type chromosomes(chromosomesSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type unit(unitSEXP);
    Rcpp::traits::input_parameter< int >::type resolution(resolutionSEXP);
    Rcpp::traits::input_parameter< const int& >::type sequenceDepth(sequenceDepthSEXP);
    Rcpp::traits::input_parameter< const double& >::type countScale(countScaleSEXP);
    Rcpp::traits::input_parameter< const double& >::type noiseRate(noiseRateSEXP);
    Rcpp::traits::input_parameter< const double& >::type neighborZeroRate(neighborZeroRateSEXP);
    rcpp_result_gen = Rcpp::wrap(hicDataSimu(fileName, chromosomes, unit, resolution, sequenceDepth, countScale, noiseRate, neighborZeroRate));
    return rcpp_result_gen;
END_RCPP
}
// hicDataSimuPure
Rcpp::List hicDataSimuPure(const Rcpp::List& contactRecords, const std::vector<std::string>& names, int resolution, const int& sequenceDepth, const double& countScale, const double& noiseRate, const double& neighborZeroRate);
RcppExport SEXP _FreeHiCLite_hicDataSimuPure(SEXP contactRecordsSEXP, SEXP namesSEXP, SEXP resolutionSEXP, SEXP sequenceDepthSEXP, SEXP countScaleSEXP, SEXP noiseRateSEXP, SEXP neighborZeroRateSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type contactRecords(contactRecordsSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type names(namesSEXP);
    Rcpp::traits::input_parameter< int >::type resolution(resolutionSEXP);
    Rcpp::traits::input_parameter< const int& >::type sequenceDepth(sequenceDepthSEXP);
    Rcpp::traits::input_parameter< const double& >::type countScale(countScaleSEXP);
    Rcpp::traits::input_parameter< const double& >::type noiseRate(noiseRateSEXP);
    Rcpp::traits::input_parameter< const double& >::type neighborZeroRate(neighborZeroRateSEXP);
    rcpp_result_gen = Rcpp::wrap(hicDataSimuPure(contactRecords, names, resolution, sequenceDepth, countScale, noiseRate, neighborZeroRate));
    return rcpp_result_gen;
END_RCPP
}
// spikein
Rcpp::IntegerMatrix spikein(const Rcpp::IntegerMatrix& background, const Rcpp::IntegerMatrix& SpikeInSignal, int resolution, bool smooth);
RcppExport SEXP _FreeHiCLite_spikein(SEXP backgroundSEXP, SEXP SpikeInSignalSEXP, SEXP resolutionSEXP, SEXP smoothSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::IntegerMatrix& >::type background(backgroundSEXP);
    Rcpp::traits::input_parameter< const Rcpp::IntegerMatrix& >::type SpikeInSignal(SpikeInSignalSEXP);
    Rcpp::traits::input_parameter< int >::type resolution(resolutionSEXP);
    Rcpp::traits::input_parameter< bool >::type smooth(smoothSEXP);
    rcpp_result_gen = Rcpp::wrap(spikein(background, SpikeInSignal, resolution, smooth));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_FreeHiCLite_hicData", (DL_FUNC) &_FreeHiCLite_hicData, 5},
    {"_FreeHiCLite_hicDataHttp", (DL_FUNC) &_FreeHiCLite_hicDataHttp, 5},
    {"_FreeHiCLite_hicDataExtra", (DL_FUNC) &_FreeHiCLite_hicDataExtra, 5},
    {"_FreeHiCLite_hicDataFragSites", (DL_FUNC) &_FreeHiCLite_hicDataFragSites, 3},
    {"_FreeHiCLite_hicDataInformation", (DL_FUNC) &_FreeHiCLite_hicDataInformation, 2},
    {"_FreeHiCLite_hicDataSimu", (DL_FUNC) &_FreeHiCLite_hicDataSimu, 8},
    {"_FreeHiCLite_hicDataSimuPure", (DL_FUNC) &_FreeHiCLite_hicDataSimuPure, 7},
    {"_FreeHiCLite_spikein", (DL_FUNC) &_FreeHiCLite_spikein, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_FreeHiCLite(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
