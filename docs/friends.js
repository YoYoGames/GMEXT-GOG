// FUNCTIONS

/**
 * @function GOG_Friends_ClearRichPresence
 * @desc Removes all rich presence data for the user. This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_ClearRichPresence"`
 * @member {string} error The error message; only if the request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_ClearRichPresence();
 * ```
 * The code sample above starts a clear rich presence task which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_ClearRichPresence")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     
 *     show_debug_message("ClearRichPresence SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Friends_DeleteFriend
 *
 * @desc This function removes a user from the friend list.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 *
 * @param {struct.GalaxyID} userID The ${struct.GalaxyID} of the user to be removed from the friend list.
 *
 * @event social
 * @member {string} type `"GOG_Friends_DeleteFriend"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {struct.GalaxyID} userID GOG Galaxy user identifier
 * @event_end
 *
 * @example
 * ```gml
 * GOG_Friends_DeleteFriend(myFriendID);
 * ```
 *   The code sample above starts a friend deletion task which result can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_DeleteFriend")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     var _deletedFriend = async_load[?"userID"];
 *     show_debug_message("Friend Deleted");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Friends_DeleteRichPresence
 * @desc This function removes the variable value under a specified name. If the variable doesn't exist, the method call has no effect.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} key The name of the variable to be removed.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_DeleteRichPresence"`
 * @member {string} error The error message; only if the request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_DeleteRichPresence("playing");
 * ```
 * The code sample above starts a rich presence delete task of which the results can be caught inside an ${event.social}.
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_DeleteRichPresence")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("DeleteRichPresence SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @func GOG_Friends_FindUser
 * @desc This function finds a specified user.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} userSpecifier The specifier of the user.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_FindUser"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {struct.GalaxyID} userID The ID of the user.
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_FindUser(userSpecifier);
 * ```
 * The code sample above starts a find user task which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_FindUser")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     var _user = async_load[?"userID"];
 *     show_debug_message("FindUser SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_GetDefaultAvatarCriteria
 * @desc This function returns the default avatar criteria which is a ${type.real} with the bit sum of the default ${constant.AvatarType}.
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _AvatarCriteria = GOG_Friends_GetDefaultAvatarCriteria();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 * 
 * @func GOG_Friends_GetFriendAvatarImageID
 * @desc Returns the ID of the avatar of a specified user.
 * 
 * > **:warning: REQUIREMENT**
 * >
 * > Retrieve the avatar image first by calling ${function.GOG_Friends_RequestUserInformation} with appropriate avatar criteria.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * @param {constant.AvatarType} avatarType The type of avatar.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _ImageID = GOG_Friends_GetFriendAvatarImageID(userID, GOG_AVATAR_TYPE_SMALL);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendAvatarImageRGBA
 * @desc This function copies the avatar of a specified user.
 * 
 * [[WARNING: REQUIREMENT You might need to retrieve the data first by calling ${function.GOG_Friends_RequestUserInformation}.]]
 * 
 * [[NOTE: The size of the output buffer will be 4 * height * width (check [AvatarType,](#AvatarType) for width and height values).]]
 * 
 * [[WARNING: This function creates a new buffer everytime it is called, unless a buffer is already specified. You need to ensure you correctly delete the buffer when you don't need it anymore using the ${function.buffer_delete} function. Failing to do so will result in memory leaks.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * @param {constant.AvatarType} AvatarType The type of avatar.
 * @param {type.buffer} [bufferID] OPTIONAL: use an existing buffer instead of allocating a new one
 * @param {real} [byteOffset] OPTIONAL: write data to a specific offset in the buffer
 * 
 * @returns {type.buffer}
 * 
 * @example
 * ```gml
 * if(GOG_Friends_IsFriendAvatarImageRGBAAvailable(userID, GOG_AVATAR_TYPE_LARGE))
 * {
 *     var _buff = GOG_Friends_GetFriendAvatarImageRGBA(userID, GOG_AVATAR_TYPE_LARGE);
 * 
 *     var _size = buffer_get_size(_buff);
 *     var _L = sqrt(_size/4);
 * 
 *     surf = surface_create(_L, _L);
 *     buffer_set_surface(_buff, surf, 0);
 * 
 *     buffer_delete(_buff);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendAvatarUrl
 * @desc Returns the URL of the avatar of a specified user.
 * 
 * [[WARNING: REQUIREMENT You might need to retrieve the data first by calling ${function.GOG_Friends_RequestUserInformation}.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * @param {constant.AvatarType} avatarType The type of avatar.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _url = GOG_Friends_GetFriendAvatarUrl(userID, GOG_AVATAR_TYPE_SMALL);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendByIndex
 * @desc This function returns the ${struct.GalaxyID} for a friend.
 * 
 * [[WARNING: REQUIREMENT Retrieve the list of friends first by calling ${function.GOG_Friends_RequestFriendList}.]]
 * 
 * @param {real} index Index as an integer in the range of [0, number of friends].
 * 
 * @returns {struct.GalaxyID}
 * 
 * @example
 * ```gml
 * for(var a = 0 ; a < GOG_Friends_GetFriendCount() ; a++)
 * {
 *     var _friendID = GOG_Friends_GetFriendByIndex(a);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendCount
 * @desc This function returns the number of retrieved friends in the user's list of friends.
 * 
 * [[WARNING: REQUIREMENT Retrieve the list of friends first by calling ${function.GOG_Friends_RequestFriendList}.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var a = 0 ; a < GOG_Friends_GetFriendCount() ; a++)
 * {
 *     var _friendID = GOG_Friends_GetFriendByIndex(a);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 * 
 * @func GOG_Friends_GetFriendInvitationByIndex
 * @desc This function reads the details of the friend invitation.
 * 
 * @param {real} index Index as an integer in the range of [0, number of friend invitations].
 * 
 * @returns {struct.FriendInvitationDetails}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GOG_Friends_GetFriendInvitationCount() ; i++)
 * {
 *     var _struct = GOG_Friends_GetFriendInvitationByIndex(i);
 *     var _userID = _struct.userID;
 *     var _sendTime = _struct.sendTime;
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendInvitationCount
 * @desc This function returns the number of retrieved friend invitations.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GOG_Friends_GetFriendInvitationCount() ; i++)
 * {
 *     var _struct = GOG_Friends_GetFriendInvitationByIndex(i);
 *     var _userID = _struct.userID;
 *     var _sendTime = _struct.sendTime;
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendPersonaName
 * @desc This function returns the nickname of a specified user.
 * 
 * [[WARNING: REQUIREMENT You might need to retrieve the data first by calling ${function.GOG_Friends_RequestUserInformation}.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _name = GOG_Friends_GetFriendPersonaName(GOG_User_GetGalaxyID());
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetFriendPersonaState
 * @desc This function returns the state of a specified user, see ${constant.PersonaState}.
 * 
 * [[WARNING: REQUIREMENT You might need to retrieve the data first by calling ${function.GOG_Friends_RequestUserInformation}.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {constant.PersonaState}
 * 
 * @example
 * ```gml
 * if (GOG_Friends_GetFriendPersonaState(myFriendID) == GOG_PERSONA_STATE_ONLINE)
 * {
 *     //My friend is online, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetPersonaName
 * @desc This function returns the user's nickname.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _name = GOG_Friends_GetPersonaName();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
* @func GOG_Friends_GetPersonaState
* @desc This function returns the user's state.
* 
* @returns {constant.PersonaState}
* 
* @example
* ```gml
* if(GOG_Friends_GetPersonaState() == GOG_PERSONA_STATE_ONLINE)
* {
*     // I'm online right now
* }
* ```
* The code above provides a simple usage example.
* @func_end
*/

