// FUNCTIONS

/**
 * @func GOG_Storage_DownloadSharedFile
 * @desc This function downloads a previously shared file.
 * This is an asynchronous function that will trigger a ${event.social} when the task is finished.
 * 
 * @param {int64} sharedFileID The ID of the shared file.
 * 
 * @event social
 * @member {string} type `"GOG_Storage_DownloadSharedFile"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} sharedFileID The ID of the shared file.
 * @member {string} fileName Name of the shared file
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Storage_DownloadSharedFile(sharedFileID);
 * ```
 * The code sample above starts a task for download a shared file, which results can be caught inside a ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Storage_DownloadSharedFile")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     var _sharedFileID = async_load[?"sharedFileID"];
 *     var _fileName = async_load[?"fileName"];
 * 
 *     show_debug_message("DownloadSharedFile SUCCESS");
 * }
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Storage_FileDelete
 * @desc This function deletes the given file.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * 
 * @param {string} fileName The name of the file in the form of a path
 * 
 * @example
 * ```gml
 * GOG_Storage_FileDelete(fileName);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_FileExists
 * @desc This function returns if the given file exists.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * 
 * @param {string} fileName The name of the file in the form of a path
 * 
 * @returns {boolean}
 * 
 * @example
 * ```gml
 * if(GOG_Storage_FileExists(fileName))
 * {
 *    //File exists, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_FileRead
 * @desc This function reads file content into the buffer.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * [[WARNING This function creates a new buffer everytime it is called you need to ensure you correctly delete the buffer when you don&#39;t need it anymore using the ${function.buffer_delete} function. Failing to do so will result in memory leaks.]]
 * 
 * @param {string} fileName The name of the file in the form of a path
 * 
 * @returns {type.buffer}
 * 
 * @example
 * ```gml
 * var _buffer = GOG_Storage_FileRead(fileName);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_FileShare
 * @desc This function uploads the file for sharing.
 * This is an asynchronous function that will trigger the a ${event.social} when the task is finished.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * 
 * @param {string} fileName The name of the file in the form of a path
 * 
 * @event social
 * @member {string} type `"GOG_Storage_FileShare"`
 * @member {string} error The error message; only if request failed :eight_pointed_black_star: OPTIONAL
 * @member {string} sharedFileID The ID of the shared file.
 * @member {string} fileName Name of the shared file
 * @event_end
 * 
 * @example
 * ```gml
 * GOG_Storage_FileShare(fileName);
 * ```
 * The code sample above starts a task for sharing a file, which results can be caught inside a ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "GOG_Storage_FileShare")
 * {
 *     if (ds_map_exists(async_load, "error"))
 *     {
 *         show_debug_message(async_load[?"error"]);
 *         exit;
 *     }
 * 
 *     var _sharedFileID = async_load[?"sharedFileID"];
 *     var _fileName = async_load[?"fileName"];
 * 
 *     show_debug_message("FileShare SUCCESS");
 * }
 * 
 * ```
 * This code sample provides an example of handling the returned callback data.
 * @func_end
 */

