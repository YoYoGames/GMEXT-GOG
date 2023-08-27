/// @param {Real} gogTime GOG's unix epoch time
/// @returns {Real} GameMaker date time value
function GOG_UnixTimeToGMTime(gogTime) {
	return ((gogTime + 0.5) / 86400.0) + 25569.0;
}