/**
 * @func GOG_Friends_GetRichPresence
 * @desc This function returns the rich presence of a specified user.
 * 
 * [[WARNING: REQUIREMENT Retrieve the rich presence first by calling ${function.GOG_Friends_RequestRichPresence}.]]
 * 
 * 
 * @param {string} key The name of the property of the user's rich presence.
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _value = GOG_Friends_GetRichPresence("playing", GOG_User_GetGalaxyID());
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetRichPresenceByIndex
 * @desc Returns a property from the rich presence storage by index.
 * 
 * [[WARNING: REQUIREMENT Retrieve the rich presence first by calling ${function.GOG_Friends_RequestRichPresence}.]]
 * 
 * @param {real} index Index as an integer in the range of [0, number of entries].
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {struct.RichPresenceProperty}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GOG_Friends_GetRichPresenceCount(GOG_User_GetGalaxyID()) ; i++)
 * {
 *     var _struct = GOG_Friends_GetRichPresenceByIndex(i, GOG_User_GetGalaxyID());
 *     var _key = _struct.key;
 *     var _value = _struct.value;
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_GetRichPresenceCount
 * @desc This function returns the number of retrieved properties in a user's rich presence.
 * 
 * [[warning: REQUIREMENT Retrieve the rich presence first by calling ${function.GOG_Friends_RequestRichPresence}.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GOG_Friends_GetRichPresenceCount(GOG_User_GetGalaxyID()) ; i++)
 * {
 *     var _struct = GOG_Friends_GetRichPresenceByIndex(i, GOG_User_GetGalaxyID());
 *     var _key = _struct.key;
 *     var _value = _struct.value;
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */


