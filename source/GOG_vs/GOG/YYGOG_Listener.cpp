#include "YYGOG_Listener.hpp"
#include <memory>

std::unique_ptr<GMAsyncEventListener> GMAsyncEventListener::SingletonInstance;

GMAsyncEventListener *GMAsyncEventListener::Instance()
{
	// ensure only one instance
	if (!SingletonInstance)
	{
		SingletonInstance = std::make_unique<GMAsyncEventListener>();
	}

	// can be downcasted to any listener that is inherited
	// by GMAsyncEventListener...
	return SingletonInstance.get();
}

void GMAsyncEventListener::Unregister()
{
	SingletonInstance.reset();
}

GMAsyncEventListener::~GMAsyncEventListener()
{
	// no-op
}

void GMAsyncEventListener::OnDlcCheckSuccess(galaxy::api::ProductID productId, bool isOwned)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Apps_IsDlcOwned");
	DsMapAddInt64(map, "productID", productId);
	DsMapAddBool(map, "isOwned", isOwned);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnDlcCheckFailure(galaxy::api::ProductID producId, galaxy::api::IIsDlcOwnedListener::FailureReason failueReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Apps_IsDlcOwned");
	DsMapAddInt64(map, "productID", producId);
	switch (failueReason)
	{
	case galaxy::api::IIsDlcOwnedListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::IIsDlcOwnedListener::FailureReason::FAILURE_REASON_GALAXY_SERVICE_NOT_SIGNED_IN:
		DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_SERVICE_NOT_SIGNED_IN"); break;
	case galaxy::api::IIsDlcOwnedListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::IIsDlcOwnedListener::FailureReason::FAILURE_REASON_EXTERNAL_SERVICE_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_EXTERNAL_SERVICE_FAILURE"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserInformationRetrieveSuccess(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestUserInformation");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserInformationRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalUserInformationRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestUserInformation");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalUserInformationRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalUserInformationRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendListRetrieveSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestFriendList");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendListRetrieveFailure(galaxy::api::GlobalFriendListListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestFriendList");
	switch (failureReason)
	{
	case galaxy::api::GlobalFriendListListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalFriendListListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationSendSuccess(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_SendFriendInvitation");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationSendFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendInvitationSendListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_SendFriendInvitation");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalFriendInvitationSendListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalFriendInvitationSendListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalFriendInvitationSendListener::FailureReason::FAILURE_REASON_USER_DOES_NOT_EXIST:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_DOES_NOT_EXIST"); break;
	case galaxy::api::GlobalFriendInvitationSendListener::FailureReason::FAILURE_REASON_USER_ALREADY_INVITED:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_ALREADY_INVITED"); break;
	case galaxy::api::GlobalFriendInvitationSendListener::FailureReason::FAILURE_REASON_USER_ALREADY_FRIEND:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_ALREADY_FRIEND"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationListRetrieveSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestFriendInvitationList");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationListRetrieveFailure(galaxy::api::GlobalFriendInvitationListRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestFriendInvitationList");
	switch (failureReason)
	{
	case galaxy::api::GlobalFriendInvitationListRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalFriendInvitationListRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnSentFriendInvitationListRetrieveSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnSentFriendInvitationListRetrieveFailure(galaxy::api::GlobalSentFriendInvitationListRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
	switch (failureReason)
	{
	case galaxy::api::GlobalSentFriendInvitationListRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalSentFriendInvitationListRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationRespondToSuccess(galaxy::api::GalaxyID userID, bool accept)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	DsMapAddBool(map, "accept", accept);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationRespondToFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestSentFriendInvitationList");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason::FAILURE_REASON_USER_DOES_NOT_EXIST:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_DOES_NOT_EXIST"); break;
	case galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason::FAILURE_REASON_FRIEND_INVITATION_DOES_NOT_EXIST:
		DsMapAddString(map, "error", "FAILURE_REASON_FRIEND_INVITATION_DOES_NOT_EXIST"); break;
	case galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason::FAILURE_REASON_USER_ALREADY_FRIEND:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_ALREADY_FRIEND"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendDeleteSuccess(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_DeleteFriend");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendDeleteFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendDeleteListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_DeleteFriend");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalFriendDeleteListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalFriendDeleteListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnRichPresenceChangeSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_SetRichPresence");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnRichPresenceChangeFailure(galaxy::api::GlobalRichPresenceChangeListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_SetRichPresence");
	switch (failureReason)
	{
	case galaxy::api::GlobalRichPresenceChangeListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalRichPresenceChangeListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnRichPresenceRetrieveSuccess(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestRichPresence");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnRichPresenceRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalRichPresenceRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RequestRichPresence");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalRichPresenceRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalRichPresenceRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnInvitationSendSuccess(galaxy::api::GalaxyID userID, const char* connectionString)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_SendInvitation");
	DsMapAddString(map, "connectionString", connectionString);
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnInvitationSendFailure(galaxy::api::GalaxyID userID, const char* connectionString, galaxy::api::GlobalSendInvitationListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_SendInvitation");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	DsMapAddString(map, "connectionString", connectionString);
	switch (failureReason)
	{
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_USER_DOES_NOT_EXIST:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_DOES_NOT_EXIST"); break;
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_RECEIVER_DOES_NOT_ALLOW_INVITING:
		DsMapAddString(map, "error", "FAILURE_REASON_RECEIVER_DOES_NOT_ALLOW_INVITING"); break;
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_SENDER_DOES_NOT_ALLOW_INVITING:
		DsMapAddString(map, "error", "FAILURE_REASON_SENDER_DOES_NOT_ALLOW_INVITING"); break;
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_RECEIVER_BLOCKED:
		DsMapAddString(map, "error", "FAILURE_REASON_RECEIVER_BLOCKED"); break;
	case galaxy::api::GlobalSendInvitationListener::FailureReason::FAILURE_REASON_SENDER_BLOCKED:
		DsMapAddString(map, "error", "FAILURE_REASON_SENDER_BLOCKED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserFindSuccess(const char* userSpecifier, galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_FindUser");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserFindFailure(const char* userSpecifier, galaxy::api::GlobalUserFindListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_FindUser");
	DsMapAddString(map, "userSpecifier", userSpecifier);
	switch (failureReason)
	{
	case galaxy::api::GlobalUserFindListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalUserFindListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalUserFindListener::FailureReason::FAILURE_REASON_USER_NOT_FOUND:
		DsMapAddString(map, "error", "FAILURE_REASON_USER_NOT_FOUND"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserStatsAndAchievementsRetrieveSuccess(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestUserStatsAndAchievements");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserStatsAndAchievementsRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalUserStatsAndAchievementsRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestUserStatsAndAchievements");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalUserStatsAndAchievementsRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalUserStatsAndAchievementsRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserStatsAndAchievementsStoreSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_StoreStatsAndAchievements");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserStatsAndAchievementsStoreFailure(galaxy::api::GlobalStatsAndAchievementsStoreListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_StoreStatsAndAchievements");
	switch (failureReason)
	{
	case galaxy::api::GlobalStatsAndAchievementsStoreListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalStatsAndAchievementsStoreListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardsRetrieveSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestLeaderboards");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardsRetrieveFailure(galaxy::api::GlobalLeaderboardsRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestLeaderboards");
	switch (failureReason)
	{
	case galaxy::api::GlobalLeaderboardsRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalLeaderboardsRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardEntriesRetrieveSuccess(const char* name, uint32_t entryCount)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestLeaderboardEntries");
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

		const int detailsSize = 3071;
		char pDetails[detailsSize];

		uint32_t outDetailsSize;
		galaxy::api::Stats()->GetRequestedLeaderboardEntryWithDetails(index, rank, score, pDetails, detailsSize, outDetailsSize, userID);

		if (outDetailsSize > 0)
		{
			int dataSize = (int)(outDetailsSize * 4.0 / 3.0) + 1;
			void* pData = YYAlloc(dataSize);
			Base64Encode(pDetails, outDetailsSize, static_cast<char*>(pData), detailsSize);
			YYStructAddString(&entryStruct, "data", static_cast<char*>(pData));
			YYFree(pData);
		}

		YYStructAddDouble(&entryStruct, "rank", rank);
		YYStructAddDouble(&entryStruct, "score", score);

		RValue _struct = getStructFromGalaxyID(userID);
		YYStructAddRValue(&entryStruct, "userID", &_struct);

		SET_RValue(&entriesArray, &entryStruct, NULL, index);
	}

	DsMapAddRValue(map, "entries", &entriesArray);

	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardEntriesRetrieveFailure(const char* name, galaxy::api::GlobalLeaderboardEntriesRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestLeaderboardEntries");
	DsMapAddString(map, "name", name);
	switch (failureReason)
	{
	case galaxy::api::GlobalLeaderboardEntriesRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalLeaderboardEntriesRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalLeaderboardEntriesRetrieveListener::FailureReason::FAILURE_REASON_NOT_FOUND:
		DsMapAddString(map, "error", "FAILURE_REASON_NOT_FOUND"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardScoreUpdateSuccess(const char* name, int32_t score, uint32_t oldRank, uint32_t newRank)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_SetLeaderboardScore");
	DsMapAddString(map, "name", name);
	DsMapAddDouble(map, "score", score);
	DsMapAddDouble(map, "oldRank", oldRank);
	DsMapAddDouble(map, "newRank", newRank);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardScoreUpdateFailure(const char* name, int32_t score, galaxy::api::GlobalLeaderboardScoreUpdateListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_SetLeaderboardScore");
	DsMapAddString(map, "name", name);
	DsMapAddDouble(map, "score", score);
	switch (failureReason)
	{
	case galaxy::api::GlobalLeaderboardScoreUpdateListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalLeaderboardScoreUpdateListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalLeaderboardScoreUpdateListener::FailureReason::FAILURE_REASON_NO_IMPROVEMENT:
		DsMapAddString(map, "error", "FAILURE_REASON_NO_IMPROVEMENT"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardRetrieveSuccess(const char* name)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_FindLeaderboard");
	DsMapAddString(map, "name", name);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnLeaderboardRetrieveFailure(const char* name, galaxy::api::GlobalLeaderboardRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_FindLeaderboard");
	DsMapAddString(map, "name", name);
	switch (failureReason)
	{
	case galaxy::api::GlobalLeaderboardRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalLeaderboardRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserTimePlayedRetrieveSuccess(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestUserTimePlayed");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserTimePlayedRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalUserTimePlayedRetrieveListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_RequestUserTimePlayed");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (failureReason)
	{
	case galaxy::api::GlobalUserTimePlayedRetrieveListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalUserTimePlayedRetrieveListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFileShareSuccess(const char* fileName, galaxy::api::SharedFileID sharedFileID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Storage_FileShare");
	DsMapAddInt64(map, "sharedFileID", sharedFileID);
	DsMapAddString(map, "fileName", fileName);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFileShareFailure(const char* fileName, galaxy::api::GlobalFileShareListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Storage_FileShare");
	DsMapAddString(map, "fileName", fileName);
	switch (failureReason)
	{
	case galaxy::api::GlobalFileShareListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalFileShareListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnSharedFileDownloadSuccess(galaxy::api::SharedFileID sharedFileID, const char* fileName)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Storage_DownloadSharedFile");
	DsMapAddInt64(map, "sharedFileID", sharedFileID);
	DsMapAddString(map, "fileName", fileName);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnSharedFileDownloadFailure(galaxy::api::SharedFileID sharedFileID, galaxy::api::GlobalSharedFileDownloadListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Storage_DownloadSharedFile");
	DsMapAddInt64(map, "sharedFileID", sharedFileID);
	switch (failureReason)
	{
	case galaxy::api::GlobalSharedFileDownloadListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalSharedFileDownloadListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnTelemetryEventSendSuccess(const char* eventType, uint32_t sentEventIndex)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Telemetry_SendTelemetryEvent");
	DsMapAddString(map, "eventType", eventType);
	DsMapAddDouble(map, "sentEventIndex", sentEventIndex);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnTelemetryEventSendFailure(const char* eventType, uint32_t sentEventIndex, galaxy::api::GlobalTelemetryEventSendListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Telemetry_SendTelemetryEvent");
	DsMapAddString(map, "eventType", eventType);
	DsMapAddDouble(map, "sentEventIndex", sentEventIndex);
	switch (failureReason)
	{
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_CLIENT_FORBIDDEN:
		DsMapAddString(map, "error", "FAILURE_REASON_CLIENT_FORBIDDEN"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_INVALID_DATA:
		DsMapAddString(map, "error", "FAILURE_REASON_INVALID_DATA"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_NO_SAMPLING_CLASS_IN_CONFIG:
		DsMapAddString(map, "error", "FAILURE_REASON_NO_SAMPLING_CLASS_IN_CONFIG"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_SAMPLING_CLASS_FIELD_MISSING:
		DsMapAddString(map, "error", "FAILURE_REASON_SAMPLING_CLASS_FIELD_MISSING"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_EVENT_SAMPLED_OUT:
		DsMapAddString(map, "error", "FAILURE_REASON_EVENT_SAMPLED_OUT"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_SAMPLING_RESULT_ALREADY_EXIST:
		DsMapAddString(map, "error", "FAILURE_REASON_SAMPLING_RESULT_ALREADY_EXIST"); break;
	case galaxy::api::GlobalTelemetryEventSendListener::FailureReason::FAILURE_REASON_SAMPLING_INVALID_RESULT_PATH:
		DsMapAddString(map, "error", "FAILURE_REASON_SAMPLING_INVALID_RESULT_PATH"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnAuthSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_SignIn");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnAuthFailure(galaxy::api::GlobalAuthListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_SignIn");
	switch (failureReason)
	{
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_GALAXY_SERVICE_NOT_AVAILABLE:
		DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_SERVICE_NOT_AVAILABLE"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_GALAXY_SERVICE_NOT_SIGNED_IN:
		DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_SERVICE_NOT_SIGNED_IN"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_NO_LICENSE:
		DsMapAddString(map, "error", "FAILURE_REASON_NO_LICENSE"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_INVALID_CREDENTIALS:
		DsMapAddString(map, "error", "FAILURE_REASON_INVALID_CREDENTIALS"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_GALAXY_NOT_INITIALIZED:
		DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_NOT_INITIALIZED"); break;
	case galaxy::api::GlobalAuthListener::FailureReason::FAILURE_REASON_EXTERNAL_SERVICE_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_EXTERNAL_SERVICE_FAILURE"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnAuthLost()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_SignIn");
	DsMapAddString(map, "error", "FAILURE_REASON_OnAuthLost");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnSpecificUserDataUpdated(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_RequestUserData");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnEncryptedAppTicketRetrieveSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_RequestEncryptedAppTicket");
	DsMapAddDouble(map, "success", 1.0);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnEncryptedAppTicketRetrieveFailure(galaxy::api::GlobalEncryptedAppTicketListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_RequestEncryptedAppTicket");
	DsMapAddDouble(map, "success", 0.0);
	switch (failureReason)
	{
	case galaxy::api::GlobalEncryptedAppTicketListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalEncryptedAppTicketListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnOtherSessionStarted()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_OtherSessionStart");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnOperationalStateChanged(uint32_t operationalState)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_OperationalStateChanged");
	DsMapAddDouble(map, "operationalState", operationalState);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnUserDataUpdated()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_UserDataUpdated");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnAccessTokenChanged()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_AccessTokenChanged");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnPlayFabCreateOpenIDConnectionSuccess(bool connectionAlreadyExists)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_PlayFabCreateOpenIDConnection");
	DsMapAddBool(map, "connectionAlreadyExists", connectionAlreadyExists);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnPlayFabCreateOpenIDConnectionFailure(galaxy::api::GlobalPlayFabCreateOpenIDConnectionListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_PlayFabCreateOpenIDConnection");
	switch (failureReason)
	{
	case galaxy::api::GlobalPlayFabCreateOpenIDConnectionListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalPlayFabCreateOpenIDConnectionListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnPlayFabLoginWithOpenIDConnectSuccess()
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_PlayFabLoginWithOpenIDConnect");
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnPlayFabLoginWithOpenIDConnectFailure(galaxy::api::GlobalPlayFabLoginWithOpenIDConnectListener::FailureReason failureReason)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_User_PlayFabLoginWithOpenIDConnect");
	switch (failureReason)
	{
	case galaxy::api::GlobalPlayFabLoginWithOpenIDConnectListener::FailureReason::FAILURE_REASON_UNDEFINED:
		DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
	case galaxy::api::GlobalPlayFabLoginWithOpenIDConnectListener::FailureReason::FAILURE_REASON_CONNECTION_FAILURE:
		DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnOverlayVisibilityChanged(bool overlayVisible)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Utils_OverlayVisibilityChanged");
	DsMapAddBool(map, "overlayVisible", overlayVisible);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnOverlayStateChanged(galaxy::api::OverlayState overlayState)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Utils_OverlayStateChanged");
	DsMapAddBool(map, "overlayState", overlayState);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnNotificationReceived(galaxy::api::NotificationID notificationID, uint32_t typeLength, uint32_t contentSize)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Utils_NotificationReceived");
	DsMapAddInt64(map, "notificationID", notificationID);
	DsMapAddDouble(map, "typeLength", typeLength);
	DsMapAddDouble(map, "contentSize", contentSize);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnConnectionStateChange(galaxy::api::GogServicesConnectionState connectionState)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Utils_ConnectionStateChange");
	switch (connectionState)
	{
	case galaxy::api::GogServicesConnectionState::GOG_SERVICES_CONNECTION_STATE_AUTH_LOST:
		DsMapAddString(map, "connectionState", "GOG_SERVICES_CONNECTION_STATE_AUTH_LOST"); break;
	case galaxy::api::GogServicesConnectionState::GOG_SERVICES_CONNECTION_STATE_DISCONNECTED:
		DsMapAddString(map, "connectionState", "GOG_SERVICES_CONNECTION_STATE_DISCONNECTED"); break;
	case galaxy::api::GogServicesConnectionState::GOG_SERVICES_CONNECTION_STATE_CONNECTED:
		DsMapAddString(map, "connectionState", "GOG_SERVICES_CONNECTION_STATE_CONNECTED"); break;
	case galaxy::api::GogServicesConnectionState::GOG_SERVICES_CONNECTION_STATE_UNDEFINED:
		DsMapAddString(map, "connectionState", "GOG_SERVICES_CONNECTION_STATE_UNDEFINED"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnAchievementUnlocked(const char* name)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Stats_AchievementUnlocked");
	DsMapAddString(map, "name", name);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnPersonaDataChanged(galaxy::api::GalaxyID userID, uint32_t personaStateChange)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_PersonaDataChanged");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	DsMapAddDouble(map, "personaStateChange", personaStateChange);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendInvitationReceived(galaxy::api::GalaxyID userID, uint32_t sendTime)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_InvitationReceived");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	DsMapAddDouble(map, "sendTime", sendTime);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnFriendAdded(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendAddListener::InvitationDirection invitationDirection)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_FriendAdded");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	switch (invitationDirection)
	{
	case galaxy::api::GlobalFriendAddListener::InvitationDirection::INVITATION_DIRECTION_INCOMING:
		DsMapAddString(map, "invitationDirection", "INVITATION_DIRECTION_INCOMING"); break;
	case galaxy::api::GlobalFriendAddListener::InvitationDirection::INVITATION_DIRECTION_OUTGOING:
		DsMapAddString(map, "invitationDirection", "INVITATION_DIRECTION_OUTGOING"); break;
	}
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnRichPresenceUpdated(galaxy::api::GalaxyID userID)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_RichPresenceUpdated");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnGameJoinRequested(galaxy::api::GalaxyID userID, const char* connectionString)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_GameJoinRequested");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	DsMapAddString(map, "connectionString", connectionString);
	CreateAsyncEventWithDSMap(map, 70);
}

void GMAsyncEventListener::OnGameInvitationReceived(galaxy::api::GalaxyID userID, const char* connectionString)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "GOG_Friends_GameInvitationReceived");
	RValue struct_userID = getStructFromGalaxyID(userID);
	DsMapAddRValue(map, "userID", &struct_userID);
	DsMapAddString(map, "connectionString", connectionString);
	CreateAsyncEventWithDSMap(map, 70);
}
