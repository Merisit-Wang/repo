#ifndef INCL_DCM_HFE76C40C_7665_45F3_B7E3_7A0F7C23F573
#define INCL_DCM_HFE76C40C_7665_45F3_B7E3_7A0F7C23F573

#include "infra/base/repo.h"
#include "infra/dci/role.h"
#include <string>
#include "cmd-line/CmdLineRunner.h"
#include "cmd-line/CmdLineParser.h"
#include "options/core/OptionFactory.h"

REPO_NS_BEGIN

DEFINE_ROLE(RepoRuntime)
{
    static RepoRuntime& getInstance();

    HAS_ROLE(CmdLineRunner);
    HAS_ROLE(CmdLineParser);
    HAS_ROLE(OptionFactory);
};

#define REPO_RUNTIME(type) RepoRuntime::getInstance().ROLE(type)

REPO_NS_END

#endif