/**
 * @func GOG_Friends_GetRichPresenceKeyByIndex
 * @desc This function returns a key from the rich presence storage by index.
 * 
 * [[WARNING: REQUIREMENT Retrieve the rich presence first by calling ${function.GOG_Friends_RequestRichPresence}.]]
 * 
 * @param {real} index Index as an integer in the range of [0, number of entries].
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * for (var i = 0; i < GOG_Friends_GetRichPresenceCount(GOG_User_GetGalaxyID()); i++)
 * {
 *     var _key = GOG_Friends_GetRichPresenceKeyByIndex(i, GOG_User_GetGalaxyID());
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_IsFriend
 * @desc This function checks if a specified user is a friend.
 * 
 * [[WARNING: REQUIREMENT Retrieve the list of friends first by calling ${function.GOG_Friends_RequestFriendList}.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if (GOG_Friends_IsFriend(friendID))
 * {
 *     //Is my friend, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_IsFriendAvatarImageRGBAAvailable
 * @desc This function checks if a specified avatar image is available.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * @param {constant.AvatarType} avatarID The type of avatar.
 * 
 * @returns {bool}
 * 
 * @example
 * ```gml
 * if (GOG_Friends_IsFriendAvatarImageRGBAAvailable(userID, GOG_AVATAR_TYPE_LARGE))
 * {
 *     var _buff = GOG_Friends_GetFriendAvatarImageRGBA(userID, GOG_AVATAR_TYPE_LARGE);
 * 
 *     var _size = buffer_get_size(_buff);
 *     var _L = sqrt(_size/4);
 * 
 *     surf = surface_create(_L, _L);
 *     buffer_set_surface(_buff, surf, 0);
 * 
 *     buffer_delete(_buff);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_IsUserInformationAvailable
 * @desc Checks if the information of specified user is available.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {bool}
 * 
 * @example
 * ```gml
 * if (GOG_Friends_IsUserInformationAvailable(GOG_User_GetGalaxyID()))
 * {
 *    var _name = GOG_Friends_GetPersonaName(GOG_User_GetGalaxyID());
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_IsUserInTheSameGame
 * @desc This function checks if a specified user is playing the same game.
 * 
 * [[WARNING: REQUIREMENT Retrieve the rich presence first by calling ${function.GOG_Friends_RequestRichPresence}.]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @returns {bool}
 * 
 * @example
 * ```gml
 * if(GOG_Friends_IsUserInformationAvailable(friendID))
 * {
 *    if(GOG_Friends_IsUserInTheSameGame(friendID))
 *    {
 *        //my friend is on the same game, do something
 *    }
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_RequestFriendInvitationList
 * @desc This function performs a request for the user's list of incoming friend invitations.
 * 
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RequestFriendInvitationList"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RequestFriendInvitationList();
 * ```
 * The code sample above starts task for requesting friends invitation data which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RequestFriendInvitationList")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RequestFriendInvitationList SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_RequestFriendList
 * @desc This function performs a request for the user's list of friends.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RequestFriendList"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RequestFriendList();
 * ```
 * The code sample above starts task for requesting friends data which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RequestFriendList")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RequestFriendList SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_RequestRichPresence
 * @desc Performs a request for the user's rich presence.
 * 
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RequestRichPresence"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RequestRichPresence();
 * ```
 * The code sample above starts task for requesting rich presence data which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RequestRichPresence")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RequestRichPresence SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_RequestSentFriendInvitationList
 * @desc This function performs a request for the user's list of outgoing friend invitations.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RequestSentFriendInvitationList"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RequestSentFriendInvitationList() ;
 * ```
 * The code sample above starts task for requesting sent friendship invitation data which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RequestSentFriendInvitationList")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RequestSentFriendInvitationList SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_RequestUserInformation
 * @desc This function performs a request for information about a specified user.
 * 
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RequestUserInformation"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RequestUserInformation();
 * ```
 * The code sample above starts task for requesting user information data which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RequestUserInformation")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("GOG_Friends_RequestUserInformation SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_RespondToFriendInvitation
 * @desc This function responds to the friend invitation.
 * 
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} userID The ID of the user who sent the friend invitation.
 * @param {bool} accept True when accepting the invitation, false when declining.
 * 
 * @event social
 * @member {string} type`"GOG_Friends_RespondToFriendInvitation"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {struct.GalaxyID} userID The ID of the user.
 * @member {boolean} accept true to accept invitation, false to refuse.
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RespondToFriendInvitation()
 * ```
 * The code sample above starts task for responding to a pending invitation which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RespondToFriendInvitation") 
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RespondToFriendInvitation SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_SendFriendInvitation
 * @desc This function sends a friend invitation.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_SendFriendInvitation"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {struct.GalaxyID} userID The ID of the user.
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_SendFriendInvitation(friendID);
 * ```
 * The code sample above starts a task for sending a friend invitation which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if(async_load[? "type"] == "GOG_Friends_SendFriendInvitation")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("SendFriendInvitationSUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_SendInvitation
 * @desc This function sends a game invitation without using the overlay.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} userID The ID of the user.
 * @param {string} connectionString The string which contains connection info with the limit of 4095 bytes.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RespondToFriendInvitation"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {struct.GalaxyID} userID The ID of the user.
 * @member {string} connectionString connectionString
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_SendInvitation(userID, connectionString);
 * ```
 * The code sample above starts task for sending a play invitation which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_RespondToFriendInvitation")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("SendInvitation SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_SetDefaultAvatarCriteria
 * @desc This function sets the default avatar criteria.
 * 
 * @param {real} defaultAvatarCriteria The bit sum of the default ${constant.AvatarType}.
 * 
 * @example
 * ```gml
 * GOG_Friends_SetDefaultAvatarCriteria(GOG_AVATAR_TYPE_SMALL);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Friends_SetRichPresence
 * @desc This function sets the variable value under a specified name.
 * There are three keys that can be used:
 * 
 * * `"status"` - The description visible in Galaxy Client with the limit of 3000 bytes.
 * * `"metadata"` - The metadata that describes the status to other instances of the game with the limit of 2048 bytes.
 * * `"connect"` - The string which contains connection info with the limit of 4095 bytes. It can be regarded as a passive version of ${function.GOG_Friends_SendInvitation} because it allows friends that notice the rich presence to join a multiplayer game.
 * 
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} key The name of the property of the user's rich presence (see above).
 * @param {string} value The value of the property to set.
 * 
 * @event social
 * @member {string} type `"GOG_Friends_RespondToFriendInvitation"`
 * @member {string} error Only if the request failed
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Friends_RespondToFriendInvitation();
 * ```
 * The code sample above starts task for setting the rich presence value which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Friends_SetRichPresence")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *    show_debug_message("SetRichPresence SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Friends_ShowOverlayInviteDialog
 * @desc This function shows a game invitation dialog that allows to invite users to the game.
 * 
 * [[NOTE: For this call to work, the overlay needs to be initialized first. To check whether the overlay is initialized, call ${function.GOG_Utils_GetOverlayState}.]]
 * 
 * @param {string} connectionString The string which contains connection info with the limit of 4095 bytes.
 * 
 * @example
 * ```gml
 * GOG_Friends_ShowOverlayInviteDialog(connectionString);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

// CONSTANTS

/**
 * @const PersonaState
 * @desc These constants represent the state of a user.
 * @member GOG_PERSONA_STATE_OFFLINE User is not currently logged on.
 * @member GOG_PERSONA_STATE_ONLINE User is logged on.
 * @const_end
 */

