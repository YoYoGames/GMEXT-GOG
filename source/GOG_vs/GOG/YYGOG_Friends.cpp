
#include "YYGOG.h"
#include <vector>
#include <string>

YYEXPORT void GOG_Friends_GetDefaultAvatarCriteria(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetDefaultAvatarCriteria();
}

YYEXPORT void GOG_Friends_SetDefaultAvatarCriteria(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	double defaultAvatarCriteria = YYGetReal(arg, 0);

	galaxy::api::Friends()->SetDefaultAvatarCriteria(static_cast<galaxy::api::AvatarCriteria>(defaultAvatarCriteria));
}

YYEXPORT void GOG_Friends_RequestUserInformation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	double AvatarCriteria = (argc > 1) ? YYGetReal(arg, 1) : 0;

	galaxy::api::Friends()->RequestUserInformation(userID, (galaxy::api::AvatarCriteria)AvatarCriteria);
}

YYEXPORT void GOG_Friends_IsUserInformationAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsUserInformationAvailable(userID);
}

YYEXPORT void GOG_Friends_GetPersonaName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	YYCreateString(&Result, galaxy::api::Friends()->GetPersonaName());
}

YYEXPORT void GOG_Friends_GetPersonaState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetPersonaState();
}

YYEXPORT void GOG_Friends_GetFriendPersonaName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	YYCreateString(&Result, galaxy::api::Friends()->GetFriendPersonaName(userID));
}

YYEXPORT void GOG_Friends_GetFriendPersonaState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendPersonaState(userID);
}

YYEXPORT void GOG_Friends_GetFriendAvatarUrl(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(2);

	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	YYCreateString(&Result, galaxy::api::Friends()->GetFriendAvatarUrl(userID, (galaxy::api::AvatarType)avatarType));
}

YYEXPORT void GOG_Friends_GetFriendAvatarImageID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(2);

	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendAvatarImageID(userID, (galaxy::api::AvatarType)avatarType);
}

YYEXPORT void GOG_Friends_GetFriendAvatarImageRGBA(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = -1.0;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);
	double avatarType = YYGetReal(arg, 1);
	int bufferID = (argc > 2) ? YYGetInt32(arg, 2) : -1;
	int byteOffset = (argc > 3) ? YYGetInt32(arg, 3) : 0;

	uint32 size;
	/*AVATAR_TYPE_NONE = 0x0000, ///< No avatar type specified.
	AVATAR_TYPE_SMALL = 0x0001, ///< Avatar resolution size: 32x32.
	AVATAR_TYPE_MEDIUM = 0x0002, ///< Avatar resolution size: 64x64.
	AVATAR_TYPE_LARGE = 0x0004 ///< Avatar resolution size: 184x184.*/
	switch((galaxy::api::AvatarType)avatarType)
	{
		case galaxy::api::AvatarType::AVATAR_TYPE_SMALL: size = 32 * 32 * 4; break;
		case galaxy::api::AvatarType::AVATAR_TYPE_MEDIUM: size = 64 * 64 * 4; break;
		case galaxy::api::AvatarType::AVATAR_TYPE_LARGE: size = 184 * 184 * 4; break;
		default: return; // if the size is invalid then -1 will be returned
	}

	std::vector<uint8_t> data;
	data.resize(size);
	uint8_t* d = data.data();
	galaxy::api::Friends()->GetFriendAvatarImageRGBA(userID, (galaxy::api::AvatarType)avatarType, d, size);
	if (bufferID < 0)
	{
		bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	}
	BufferWriteContent(bufferID, byteOffset, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Friends_IsFriendAvatarImageRGBAAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsFriendAvatarImageRGBAAvailable(userID, (galaxy::api::AvatarType)avatarType);
}

YYEXPORT void GOG_Friends_RequestFriendList(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Friends()->RequestFriendList();
}

YYEXPORT void GOG_Friends_IsFriend(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsFriend(userID);
}

YYEXPORT void GOG_Friends_GetFriendCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendCount();
}

