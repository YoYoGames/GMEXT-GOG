
api_key ??= "ERROR";

name = GOG_Stats_GetLeaderboardDisplayName(api_key)
type = GOG_Stats_GetLeaderboardDisplayType(api_key)
sort = GOG_Stats_GetLeaderboardSortMethod(api_key)

//GOG_Stats_RequestLeaderboardEntriesAroundUser()
//GOG_Stats_RequestLeaderboardEntriesGlobal()
//Leaderboard

var str = "Hello World"
var size = string_length(str)+1
var buffer = buffer_create(size,buffer_fixed,1)

show_debug_message(buffer)
buffer_write(buffer,buffer_string,str)
show_debug_message(buffer_get_size(buffer))

//GOG_Stats_SetLeaderboardScore(api_key,100,true)
GOG_Stats_SetLeaderboardScoreWithDetails(api_key,100,true,buffer)

GOG_Stats_RequestLeaderboardEntriesGlobal(api_key,0,4)

