
draw_set_font(Font_YoYo_20)

draw_set_halign(fa_left)
draw_set_valign(fa_top)
draw_text(100,100,"My GalaxyID: " + json_stringify(GOG_User_GetGalaxyID()))
draw_text(100,130,"SessionID: " + string(GOG_User_GetSessionID()))
draw_text(100,160,"UserDataAvailable: " + string(GOG_User_IsUserDataAvailable(GOG_User_GetGalaxyID())))

//draw_text(100,210,"here: " + GOG_User_GetUserData("Data2",GOG_User_GetGalaxyID()))
draw_text(100,190,"User Data: ")
for(var a = 0 ; a < GOG_User_GetUserDataCount(GOG_User_GetGalaxyID()) ; a ++ )
	draw_text(100,220+a*30,GOG_User_GetUserDataByIndex(a,GOG_User_GetGalaxyID()))
