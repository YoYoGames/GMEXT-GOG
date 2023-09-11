// FUNCTIONS

/**
 * @function GOG_Stats_ClearAchievement
 * @desc This function clears an achievement.
 * 
 * [[NOTE: In order to make this and other changes persistent, call [GOG_Stats_StoreStatsAndAchievements](#GOG_Stats_StoreStatsAndAchievements).]]
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the achievement.
 * 
 * @example
 * ```gml
 * GOG_Stats_ClearAchievement("100kills");
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_FindLeaderboard
 * @desc This function performs a request for the definition of a specified leaderboard.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * @param {string} name The name of the leaderboard.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_FindLeaderboard"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} name Name of the leaderboard
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_FindLeaderboard("BestScoresLeaderboard")
 * ```
 * The code sample above starts a task for finding a leaderboard which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_FindLeaderboard")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     var _name = async_load[?"name"];
 *     show_debug_message(" FindLeaderboard SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_FindOrCreateLeaderboard
 * @desc This function performs a request for definition of a specified leaderboard, creating it if there is no such leaderboard yet.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {string} name The name of the leaderboard.
 * @param {string} displayName The display name of the leaderboard.
 * @param {struct.LeaderboardSortMethod} sortMethod The sort method of the leaderboard.
 * @param {struct.LeaderboardDisplayType} displayType The display method of the leaderboard.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_FindOrCreateLeaderboard"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} name Name of the leaderboard
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_FindOrCreateLeaderboard("BestScoresLeaderboard");
 * ```
 * The code sample above starts a task for finding or creating a leaderboard which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_FindOrCreateLeaderboard")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     var _name = async_load[?"name"];
 *     show_debug_message(" FindOrCreateLeaderboard SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_GetAchievement
 * @desc Reads the state of an achievement of a specified user.
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the achievement.
 * 
 * @returns {struct.UnlockedInfo}
 * 
 * @example
 * ```gml
 * var _struct = GOG_Stats_GetAchievement("100kills");
 * var _unlocked = _struct.unlocked;
 * if(_unlocked)
 * {
 *     unlockTime = _struct.unlockTime;
 *     //Achievement unlocked, do something....
 * }
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetAchievementDescription
 * @desc This function returns the description of a specified achievement.
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The name of the achievement.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _description = GOG_Stats_GetAchievementDescription("100kills");
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetAchievementDisplayName
 * @desc This function returns the display name of a specified achievement.
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The name of the achievement.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _displayName = GOG_Stats_GetAchievementDisplayName("100kills");
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetLeaderboardDisplayName
 * @desc This function returns the display name of a specified leaderboard.
 * 
 * [[WARNING: REQUIREMENT Retrieve definition of this particular leaderboard first by calling either  [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).]]
 * 
 * @param {string} name The name of the leaderboard.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _displayName = GOG_Stats_GetLeaderboardDisplayName("100kills");
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetLeaderboardDisplayType
 * @desc This function returns the display type of a specified leaderboard.
 * 
 * [[WARNING: REQUIREMENT Retrieve the definition of this particular leaderboard first by calling either  [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).]]
 * 
 * @param {string} name The name of the leaderboard.
 * 
 * @returns {struct.LeaderboardDisplayType}
 * 
 * @example
 * ```gml
 * var _displayType = GOG_Stats_GetLeaderboardDisplayType(name);
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetLeaderboardEntryCount
 * @desc This function returns the leaderboard entry count for the requested leaderboard.
 * 
 * [[WARNING: REQUIREMENT In order to retrieve the leaderboard entry count, first you need to call [GOG_Stats_RequestLeaderboardEntriesGlobal](#GOG_Stats_RequestLeaderboardEntriesGlobal).]]
 * 
 * @param {string} name The name of the leaderboard.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = GOG_Stats_GetLeaderboardEntryCount(name);
 * ```
 * The code above provides a simple usage example.
 * @function_end*/

