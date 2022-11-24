
if(async_load[?"type"] == "GOG_Stats_RequestLeaderboardEntriesGlobal")
{
	var array = async_load[?"entries"]
	var lenght = array_length(array)
	
	for(var a = 0 ; a < lenght ; a++)
	{
		var struct = array[a]
		instance_create_depth(x,y,0,Obj_GOG_Leaderboard_Entry,struct)//index,rank,userID,score,buffer
	}
}

