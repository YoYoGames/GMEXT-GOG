
show_debug_message(json_encode(async_load))

switch(async_load[?"type"])
{
	case "GOG_User_SignInGalaxy":
		room_goto(Room_GOG_Menu)
	break
}