/**
 * @function GOG_Stats_GetLeaderboardSortMethod
 * @desc This function returns the sort method of a specified leaderboard.
 * 
 * [[WARNING: REQUIREMENT Retrieve definition of this particular leaderboard first by calling either  [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).]]
 * 
 * @param {string} name The name of the leaderboard.
 * 
 * @returns {struct.LeaderboardSortMethod}
 * 
 * @example
 * ```gml
 * GOG_Stats_GetLeaderboardSortMethod(name);
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetStatFloat
 * @desc This function reads a floating point value of a statistic of a specified user.
 * 
 * [[WARNING: REQUIREMENT Retrieve the statistics first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the statistic.
 * @param {struct.GalaxyID} userID The ID of the user. It can be omitted when requesting for own data.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _value = GOG_Stats_GetStatFloat(nameStat, GOG_User_GetGalaxyID());
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetStatInt
 * @desc This function reads an integer value of a statistic of a specified user.
 * 
 * [[WARNING: REQUIREMENT Retrieve the statistics first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the statistic.
 * @param {struct.GalaxyID} userID The ID of the user. It can be omitted when requesting for own data.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _value = GOG_Stats_GetStatInt(name, GOG_User_GetGalaxyID());
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_GetUserTimePlayed
 * @desc This function reads the number of seconds played by a specified user.
 * 
 * [[WARNING: REQUIREMENT Retrieve the statistics first by calling [GOG_Stats_RequestUserTimePlayed](#GOG_Stats_RequestUserTimePlayed).]]
 * 
 * @param {struct.GalaxyID} userID The ID of the user. It can be omitted when requesting for own data.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * GOG_Stats_GetUserTimePlayed(GOG_User_GetGalaxyID());
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_IsAchievementVisible
 * @desc This function returns the visibility status of a specified achievement.
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The name of the achievement.
 * 
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if(GOG_Stats_IsAchievementVisible(name))
 * {
 *     //Achievement is visible, do something...
 * }
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_IsAchievementVisibleWhileLocked
 * @desc This function returns the visibility status of a specified achievement before unlocking.
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The name of the achievement.
 * 
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if(GOG_Stats_IsAchievementVisibleWhileLocked(appId))
 * {
 *     //Achievement visible while locked
 * }
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_RequestLeaderboardEntriesAroundUser
 * @desc This function performs a request for entries of a specified leaderboard for and near the specified user.
 * The specified numbers of entries before and after the specified user are treated as hints. If the requested range would go beyond the set of all leaderboard entries, it is shifted so that it fits in the set of all leaderboard entries and preserves its size if possible.
 * 
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * > **:warning: REQUIREMENT**
 * >
 * > Retrieve the definition of this particular leaderboard first by calling either [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).
 * 
 * @param {string} name The name of the leaderboard.
 * @param {real} countBefore The number of entries placed before the user's entry to retrieve (hint).
 * @param {real} countAfter The number of entries placed after the user's entry to retrieve (hint).
 * 
 * @event social
 * @member {string} type `"GOG_Stats_RequestLeaderboardEntriesAroundUser"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} name The name of the leaderboard being queried; only if request succeeded :eight_pointed_black_star: OPTIONAL
 * @member {real} entryCount The number of retrieved entries; only if request succeeded :eight_pointed_black_star: OPTIONAL
 * @member {array[struct.LeaderboardEntry]} entries An array of LeaderboardEntry data for for each queried entry; only if request succeeded :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_RequestLeaderboardEntriesAroundUser("NearScores", 1, 10);
 * ```
 * The code sample above starts a task that requests leaderboard entries around user which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_RequestLeaderboardEntriesAroundUser")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("DeleteRichPresence SUCCESS");
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_RequestLeaderboardEntriesGlobal
 * @desc This function performs a request for entries of a specified leaderboard in a global scope, i.e. without any specific users in the scope of interest.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * [[WARNING: REQUIREMENT Retrieve definition of this particular leaderboard first by calling either [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).]]
 * 
 * @param {real} name The name of the leaderboard.
 * @param {real} rangeStart The index position of the entry to start with.
 * @param {string} rangeEnd The index position of the entry to finish with.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_RequestLeaderboardEntriesGlobal"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} name The name of the leaderboard being queried; only if request succeeded :eight_pointed_black_star: OPTIONAL
 * @member {real} entryCount The number of retrieved entries; only if request succeeded :eight_pointed_black_star: OPTIONAL
 * @member {array[struct.LeaderboardEntry]} entries An array of LeaderboardEntry data for each queried entry; only if request succeeded :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_RequestLeaderboardEntriesGlobal("BestScores", 1, 10);
 * ```
 * The code sample above starts a task that requests global leadboard entries which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_RequestLeaderboardEntriesGlobal")
 * {
 *     if (ds_map_exists(async_load,"error"))
 *     {
 *         show_debug_message(async_load[?"error"])
 *         exit
 *     }
 * 
 *     show_debug_message("DeleteRichPresence SUCCESS")
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_RequestLeaderboards
 * @desc Performs a request for definitions of leaderboards.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_RequestLeaderboards"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_RequestLeaderboards();
 * ```
 * The code sample above starts a task that requests all leadboard definitions which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_RequestLeaderboards")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RequestLeaderboards SUCCESS");
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_RequestUserStatsAndAchievements
 * @desc Performs a request for statistics and achievements of a specified user.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} The ID of the user. It can be omitted when requesting for own data.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_RequestUserStatsAndAchievements"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_RequestUserStatsAndAchievements(GOG_User_GetGalaxyID());
 * ```
 * The code sample above starts a task that requests data for stats and achievements which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_RequestUserStatsAndAchievements ")
 * {
 *     if (ds_map_exists(async_load, "error"));
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     show_debug_message("RequestUserStatsAndAchievements SUCCESS");
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_RequestUserTimePlayed
 * @desc This function performs a request for user time played.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * @param {struct.GalaxyID} userID The ID of the user. It can be omitted when requesting for own data.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_RequestUserTimePlayed"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_RequestUserTimePlayed (GOG_User_GetGalaxyID())
 * ```
 * The code sample above starts a task that requests user&#39;s play time and which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_RequestUserTimePlayed ")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     var _userID = async_load[?"userID"];
 *     show_debug_message(" RequestUserTimePlayed SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_ResetStatsAndAchievements
 * @desc This function resets all statistics and achievements.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * [[NOTE: This is the same as setting statistics and achievements to their initial values and calling [GOG_Stats_StoreStatsAndAchievements](#GOG_Stats_StoreStatsAndAchievements).]]
 * 
 * @event social
 * @member {string} type `"GOG_Stats_ResetStatsAndAchievements "`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_ResetStatsAndAchievements();
 * ```
 * The code sample above starts a task for resetting stats and achievements and which results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_ResetStatsAndAchievements ")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     show_debug_message("ResetStatsAndAchievements     SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_SetAchievement
 * @desc This function unlocks an achievement.
 * 
 * [[NOTE: In order to make this and other changes persistent, call [GOG_Stats_StoreStatsAndAchievements](#GOG_Stats_StoreStatsAndAchievements).]]
 * 
 * [[WARNING: REQUIREMENT Retrieve the achievements first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param name|string|The code name of the achievement.
 * 
 * @example
 * ```gml
 * GOG_Stats_SetAchievement("100kills");
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_SetLeaderboardScore
 * @desc This function updates the entry for own user in a specified leaderboard.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 *
 * [[WARNING: REQUIREMENT Retrieve definition of this particular leaderboard first by calling either [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).]]
 * 
 * [[NOTE: For this call to work while the user is logged off, the definition of the leaderboard must have been retrieved at least once while the user was logged on.]]
 * 
 * 
 * @param {string} name The name of the leaderboard.
 * @param {real} score The score to set.
 * @param {boolean} forceUpdate If the update should be performed in case the score is worse than the previous score.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_SetLeaderboardScore "`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} name The name of the Leaderboard
 * @member {real} score The score submitted
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_SetLeaderboardScore ("BestScores", 992, false);
 * ```
 * The code sample above starts a task for updating the score of a given leaderboard, of which the results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_SetLeaderboardScore ")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     show_debug_message("SetLeaderboardScore           SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_SetLeaderboardScoreWithDetails
 * @desc This function updates entry with details for own user in a specified leaderboard.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * [[WARNING: REQUIREMENT Retrieve the definition of this particular leaderboard first by calling either [GOG_Stats_FindLeaderboard](#GOG_Stats_FindLeaderboard)  or [GOG_Stats_FindOrCreateLeaderboard](#GOG_Stats_FindOrCreateLeaderboard), or definitions of all existing leaderboards by calling [GOG_Stats_RequestLeaderboards](#GOG_Stats_RequestLeaderboards).]]
 * 
 * [[ NOTE: For this call to work while the user is logged off, the definition of the leaderboard must have been retrieved at least once while the user was logged on.]]
 * 
 * @param {string} name The name of the leaderboard.
 * @param {real} score The score to set.
 * @param {boolean} forceUpdate If the update should be performed in case the score is worse than the previous score.
 * @param {type.buffer} details An extra game-defined information regarding how the user got that score with the limit of 3071 bytes.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_SetLeaderboardScore "`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} name The name of the Leaderboard
 * @member {real} score The score submitted
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_SetLeaderboardScore ("BestScores", 992, false);
 * ```
 * The code sample above starts a task for updating the score (with extra details) of a given leaderboard, of which the results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_SetLeaderboardScore ")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     show_debug_message("SetLeaderboardScore           SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_SetStatFloat
 * @desc This function updates a statistic with a floating point value.
 * 
 * [[ NOTE: In order to make this and other changes persistent, call [GOG_Stats_StoreStatsAndAchievements](#GOG_Stats_StoreStatsAndAchievements).]]
 * 
 * [[ WARNING: REQUIREMENT Retrieve the statistics first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the statistic.
 * @param {real} value The value of the statistic to set.
 * 
 * @example
 * ```gml
 * GOG_Stats_SetStatFloat("speed", 12.2);
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_SetStatInt
 * @desc This function updates a statistic with an integer value.
 * 
 * [[NOTE: In order to make this and other changes persistent, call [GOG_Stats_StoreStatsAndAchievements](#GOG_Stats_StoreStatsAndAchievements).]]
 * 
 * [[WARNING: REQUIREMENT Retrieve the statistics first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the statistic.
 * @param {real} value The value of the statistic to set.
 * 
 * @example
 * ```gml
 * GOG_Stats_SetStatInt("attack", 100);
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

/**
 * @function GOG_Stats_StoreStatsAndAchievements
 * @desc This function persists all changes in statistics and achievements.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @event social
 * @member {string} type `"GOG_Stats_StoreStatsAndAchievements    "`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Stats_StoreStatsAndAchievements();
 * ```
 * The code sample above starts a task to store stats and achievements data. The results can be caught inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Stats_StoreStatsAndAchievements  ")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 *     var _userID = async_load[?"userID"];
 *     show_debug_message(" StoreStatsAndAchievements     SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @function_end
 */

