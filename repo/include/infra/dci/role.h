#ifndef INCL_DCM_HEAFD2E2F_8149_40DA_B673_C4FF2F143ECF
#define INCL_DCM_HEAFD2E2F_8149_40DA_B673_C4FF2F143ECF

#include "infra/base/KeyWords.h"

//////////////////////////////////////////////////////////////////////////
#define ROLE(role) get##role()
#define ROLE_PROTO_TYPE(role) role& ROLE(role) const
#define USE_ROLE(role) virtual ROLE_PROTO_TYPE(role) = 0
#define HAS_ROLE(role) USE_ROLE(role)

//////////////////////////////////////////////////////////////////
#define IMPL_ROLE(role)                                       \
ROLE_PROTO_TYPE(role)                                         \
{                                                             \
   return const_cast<role&>(static_cast<const role&>(*this)); \
}

//////////////////////////////////////////////////////////////////////////
namespace details
{
   struct Role
   {
      virtual ~Role() {}
   };
}

#define DEFINE_ROLE(role)  struct role : ::details::Role

#endif
