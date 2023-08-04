
if(async_load[? "id"] == request)
if(async_load[?"status"])
{
    var value = async_load[?"value"]
	GOG_Stats_SetStatInt(api_key,value)
}

