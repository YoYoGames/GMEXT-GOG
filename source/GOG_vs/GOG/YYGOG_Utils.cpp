
#include "YYGOG.h"
#include <vector>

YYEXPORT void GOG_Utils_GetImageSize(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;
	GOG_EnsureArgc(1);

	double imageID = YYGetReal(arg, 0);
	int32_t width = 0;
	int32_t height = 0;
	galaxy::api::Utils()->GetImageSize(static_cast<uint32_t>(imageID), width, height);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddInt(&Struct, "width", width);
	YYStructAddInt(&Struct, "height", height);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Utils_GetImageRGBA(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	double imageID = YYGetReal(arg, 0);
	int bufferID = (argc > 1) ? YYGetInt32(arg, 1) : -1;
	int byteOffset = (argc > 2) ? YYGetInt32(arg, 2) : 0;

	int32_t width = 0, height = 0;
	galaxy::api::Utils()->GetImageSize(static_cast<uint32_t>(imageID), width, height);
	size_t size = 4 * static_cast<size_t>(height) * static_cast<size_t>(width) * sizeof(char);
	std::vector<uint8_t> data;
	data.resize(size);
	uint8_t* d = data.data();

	galaxy::api::Utils()->GetImageRGBA(static_cast<uint32_t>(imageID), d, static_cast<uint32_t>(size));

	if (bufferID < 0)
	{
		bufferID = CreateBuffer(static_cast<int>(size), eBuffer_Format_Fixed, 1);
	}

	BufferWriteContent(bufferID, byteOffset, d, static_cast<int>(size));

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Utils_RegisterForNotification(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* type = YYGetString(arg, 0);

	galaxy::api::Utils()->RegisterForNotification(type);
}

YYEXPORT void GOG_Utils_GetNotification(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;

	uint64_t notificationID = YYGetInt64(arg, 0);
	int bufferIdType = YYGetInt32(arg, 1);
	int bufferIdContent = YYGetInt32(arg, 2);

	bool consumable = false;
	
	void* type = nullptr; int typeSize = 0;
	void* content = nullptr; int contentSize = 0;
	YYStructCreate(&Result);
	// TODO: This code most likely doesn't work since BufferGetContent copies out the memory!
	if (BufferGetContent(bufferIdType, &type, &typeSize) && BufferGetContent(bufferIdContent, &content, &contentSize))
	{
		uint32_t wrote = galaxy::api::Utils()->GetNotification(
			notificationID,
			consumable,
			reinterpret_cast<char*>(type),
			typeSize,
			content,
			contentSize);
		YYStructAddInt64(&Result, "notificationID", notificationID);
		YYStructAddBool(&Result, "consumable", consumable);
		YYStructAddDouble(&Result, "contentWrote", wrote);
	}
	YYFree(type);
	YYFree(content);
}

YYEXPORT void GOG_Utils_ShowOverlayWithWebPage(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* url = YYGetString(arg, 0);

	galaxy::api::Utils()->ShowOverlayWithWebPage(url);
}

YYEXPORT void GOG_Utils_IsOverlayVisible(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Utils()->IsOverlayVisible();
}

YYEXPORT void GOG_Utils_GetOverlayState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = (int) galaxy::api::Utils()->GetOverlayState();
}

YYEXPORT void GOG_Utils_DisableOverlayPopups(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* popupGroup = YYGetString(arg, 0);

	galaxy::api::Utils()->DisableOverlayPopups(popupGroup);
}

YYEXPORT void GOG_Utils_GetGogServicesConnectionState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = (int) galaxy::api::Utils()->GetGogServicesConnectionState();
}
