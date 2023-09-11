// FUNCTIONS

/**
 * @func GOG_Utils_DisableOverlayPopups
 * @desc This function disables overlay pop-up notifications.
 * It hides overlay pop-up notifications based on the group specified below:
 * 
 * * `"chat_message"` - New chat messages received.
 * * `"friend_invitation"` - Friend request received, new user added to the friend list.
 * * `"game_invitation"` - Game invitation sent or received.
 * 
 * [[NOTE: For this call to work, the overlay needs to be initialized first. To check whether the overlay is initialized successfully, call [GOG_Utils_GetOverlayState](#GOG_Utils_GetOverlayState).]]
 * 
 * @param {string} popupGroup The name of the notification pop-up group.
 * 
 * @example 
 * ```gml
 * GOG_Utils_DisableOverlayPopups("chat_message");
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @func GOG_Utils_GetGogServicesConnectionState
 * @desc This function returns the current state of the connection to GOG services, see [ServicesConnectionState](#ServicesConnectionState).
 * 
 * @returns {real} (ServicesConnectionState)
 * 
 * @example 
 * ```gml
 * GOG_Utils_GetGogServicesConnectionState();
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @func GOG_Utils_GetImageRGBA
 * @desc This function reads the image of a specified ID into a buffer.
 * 
 * [[NOTE: The size of the output buffer will be 4 * height * width (see function [GOG_Utils_GetImageSize](#GOG_Utils_GetImageSize)).]]
 * 
 * [[WARNING: This function creates a new buffer everytime it is called you need to ensure you correctly delete the buffer when you don&#39;t need it anymore using the [buffer_delete](https://manual.yoyogames.com/GameMaker_Language/GML_Reference/Buffers/buffer_delete.htm) function. Failing to do so will result in memory leaks.]]
 * 
 * @param {real} imageID The ID of the image.
 * 
 * @returns {type.buffer}
 * 
 * @example 
 * ```gml
 * var _buff = GOG_Utils_GetImageRGBA(imageID);
 * 
 * var _size = buffer_get_size(_buff);
 * var _L = sqrt(_size / 4);
 * 
 * surf = surface_create(_L, _L);
 * buffer_set_surface(_buff, _surf, 0);
 * 
 * buffer_delete(_buff);
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @func GOG_Utils_GetImageSize
 * @desc This function reads the width and height of the image of a specified ID.
 * 
 * @param {real} imageID The ID of the image.
 * 
 * @returns {struct}
 * 
 * @param {real} width The width of the image.
 * @param {real} height The height of the image.
 * 
 * @example 
 * ```gml
 * var _struct = GOG_Utils_GetImageSize(imageID);
 * var _width = struct.width;
 * var _height = struct.height;
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @func GOG_Utils_GetOverlayState
 * @desc This function returns the current state of the overlay.
 * 
 * @returns {struct.OverlayState}
 * 
 * @example 
 * ```gml
 * if(GOG_Utils_GetOverlayState() == GOG_OVERLAY_STATE_INITIALIZED)
 * {
 *    //Overlay initialized, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @func GOG_Utils_IsOverlayVisible
 * @desc This function returns the current visibility of the overlay.
 * 
 * @returns {boolean}
 * 
 * @example 
 * ```gml
 * if(GOG_Utils_IsOverlayVisible())
 * {
 *    //Overlay visible, do something
 * }
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @func GOG_Utils_ShowOverlayWithWebPage
 * @desc This function shows a web page in the overlay.
 * 
 * @param {string} url The URL address of a specified web page with the limit of 2047 bytes.
 * 
 * @example 
 * ```gml
 * GOG_Utils_ShowOverlayWithWebPage("https://gamemaker.io");
 * ```
 * The code above provides a simple usage example.
 * @func_end
*/

/**
 * @const OverlayState
 * @desc These constants represent the currect overlay state.
 * 
 * @member GOG_OVERLAY_STATE_UNDEFINED Overlay state is undefined.
 * @member GOG_OVERLAY_STATE_NOT_SUPPORTED Overlay is not supported.
 * @member GOG_OVERLAY_STATE_DISABLED Overlay is disabled by the user in the Galaxy Client.
 * @member GOG_OVERLAY_STATE_FAILED_TO_INITIALIZE Galaxy Client failed to initialize the overlay or inject it into the game.
 * @member GOG_OVERLAY_STATE_INITIALIZED Overlay has been successfully injected into the game.
 * @const_end
*/

/**
 * @const ServicesConnectionState
 * @desc These constants represent the current state of the services connection.
 * @member GOG_SERVICES_CONNECTION_STATE_UNDEFINED Connection state is undefined.
 * @member GOG_SERVICES_CONNECTION_STATE_CONNECTED Connection to the GOG services has been established.
 * @member GOG_SERVICES_CONNECTION_STATE_DISCONNECTED Connection to the GOG services has been lost.
 * @member GOG_SERVICES_CONNECTION_STATE_AUTH_LOST Connection to the GOG services has been lost due to lose of peer authentication.
 * @const_end
*/

/**
 * @module utils
 * @title Utils
 * @section_func
 * @ref GOG_Utils_DisableOverlayPopups
 * @ref GOG_Utils_GetGogServicesConnectionState
 * @ref GOG_Utils_GetImageRGBA
 * @ref GOG_Utils_GetImageSize
 * @ref GOG_Utils_GetOverlayState
 * @ref GOG_Utils_IsOverlayVisible
 * @ref GOG_Utils_ShowOverlayWithWebPage
 * @section_end
 * @section_const
 * @ref OverlayState
 * @ref ServicesConnectionState
 * @section_end
 * @module_end
*/
