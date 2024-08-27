
#include "YYGOG.h"
#include <string>
#include <vector>


YYEXPORT void GOG_Stats_RequestUserStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);
	galaxy::api::Stats()->RequestUserStatsAndAchievements(userID);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_GetStatInt(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1); // userID optional

	const char* name = YYGetString(arg, 0);
	galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetStatInt(name,userID);
}

YYEXPORT void GOG_Stats_GetStatFloat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1); // userID optional

	const char* name = YYGetString(arg, 0);
	galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetStatFloat(name,userID);
}

YYEXPORT void GOG_Stats_SetStatInt(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = YYGetString(arg, 0);
	int32_t value = static_cast<int32_t>(YYGetReal(arg, 1));

	galaxy::api::Stats()->SetStatInt(name,value);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_SetStatFloat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = YYGetString(arg, 0);
	double value = YYGetReal(arg, 1);

	galaxy::api::Stats()->SetStatFloat(name, static_cast<float>(value));
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_UpdateAvgRateStat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(3);

	const char* name = YYGetString(arg, 0);
	double countThisSession = YYGetReal(arg, 1);
	double sessionLenght = YYGetReal(arg, 2);

	galaxy::api::Stats()->UpdateAvgRateStat(name, static_cast<float>(countThisSession),sessionLenght);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_GetAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;
	GOG_EnsureArgc(1); // userID optional

	const char* name = YYGetString(arg, 0);
	galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

	bool unlocked = false;
	uint32 unlockTime = 0;

	galaxy::api::Stats()->GetAchievement(name,unlocked,unlockTime,userID);

	YYStructCreate(&Result);
	YYStructAddBool(&Result, "unlocked", unlocked);
	YYStructAddDouble(&Result, "unlockTime", unlockTime);
}

YYEXPORT void GOG_Stats_SetAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->SetAchievement(name);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_ClearAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->ClearAchievement(name);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_StoreStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Stats()->StoreStatsAndAchievements();
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_ResetStatsAndAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Stats()->ResetStatsAndAchievements();
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_GetAchievementDisplayName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementDisplayName(name));
}

YYEXPORT void GOG_Stats_GetAchievementDescription(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementDescription(name));
}

YYEXPORT void GOG_Stats_IsAchievementVisible(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Stats()->IsAchievementVisible(name);
}

YYEXPORT void GOG_Stats_IsAchievementVisibleWhileLocked(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Stats()->IsAchievementVisibleWhileLocked(name);
}

YYEXPORT void GOG_Stats_RequestLeaderboards(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Stats()->RequestLeaderboards();
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_GetLeaderboardDisplayName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetLeaderboardDisplayName(name));
}

YYEXPORT void GOG_Stats_GetLeaderboardSortMethod(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardSortMethod(name);
}

YYEXPORT void GOG_Stats_GetLeaderboardDisplayType(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardDisplayType(name);
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesGlobal(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(3);

	const char* name = YYGetString(arg, 0);
	double rangeStart = YYGetReal(arg, 1);
	double rangeEnd = YYGetReal(arg, 2);

	galaxy::api::Stats()->RequestLeaderboardEntriesGlobal(name, static_cast<uint32_t>(rangeStart), static_cast<uint32_t>(rangeEnd));
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesAroundUser(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(3);

	const char* name = YYGetString(arg, 0);
	double countBefore = YYGetReal(arg, 1);
	double countAfter = YYGetReal(arg, 2);

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(3);

	galaxy::api::Stats()->RequestLeaderboardEntriesAroundUser(name, static_cast<uint32_t>(countBefore), static_cast<uint32_t>(countAfter), userID);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_RequestLeaderboardEntriesForUsers(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

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
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_SetLeaderboardScore(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = YYGetString(arg, 0);
	double score = YYGetReal(arg, 1);
	bool forceUpdate = (argc > 2) ? YYGetBool(arg, 2) : false;
	
	galaxy::api::Stats()->SetLeaderboardScore(name, static_cast<int32_t>(score), forceUpdate);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_SetLeaderboardScoreWithDetails(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(4);

	const char* name = YYGetString(arg, 0);
	double score = YYGetReal(arg, 1);
	bool forceUpdate = YYGetBool(arg, 2);
	int32_t buffer = YYGetInt32(arg, 3);

	void* buffer_data = nullptr;
	int buffer_size = 0;

	if (!BufferGetContent(buffer, &buffer_data, &buffer_size))
	{
		DebugConsoleOutput("GOG_Stats_SetLeaderboardScoreWithDetails - error: specified buffer not found\n");
		return;
	}
    
    galaxy::api::Stats()->SetLeaderboardScoreWithDetails(name, static_cast<int32_t>(score), buffer_data, buffer_size, forceUpdate);
	YYFree(buffer_data);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_GetLeaderboardEntryCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetLeaderboardEntryCount(name);
}

YYEXPORT void GOG_Stats_FindLeaderboard(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	galaxy::api::Stats()->FindLeaderboard(name);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_FindOrCreateLeaderboard(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(4);

	const char* name = YYGetString(arg, 0);
	const char* displayName = YYGetString(arg, 1);
	int sortMethod = YYGetInt32(arg, 2);
	int displayType = YYGetInt32(arg, 3);

	galaxy::api::Stats()->FindOrCreateLeaderboard(name,displayName,(galaxy::api::LeaderboardSortMethod)sortMethod,(galaxy::api::LeaderboardDisplayType)displayType);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_RequestUserTimePlayed(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	galaxy::api::Stats()->RequestUserTimePlayed(userID);
	Result.kind = VALUE_BOOL;
	Result.val = 1;
}

YYEXPORT void GOG_Stats_GetUserTimePlayed(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	
	galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetUserTimePlayed(userID);
}

YYEXPORT void GOG_Stats_GetAchievementsNumber(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Stats()->GetAchievementsNumber();
}

YYEXPORT void GOG_Stats_GetAchievementName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	double index = YYGetReal(arg, 0);

	YYCreateString(&Result, galaxy::api::Stats()->GetAchievementName(static_cast<uint32_t>(index)));
}
