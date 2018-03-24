#ifndef INCL_REPO_H5BFD555D_D25D_4031_AE19_D76073F758DA
#define INCL_REPO_H5BFD555D_D25D_4031_AE19_D76073F758DA

#include "infra/base/repo.h"
#include <string>

REPO_NS_BEGIN

static std::string DIR_CPU = "Code_CPUPlatform/";
static std::string DIR_LTE = "Code_LTE/";
static std::string DIR_PUB = DIR_LTE + "pub/";
static std::string DIR_SDR = DIR_LTE + "sdr/";
static std::string DIR_SPS = DIR_LTE + "sps/";
static std::string DIR_PROJECT = "Project/";
static std::string DIR_BUILD = "DailyBuild/";
static std::string REPO = ".repo";

struct Repo
{
    static int init();
    static bool isValid();
    static void rmRepo();

private:
    static bool verify();
};

REPO_NS_END

#endif
