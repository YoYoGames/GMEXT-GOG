
show_debug_message("[GOG ASYNC]: " + json_encode(async_load))

switch(async_load[?"type"])
{
	case "GOG_User_SignIn":
	// this was "GOG_User_SignInGalaxy" in older versions!
		room_goto(Room_GOG_Menu)
	break
}


