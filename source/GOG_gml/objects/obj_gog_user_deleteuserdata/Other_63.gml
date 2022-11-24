
if(async_load[?"id"] == request)
if(async_load[?"status"])
if(async_load[?"result"] != "")
	GOG_User_DeleteUserData(async_load[?"result"])
