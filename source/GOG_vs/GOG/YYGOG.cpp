
#include "YYGOG.h"
#include <string>
#include "YYGOG_Listener.hpp"


bool GOG_isInitialised = false;
void OldPreGraphicsInitialisation()
{
	std::string clientID = extOptGetString("GOG", "clientID");
	std::string clientSecret = extOptGetString("GOG", "clientSecret");
	
	galaxy::api::InitOptions options(clientID.c_str(), clientSecret.c_str());
	galaxy::api::Init(options);
	// poke it once so it registers
	GMAsyncEventListener::Instance();

	GOG_isInitialised = true;
}

YYEXPORT void GOG_Shutdown(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GMAsyncEventListener::Unregister();
	galaxy::api::Shutdown();
	GOG_isInitialised = false;
	DebugConsoleOutput("[GMEXT-GOG]: GOG_Shutdown is done\n");
}

YYEXPORT void GOG_ProcessData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	galaxy::api::ProcessData();
}

YYEXPORT void GOG_GetError(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;

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

	// `ID` is always passed by value, so it cannot be null
	YYStructAddInt64(&Struct, "ID", ID.GetRealID());
	YYStructAddInt(&Struct, "IDType", ID.GetIDType());

	return Struct;
}

galaxy::api::GalaxyID GalaxyIDFromStruct(RValue* _struct)
{
	RValue *IDType, *ID;
	if ((_struct == NULL)
		|| ((IDType = YYStructGetMember(_struct, "IDType")) == NULL)
		|| ((ID = YYStructGetMember(_struct, "ID")) == NULL)
		|| (ID->v64 == 0)
		|| (IDType->v64 == 0))
	{
		return galaxy::api::GalaxyID();
	}

	double type = YYGetReal(IDType, 0);
	uint64_t value = YYGetInt64(ID, 0);

	return galaxy::api::GalaxyID::FromRealID((galaxy::api::GalaxyID::IDType)type, value);
}