/**
 * @func GOG_Storage_FileWrite
 * @desc This function writes data into the file.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * 
 * [[NOTE: The files created using this method will be stored in GOG Galaxy internal directory and should be accessed only via Galaxy SDK methods.]]
 * 
 * @param {string} fileName Name of the file
 * @param {type.buffer} buffer Buffer with data
 * 
 * @example
 * ```gml
 * GOG_Storage_FileWrite(fileName, buffer);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetDownloadedSharedFileByIndex
 * @desc This function returns the ID of the open downloaded shared file.
 * 
 * @param {real} index Index as an integer in the range of [0, number of open downloaded shared files)].
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GetDownloadedSharedFileCount() ; i++)
 * {
 *    var _sharedFileID= GOG_Storage_GetDownloadedSharedFileByIndex(index);
 *    var _fileName = GOG_Storage_GetSharedFileName(sharedFileID);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(sharedFileID);
 *    var _owner = GOG_Storage_GetSharedFileOwner(sharedFileID);
 *    var _buffer = GOG_Storage_SharedFileRead(sharedFileID);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetDownloadedSharedFileCount
 * @desc This function returns the number of open downloaded shared files.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GetDownloadedSharedFileCount() ; i++)
 * {
 *    var _sharedFileID= GOG_Storage_GetDownloadedSharedFileByIndex(index);
 *    var _fileName = GOG_Storage_GetSharedFileName(sharedFileID);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(sharedFileID);
 *    var _owner = GOG_Storage_GetSharedFileOwner(sharedFileID);
 *    var _buffer = GOG_Storage_SharedFileRead(sharedFileID);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetFileCount
 * @desc This function returns the number of files in the storage.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(i = 0 ; i < GOG_Storage_GetFileCount() ; i++)
 * {
 *    var _filename = GOG_Storage_GetFileNameByIndex(i);
 *    var _fileSize = GOG_Storage_GetFileSize(filename);
 *    var _fileTimestamp = GOG_Storage_GetFileTimestamp(filename);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(filename);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetFileNameByIndex
 * @desc This function returns the name of the file.
 * 
 * @param {real} index The index as an integer in the range of [0, number of files)].
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * for(i = 0 ; i < GOG_Storage_GetFileCount() ; i++)
 * {
 *    var _filename = GOG_Storage_GetFileNameByIndex(i);
 *    var _fileSize = GOG_Storage_GetFileSize(filename);
 *    var _fileTimestamp = GOG_Storage_GetFileTimestamp(filename);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(filename);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetFileSize
 * @desc This function returns the size of the file.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * 
 * @param {string} filename The name of the file in the form of a path.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(i = 0 ; i < GOG_Storage_GetFileCount() ; i++)
 * {
 *    var _filename = GOG_Storage_GetFileNameByIndex(i);
 *    var _fileSize = GOG_Storage_GetFileSize(filename);
 *    var _fileTimestamp = GOG_Storage_GetFileTimestamp(filename);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(filename);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetFileTimestamp
 * @desc This function returns the timestamp of the last file modification.
 * 
 * [[WARNING: REQUIREMENT The name that specifies the file has to be provided in the form of a relative path that uses slashes as separators. Every part of the path must not refer to any special or restricted name on any of the supported platforms. Backslashes are not allowed.]]
 * 
 * @param {string} filename The name of the file in the form of a path.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(i = 0 ; i < GOG_Storage_GetFileCount() ; i++)
 * {
 *    var _filename = GOG_Storage_GetFileNameByIndex(i);
 *    var _fileSize = GOG_Storage_GetFileSize(filename);
 *    var _fileTimestamp = GOG_Storage_GetFileTimestamp(filename);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(filename);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetSharedFileName
 * @desc This function gets the name of a downloaded shared file.
 * 
 * @param {string} sharedFileID The ID of the shared file.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GetDownloadedSharedFileCount() ; i++)
 * {
 *    var _sharedFileID = GOG_Storage_GetDownloadedSharedFileByIndex(index);
 *    var _fileName = GOG_Storage_GetSharedFileName(sharedFileID);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(sharedFileID);
 *    var _owner = GOG_Storage_GetSharedFileOwner(sharedFileID);
 *    var _buffer = GOG_Storage_SharedFileRead(sharedFileID);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetSharedFileOwner
 * @desc This function gets the owner ${struct.GalaxyID} of a downloaded shared file.
 * 
 * @param {int64} sharedFileID The ID of the shared file.
 * 
 * @returns struct (GalaxyID)
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GetDownloadedSharedFileCount() ; i++)
 * {
 *    var _sharedFileID = GOG_Storage_GetDownloadedSharedFileByIndex(index);
 *    var _fileName = GOG_Storage_GetSharedFileName(sharedFileID);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(sharedFileID);
 *    var _owner = GOG_Storage_GetSharedFileOwner(sharedFileID);
 *    var _buffer = GOG_Storage_SharedFileRead(sharedFileID);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_GetSharedFileSize
 * @desc This function gets the size of a downloaded shared file.
 * 
 * @param {int64} sharedFileID The ID of the shared file.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GetDownloadedSharedFileCount() ; i++)
 * {
 *    var _sharedFileID = GOG_Storage_GetDownloadedSharedFileByIndex(index);
 *    var _fileName = GOG_Storage_GetSharedFileName(sharedFileID);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(sharedFileID);
 *    var _owner = GOG_Storage_GetSharedFileOwner(sharedFileID);
 *    var _buffer = GOG_Storage_SharedFileRead(sharedFileID);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_SharedFileClose
 * @desc This function closes the given downloaded shared file and frees the memory.
 * 
 * @param {int64} sharedFileID The ID of the shared file.
 * 
 * @example
 * ```gml
 * GOG_Storage_SharedFileClose(sharedFileID);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Storage_SharedFileRead
 * @desc This function reads the given downloaded shared file's contents into the buffer.
 * 
 * [[WARNING: This function creates a new buffer everytime it is called you need to ensure you correctly delete the buffer when you don't need it anymore using the ${function.buffer_delete} function. Failing to do so will result in memory leaks.]]
 * 
 * @param {int64} sharedFileID The ID of the shared file.
 * 
 * @returns {type.buffer}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < GetDownloadedSharedFileCount() ; i++)
 * {
 *    var _sharedFileID = GOG_Storage_GetDownloadedSharedFileByIndex(index);
 *    var _fileName = GOG_Storage_GetSharedFileName(sharedFileID);
 *    var _fileSize = GOG_Storage_GetSharedFileSize(sharedFileID);
 *    var _owner = GOG_Storage_GetSharedFileOwner(sharedFileID);
 *    var _buffer = GOG_Storage_SharedFileRead(sharedFileID);
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @module storage
 * @title Storage
 * @desc This is a module for managing of cloud storage files.
 * @section_func
 * @ref GOG_Storage_DownloadSharedFile
 * @ref GOG_Storage_FileDelete
 * @ref GOG_Storage_FileExists
 * @ref GOG_Storage_FileRead
 * @ref GOG_Storage_FileShare
 * @ref GOG_Storage_FileWrite
 * @ref GOG_Storage_GetDownloadedSharedFileByIndex
 * @ref GOG_Storage_GetDownloadedSharedFileCount
 * @ref GOG_Storage_GetFileCount
 * @ref GOG_Storage_GetFileNameByIndex
 * @ref GOG_Storage_GetFileSize
 * @ref GOG_Storage_GetFileTimestamp
 * @ref GOG_Storage_GetSharedFileName
 * @ref GOG_Storage_GetSharedFileOwner
 * @ref GOG_Storage_GetSharedFileSize
 * @ref GOG_Storage_SharedFileClose
 * @ref GOG_Storage_SharedFileRead
 * @section_end
 * @module_end
 */