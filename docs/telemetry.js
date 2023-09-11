// FUNCTIONS

/**
 * @func GOG_Telemetry_AddArrayParam
 * @desc This function adds an array parameter to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 * 
 * @param {string} name The name of the parameter
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int",123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_AddBoolParam
 * @desc This function adds a boolean parameter to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 *   <dl>
 *   </dl>
 * 
 * @param {string} name The name of the parameter or **empty string** when adding a value to an array.
 * @param {boolean} value The value of the parameter.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_AddFloatParam
 * @desc This function adds a float parameter to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 *   <dl>
 *   </dl>
 * 
 * @param {string} name The name of the parameter or **empty string** when adding a value to an array.
 * @param {real} value The value of the parameter.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_AddIntParam
 * @desc This function adds an integer parameter to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 *   <dl>
 *   </dl>
 * 
 * @param {string} name The name of the parameter or **empty string** when adding a value to an array.
 * @param {real} value The value of the parameter.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name) ;
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_AddObjectParam
 * @desc This function adds an object parameter to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 * 
 * @param {string} name The name of the parameter or **empty string** when adding a value to an array.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int",123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_AddStringParam
 * @desc This function adds a string parameter to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 * 
 * @param {string} name The name of the parameter or **empty string** when adding a value to an array.
 * @param {string} value The value of the parameter.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int",123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_ClearParams
 * @desc This function clears all parameters that may have been set so far at any level.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_CloseParam
 * @desc This function closes an object or array parameter and leaves its scope.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_GetVisitID
 * @desc This function retrieves the current VisitID.
 * 
 * [[NOTE: Visit ID is used to link subsequent telemetry events that corresponds to the same action (e.g. game session).]]
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _VisitID = GOG_Telemetry_GetVisitID();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */
 
/**
 * @func GOG_Telemetry_ResetVisitID
 * @desc This function resets the current VisitID.
 * 
 * > **:information_source: NOTE**
 * >
 * > The visit ID is used to link subsequent telemetry events that correspond to the same action (e.g. game session).
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ResetVisitID();
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_SendAnonymousTelemetryEvent
 * @desc This function sends an anonymous telemetry event.
 * 
 * @param {string} eventType The type of the event.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendAnonymousTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_SendTelemetryEvent
 * @desc This function sends a telemetry event.
 * 
 * @param {string} eventType The type of the event.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_ClearParams();
 * GOG_Telemetry_AddStringParam("hello", "world");
 * 
 * GOG_Telemetry_AddArrayParam (name);
 * GOG_Telemetry_AddIntParam("int", 123);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_AddObjectParam(name);
 * GOG_Telemetry_AddBoolParam("bool", true);
 * GOG_Telemetry_AddFloatParam("float", 987.765);
 * GOG_Telemetry_CloseParam();
 * 
 * GOG_Telemetry_SendTelemetryEvent(eventType);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @func GOG_Telemetry_SetSamplingClass
 * @desc This function sets a sampling class to be applied next time you call ${function.GOG_Telemetry_SendTelemetryEvent} or ${function.GOG_Telemetry_SendAnonymousTelemetryEvent}.
 * 
 * @param {string} name The name of the sampling class.
 * 
 * @example
 * ```gml
 * GOG_Telemetry_SetSamplingClass(name);
 * ```
 * The code above provides a simple usage example.
 * @func_end
 */

/**
 * @module telemetry
 * @title Telemetry
 * @desc This is a module for handling telemetry.
 * @section_func Functions
 * @ref GOG_Telemetry_AddArrayParam
 * @ref GOG_Telemetry_AddBoolParam
 * @ref GOG_Telemetry_AddFloatParam
 * @ref GOG_Telemetry_AddIntParam
 * @ref GOG_Telemetry_AddObjectParam
 * @ref GOG_Telemetry_AddStringParam
 * @ref GOG_Telemetry_ClearParams
 * @ref GOG_Telemetry_CloseParam
 * @ref GOG_Telemetry_GetVisitID
 * @ref GOG_Telemetry_ResetVisitID
 * @ref GOG_Telemetry_SendAnonymousTelemetryEvent
 * @ref GOG_Telemetry_SendTelemetryEvent
 * @ref GOG_Telemetry_SetSamplingClass
 * @section_end
 * @module_end
 */