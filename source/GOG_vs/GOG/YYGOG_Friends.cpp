
#include "YYGOG.h"

#include <vector>
#include <string>

//IUserInformationRetrieveListener

YYEXPORT void GOG_Friends_GetDefaultAvatarCriteria(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetDefaultAvatarCriteria();
}

YYEXPORT void GOG_Friends_SetDefaultAvatarCriteria(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	double defaultAvatarCriteria = YYGetReal(arg, 0);

	galaxy::api::Friends()->SetDefaultAvatarCriteria(defaultAvatarCriteria);
}


class YYIUserInformationRetrieveListener : public galaxy::api::IUserInformationRetrieveListener
{
public:
	virtual void OnUserInformationRetrieveSuccess(galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestUserInformation");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}

	virtual void OnUserInformationRetrieveFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestUserInformation");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		switch (failureReason)
		{
			case FailureReason::FAILURE_REASON_CONNECTION_FAILURE :DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
			case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};

YYEXPORT void GOG_Friends_RequestUserInformation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	double AvatarCriteria = YYGetReal(arg, 1);

	YYIUserInformationRetrieveListener *callback = new YYIUserInformationRetrieveListener();
	galaxy::api::Friends()->RequestUserInformation(userID, (galaxy::api::AvatarCriteria)AvatarCriteria, callback);
}

YYEXPORT void GOG_Friends_IsUserInformationAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->IsUserInformationAvailable(userID);
}

YYEXPORT void GOG_Friends_GetPersonaName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYCreateString(&Result, galaxy::api::Friends()->GetFriendPersonaName(userID));
}

//YYEXPORT void GOG_Friends_GetPersonaNameCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Friends()->
//}

YYEXPORT void GOG_Friends_GetPersonaState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetPersonaState();
}

YYEXPORT void GOG_Friends_GetFriendPersonaName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYCreateString(&Result, galaxy::api::Friends()->GetFriendPersonaName(userID));
}

//YYEXPORT void GOG_Friends_GetFriendPersonaNameCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	galaxy::api::Friends()->
//}

YYEXPORT void GOG_Friends_GetFriendPersonaState(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendPersonaState(userID);
}

YYEXPORT void GOG_Friends_GetFriendAvatarUrl(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	RValue* pV = &(arg[0]);
	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYCreateString(&Result, galaxy::api::Friends()->GetFriendAvatarUrl(userID, (galaxy::api::AvatarType)avatarType));
}

//YYEXPORT void GOG_Friends_GetFriendAvatarUrlCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	galaxy::api::Friends()->GetFriendAvatarUrlCopy
//}

YYEXPORT void GOG_Friends_GetFriendAvatarImageID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	RValue* pV = &(arg[0]);
	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendAvatarImageID(userID, (galaxy::api::AvatarType)avatarType);
}

YYEXPORT void GOG_Friends_GetFriendAvatarImageRGBA(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	RValue* pV = &(arg[0]);
	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	uint32 size;
	/*AVATAR_TYPE_NONE = 0x0000, ///< No avatar type specified.
	AVATAR_TYPE_SMALL = 0x0001, ///< Avatar resolution size: 32x32.
	AVATAR_TYPE_MEDIUM = 0x0002, ///< Avatar resolution size: 64x64.
	AVATAR_TYPE_LARGE = 0x0004 ///< Avatar resolution size: 184x184.*/
	switch((int)avatarType)
	{
		case 1: size = 32 * 32 * 4; break;
		case 2: size = 64 * 64 * 4; break;
		case 4: size = 184 * 184 * 4; break;
		default: return;
	}

	std::vector<uint8_t> data;
	data.reserve(size);
	uint8_t* d = data.data();
	galaxy::api::Friends()->GetFriendAvatarImageRGBA(userID, (galaxy::api::AvatarType)avatarType, d, size);
	int bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	BufferWriteContent(bufferID, 0, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Friends_IsFriendAvatarImageRGBAAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);
	double avatarType = YYGetReal(arg, 1);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsFriendAvatarImageRGBAAvailable(userID, (galaxy::api::AvatarType)avatarType);
}

class YYIFriendListListener : public galaxy::api::IFriendListListener
{
public:
	virtual void OnFriendListRetrieveSuccess()
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestFriendList");
		CreateAsyncEventWithDSMap(map, 70);
	}

	virtual void OnFriendListRetrieveFailure(FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestFriendList");
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_RequestFriendList(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYIFriendListListener* callback = new YYIFriendListListener();
	galaxy::api::Friends()->RequestFriendList(callback);
}

YYEXPORT void GOG_Friends_IsFriend(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsFriend(userID);
}

YYEXPORT void GOG_Friends_GetFriendCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendCount();
}

YYEXPORT void GOG_Friends_GetFriendByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT

	double index = YYGetReal(arg, 0);

	galaxy::api::GalaxyID userID = galaxy::api::Friends()->GetFriendByIndex(index);

	RValue Struct = getStructFromGalaxyID(userID);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

