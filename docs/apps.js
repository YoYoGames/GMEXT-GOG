// FUNCTIONS

/**
 * @func GOG_Apps_GetCurrentGameLanguage
 * @desc This function returns the current game language for the given product ID.
 * @param {type.int64} productID The ID of the game or DLC to check.
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _language = GOG_Apps_GetCurrentGameLanguage(productID);
 * ```
 * The code sample above will return the current game language for the provided product identifier.
 * @func_end
 */

/**
 * @func GOG_Apps_IsDlcInstalled
 * @desc This function checks if the specified DLC is installed.
 * @param {type.int64} productID 	The ID of the DLC to check.
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if(GOG_Apps_IsDlcInstalled(productID))
 * {
 *     //Do something with this DLC
 * }
 * ```
 * The code sample above will check if a given DLC is installed. The developer can then decide what should be done if it is.
 * @func_end
 */

// MODULES
/**
 * @module apps
 * @title Apps
 * @desc This a module that manages application activities.
 * 
 * @section_func
 * @desc The following functions are provided to interact with this module:
 * @ref GOG_Apps_GetCurrentGameLanguage
 * @ref GOG_Apps_IsDlcInstalled
 * @section_end
 * 
 * @module_end
 */