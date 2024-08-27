
#include "Extension_Interface.h"

#include "YYRValue.h"
#include "GalaxyApi.h"

extern RValue getStructFromGalaxyID(galaxy::api::GalaxyID ID);
extern galaxy::api::GalaxyID GalaxyIDFromStruct(RValue* _struct);

extern bool GOG_isInitialised;

#define GOG_NotInitialisedReturn_BOOL if (!GOG_isInitialised) { Result.kind = VALUE_BOOL; Result.val = false; return; }
#define GOG_NotInitialisedReturn_STRING if (!GOG_isInitialised) {Result.kind = VALUE_STRING; YYCreateString(&Result, ""); return; }
#define GOG_NotInitialisedReturn_STRUCT if (!GOG_isInitialised){ YYStructCreate(&Result); return; }
#define GOG_NotInitialisedReturn_INT32 if (!GOG_isInitialised) { Result.kind = VALUE_INT32; Result.val = 0; return; }
#define GOG_NotInitialisedReturn_INT64 if (!GOG_isInitialised) { Result.kind = VALUE_INT64; Result.v64 = 0; return; }
#define GOG_NotInitialisedReturn_REAL if (!GOG_isInitialised) { Result.kind = VALUE_REAL; Result.val = 0.0; return; }

#define GOG_GetOptUserId(_ArgIndex) ((((_ArgIndex) < argc) && (arg != nullptr)) ? GalaxyIDFromStruct(&arg[(_ArgIndex)]) : galaxy::api::GalaxyID())

#define GOG_EnsureArgc(_ArgC) \
	do { \
		if ((argc < (_ArgC)) || (arg == nullptr)) \
			YYError("%s expected %d required arguments got %d", __func__, static_cast<int>(_ArgC), static_cast<int>(argc)); \
	} while (0)
