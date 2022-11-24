
show_debug_message(json_encode(async_load));

if(async_load[?"id"] == request)
if(async_load[?"status"])
if(async_load[?"result"] != "")
	GOG_Utils_ShowOverlayWithWebPage(async_load[?"result"])
