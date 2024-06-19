
#include "YYGOG.h"
#include <string>

YYEXPORT void GOG_Telemetry_AddStringParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = (KIND_RValue(&arg[0]) == VALUE_STRING) ? YYGetString(arg, 0) : nullptr;
	const char* value = YYGetString(arg, 1);

	galaxy::api::Telemetry()->AddStringParam(name,value);
}

YYEXPORT void GOG_Telemetry_AddIntParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = (KIND_RValue(&arg[0]) == VALUE_STRING) ? YYGetString(arg, 0) : nullptr;
	double value = YYGetReal(arg, 1);

	galaxy::api::Telemetry()->AddIntParam(name, static_cast<int32_t>(value));
}

YYEXPORT void GOG_Telemetry_AddFloatParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = (KIND_RValue(&arg[0]) == VALUE_STRING) ? YYGetString(arg, 0) : nullptr;
	double value = YYGetReal(arg, 1);

	galaxy::api::Telemetry()->AddFloatParam(name,value);
}

YYEXPORT void GOG_Telemetry_AddBoolParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* name = (KIND_RValue(&arg[0]) == VALUE_STRING) ? YYGetString(arg, 0) : nullptr;
	bool value = YYGetBool(arg, 1);

	galaxy::api::Telemetry()->AddBoolParam(name,value);
}

YYEXPORT void GOG_Telemetry_AddObjectParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	// here name can be nullptr, apparently?
	const char* name = ((argc > 0) && KIND_RValue(&arg[0]) == VALUE_STRING) ? YYGetString(arg, 0) : nullptr;

	galaxy::api::Telemetry()->AddObjectParam(name);
}

YYEXPORT void GOG_Telemetry_AddArrayParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	// here name can be nullptr, apparently?
	const char* name = ((argc > 0) && KIND_RValue(&arg[0]) == VALUE_STRING) ? YYGetString(arg, 0) : nullptr;

	galaxy::api::Telemetry()->AddArrayParam(name);
}

YYEXPORT void GOG_Telemetry_CloseParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Telemetry()->CloseParam();
}

YYEXPORT void GOG_Telemetry_ClearParams(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Telemetry()->ClearParams();
}

YYEXPORT void GOG_Telemetry_SetSamplingClass(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* name = YYGetString(arg, 0);

	galaxy::api::Telemetry()->SetSamplingClass(name);
}

YYEXPORT void GOG_Telemetry_SendTelemetryEvent(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* eventType = YYGetString(arg, 0);

	galaxy::api::Telemetry()->SendTelemetryEvent(eventType);
}

YYEXPORT void GOG_Telemetry_SendAnonymousTelemetryEvent(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* eventType = YYGetString(arg, 0);

	galaxy::api::Telemetry()->SendAnonymousTelemetryEvent(eventType);
}

YYEXPORT void GOG_Telemetry_GetVisitID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	YYCreateString(&Result, galaxy::api::Telemetry()->GetVisitID());
}

YYEXPORT void GOG_Telemetry_ResetVisitID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::Telemetry()->ResetVisitID();
}