/**
 * @function GOG_Stats_UpdateAvgRateStat
 * @desc This function updates an average-rate statistic with a delta.
 * 
 * [[WARNING: REQUIREMENT Retrieve the statistics first by calling [GOG_Stats_RequestUserStatsAndAchievements](#GOG_Stats_RequestUserStatsAndAchievements).]]
 * 
 * @param {string} name The code name of the statistic.
 * @param {real} countThisSession The delta of the count.
 * @param {real} sessionLenght The delta of the session.
 * 
 * @example
 * ```gml
 * GOG_Stats_UpdateAvgRateStat("coins", 100, 1000);
 * ```
 * The code above provides a simple usage example.
 * @function_end
 */

// CONST

/**
 * @struct LeaderboardEntry
 * @desc A leaderboard entry struct's members.
 * [[NOTE: The data member of this struct will be base64 encoded and so you will need to use the function ${function.buffer_base64_decode} on the data before reading from the buffer.]]
 * @member {real} rank The rank of the entry on the specified leaderboard
 * @member {string} data The base64 encoded string with the data provided when uploading scores
 * @member {real} score The score attributed to this entry
 * @member {struct.GalaxyID} userID The unique user id of the player for this entry
 * @struct_end
 */

/**
 * @struct struct.UnlockedInfo
 * @desc This structure represents unlocked info about an achievement.
 * 
 * @member {boolean} unlocked Indicates if the achievement has been unlocked.
 * @member {real} unlockedTime The time at which the achievement was unlocked.
 * @struct_end
 */

/**
 * @const LeaderboardDisplayType
 * @desc These constants represent the display type of the leaderboard data.
 * @member GOG_LEADERBOARD_DISPLAY_TYPE_NONE No display type specified.
 * @member GOG_LEADERBOARD_DISPLAY_TYPE_NUMBER Simple numerical score.
 * @member GOG_LEADERBOARD_DISPLAY_TYPE_TIME_SECONDS The score represents time, in seconds.
 * @member GOG_LEADERBOARD_DISPLAY_TYPE_TIME_MILLISECONDS The score represents time, in milliseconds.
 * @const_end
 */

/**
 * @const LeaderboardSortMethod
 * @desc These constants represent the method used to sort scores within a leaderboard.
 * @member GOG_LEADERBOARD_SORT_METHOD_NONE No sorting method specified.
 * @member GOG_LEADERBOARD_SORT_METHOD_ASCENDING Top score is lowest number.
 * @member GOG_LEADERBOARD_SORT_METHOD_DESCENDING Top score is highest number.
 * @const_end
 */

// MODULES
