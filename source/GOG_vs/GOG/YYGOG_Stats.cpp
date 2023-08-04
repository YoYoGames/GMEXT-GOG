
#include "YYGOG.h"
#include <string>
#include <vector>

class YYIUserStatsAndAchievementsRetrieveListener : public galaxy::api::IUserStatsAndAchievementsRetrieveListener
{
public:
	virtual void OnUserStatsAndAchievementsRetrieveSuccess(galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Stats_RequestUserStatsAndAchievements");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnUserStatsAndAchievementsRetrieveFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Stats_RequestUserStatsAndAchievements");
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
YYEXPORT void GOG_Stats_RequestUserStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYIUserStatsAndAchievementsRetrieveListener* callback = new YYIUserStatsAndAchievementsRetrieveListener();
	galaxy::api::Stats()->RequestUserStatsAndAchievements(userID, callback);
}

YYEXPORT void GOG_Stats_GetStatInt(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetStatInt(name,userID);
}

YYEXPORT void GOG_Stats_GetStatFloat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetStatFloat(name,userID);
}

YYEXPORT void GOG_Stats_SetStatInt(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	int32_t value = (int32_t)YYGetReal(arg, 1);

	galaxy::api::Stats()->SetStatInt(name,value);
}

YYEXPORT void GOG_Stats_SetStatFloat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	double value = YYGetReal(arg, 1);

	galaxy::api::Stats()->SetStatFloat(name, static_cast<float>(value));
}

YYEXPORT void GOG_Stats_UpdateAvgRateStat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	double countThisSession = YYGetReal(arg, 1);
	double sessionLenght = YYGetReal(arg, 2);

	galaxy::api::Stats()->UpdateAvgRateStat(name, static_cast<float>(countThisSession),sessionLenght);
}

YYEXPORT void GOG_Stats_GetAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	bool unlocked;
	uint32 unlockTime;

	galaxy::api::Stats()->GetAchievement(name,unlocked,unlockTime,userID);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddBool(&Struct, "unlocked", unlocked);
	if (unlocked)
	{
		YYStructAddDouble(&Struct, "unlockTime", unlockTime);
	}

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Stats_SetAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->SetAchievement(name);
}

YYEXPORT void GOG_Stats_ClearAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->ClearAchievement(name);
}

class YYIStatsAndAchievementsStoreListener : public galaxy::api::IStatsAndAchievementsStoreListener
{
public:
	std::string event;
	virtual void OnUserStatsAndAchievementsStoreSuccess()
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnUserStatsAndAchievementsStoreFailure(FailureReason failureReason)
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
YYEXPORT void GOG_Stats_StoreStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYIStatsAndAchievementsStoreListener* callback = new YYIStatsAndAchievementsStoreListener();
	callback->event = "GOG_Stats_StoreStatsAndAchievements";
	galaxy::api::Stats()->StoreStatsAndAchievements(callback);
}

YYEXPORT void GOG_Stats_ResetStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYIStatsAndAchievementsStoreListener* callback = new YYIStatsAndAchievementsStoreListener();
	callback->event = "GOG_Stats_ResetStatsAndAchievements";
	galaxy::api::Stats()->ResetStatsAndAchievements(callback);
}

YYEXPORT void GOG_Stats_GetAchievementDisplayName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementDisplayName(name));
}

//YYEXPORT void GOG_Stats_GetAchievementDisplayNameCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Stats()->GetAchievementDisplayNameCopy();
//}

YYEXPORT void GOG_Stats_GetAchievementDescription(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementDescription(name));
}

//YYEXPORT void GOG_Stats_GetAchievementDescriptionCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Stats()->GetAchievementDescriptionCopy
//}

YYEXPORT void GOG_Stats_IsAchievementVisible(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Stats()->IsAchievementVisible(name);
}

YYEXPORT void GOG_Stats_IsAchievementVisibleWhileLocked(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Stats()->IsAchievementVisibleWhileLocked(name);
}

