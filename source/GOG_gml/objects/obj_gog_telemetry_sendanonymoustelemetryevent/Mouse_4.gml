
GOG_Telemetry_ClearParams()

GOG_Telemetry_AddBoolParam("BOOL",true)
GOG_Telemetry_AddFloatParam("FLOAT",123.456)
GOG_Telemetry_AddIntParam("INT",10)

GOG_Telemetry_SendAnonymousTelemetryEvent("RandomEvent")
