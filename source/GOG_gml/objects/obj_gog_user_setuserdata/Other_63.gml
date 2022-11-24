
if(async_load[?"status"])
if(async_load[?"result"] != "")
{
	if(async_load[?"id"] == request_key)
	{
		key = async_load[?"result"]
		request_value = get_string_async("Value:","Hello World")
	}
	
	if(async_load[?"id"] == request_value)
	{
		GOG_User_SetUserData(key,async_load[?"result"])
	}
}
	
