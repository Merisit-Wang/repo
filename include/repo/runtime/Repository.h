#ifndef INCL_REPO_H5BFD555D_D25D_4031_AE19_D76073F758DA
#define INCL_REPO_H5BFD555D_D25D_4031_AE19_D76073F758DA

#include "infra/base/repo.h"

REPO_NS_BEGIN

struct Repository
{
    void init();

private:
    bool isValidRepo() const;
};

REPO_NS_END

#endif
