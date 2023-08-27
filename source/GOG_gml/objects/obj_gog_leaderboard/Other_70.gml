
// this was "GOG_Stats_RequestLeaderboardEntriesGlobal" in older versions
if(async_load[?"type"] == "GOG_Stats_RequestLeaderboardEntries")
{
	var array = async_load[? "entries"];
	var lenght = array_length(array)
	
	for(var a = 0 ; a < lenght ; a++)
	{
		var struct = array[a]
		instance_create_depth(x, y, 0, Obj_GOG_Leaderboard_Entry, struct)//index,rank,userID,score,data
	}
}

// this was "GOG_Stats_SetLeaderboardScoreWithDetails" in older versions
if(async_load[?"type"] == "GOG_Stats_SetLeaderboardScore")
{
	GOG_Stats_RequestLeaderboardEntriesGlobal(api_key,0,4);
}

