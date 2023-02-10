
//userID

surf = noone
show_debug_message(userID)
show_debug_message(GOG_Friends_IsFriendAvatarImageRGBAAvailable(userID,GOG_AVATAR_TYPE_MEDIUM))
if(GOG_Friends_IsFriendAvatarImageRGBAAvailable(userID,GOG_AVATAR_TYPE_MEDIUM))
{
	var buff = GOG_Friends_GetFriendAvatarImageRGBA(userID,GOG_AVATAR_TYPE_MEDIUM)
		
	var size = buffer_get_size(buff)
	var L = sqrt(size/4)
		
	surf = surface_create(L,L)
	buffer_set_surface(buff,surf,0)
		
	buffer_delete(buff)
}