class YYIFriendInvitationSendListener : public galaxy::api::IFriendInvitationSendListener
{
public:
	virtual void OnFriendInvitationSendSuccess(galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_SendFriendInvitation");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnFriendInvitationSendFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_SendFriendInvitation");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_USER_DOES_NOT_EXIST: DsMapAddString(map, "error", "FAILURE_REASON_USER_DOES_NOT_EXIST"); break;
		case FailureReason::FAILURE_REASON_USER_ALREADY_INVITED: DsMapAddString(map, "error", "FAILURE_REASON_USER_ALREADY_INVITED"); break;
		case FailureReason::FAILURE_REASON_USER_ALREADY_FRIEND: DsMapAddString(map, "error", "FAILURE_REASON_USER_ALREADY_FRIEND"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};

YYEXPORT void GOG_Friends_SendFriendInvitation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	galaxy::api::Friends()->SendFriendInvitation(userID,new YYIFriendInvitationSendListener());
}

class YYIFriendInvitationListRetrieveListener : public galaxy::api::IFriendInvitationListRetrieveListener
{
public:
	virtual void OnFriendInvitationListRetrieveSuccess()
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestFriendInvitationList");
		CreateAsyncEventWithDSMap(map, 70);
	}

	virtual void OnFriendInvitationListRetrieveFailure(FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestFriendInvitationList");
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_RequestFriendInvitationList(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYIFriendInvitationListRetrieveListener* callback = new YYIFriendInvitationListRetrieveListener();
	galaxy::api::Friends()->RequestFriendInvitationList(callback);
	//IFriendInvitationListRetrieveListener
}

class YYISentFriendInvitationListRetrieveListener : public galaxy::api::ISentFriendInvitationListRetrieveListener
{
public:
	virtual void OnSentFriendInvitationListRetrieveSuccess()
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
		CreateAsyncEventWithDSMap(map, 70);
	}

	virtual void OnSentFriendInvitationListRetrieveFailure(FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_RequestSentFriendInvitationList(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYISentFriendInvitationListRetrieveListener *callback = new YYISentFriendInvitationListRetrieveListener();
	galaxy::api::Friends()->RequestSentFriendInvitationList(callback);
	//ISentFriendInvitationListRetrieveListener
}

YYEXPORT void GOG_Friends_GetFriendInvitationCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetFriendInvitationCount();
}

YYEXPORT void GOG_Friends_GetFriendInvitationByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT

	double index = YYGetReal(arg, 0);

	galaxy::api::GalaxyID userID;
	uint32_t sendTime;
	galaxy::api::Friends()->GetFriendInvitationByIndex(index,userID,sendTime);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);
	
	RValue _struct = getStructFromGalaxyID(userID);
	YYStructAddRValue(&Struct, "userID", &_struct);
	YYStructAddDouble(&Struct, "sendTime", sendTime);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

class YYIFriendInvitationRespondToListener : public galaxy::api::IFriendInvitationRespondToListener
{
public:
	virtual void OnFriendInvitationRespondToSuccess(galaxy::api::GalaxyID userID, bool accept)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		DsMapAddBool(map, "accept", accept);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnFriendInvitationRespondToFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_USER_DOES_NOT_EXIST: DsMapAddString(map, "error", "FAILURE_REASON_USER_DOES_NOT_EXIST"); break;
		case FailureReason::FAILURE_REASON_FRIEND_INVITATION_DOES_NOT_EXIST: DsMapAddString(map, "error", "FAILURE_REASON_FRIEND_INVITATION_DOES_NOT_EXIST"); break;
		case FailureReason::FAILURE_REASON_USER_ALREADY_FRIEND: DsMapAddString(map, "error", "FAILURE_REASON_USER_ALREADY_FRIEND"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_RespondToFriendInvitation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);
	double accept = YYGetReal(arg, 0);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYIFriendInvitationRespondToListener *callback = new YYIFriendInvitationRespondToListener();
	galaxy::api::Friends()->RespondToFriendInvitation(userID, accept,callback);
}

class YYIFriendDeleteListener : public galaxy::api::IFriendDeleteListener
{
public:
	virtual void OnFriendDeleteSuccess(galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_DeleteFriend");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnFriendDeleteFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_DeleteFriend");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_DeleteFriend(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYIFriendDeleteListener* callback = new YYIFriendDeleteListener();
	galaxy::api::Friends()->DeleteFriend(userID, callback);
}

class YYIRichPresenceChangeListener : public galaxy::api::IRichPresenceChangeListener
{
public:

	std::string event;

	virtual void OnRichPresenceChangeSuccess()
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		CreateAsyncEventWithDSMap(map, 70);
	}

	virtual void OnRichPresenceChangeFailure(FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_SetRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* key = YYGetString(arg, 0);
	const char* value = YYGetString(arg, 1);

	YYIRichPresenceChangeListener *callback = new YYIRichPresenceChangeListener();
	callback->event = "GOG_Friends_SetRichPresence";
	galaxy::api::Friends()->SetRichPresence(key,value, callback);
}

YYEXPORT void GOG_Friends_DeleteRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* key = YYGetString(arg, 0);
	
