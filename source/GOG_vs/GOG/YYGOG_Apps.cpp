
#include "YYGOG.h"

YYEXPORT void GOG_Apps_IsDlcInstalled(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	int64 productID = YYGetInt64(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Apps()->IsDlcInstalled((galaxy::api::ProductID)productID);
}

YYEXPORT void GOG_Apps_GetCurrentGameLanguage(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	int64 productID = YYGetInt64(arg, 0);

	const char* GameLanguage = galaxy::api::Apps()->GetCurrentGameLanguage((galaxy::api::ProductID)productID);

	YYCreateString(&Result, GameLanguage);
}

//YYEXPORT void GOG_Apps_GetCurrentGameLanguageCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	galaxy::api::Apps()->GetCurrentGameLanguageCopy()
//}

