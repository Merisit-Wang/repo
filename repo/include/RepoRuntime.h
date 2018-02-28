#ifndef INCL_DCM_HFE76C40C_7665_45F3_B7E3_7A0F7C23F573
#define INCL_DCM_HFE76C40C_7665_45F3_B7E3_7A0F7C23F573

#include "infra/base/repo.h"
#include "infra/dci/role.h"
#include <string>

REPO_NS_BEGIN

DEFINE_ROLE(RepoRuntime)
{
    static RepoRuntime& getInstance();

    ABSTRACT(void run(std::string cmd));
};

#define REPO_RUNTIME(cmd) RepoRuntime::getInstance().run(cmd);

REPO_NS_END

#endif
