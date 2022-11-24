
#include "YYGOG.h"
#include <string>

YYEXPORT void GOG_Telemetry_AddStringParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);
	const char* value = YYGetString(arg, 1);

	galaxy::api::Telemetry()->AddStringParam(name,value);
}

YYEXPORT void GOG_Telemetry_AddIntParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);
	int32_t value = YYGetReal(arg, 1);

	galaxy::api::Telemetry()->AddIntParam(name, value);
}

YYEXPORT void GOG_Telemetry_AddFloatParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);
	double value = YYGetReal(arg, 1);

	galaxy::api::Telemetry()->AddFloatParam(name,value);
}

YYEXPORT void GOG_Telemetry_AddBoolParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);
	bool value = YYGetBool(arg, 1);

	galaxy::api::Telemetry()->AddBoolParam(name,value);
}

YYEXPORT void GOG_Telemetry_AddObjectParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);

	galaxy::api::Telemetry()->AddObjectParam(name);
}

YYEXPORT void GOG_Telemetry_AddArrayParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);

	galaxy::api::Telemetry()->AddArrayParam(name);
}

YYEXPORT void GOG_Telemetry_CloseParam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	galaxy::api::Telemetry()->CloseParam();
}

YYEXPORT void GOG_Telemetry_ClearParams(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	galaxy::api::Telemetry()->ClearParams();
}

YYEXPORT void GOG_Telemetry_SetSamplingClass(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* name = YYGetString(arg, 0);

	galaxy::api::Telemetry()->SetSamplingClass(name);
}

class YYITelemetryEventSendListener : public galaxy::api::ITelemetryEventSendListener
{
public:
	std::string event;
	virtual void OnTelemetryEventSendSuccess(const char* eventType, uint32_t sentEventIndex)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "eventType", eventType);
		DsMapAddDouble(map, "sentEventIndex", sentEventIndex);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnTelemetryEventSendFailure(const char* eventType, uint32_t sentEventIndex, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", event.c_str());
		DsMapAddString(map, "eventType", eventType);
		DsMapAddDouble(map, "sentEventIndex", sentEventIndex);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		case FailureReason::FAILURE_REASON_CLIENT_FORBIDDEN: DsMapAddString(map, "error", "FAILURE_REASON_CLIENT_FORBIDDEN"); break;
		case FailureReason::FAILURE_REASON_INVALID_DATA: DsMapAddString(map, "error", "FAILURE_REASON_INVALID_DATA"); break;
		case FailureReason::FAILURE_REASON_NO_SAMPLING_CLASS_IN_CONFIG: DsMapAddString(map, "error", "FAILURE_REASON_NO_SAMPLING_CLASS_IN_CONFIG"); break;
		case FailureReason::FAILURE_REASON_SAMPLING_CLASS_FIELD_MISSING: DsMapAddString(map, "error", "FAILURE_REASON_SAMPLING_CLASS_FIELD_MISSING"); break;
		case FailureReason::FAILURE_REASON_EVENT_SAMPLED_OUT: DsMapAddString(map, "error", "FAILURE_REASON_EVENT_SAMPLED_OUT"); break;
		case FailureReason::FAILURE_REASON_SAMPLING_RESULT_ALREADY_EXIST: DsMapAddString(map, "error", "FAILURE_REASON_SAMPLING_RESULT_ALREADY_EXIST"); break;
		case FailureReason::FAILURE_REASON_SAMPLING_INVALID_RESULT_PATH: DsMapAddString(map, "error", "FAILURE_REASON_SAMPLING_INVALID_RESULT_PATH"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Telemetry_SendTelemetryEvent(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* eventType = YYGetString(arg, 0);

	YYITelemetryEventSendListener* callback = new YYITelemetryEventSendListener();
	callback->event = "GOG_Telemetry_SendTelemetryEvent";
	galaxy::api::Telemetry()->SendTelemetryEvent(eventType, callback);
}

YYEXPORT void GOG_Telemetry_SendAnonymousTelemetryEvent(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* eventType = YYGetString(arg, 0);

	YYITelemetryEventSendListener* callback = new YYITelemetryEventSendListener();
	callback->event = "GOG_Telemetry_SendTelemetryEvent";
	galaxy::api::Telemetry()->SendAnonymousTelemetryEvent(eventType,callback);
}

YYEXPORT void GOG_Telemetry_GetVisitID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	YYCreateString(&Result, galaxy::api::Telemetry()->GetVisitID());
}

//YYEXPORT void GOG_Telemetry_GetVisitIDCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Telemetry()->GetVisitIDCopy
//}

YYEXPORT void GOG_Telemetry_ResetVisitID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	galaxy::api::Telemetry()->ResetVisitID();
}