/**
 * @const AvatarType
 * @desc These constants represent the type of a user avatar. They are used as a bit mask sum in the return value of ${function.GOG_Friends_GetDefaultAvatarCriteria}.
 * @member GOG_AVATAR_TYPE_NONE No avatar type specified.
 * @member GOG_AVATAR_TYPE_SMALL Avatar resolution size: 32x32.
 * @member GOG_AVATAR_TYPE_MEDIUM Avatar resolution size: 64x64.
 * @member GOG_AVATAR_TYPE_LARGE Avatar resolution size: 184x184.
 * @const_end
 */

// STRUCTS

/**
 * @struct FriendInvitationDetails
 * @desc This struct contains details about a friend invitation.
 * 
 * @member {struct.GalaxyID} userID The ID of the user who sent the invitation.
 * @member {real} sendTime The time at which the friend invitation was sent.
 * 
 * @struct_end
 */

/**
 * @struct RichPresenceProperty
 * @desc A struct containing the property of a rich presence.
 * 
 * @member {string} key The name of the property of the user's rich presence.
 * @member {string} value The value of the property.
 * 
 * @struct_end
 */

// MODULES

/**
 * @module friends
 * @title Friends
 * @section_func Functions
 * @desc Functions related to the Friends functionality.
 * @ref GOG_Friends_ClearRichPresence
 * @ref GOG_Friends_DeleteFriend
 * @ref GOG_Friends_DeleteRichPresence
 * @ref GOG_Friends_FindUser
 * @ref GOG_Friends_GetDefaultAvatarCriteria
 * @ref GOG_Friends_GetFriendAvatarImageID
 * @ref GOG_Friends_GetFriendAvatarImageRGBA
 * @ref GOG_Friends_GetFriendAvatarUrl
 * @ref GOG_Friends_GetFriendByIndex
 * @ref GOG_Friends_GetFriendCount
 * @ref GOG_Friends_GetFriendInvitationByIndex
 * @ref GOG_Friends_GetFriendInvitationCount
 * @ref GOG_Friends_GetFriendPersonaName
 * @ref GOG_Friends_GetFriendPersonaState
 * @ref GOG_Friends_GetPersonaName
 * @ref GOG_Friends_GetPersonaState
 * @ref GOG_Friends_GetRichPresence
 * @ref GOG_Friends_GetRichPresenceByIndex
 * @ref GOG_Friends_GetRichPresenceCount
 * @ref GOG_Friends_GetRichPresenceKeyByIndex
 * @ref GOG_Friends_IsFriend
 * @ref GOG_Friends_IsFriendAvatarImageRGBAAvailable
 * @ref GOG_Friends_IsUserInformationAvailable
 * @ref GOG_Friends_IsUserInTheSameGame
 * @ref GOG_Friends_RequestFriendInvitationList
 * @ref GOG_Friends_RequestFriendList
 * @ref GOG_Friends_RequestRichPresence
 * @ref GOG_Friends_RequestSentFriendInvitationList
 * @ref GOG_Friends_RequestUserInformation
 * @ref GOG_Friends_RespondToFriendInvitation
 * @ref GOG_Friends_SendFriendInvitation
 * @ref GOG_Friends_SendInvitation
 * @ref GOG_Friends_SetDefaultAvatarCriteria
 * @ref GOG_Friends_SetRichPresence
 * @ref GOG_Friends_ShowOverlayInviteDialog
 * @section_end
 * @section_const Constants
 * @desc Constants related to the Friends functionality.
 * @ref PersonaState
 * @ref AvatarType
 * @section_end
 * @section_struct
 * @desc Structs related to the Friends functionality.
 * @ref FriendInvitationDetails
 * @ref RichPresenceProperty
 * @section_end
 * @module_end
 */
 