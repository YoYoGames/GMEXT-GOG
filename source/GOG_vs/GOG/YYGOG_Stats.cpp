
#include "YYGOG.h"
#include <string>
#include <vector>


YYEXPORT void GOG_Stats_RequestUserStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	RValue* pV = &(arg[0]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	galaxy::api::Stats()->RequestUserStatsAndAchievements(userID);
}

YYEXPORT void GOG_Stats_GetStatInt(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);

	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetStatInt(name,userID);
}

YYEXPORT void GOG_Stats_GetStatFloat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetStatFloat(name,userID);
}

YYEXPORT void GOG_Stats_SetStatInt(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	int32_t value = (int32_t)YYGetReal(arg, 1);

	galaxy::api::Stats()->SetStatInt(name,value);
}

YYEXPORT void GOG_Stats_SetStatFloat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	double value = YYGetReal(arg, 1);

	galaxy::api::Stats()->SetStatFloat(name, static_cast<float>(value));
}

YYEXPORT void GOG_Stats_UpdateAvgRateStat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	double countThisSession = YYGetReal(arg, 1);
	double sessionLenght = YYGetReal(arg, 2);

	galaxy::api::Stats()->UpdateAvgRateStat(name, static_cast<float>(countThisSession),sessionLenght);
}

YYEXPORT void GOG_Stats_GetAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	bool unlocked = false;
	uint32 unlockTime = 0;

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
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->SetAchievement(name);
}

YYEXPORT void GOG_Stats_ClearAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->ClearAchievement(name);
}

YYEXPORT void GOG_Stats_StoreStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Stats()->StoreStatsAndAchievements();
}

YYEXPORT void GOG_Stats_ResetStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Stats()->ResetStatsAndAchievements();
}

YYEXPORT void GOG_Stats_GetAchievementDisplayName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementDisplayName(name));
}

YYEXPORT void GOG_Stats_GetAchievementDescription(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementDescription(name));
}

YYEXPORT void GOG_Stats_IsAchievementVisible(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Stats()->IsAchievementVisible(name);
}

YYEXPORT void GOG_Stats_IsAchievementVisibleWhileLocked(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Stats()->IsAchievementVisibleWhileLocked(name);
}

YYEXPORT void GOG_Stats_RequestLeaderboards(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Stats()->RequestLeaderboards();
}

YYEXPORT void GOG_Stats_GetLeaderboardDisplayName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetLeaderboardDisplayName(name));
}

YYEXPORT void GOG_Stats_GetLeaderboardSortMethod(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardSortMethod(name);
}

YYEXPORT void GOG_Stats_GetLeaderboardDisplayType(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardDisplayType(name);
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesGlobal(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	double rangeStart = YYGetReal(arg, 1);
	double rangeEnd = YYGetReal(arg, 2);

	galaxy::api::Stats()->RequestLeaderboardEntriesGlobal(name, static_cast<uint32_t>(rangeStart), static_cast<uint32_t>(rangeEnd));
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesAroundUser(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	double countBefore = YYGetReal(arg, 1);
	double countAfter = YYGetReal(arg, 2);

	RValue* pV = &(arg[3]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	galaxy::api::Stats()->RequestLeaderboardEntriesAroundUser(name, static_cast<uint32_t>(countBefore), static_cast<uint32_t>(countAfter), userID);
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesForUsers(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);

	RValue* pV = &(arg[1]);

	std::vector<galaxy::api::GalaxyID> users;
	int len = YYArrayGetLength(pV);
	for (int i = 0; i < len; ++i)
	{
		RValue userStruct = { 0 };
		if (GET_RValue(&userStruct, pV, nullptr, i))
		{
			users.push_back(GalaxyIDFromStruct(&userStruct));
			FREE_RValue(&userStruct);
		}
	}

	galaxy::api::Stats()->RequestLeaderboardEntriesForUsers(
		name,
		users.data(),
		static_cast<uint32_t>(users.size()));
}

YYEXPORT void GOG_Stats_SetLeaderboardScore(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	double score = YYGetReal(arg, 1);
	bool forceUpdate = YYGetBool(arg, 2);
	
	galaxy::api::Stats()->SetLeaderboardScore(name, static_cast<int32_t>(score), forceUpdate);
}

YYEXPORT void GOG_Stats_SetLeaderboardScoreWithDetails(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	double score = YYGetReal(arg, 1);
	bool forceUpdate = YYGetBool(arg, 2);
	int32_t buffer = YYGetInt32(arg, 3);

	unsigned char* buffer_data = nullptr;
	int buffer_size = 0;

	if (!BufferGetContent(buffer, (void**)(&buffer_data), &buffer_size))
	{
		DebugConsoleOutput("GOG_Stats_SetLeaderboardScoreWithDetails - error: specified buffer not found\n");
		return;
	}
    
    galaxy::api::Stats()->SetLeaderboardScoreWithDetails(name, static_cast<int32_t>(score), buffer_data, buffer_size, forceUpdate);
	YYFree(buffer_data);
}

YYEXPORT void GOG_Stats_GetLeaderboardEntryCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardEntryCount(name);
}

YYEXPORT void GOG_Stats_FindLeaderboard(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->FindLeaderboard(name);
}

YYEXPORT void GOG_Stats_FindOrCreateLeaderboard(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* name = YYGetString(arg, 0);
	const char* displayName = YYGetString(arg, 1);
	int sortMethod = YYGetInt32(arg, 2);
	int displayType = YYGetInt32(arg, 3);

	galaxy::api::Stats()->FindOrCreateLeaderboard(name,displayName,(galaxy::api::LeaderboardSortMethod)sortMethod,(galaxy::api::LeaderboardDisplayType)displayType);
}

YYEXPORT void GOG_Stats_RequestUserTimePlayed(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	RValue* pV = &(arg[0]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	galaxy::api::Stats()->RequestUserTimePlayed(userID);
}

YYEXPORT void GOG_Stats_GetUserTimePlayed(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	
	RValue* pV = &(arg[0]);
	galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetUserTimePlayed(userID);
}
