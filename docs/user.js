// FUNCTIONS

/**
 * @func GOG_User_DeleteUserData
 * @desc This function clears a property of user data storage.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * [[WARNING: REQUIREMENT Retrieve the user data first by calling [GOG_User_RequestUserData](#GOG_User_RequestUserData).
 * 
 * @param {string} key The name of the property of the user data storage.
 * 
 * @event social
 * @member {string} type `"GOG_User_DeleteUserData"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_DeleteUserData("weapon");
 * ```
 * The code sample above starts a task for deleting user data, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_DeleteUserData")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     show_debug_message(" DeleteUserData SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_GetAccessToken
 * @desc This function returns the access token for current session.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _accessToken = GOG_User_GetAccessToken();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_GetGalaxyID
 * @desc This function returns the ID of the user, provided that the user is signed in.
 * 
 * @returns struct (GalaxyID)
 * 
 * @example
 * ```gml
 * var _myUsedID = GOG_User_GetGalaxyID();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_GetSessionID
 * @desc This function returns the ID of current session.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _sessionID = GOG_User_GetSessionID();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_GetRefreshToken
 * @desc This function returns the refresh token for the current version.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _refreshToken = GOG_User_GetRefreshToken();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_GetUserData
 * @desc This function returns an entry from the data storage of current user.
 * 
 * [[WARNING: REQUIREMENT Retrieve the user data first by calling [GOG_User_RequestUserData](#GOG_User_RequestUserData).]]
 * 
 * @param {string} key The name of the property of the user data storage.
 * @param {GalaxyID} userID The ID of the user. It can be omitted when reading own data.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * Discord_Core_Create(appId);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_GetUserDataByIndex
 * @desc This function returns a property from the user data storage by index.
 * 
 * [[WARNING: REQUIREMENT Retrieve the user data first by calling [GOG_User_RequestUserData](#GOG_User_RequestUserData).]]
 * 
 * @param {real} index Index as an integer in the range of [0, number of entries).
 * @param {GalaxyID} userID The ID of the user. It can be omitted when reading own data.
 * 
 * @returns {struct}
 * 
 * @member {string} key The name of the property of the user data storage.
 * @member {string} value The value of the property of the user data storage.
 * 
 * @example
 * ```gml
 * for(var a = 0 ; a < GOG_User_GetUserDataCount(GOG_User_GetGalaxyID()) ; a ++ )
 *     draw_text(100, 220 + a*30, GOG_User_GetUserDataByIndex(a, GOG_User_GetGalaxyID()));
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_GetUserDataCount
 * @desc This function returns the number of entries in the user data storage.
 * 
 * [[WARNING: REQUIREMENT Retrieve the user data first by calling [GOG_User_RequestUserData](#GOG_User_RequestUserData).]]
 * 
 * @param {GalaxyID} userID The ID of the user. It can be omitted when reading own data.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var a = 0 ; a < GOG_User_GetUserDataCount(GOG_User_GetGalaxyID()) ; a ++ )
 *     draw_text(100, 220 + a*30, GOG_User_GetUserDataByIndex(a, GOG_User_GetGalaxyID()));
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_IsLoggedOn
 * @desc This function checks if the user is logged on to Galaxy backend services.
 * 
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if(GOG_User_IsLoggedOn())
 * {
 *    //User is logged, do something...
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_IsUserDataAvailable
 * @desc This function checks if user data exists.
 * 
 * [[warning: REQUIREMENT Retrieve the user data first by calling [GOG_User_RequestUserData](#GOG_User_RequestUserData).]]
 * 
 * @param {GalaxyID} userID The ID of the user. It can be omitted when reading own data.
 * 
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if(GOG_User_IsUserDataAvailable())
 * {
 *    //User data is available, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_ReportInvalidAccessToken
 * @desc This function reports the current access token as no longer working.
 * 
 * @param {string} accessToken The invalid access token.
 * @param {string} info Additional information.
 * 
 * @example
 * ```gml
 * GOG_User_ReportInvalidAccessToken(accessToken, "A hacker wanna be...");
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_User_RequestUserData
 * @desc This function retrieves/refreshes user data storage.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {GalaxyID} userID The ID of the user. It can be omitted when reading own data.
 * 
 * @event social
 * @member {string} type `"GOG_User_RequestUserData"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_RequestUserData("BestScoresLeaderboard");
 * ```
 * The code sample above starts a task for requesting user data, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_RequestUserData")
 * {
 *     show_debug_message("RequestUserData SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SetUserData
 * @desc This function creates or updates an entry in the user data storage.
 * 
 * [[WARNING: REQUIREMENT Retrieve the user data first by calling [GOG_User_RequestUserData](#GOG_User_RequestUserData).]]
 * 
 * @param {string} key The name of the property of the user data storage with the limit of 1023 bytes.
 * @param {string} value The value of the property to set with the limit of 4095 bytes.
 * 
 * @event social
 * @member {string} type `"GOG_User_SetUserData"`
 * @member {GalaxyID} userID The ID of the user.
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SetUserData("weapon", "sword");
 * ```
 * The code sample above starts a task for setting user data, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SetUserData")
 * {
 *     show_debug_message("User data was set for user {0}", async_load[? "userID"]);
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignedIn
 * @desc This function checks if the user is signed in to Galaxy.
 * The user should be reported as signed in as soon as the authentication process is finished.
 * If the user is not able to sign in or gets signed out, there might be either a networking issue or a limited availability of Galaxy backend services.
 * After loosing authentication the user needs to sign in again in order for the Galaxy Peer to operate.
 * 
 * @returns {bool}
 * 
 * @example
 * ```gml
 * if(GOG_User_SignedIn())
 * {
 *    //user signed in, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 @func GOG_User_SignInAnonymous
 @desc This function authenticates the Galaxy Game Server anonymously.
 This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 
 @event social
 @member {string} type `"GOG_User_SignInAnonymous"`
 @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 @event_end
 
 @example
 ```gml
 GOG_User_SignInAnonymous();
 ```
 The code sample above starts a task for signing in anonymously, which results can be caught inside a ${event.social}.
 
 ```gml
 if (async_load[? "type"] == "GOG_User_SignInAnonymous")
 {
     if (ds_map_exists(async_load, "error"))
     {
         show_debug_message(async_load[?"error"]);
         exit;
     }
 
     show_debug_message(" SignInAnonymous SUCCESS");
 }
 ```
 This code sample provides an example of handling the returned callback data.
 @func_end
 */

