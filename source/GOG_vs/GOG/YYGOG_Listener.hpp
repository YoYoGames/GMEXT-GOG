#pragma once
#include "YYGOG.h"
#include <memory>

// https://github.com/gogcom/galaxy-demo-app/blob/master/src/game/networking/ILobby.h#L18
// https://github.com/gogcom/galaxy-demo-app/blob/master/src/game/networking/Lobby.h
// It seems that it is legally allowed by the Galaxy SDK to inherit from multiple listeners
// at once.
// You just declare all your functions as virtual override and make a virtual constructor
// and you should be good to go.
class GMAsyncEventListener :
	public galaxy::api::IIsDlcOwnedListener, // TODO: this one has no Global version for some reason?!
	public galaxy::api::GlobalUserInformationRetrieveListener,
	public galaxy::api::GlobalFriendListListener,
	public galaxy::api::GlobalFriendInvitationSendListener,
	public galaxy::api::GlobalFriendInvitationListRetrieveListener,
	public galaxy::api::GlobalSentFriendInvitationListRetrieveListener,
	public galaxy::api::GlobalFriendInvitationRespondToListener,
	public galaxy::api::GlobalFriendDeleteListener,
	public galaxy::api::GlobalRichPresenceChangeListener,
	public galaxy::api::GlobalRichPresenceRetrieveListener,
	public galaxy::api::GlobalSendInvitationListener,
	public galaxy::api::GlobalUserFindListener,
	public galaxy::api::GlobalUserStatsAndAchievementsRetrieveListener,
	public galaxy::api::GlobalStatsAndAchievementsStoreListener,
	public galaxy::api::GlobalLeaderboardsRetrieveListener,
	public galaxy::api::GlobalLeaderboardEntriesRetrieveListener,
	public galaxy::api::GlobalLeaderboardScoreUpdateListener,
	public galaxy::api::GlobalLeaderboardRetrieveListener,
	public galaxy::api::GlobalUserTimePlayedRetrieveListener,
	public galaxy::api::GlobalFileShareListener,
	public galaxy::api::GlobalSharedFileDownloadListener,
	public galaxy::api::GlobalTelemetryEventSendListener,
	public galaxy::api::GlobalAuthListener,
	public galaxy::api::GlobalSpecificUserDataListener,
	public galaxy::api::GlobalEncryptedAppTicketListener,
	public galaxy::api::GlobalOtherSessionStartListener,
	public galaxy::api::GlobalOperationalStateChangeListener,
	public galaxy::api::GlobalUserDataListener,
	public galaxy::api::GlobalAccessTokenListener,
	public galaxy::api::GlobalPlayFabCreateOpenIDConnectionListener,
	public galaxy::api::GlobalPlayFabLoginWithOpenIDConnectListener,
	public galaxy::api::GlobalOverlayVisibilityChangeListener,
	public galaxy::api::GlobalOverlayInitializationStateChangeListener,
	public galaxy::api::GlobalNotificationListener,
	public galaxy::api::GlobalGogServicesConnectionStateListener,
	public galaxy::api::GlobalAchievementChangeListener,
	public galaxy::api::GlobalPersonaDataChangedListener,
	public galaxy::api::GlobalFriendInvitationListener,
	public galaxy::api::GlobalFriendAddListener,
	public galaxy::api::GlobalRichPresenceListener,
	public galaxy::api::GlobalGameJoinRequestedListener,
	public galaxy::api::GlobalGameInvitationReceivedListener
{
private:
	static std::unique_ptr<GMAsyncEventListener> SingletonInstance;

public:
	// Lifetime

	static GMAsyncEventListener *Instance();
	static void Unregister();

	virtual ~GMAsyncEventListener(); // don't override since constructors aren't overridable

	// IIsDlcOwnedListener

	virtual void OnDlcCheckSuccess(galaxy::api::ProductID productId, bool isOwned) override;
	virtual void OnDlcCheckFailure(galaxy::api::ProductID productId, galaxy::api::IIsDlcOwnedListener::FailureReason failureReason) override;

	// GlobalUserInformationRetrieveListener

	virtual void OnUserInformationRetrieveSuccess(galaxy::api::GalaxyID userID) override;
	virtual void OnUserInformationRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalUserInformationRetrieveListener::FailureReason failureReason) override;

	// GlobalFriendListListener

	virtual void OnFriendListRetrieveSuccess() override;
	virtual void OnFriendListRetrieveFailure(galaxy::api::GlobalFriendListListener::FailureReason failureReason) override;

	// GlobalFriendInvitationSendListener

	virtual void OnFriendInvitationSendSuccess(galaxy::api::GalaxyID userID) override;
	virtual void OnFriendInvitationSendFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendInvitationSendListener::FailureReason failureReason) override;

	// GlobalFriendInvitationListRetrieveListener

	virtual void OnFriendInvitationListRetrieveSuccess() override;
	virtual void OnFriendInvitationListRetrieveFailure(galaxy::api::GlobalFriendInvitationListRetrieveListener::FailureReason failureReason) override;

	// GlobalSentFriendInvitationListRetrieveListener

	virtual void OnSentFriendInvitationListRetrieveSuccess() override;
	virtual void OnSentFriendInvitationListRetrieveFailure(galaxy::api::GlobalSentFriendInvitationListRetrieveListener::FailureReason failureReason) override;

	// GlobalFriendInvitationRespondToListener

	virtual void OnFriendInvitationRespondToSuccess(galaxy::api::GalaxyID userID, bool accept) override;
	virtual void OnFriendInvitationRespondToFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendInvitationRespondToListener::FailureReason failureReason) override;

	// GlobalFriendDeleteListener

	virtual void OnFriendDeleteSuccess(galaxy::api::GalaxyID userID) override;
	virtual void OnFriendDeleteFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendDeleteListener::FailureReason failureReason) override;

	// GlobalRichPresenceChangeListener

	virtual void OnRichPresenceChangeSuccess() override;
	virtual void OnRichPresenceChangeFailure(galaxy::api::GlobalRichPresenceChangeListener::FailureReason failureReason) override;

	// GlobalRichPresenceRetrieveListener

	virtual void OnRichPresenceRetrieveSuccess(galaxy::api::GalaxyID userID) override;
	virtual void OnRichPresenceRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalRichPresenceRetrieveListener::FailureReason failureReason) override;

	// GlobalSendInvitationListener

	virtual void OnInvitationSendSuccess(galaxy::api::GalaxyID userID, const char* connectionString) override;
	virtual void OnInvitationSendFailure(galaxy::api::GalaxyID userID, const char* connectionString, galaxy::api::GlobalSendInvitationListener::FailureReason failureReason) override;

	// GlobalUserFindListener

	virtual void OnUserFindSuccess(const char* userSpecifier, galaxy::api::GalaxyID userID) override;
	virtual void OnUserFindFailure(const char* userSpecifier, galaxy::api::GlobalUserFindListener::FailureReason failureReason) override;

	// GlobalUserStatsAndAchievementsRetrieveListener

	virtual void OnUserStatsAndAchievementsRetrieveSuccess(galaxy::api::GalaxyID userID) override;
	virtual void OnUserStatsAndAchievementsRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalUserStatsAndAchievementsRetrieveListener::FailureReason failureReason) override;

	// GlobalStatsAndAchievementsStoreListener

	virtual void OnUserStatsAndAchievementsStoreSuccess() override;
	virtual void OnUserStatsAndAchievementsStoreFailure(galaxy::api::GlobalStatsAndAchievementsStoreListener::FailureReason failureReason) override;

	// GlobalLeaderboardsRetrieveListener

	virtual void OnLeaderboardsRetrieveSuccess() override;
	virtual void OnLeaderboardsRetrieveFailure(galaxy::api::GlobalLeaderboardsRetrieveListener::FailureReason failureReason) override;

	// GlobalLeaderboardEntriesRetrieveListener

	virtual void OnLeaderboardEntriesRetrieveSuccess(const char* name, uint32_t entryCount) override;
	virtual void OnLeaderboardEntriesRetrieveFailure(const char* name, galaxy::api::GlobalLeaderboardEntriesRetrieveListener::FailureReason failureReason) override;

	// GlobalLeaderboardScoreUpdateListener

	virtual void OnLeaderboardScoreUpdateSuccess(const char* name, int32_t score, uint32_t oldRank, uint32_t newRank) override;
	virtual void OnLeaderboardScoreUpdateFailure(const char* name, int32_t score, galaxy::api::GlobalLeaderboardScoreUpdateListener::FailureReason failureReason) override;

	// GlobalLeaderboardRetrieveListener

	virtual void OnLeaderboardRetrieveSuccess(const char* name) override;
	virtual void OnLeaderboardRetrieveFailure(const char* name, galaxy::api::GlobalLeaderboardRetrieveListener::FailureReason failureReason) override;

	// GlobalUserTimePlayedRetrieveListener

	virtual void OnUserTimePlayedRetrieveSuccess(galaxy::api::GalaxyID userID) override;
	virtual void OnUserTimePlayedRetrieveFailure(galaxy::api::GalaxyID userID, galaxy::api::GlobalUserTimePlayedRetrieveListener::FailureReason failureReason) override;

	// GlobalFileShareListener

	virtual void OnFileShareSuccess(const char* fileName, galaxy::api::SharedFileID sharedFileID) override;
	virtual void OnFileShareFailure(const char* fileName, galaxy::api::GlobalFileShareListener::FailureReason failureReason) override;

	// GlobalSharedFileDownloadListener

	virtual void OnSharedFileDownloadSuccess(galaxy::api::SharedFileID sharedFileID, const char* fileName) override;
	virtual void OnSharedFileDownloadFailure(galaxy::api::SharedFileID sharedFileID, galaxy::api::GlobalSharedFileDownloadListener::FailureReason failureReason) override;

	// GlobalTelemetryEventSendListener

	virtual void OnTelemetryEventSendSuccess(const char* eventType, uint32_t sentEventIndex) override;
	virtual void OnTelemetryEventSendFailure(const char* eventType, uint32_t sentEventIndex, galaxy::api::GlobalTelemetryEventSendListener::FailureReason failureReason) override;

	// GlobalAuthListener

	virtual void OnAuthSuccess() override;
	virtual void OnAuthFailure(galaxy::api::GlobalAuthListener::FailureReason failureReason) override;
	virtual void OnAuthLost() override;

	// GlobalSpecificUserDataListener

	virtual void OnSpecificUserDataUpdated(galaxy::api::GalaxyID userID) override;

	// GlobalEncryptedAppTicketListener

	virtual void OnEncryptedAppTicketRetrieveSuccess() override;
	virtual void OnEncryptedAppTicketRetrieveFailure(galaxy::api::GlobalEncryptedAppTicketListener::FailureReason failureReason) override;

	// GlobalOtherSessionStartListener

	virtual void OnOtherSessionStarted() override;

	// GlobalOperationalStateChangeListener

	virtual void OnOperationalStateChanged(uint32_t operationalState) override;

	// GlobalUserDataListener

	virtual void OnUserDataUpdated() override;

	// GlobalAccessTokenListener

	virtual void OnAccessTokenChanged() override;

	// GlobalPlayFabCreateOpenIDConnectionListener

	virtual void OnPlayFabCreateOpenIDConnectionSuccess(bool connectionAlreadyExists) override;
	virtual void OnPlayFabCreateOpenIDConnectionFailure(galaxy::api::GlobalPlayFabCreateOpenIDConnectionListener::FailureReason failureReason) override;

	// GlobalPlayFabLoginWithOpenIDConnectListener

	virtual void OnPlayFabLoginWithOpenIDConnectSuccess() override;
	virtual void OnPlayFabLoginWithOpenIDConnectFailure(galaxy::api::GlobalPlayFabLoginWithOpenIDConnectListener::FailureReason failureReason) override;

	// GlobalOverlayVisibilityChangeListener

	virtual void OnOverlayVisibilityChanged(bool overlayVisible) override;

	// GlobalOverlayInitializationStateChangeListener

	virtual void OnOverlayStateChanged(galaxy::api::OverlayState overlayState) override;

	// GlobalNotificationListener

	virtual void OnNotificationReceived(galaxy::api::NotificationID notificationID, uint32_t typeLength, uint32_t contentSize) override;

	// GlobalGogServicesConnectionStateListener

	virtual void OnConnectionStateChange(galaxy::api::GogServicesConnectionState connectionState) override;

	// GlobalAchievementChangeListener

	virtual void OnAchievementUnlocked(const char* name) override;

	// GlobalPersonaDataChangedListener

	virtual void OnPersonaDataChanged(galaxy::api::GalaxyID userID, uint32_t personaStateChange) override;

	// GlobalFriendInvitationListener

	virtual void OnFriendInvitationReceived(galaxy::api::GalaxyID userID, uint32_t sendTime) override;

	// GlobalFriendAddListener

	virtual void OnFriendAdded(galaxy::api::GalaxyID userID, galaxy::api::GlobalFriendAddListener::InvitationDirection invitationDirection) override;

	// GlobalRichPresenceListener

	virtual void OnRichPresenceUpdated(galaxy::api::GalaxyID userID) override;

	// GlobalGameJoinRequestedListener

	virtual void OnGameJoinRequested(galaxy::api::GalaxyID userID, const char* connectionString) override;

	// GlobalGameInvitationReceivedListener

	virtual void OnGameInvitationReceived(galaxy::api::GalaxyID userID, const char* connectionString) override;
};
