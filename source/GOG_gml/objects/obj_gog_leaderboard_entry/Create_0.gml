
userID ??= {};

//rank, userID, score, data (base64)
GOG_User_RequestUserData(userID);

if (!is_undefined(data)) {
	var _buffer = buffer_base64_decode(data);
	show_debug_message("Buffer Read: " + buffer_read(_buffer, buffer_string))
	buffer_delete(_buffer);
}