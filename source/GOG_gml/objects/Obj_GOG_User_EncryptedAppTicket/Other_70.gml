
switch(async_load[?"type"])
{
	case "GOG_User_RequestEncryptedAppTicket":
	
		if(async_load[?"success"])
		{
			var ticket = GOG_User_GetEncryptedAppTicket()
			if (ticket >= 0) {
				// this returned a string in older versions, now it returns a buffer
				show_debug_message("GOG_User_GetEncryptedAppTicket buffer = " + string(ticket) + "," + string(buffer_get_size(ticket)))
				buffer_delete(ticket)
			}
		}
		
	break
}