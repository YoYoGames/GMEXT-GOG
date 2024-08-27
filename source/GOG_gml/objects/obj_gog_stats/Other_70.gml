
var init_struct = undefined;
switch(async_load[?"type"])
{
	case "GOG_Stats_RequestUserTimePlayed":
	
		show_debug_message("GOG_Stats_GetUserTimePlayed: " + string(GOG_Stats_GetUserTimePlayed()))
		
	break
	
	case "GOG_Stats_RequestLeaderboards":
	
		show_debug_message("GOG_Stats_GetLeaderboardEntryCount: " + string(GOG_Stats_GetLeaderboardDisplayName("Leaderboard1")))
		
		init_struct = {api_key: "YYLeaderboard"}
		instance_create_depth(800,250,0,Obj_GOG_Leaderboard,init_struct)
		
	break
	
	case "GOG_Stats_RequestUserStatsAndAchievements":
		
		init_struct = {api_key: "YYStat_Int"}
		instance_create_depth(x,150,0,Obj_GOG_Stat_Int,init_struct)
		
		init_struct = {api_key: "YYStat_Float"}
		instance_create_depth(x,250,0,Obj_GOG_Stat_Float,init_struct)
		
		
		init_struct = {api_key: "YYAchievement"}
		instance_create_depth(x,350,0,Obj_GOG_Achievement,init_struct)
		
		init_struct = {api_key: "YYAchievement_Invisible"}
		instance_create_depth(x,450,0,Obj_GOG_Achievement,init_struct)
		
	break
}
