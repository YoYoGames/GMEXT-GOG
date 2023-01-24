
switch(async_load[?"type"])
{
	case "GOG_User_RequestEncryptedAppTicket":
	
		if(async_load[?"success"])
		{
			var ticket = GOG_User_GetEncryptedAppTicket()
			show_debug_message("GOG_User_GetEncryptedAppTicket: " + ticket)
		}
		
	break
}