YYEXPORT void GOG_Friends_GetFriendByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;

	double index = YYGetReal(arg, 0);

	galaxy::api::GalaxyID userID = galaxy::api::Friends()->GetFriendByIndex(static_cast<uint32_t>(index));

	RValue Struct = getStructFromGalaxyID(userID);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Friends_SendFriendInvitation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	galaxy::api::Friends()->SendFriendInvitation(userID);
}

YYEXPORT void GOG_Friends_RequestFriendInvitationList(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Friends()->RequestFriendInvitationList();
}

YYEXPORT void GOG_Friends_RequestSentFriendInvitationList(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Friends()->RequestSentFriendInvitationList();
}

YYEXPORT void GOG_Friends_GetFriendInvitationCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendInvitationCount();
}

YYEXPORT void GOG_Friends_GetFriendInvitationByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;
	GOG_EnsureArgc(1);

	double index = YYGetReal(arg, 0);

	galaxy::api::GalaxyID userID;
	uint32_t sendTime;
	galaxy::api::Friends()->GetFriendInvitationByIndex(static_cast<uint32_t>(index), userID, sendTime);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);
	
	RValue _struct = getStructFromGalaxyID(userID);
	YYStructAddRValue(&Struct, "userID", &_struct);
	FREE_RValue(&_struct);
	YYStructAddDouble(&Struct, "sendTime", sendTime);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Friends_RespondToFriendInvitation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	double accept = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);
	galaxy::api::Friends()->RespondToFriendInvitation(userID, accept);
}

YYEXPORT void GOG_Friends_DeleteFriend(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);
	galaxy::api::Friends()->DeleteFriend(userID);
}

YYEXPORT void GOG_Friends_SetRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* key = YYGetString(arg, 0);
	const char* value = (argc > 1) ? YYGetString(arg, 1) : nullptr;

	galaxy::api::Friends()->SetRichPresence(key,value);
}

YYEXPORT void GOG_Friends_DeleteRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* key = YYGetString(arg, 0);
	
	galaxy::api::Friends()->DeleteRichPresence(key);
}

YYEXPORT void GOG_Friends_ClearRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Friends()->ClearRichPresence();
}

YYEXPORT void GOG_Friends_RequestRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	galaxy::api::Friends()->RequestRichPresence(userID);
}

YYEXPORT void GOG_Friends_GetRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	const char* key = YYGetString(arg, 0);
	galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

	YYCreateString(&Result, galaxy::api::Friends()->GetRichPresence(key,userID));
}

YYEXPORT void GOG_Friends_GetRichPresenceCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetRichPresenceCount(userID);
}

YYEXPORT void GOG_Friends_GetRichPresenceByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;
	GOG_EnsureArgc(1);

	double index = YYGetReal(arg, 0);
	galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

	// from Galaxy SDK docs:
	// "connect" - with the limit of 4095 bytes.
	// this is the largest rich presence key
	// meaning our buffer should be no more than 4095+1 bytes...
	char rpKey[4096] = { 0 };
	char rpValue[4096] = { 0 };

	galaxy::api::Friends()->GetRichPresenceByIndex(
		static_cast<uint32_t>(index),
		rpKey,
		sizeof(rpKey),
		rpValue,
		sizeof(rpValue),
		userID);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddString(&Struct, "key", rpKey);
	YYStructAddString(&Struct, "value", rpValue);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Friends_GetRichPresenceKeyByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	double index = YYGetReal(arg, 0);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

	YYCreateString(&Result, galaxy::api::Friends()->GetRichPresenceKeyByIndex(static_cast<uint32_t>(index), userID));
}

YYEXPORT void GOG_Friends_ShowOverlayInviteDialog(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* connectionString = YYGetString(arg, 0);

	galaxy::api::Friends()->ShowOverlayInviteDialog(connectionString);
}

YYEXPORT void GOG_Friends_SendInvitation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	const char* connectionString = YYGetString(arg, 1);

	galaxy::api::Friends()->SendInvitation(userID, connectionString);
}

YYEXPORT void GOG_Friends_FindUser(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* userSpecifier = YYGetString(arg, 0);

	galaxy::api::Friends()->FindUser(userSpecifier);
}

YYEXPORT void GOG_Friends_IsUserInTheSameGame(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsUserInTheSameGame(userID);
}
