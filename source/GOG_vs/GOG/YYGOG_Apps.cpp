
#include "YYGOG.h"
#include "YYGOG_Listener.hpp"

YYEXPORT void GOG_Apps_IsDlcInstalled(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	int64 productID = YYGetInt64(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Apps()->IsDlcInstalled(static_cast<galaxy::api::ProductID>(productID));
}

YYEXPORT void GOG_Apps_IsDlcOwned(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	int64 productID = YYGetInt64(arg, 0);

	galaxy::api::Apps()->IsDlcOwned(static_cast<galaxy::api::ProductID>(productID), GMAsyncEventListener::Instance());
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Apps_GetCurrentGameLanguage(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	int64 productID = (argc > 0) ? YYGetInt64(arg, 0) : 0;

	const char* GameLanguage = galaxy::api::Apps()->GetCurrentGameLanguage(static_cast<galaxy::api::ProductID>(productID));

	YYCreateString(&Result, GameLanguage);
}

YYEXPORT void GOG_Apps_GetCurrentGameLanguageCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	int64 productID = (argc > 0) ? YYGetInt64(arg, 0) : 0;

	const char* GameLanguageCode = galaxy::api::Apps()->GetCurrentGameLanguageCode(static_cast<galaxy::api::ProductID>(productID));

	YYCreateString(&Result, GameLanguageCode);
}