	YYIRichPresenceChangeListener* callback = new YYIRichPresenceChangeListener();
	callback->event = "GOG_Friends_DeleteRichPresence";
	galaxy::api::Friends()->DeleteRichPresence(key,callback);
}

YYEXPORT void GOG_Friends_ClearRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYIRichPresenceChangeListener* callback = new YYIRichPresenceChangeListener();
	callback->event = "GOG_Friends_ClearRichPresence";
	galaxy::api::Friends()->ClearRichPresence(callback);
}

class YYIRichPresenceRetrieveListener : public galaxy::api::IRichPresenceRetrieveListener
{
public:
	virtual void OnRichPresenceRetrieveSuccess(galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestRichPresence");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnRichPresenceRetrieveFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_RequestRichPresence");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_RequestRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYIRichPresenceRetrieveListener* callback = new YYIRichPresenceRetrieveListener();
	galaxy::api::Friends()->RequestRichPresence(userID, callback);
}

YYEXPORT void GOG_Friends_GetRichPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	const char* key = YYGetString(arg, 0);
	RValue* pV = &(arg[1]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYCreateString(&Result, galaxy::api::Friends()->GetRichPresence(key,userID));
}

//YYEXPORT void GOG_Friends_GetRichPresenceCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	galaxy::api::Friends()->GetRichPresenceCopy
//}

YYEXPORT void GOG_Friends_GetRichPresenceCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Friends()->GetRichPresenceCount(userID);
}

YYEXPORT void GOG_Friends_GetRichPresenceByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT

	int index = YYGetReal(arg, 0);
	RValue* pV = &(arg[1]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	char key[9999];
	char value[9999];

	galaxy::api::Friends()->GetRichPresenceByIndex(index,key,9999,value,9999,userID);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddString(&Struct, "key", key);
	YYStructAddString(&Struct, "value", value);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Friends_GetRichPresenceKeyByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	double index = YYGetReal(arg, 0);
	RValue* pV = &(arg[1]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYCreateString(&Result, galaxy::api::Friends()->GetRichPresenceKeyByIndex(index, userID));
}

//YYEXPORT void GOG_Friends_GetRichPresenceKeyByIndexCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	galaxy::api::Friends()->GetRichPresenceKeyByIndexCopy()
//}

YYEXPORT void GOG_Friends_ShowOverlayInviteDialog(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* connectionString = YYGetString(arg, 0);

	galaxy::api::Friends()->ShowOverlayInviteDialog(connectionString);
}

class YYISendInvitationListener : public galaxy::api::ISendInvitationListener
{
public:
	virtual void OnInvitationSendSuccess(galaxy::api::GalaxyID userID, const char* connectionString)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_SendInvitation");
		DsMapAddString(map, "connectionString", connectionString);
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnInvitationSendFailure(galaxy::api::GalaxyID userID, const char* connectionString, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_SendInvitation");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		DsMapAddString(map, "connectionString", connectionString);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_USER_DOES_NOT_EXIST: DsMapAddString(map, "error", "FAILURE_REASON_USER_DOES_NOT_EXIST"); break;
		case FailureReason::FAILURE_REASON_RECEIVER_DOES_NOT_ALLOW_INVITING: DsMapAddString(map, "error", "FAILURE_REASON_RECEIVER_DOES_NOT_ALLOW_INVITING"); break;
		case FailureReason::FAILURE_REASON_SENDER_DOES_NOT_ALLOW_INVITING: DsMapAddString(map, "error", "FAILURE_REASON_SENDER_DOES_NOT_ALLOW_INVITING"); break;
		case FailureReason::FAILURE_REASON_RECEIVER_BLOCKED: DsMapAddString(map, "error", "FAILURE_REASON_RECEIVER_BLOCKED"); break;
		case FailureReason::FAILURE_REASON_SENDER_BLOCKED: DsMapAddString(map, "error", "FAILURE_REASON_SENDER_BLOCKED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_SendInvitation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	const char* connectionString = YYGetString(arg, 1);

	YYISendInvitationListener* callback = new YYISendInvitationListener();
	galaxy::api::Friends()->SendInvitation(userID, connectionString,callback);
}

class YYIUserFindListener : public galaxy::api::IUserFindListener
{
public:
	virtual void OnUserFindSuccess(const char* userSpecifier, galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_FindUser");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnUserFindFailure(const char* userSpecifier, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Friends_FindUser");
		DsMapAddString(map, "userSpecifier", userSpecifier);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_USER_NOT_FOUND: DsMapAddString(map, "error", "FAILURE_REASON_USER_NOT_FOUND"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Friends_FindUser(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* userSpecifier = YYGetString(arg, 0);

	YYIUserFindListener* callback = new YYIUserFindListener();
	galaxy::api::Friends()->FindUser(userSpecifier,callback);
}

YYEXPORT void GOG_Friends_IsUserInTheSameGame(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[1]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Friends()->IsUserInTheSameGame(userID);
}
