#include "Extension_Interface.h"

#include "YYRValue.h"

YYRunnerInterface gs_runnerInterface;
YYRunnerInterface* g_pYYRunnerInterface;



char PreGraphicsInitialisation_argument[1024];
double val = 0;

YYEXPORT void SimpleDesktopExample_getPreGraphicsInitialisation(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	YYCreateString(&Result, PreGraphicsInitialisation_argument);
}

extern void OldPreGraphicsInitialisation();

YYEXPORT void YYExtensionInitialise(const struct YYRunnerInterface* _pFunctions, size_t _functions_size)
{
	//copy out all the functions 
	memcpy(&gs_runnerInterface, _pFunctions, sizeof(YYRunnerInterface));
	g_pYYRunnerInterface = &gs_runnerInterface;

	if (_functions_size < sizeof(YYRunnerInterface)) {
		DebugConsoleOutput("ERROR : runner interface mismatch in extension DLL\n ");
	} // end if

	DebugConsoleOutput("YYExtensionInitialise CONFIGURED \n ");

	OldPreGraphicsInitialisation();
}


YYEXPORT void SimpleDesktopExample_ReturnString(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	YYCreateString(&Result, "Hello World");
}

YYEXPORT void SimpleDesktopExample_ReturnDouble(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	double inc = YYGetReal(arg, 0);
	
	val += inc;

	Result.kind = VALUE_REAL;
	Result.val = val;
}

YYEXPORT void SimpleDesktopExample_AsyncCallback(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "SimpleDesktopExample_AsyncCallback");
	DsMapAddDouble(map, "double",val);
	DsMapAddString(map, "string", "Hello World");

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void SimpleDesktopExample_EchoStruct(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	RValue* pV = &(arg[0]);

	COPY_RValue(&Result, pV);
	FREE_RValue(pV);
}

YYEXPORT void SimpleDesktopExample_ReturnStruct(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "double", val);
	YYStructAddString(&Struct, "string", "YoYoGames X Opera");

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void SimpleDesktopExample_ReadStruct(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	DebugConsoleOutput("SimpleDesktopExample_ReadStruct CALLED\n");

	RValue* pV = &(arg[0]);
	const char* key1 = YYGetString(arg, 1);
	const char* key2 = YYGetString(arg, 2);

	RValue* value = YYStructGetMember(pV, key1);
	const char* str = value->GetString();
	DebugConsoleOutput("%s: %s\n",key1, str);

	RValue* value2 = YYStructGetMember(pV, key2);
	double real = value2->val;
	DebugConsoleOutput("%s: %f\n", key2, real);

}
/*
YYEXPORT void SimpleDesktopExample_JSON(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	DebugConsoleOutput("SimpleDesktopExample_JSON CALLED");
	DebugConsoleOutput("\n");
	const char* json = YYGetString(arg, 0);

	json_object* jobj = json_tokener_parse(json);

	const char* key1 = json_object_get_string(json_object_object_get(jobj, "key1"));
	DebugConsoleOutput(key1);
	DebugConsoleOutput("\n");

	const char* key2 = json_object_get_string(json_object_object_get(jobj, "key2"));
	DebugConsoleOutput(key2);
	DebugConsoleOutput("\n");

	//uint32 AppID = json_object_get_int(json_object_object_get(jobj, "AppID"));
	//bool debug = json_object_get_boolean(json_object_object_get(jobj, "Debug"));
}
*/
