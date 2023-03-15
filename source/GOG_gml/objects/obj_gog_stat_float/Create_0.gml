image_xscale = 4
event_inherited();

api_key ??= "ERROR"

text = api_key// no function to get the name....

value = GOG_Stats_GetStatFloat(api_key,GOG_User_GetGalaxyID())

request = noone