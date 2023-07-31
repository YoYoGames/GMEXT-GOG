
#include "Extension_Interface.h"

#include "YYRValue.h"
#include "GalaxyApi.h"

extern RValue getStructFromGalaxyID(galaxy::api::GalaxyID ID);
extern galaxy::api::GalaxyID GalaxyIDFromStruct(RValue* _struct);

extern bool GOG_isInitialised;

#define GOG_NotInitialisedReturn_BOOL if (!GOG_isInitialised) { Result.kind = VALUE_BOOL; Result.val = false; return; }
#define GOG_NotInitialisedReturn_STRING if (!GOG_isInitialised) {Result.kind = VALUE_STRING; YYCreateString(&Result, ""); return; }
#define GOG_NotInitialisedReturn_STRUCT if (!GOG_isInitialised){ YYStructCreate(&Result); return; }
#define GOG_NotInitialisedReturn_INT32 if (!GOG_isInitialised) { Result.kind = VALUE_INT32; Result.val = 1; return; }
#define GOG_NotInitialisedReturn_INT64 if (!GOG_isInitialised) { Result.kind = VALUE_INT64; Result.v64 = 0.0; return; }
#define GOG_NotInitialisedReturn_REAL if (!GOG_isInitialised) { Result.kind = VALUE_REAL; Result.val = 0.0; return; }
