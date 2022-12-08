
#include "YYGOG.h"
#include "IniOptionsLibrary.h"
#include "DesktopExtensionTools.h"

bool GOG_isInitialised = false;
void OldPreGraphicsInitialisation()
{
	std::string clientID = extOptGetString("GOG", "clientID");
	std::string clientSecret = extOptGetString("GOG", "clientSecret");
	
	galaxy::api::InitOptions options(clientID.c_str(), clientSecret.c_str());
	galaxy::api::Init(options);

	GOG_isInitialised = true;
}

YYEXPORT void GOG_ProcessData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL

	galaxy::api::ProcessData();
}

YYEXPORT void GOG_GetError(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT

	const galaxy::api::IError *error = galaxy::api::GetError();

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	if (error != NULL)
	{
		YYStructAddInt(&Struct, "Type", (int)error->GetType());
		YYStructAddString(&Struct, "Msg", error->GetMsg());
		YYStructAddString(&Struct, "Name", error->GetName());
	}

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

//////////////////////////////////////// GLOBAL FUNCTIONS:

RValue getStructFromGalaxyID(galaxy::api::GalaxyID ID)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	if (ID != NULL)
	{
		YYStructAddInt64(&Struct, "ID", ID.GetRealID());
		YYStructAddInt(&Struct, "IDType", ID.GetIDType());
	}

	return Struct;
}

galaxy::api::GalaxyID GalaxyIDFromStruct(RValue* _struct)
{
	int type = YYStructGetMember(_struct, "IDType")->val;
	uint64_t value = YYStructGetMember(_struct, "ID")->v64;

	return galaxy::api::GalaxyID::FromRealID((galaxy::api::GalaxyID::IDType)type, value);
}
