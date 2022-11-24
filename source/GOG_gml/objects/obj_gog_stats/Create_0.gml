
event_inherited()

text = "Refresh"

function Refresh()
{
	with(Obj_GOG_Achievement)
		instance_destroy()
	
	with(Obj_GOG_Stat_Float)
		instance_destroy()
	
	with(Obj_GOG_Stat_Int)
		instance_destroy()
	
	with(Obj_GOG_Leaderboard)
		instance_destroy()
	
	GOG_Stats_RequestUserTimePlayed(GOG_User_GetGalaxyID())
	GOG_Stats_RequestLeaderboards()
	GOG_Stats_RequestUserStatsAndAchievements(GOG_User_GetGalaxyID())
}

Refresh()

//GOG_Stats_RequestLeaderboardEntriesAroundUser()
//GOG_Stats_RequestLeaderboardEntriesGlobal()
