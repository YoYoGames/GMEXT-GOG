
api_key ??= "ERROR";

image_xscale = 4
event_inherited();

text = GOG_Stats_GetAchievementDisplayName(api_key)

var _struct = GOG_Stats_GetAchievement(api_key,GOG_User_GetGalaxyID())//unlocked,unlockTime
show_debug_message(_struct)
if(_struct.unlocked)
	locked = true

GOG_Stats_GetAchievementDescription(api_key)

var _init_struct = {api_key: api_key}
instance_create_depth(bbox_right+100,y,0,Obj_GOG_Stats_Achievement_Clear, _init_struct);

