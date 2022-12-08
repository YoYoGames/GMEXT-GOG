
#include "YYGOG.h"
#include <vector>

YYEXPORT void GOG_Utils_GetImageSize(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT

	int32_t imageID= YYGetReal(arg, 0);
	int32_t width;
	int32_t height;
	galaxy::api::Utils()->GetImageSize(imageID,width,height);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddInt(&Struct, "width", width);
	YYStructAddInt(&Struct, "height", height);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Utils_GetImageRGBA(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	uint32_t imageID = YYGetReal(arg, 0);

	uint32 size = 32 * 32 * 4;
	std::vector<uint8_t> data;
	data.reserve(size);
	uint8_t* d = data.data();

	galaxy::api::Utils()->GetImageRGBA(imageID, d, size);

	int bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	BufferWriteContent(bufferID, 0, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Utils_RegisterForNotification(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* type = YYGetString(arg, 0);

	galaxy::api::Utils()->RegisterForNotification(type);
}

YYEXPORT void GOG_Utils_GetNotification(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	uint64_t notificationID = YYGetInt64(arg, 0);
	bool consumable;
	char type[999];
	uint32_t type_lenght = 999;
	void* content[99999];
	uint32_t content_size = 99999;
	galaxy::api::Utils()->GetNotification(notificationID, consumable,type, type_lenght,content, content_size);

	//JZAVALA TODO
}

YYEXPORT void GOG_Utils_ShowOverlayWithWebPage(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* url = YYGetString(arg, 0);

	galaxy::api::Utils()->ShowOverlayWithWebPage(url);
}

YYEXPORT void GOG_Utils_IsOverlayVisible(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Utils()->IsOverlayVisible();
}

YYEXPORT void GOG_Utils_GetOverlayState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	Result.kind = VALUE_REAL;
	Result.val = (int) galaxy::api::Utils()->GetOverlayState();
}

YYEXPORT void GOG_Utils_DisableOverlayPopups(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* popupGroup = YYGetString(arg, 0);

	galaxy::api::Utils()->DisableOverlayPopups(popupGroup);
}

YYEXPORT void GOG_Utils_GetGogServicesConnectionState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	Result.kind = VALUE_REAL;
	Result.val = (int) galaxy::api::Utils()->GetGogServicesConnectionState();
}
