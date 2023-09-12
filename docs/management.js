// FUNCTIONS

/**
 * @func GOG_GetError
 * @desc This function retrieves the error connected with the last API call on the local thread.
 * 
 * [[NOTE: If there was no error the return struct will be empty.]]
 * @returns {struct.Error}
 *
 * @example 
 * ```gml
 * var error = GOG_GetError();
 * if (variable_struct_names_count(error) != 0)
 * {
 *     var _type = error.Type;
 *     var _message = error.Msg;
 *     var _name = error.Name;
 * }
 * ```
 * The code above provides a simple usage example.
 * 
 * @func_end
 */

/**
 * @func GOG_ProcessData
 * @desc This function should be called each frame while the GOG extension is active. It's recommended to use a persistent Controller object that is created or placed in the first room and this call is in the ${event.step}.
 * 
 * @example 
 * ```gml
 * GOG_ProcessData();
 * ```
 * The code above provides a simple usage example.
 * 
 * @func_end
 */

// STRUCTS

/**
 * @struct Error
 * @description A struct containing error information
 * 
 * @member {real} Type The type of the error.
 * @member {string} Msg The error message.
 * @member {string} Name The name of the error.
 * 
 * @struct_end
 */

// MODULES

/**
 * @module management
 * @title Management
 * @desc This a module that contains a couple of general management functions.
 * 
 * @section_func
 * @desc The following functions are provided:
 * @ref GOG_GetError
 * @ref GOG_ProcessData
 * @section_end
 * 
 * @section_struct
 * @desc The following structs can be used: 
 * @ref Error
 * @section_end
 * 
 * @module_end
 */