/**
 * @func GOG_User_SignInAnonymousTelemetry
 * @desc This function authenticates the Galaxy Peer anonymously.
 * This authentication method enables the peer to send anonymous telemetry events.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_User_SignInAnonymousTelemetry"`
 * @member {string} error The error message; only if the request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SignInAnonymousTelemetry();
 * ```
 * The code sample above starts a task for signing in anonymously (with anonymous telemetry), which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SignInAnonymousTelemetry")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"])
 *         exit
 *     }
 * 
 *     show_debug_message(" SignInAnonymousTelemetry SUCCESS")
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignInCredentials
 * @desc This function authenticates the Galaxy Peer with specified user credentials.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} login The user's login.
 * @param {string} password The user's password.
 * 
 * @event social
 * @member {string} type`"GOG_User_SignInCredentials"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SignInServerKey(refreshToken);
 * ```
 * The code sample above starts a task for signing in with credentials, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SignInCredentials")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("SignInToken SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignInGalaxy
 * @desc This function authenticates the Galaxy Peer based on Galaxy Client authentication.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {boolean} requireOnline Indicates if sing in with Galaxy backend is required.
 * 
 * @event social
 * @member {string} type `"GOG_User_SignInGalaxy"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SignInGalaxy();
 * ```
 * The code sample above starts a task for signing in with galaxy client authentication, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SignInGalaxy")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message(" SignInGalaxy SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignInLauncher
 * @desc This function authenticates the Galaxy Peer based on launcher authentication.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_User_SignInLauncher"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SignInLauncher();
 * ```
 * The code sample above starts a task for signing in with launcher authentication, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SignInLauncher")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("SignInLauncher SUCCESS");
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignInServerKey
 * @desc This function authenticates the Galaxy Peer with a specified server key.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} key The server key.
 * 
 * @event social
 * @member {string} type `"GOG_User_SignInServerKey"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SignInServerKey(key);
 * ```
 * The code sample above starts a task for signing in using a server key, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SignInServerKey")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("SignInServerKey SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignInToken
 * @desc This function authenticates the Galaxy Peer with refresh token.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} refreshToken The refresh token obtained from Galaxy login page.
 * 
 * @event social
 * @member {string} type "GOG_User_SignInToken"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_User_SignInServerKey(refreshToken);
 * ```
 * The code sample above starts a task for signing in using a refresh token, which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_User_SignInToken")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("SignInToken SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_User_SignOut
 * @desc This function signs the Galaxy Peer out.
 * 
 * @example
 * ```gml
 * GOG_User_SignOut();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
@struct GalaxyID
 * @desc This structure represents a GOG ID (User or Lobby) and is used all across the GOG API as either a return value or function argument.
 * 
 * [[WARNING: These values shouldn't be used or changed and are to be passed back into the extension to perform the desired actions.]]
 * 
 * @param {real} ID The real ID value.
 * @param {real} IDType The type of the ID.
 * @struct_end
 */

/**
 * @module user
 * @title User
 * @desc This is a module for handling the user account.
 * @section_func
 * @ref GOG_User_DeleteUserData
 * @ref GOG_User_GetAccessToken
 * @ref GOG_User_GetGalaxyID
 * @ref GOG_User_GetRefreshToken
 * @ref GOG_User_GetSessionID
 * @ref GOG_User_GetUserData
 * @ref GOG_User_GetUserDataByIndex
 * @ref GOG_User_GetUserDataCount
 * @ref GOG_User_IsLoggedOn
 * @ref GOG_User_IsUserDataAvailable
 * @ref GOG_User_ReportInvalidAccessToken
 * @ref GOG_User_RequestUserData
 * @ref GOG_User_SetUserData
 * @ref GOG_User_SignedIn
 * @ref GOG_User_SignInAnonymous
 * @ref GOG_User_SignInAnonymousTelemetry
 * @ref GOG_User_SignInCredentials
 * @ref GOG_User_SignInGalaxy
 * @ref GOG_User_SignInLauncher
 * @ref GOG_User_SignInServerKey
 * @ref GOG_User_SignInToken
 * @ref GOG_User_SignOut
 * @section_end
 * @section_struct
 * @ref GalaxyID
 * @section_end
 * @module_end
*/
