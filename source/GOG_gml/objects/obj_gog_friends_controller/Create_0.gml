
count = 0

GOG_Friends_RequestUserInformation(GOG_User_GetGalaxyID(),GOG_AVATAR_TYPE_MEDIUM)

for(var a = 0 ; a < GOG_Friends_GetFriendCount() ; a++)
{
	GOG_Friends_RequestUserInformation(GOG_Friends_GetFriendByIndex(a),GOG_AVATAR_TYPE_MEDIUM)
}
	