class YYILeaderboardsRetrieveListener : public galaxy::api::ILeaderboardsRetrieveListener
{
public:
	virtual void OnLeaderboardsRetrieveSuccess()
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Stats_RequestLeaderboards");
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnLeaderboardsRetrieveFailure(FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Stats_RequestLeaderboards");
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Stats_RequestLeaderboards(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYILeaderboardsRetrieveListener* callback = new YYILeaderboardsRetrieveListener();
	galaxy::api::Stats()->RequestLeaderboards(callback);
}

YYEXPORT void GOG_Stats_GetLeaderboardDisplayName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetLeaderboardDisplayName(name));
}

//YYEXPORT void GOG_Stats_GetLeaderboardDisplayNameCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Stats()->GetLeaderboardDisplayNameCopy
//}


YYEXPORT void GOG_Stats_GetLeaderboardSortMethod(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardSortMethod(name);
}

YYEXPORT void GOG_Stats_GetLeaderboardDisplayType(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardDisplayType(name);
}

class YYILeaderboardEntriesRetrieveListener : public galaxy::api::ILeaderboardEntriesRetrieveListener
{
public:
	std::string event;
	virtual void OnLeaderboardEntriesRetrieveSuccess(const char* name, uint32_t entryCount)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "name", name);
		DsMapAddDouble(map, "entryCount", entryCount);

		RValue entriesArray = { 0 };
		YYCreateArray(&entriesArray);

		for (int32_t index = entryCount - 1; index >= 0; --index)
		{
			uint32_t rank;
			int32_t score;
			galaxy::api::GalaxyID userID;

			RValue entryStruct = { 0 };
			YYStructCreate(&entryStruct);

			std::vector<uint8_t> data;
			const int detailsSize = 3071;
			data.reserve(detailsSize);//limit size
			uint8_t* details = data.data();

			uint32_t outDetailsSize;
			galaxy::api::Stats()->GetRequestedLeaderboardEntryWithDetails(index, rank, score, details, detailsSize, outDetailsSize, userID);

			if (outDetailsSize > 0)
			{
				int dataSize = (int)(outDetailsSize * 4 / 3) + 1;
				void* pData = YYAlloc(dataSize);
				Base64Encode(details, outDetailsSize, pData, dataSize);
				YYStructAddString(&entryStruct, "data", (const char*)pData);
				YYFree(pData);
			}

			YYStructAddInt64(&entryStruct, "index", index);
			YYStructAddDouble(&entryStruct, "rank", rank);
			YYStructAddDouble(&entryStruct, "score", score);

			RValue _struct = getStructFromGalaxyID(userID);
			YYStructAddRValue(&entryStruct, "userID", &_struct);

			SET_RValue(&entriesArray, &entryStruct, NULL, index);
		}

		DsMapAddRValue(map, "entries", &entriesArray);

		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnLeaderboardEntriesRetrieveFailure(const char* name, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "name", name);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_NOT_FOUND: DsMapAddString(map, "error", "FAILURE_REASON_NOT_FOUND"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesGlobal(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	int32_t rangeStart = YYGetInt32(arg, 1);
	int32_t rangeEnd = YYGetInt32(arg, 2);

	YYILeaderboardEntriesRetrieveListener* callback = new YYILeaderboardEntriesRetrieveListener();
	callback->event = "GOG_Stats_RequestLeaderboardEntriesGlobal";
	galaxy::api::Stats()->RequestLeaderboardEntriesGlobal(name, static_cast<uint32_t>(rangeStart), static_cast<uint32_t>(rangeEnd), callback);
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesAroundUser(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	int32_t countBefore = YYGetInt32(arg, 1);
	int32_t countAfter = YYGetInt32(arg, 2);

	RValue* pV = &(arg[3]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYILeaderboardEntriesRetrieveListener* callback = new YYILeaderboardEntriesRetrieveListener();
	callback->event = "GOG_Stats_RequestLeaderboardEntriesAroundUser";
	galaxy::api::Stats()->RequestLeaderboardEntriesAroundUser(name, static_cast<uint32_t>(countBefore), static_cast<uint32_t>(countAfter), userID, callback);
}

//YYEXPORT void GOG_Stats_RequestLeaderboardEntriesForUsers(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Stats()->RequestLeaderboardEntriesForUsers();
//}

class YYILeaderboardScoreUpdateListener : public galaxy::api::ILeaderboardScoreUpdateListener
{
public:
	std::string event;
	virtual void OnLeaderboardScoreUpdateSuccess(const char* name, int32_t score, uint32_t oldRank, uint32_t newRank)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "name", name);
		DsMapAddDouble(map, "score", score);
		DsMapAddDouble(map, "oldRank", oldRank);
		DsMapAddDouble(map, "newRank", newRank);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnLeaderboardScoreUpdateFailure(const char* name, int32_t score, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "name", name);
		DsMapAddDouble(map, "score", score);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_NO_IMPROVEMENT: DsMapAddString(map, "error", "FAILURE_REASON_NO_IMPROVEMENT"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Stats_SetLeaderboardScore(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	double score = YYGetReal(arg, 1);
	bool forceUpdate = YYGetBool(arg, 2);
	
	YYILeaderboardScoreUpdateListener* callback = new YYILeaderboardScoreUpdateListener();
	callback->event = "GOG_Stats_SetLeaderboardScore";
	galaxy::api::Stats()->SetLeaderboardScore(name, static_cast<uint32_t>(score), forceUpdate,callback);
}

YYEXPORT void GOG_Stats_SetLeaderboardScoreWithDetails(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	YYILeaderboardScoreUpdateListener* callback = new YYILeaderboardScoreUpdateListener();
	callback->event = "GOG_Stats_SetLeaderboardScoreWithDetails";

	const char* name = YYGetString(arg, 0);
	double score = YYGetReal(arg, 1);
	bool forceUpdate = YYGetBool(arg, 2);
	int32_t buffer = YYGetInt32(arg, 3);
	//int32 size = YYGetInt32(arg, 1);

	unsigned char* buffer_data;
	int buffer_size;

	if (!BufferGetContent(buffer, (void**)(&buffer_data), &buffer_size))
	{
		DebugConsoleOutput("GOG_Stats_SetLeaderboardScoreWithDetails - error: specified buffer not found\n");
		return;
	}
	galaxy::api::Stats()->SetLeaderboardScoreWithDetails(name, static_cast<uint32_t>(score), buffer_data, buffer_size,forceUpdate);
}

YYEXPORT void GOG_Stats_GetLeaderboardEntryCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardEntryCount(name);
}

class YYILeaderboardRetrieveListener : public galaxy::api::ILeaderboardRetrieveListener
{
public:
	std::string event;
	virtual void OnLeaderboardRetrieveSuccess(const char* name)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "name", name);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnLeaderboardRetrieveFailure(const char* name, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "name", name);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Stats_FindLeaderboard(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);

	YYILeaderboardRetrieveListener* callback = new YYILeaderboardRetrieveListener();
	callback->event = "GOG_Stats_FindLeaderboard";
	galaxy::api::Stats()->FindLeaderboard(name, callback);
}

YYEXPORT void GOG_Stats_FindOrCreateLeaderboard(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	const char* name = YYGetString(arg, 0);
	const char* displayName = YYGetString(arg, 1);
	int sortMethod = YYGetInt32(arg, 2);
	int displayType = YYGetInt32(arg, 3);

	YYILeaderboardRetrieveListener* callback = new YYILeaderboardRetrieveListener();
	callback->event = "GOG_Stats_FindOrCreateLeaderboard";
	galaxy::api::Stats()->FindOrCreateLeaderboard(name,displayName,(galaxy::api::LeaderboardSortMethod)sortMethod,(galaxy::api::LeaderboardDisplayType)displayType,callback);
}

class YYIUserTimePlayedRetrieveListener : public galaxy::api::IUserTimePlayedRetrieveListener
{
public:
	virtual void OnUserTimePlayedRetrieveSuccess(galaxy::api::GalaxyID userID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Stats_RequestUserTimePlayed");
		RValue struct_userID = getStructFromGalaxyID(userID);
		DsMapAddRValue(map, "userID", &struct_userID);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnUserTimePlayedRetrieveFailure(galaxy::api::GalaxyID userID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Stats_RequestUserTimePlayed");
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
YYEXPORT void GOG_Stats_RequestUserTimePlayed(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	RValue* pV = &(arg[0]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	YYIUserTimePlayedRetrieveListener* callback = new YYIUserTimePlayedRetrieveListener();
	galaxy::api::Stats()->RequestUserTimePlayed(userID, callback);
}

YYEXPORT void GOG_Stats_GetUserTimePlayed(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL
	
	RValue* pV = &(arg[0]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetUserTimePlayed(userID);
}
