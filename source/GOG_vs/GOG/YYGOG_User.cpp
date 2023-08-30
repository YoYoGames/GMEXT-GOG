
#include "YYGOG.h"
#include <string>

YYEXPORT void GOG_User_SignedIn(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->SignedIn();
}

YYEXPORT void GOG_User_GetGalaxyID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_STRUCT;

    RValue Struct = getStructFromGalaxyID(galaxy::api::User()->GetGalaxyID());

    COPY_RValue(&Result, &Struct);
    FREE_RValue(&Struct);
}

YYEXPORT void GOG_User_SignInCredentials(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* login = YYGetString(arg, 0);
    const char* password = YYGetString(arg, 1);

    galaxy::api::User()->SignInCredentials(login,password);
}

YYEXPORT void GOG_User_SignInToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* refreshToken = YYGetString(arg, 0);

    galaxy::api::User()->SignInToken(refreshToken);
}

YYEXPORT void GOG_User_SignInLauncher(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    galaxy::api::User()->SignInLauncher();
}

YYEXPORT void GOG_User_SignInSteam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    int steamTicketBuffer = YYGetInt32(arg, 0);
    void* steamTicket = nullptr; int steamTicketSize = 0;
    if (!BufferGetContent(steamTicketBuffer, &steamTicket, &steamTicketSize))
    {
        // no buffer?
        return;
    }

    const char* personaName = YYGetString(arg, 1);
    galaxy::api::User()->SignInSteam(steamTicket, steamTicketSize, personaName);
    YYFree(steamTicket);
}

YYEXPORT void GOG_User_SignInGalaxy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    bool requireOnline = YYGetBool(arg, 0);
    galaxy::api::User()->SignInGalaxy(requireOnline);
}

YYEXPORT void GOG_User_SignInPS4(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* ps4ClientID = YYGetString(arg, 0);

    galaxy::api::User()->SignInPS4(ps4ClientID);
}

YYEXPORT void GOG_User_SignInXB1(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* xbocOneClientID = YYGetString(arg, 0);

    galaxy::api::User()->SignInXB1(xbocOneClientID);
}

YYEXPORT void GOG_User_SignInXbox(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    // should be compatible with the GDK Extension
    // ("user signed in" - Async System event)
    uint64_t xuidFromGdk = YYGetInt64(arg, 0); // XUID as I64

    galaxy::api::User()->SignInXbox(xuidFromGdk);
}

YYEXPORT void GOG_User_SignInXBLive(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* token = YYGetString(arg, 0);
    const char* signature = YYGetString(arg, 1);
    const char* marketplaceID = YYGetString(arg, 2);
    const char* locale = YYGetString(arg, 3);

    galaxy::api::User()->SignInXBLive(token,signature,marketplaceID,locale);
}

YYEXPORT void GOG_User_SignInAnonymous(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    galaxy::api::User()->SignInAnonymous();
}

YYEXPORT void GOG_User_SignInAnonymousTelemetry(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    galaxy::api::User()->SignInAnonymousTelemetry();
}

YYEXPORT void GOG_User_SignInServerKey(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* serverKey = YYGetString(arg, 0);

    galaxy::api::User()->SignInServerKey(serverKey);
}

YYEXPORT void GOG_User_SignInAuthorizationCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* authorizationCode = YYGetString(arg, 0);
    const char* redirectURI = YYGetString(arg, 1);

    galaxy::api::User()->SignInAuthorizationCode(authorizationCode, redirectURI);
}

YYEXPORT void GOG_User_SignOut(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    galaxy::api::User()->SignOut();
}

YYEXPORT void GOG_User_RequestUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    RValue* pV = &(arg[0]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    galaxy::api::User()->RequestUserData(userID);
}

YYEXPORT void GOG_User_IsUserDataAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    RValue* pV = &(arg[0]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->IsUserDataAvailable(userID);
}

YYEXPORT void GOG_User_GetUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* key = YYGetString(arg, 0);

    RValue* pV = &(arg[1]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    YYCreateString(&Result, galaxy::api::User()->GetUserData(key, userID));
}

YYEXPORT void GOG_User_SetUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* key = YYGetString(arg, 0);
    const char* value = YYGetString(arg, 1);

    galaxy::api::User()->SetUserData(key, value);
}

YYEXPORT void GOG_User_GetUserDataCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_REAL;

    RValue* pV = &(arg[0]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    Result.kind = VALUE_REAL;
    Result.val = galaxy::api::User()->GetUserDataCount(userID);
}

YYEXPORT void GOG_User_GetUserDataByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_STRUCT;

    double index = YYGetReal(arg, 0);
    RValue* pV = &(arg[1]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);
    
    char key[4096];
    char value[4096];

    galaxy::api::User()->GetUserDataByIndex(static_cast<uint32_t>(index), key, sizeof(key), value, sizeof(value), userID);

    RValue Struct = { 0 };
    YYStructCreate(&Struct);

    YYStructAddString(&Struct, "key", key);
    YYStructAddString(&Struct, "value", value);

    COPY_RValue(&Result, &Struct);
    FREE_RValue(&Struct);
}

YYEXPORT void GOG_User_DeleteUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* key = YYGetString(arg, 0);

    galaxy::api::User()->DeleteUserData(key);
}

YYEXPORT void GOG_User_IsLoggedOn(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->IsLoggedOn();
}

YYEXPORT void GOG_User_RequestEncryptedAppTicket(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    double bufferId = YYGetReal(arg, 0);

    unsigned char* buffer_data = nullptr;
    int buffer_size = 0;

    if (bufferId >= 0 && !BufferGetContent(static_cast<int32_t>(bufferId), (void**)(&buffer_data), &buffer_size))
    {
        DebugConsoleOutput("GOG_User_RequestEncryptedAppTicket() - error: specified buffer not found\n");
        Result.kind = VALUE_BOOL;
        Result.val = false;

        return;
    }

    galaxy::api::User()->RequestEncryptedAppTicket(buffer_data, buffer_size);

    YYFree(buffer_data);
}

YYEXPORT void GOG_User_GetEncryptedAppTicket(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_REAL;

    char ticket[4096] = { '\0' };
    uint32_t ticketSize = 0;
    galaxy::api::User()->GetEncryptedAppTicket(ticket, sizeof(ticket), ticketSize);
    DebugConsoleOutput("Ticket size: %u\n", ticketSize);

    int buffer = CreateBuffer(ticketSize, eBuffer_Format_Fixed, 1);
    BufferWriteContent(buffer, 0, ticket, ticketSize);

    Result.kind = VALUE_REAL;
    Result.val = buffer;
}

YYEXPORT void GOG_User_CreateOpenIDConnection(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* secretKey = YYGetString(arg, 0);
    const char* titleID = YYGetString(arg, 1);
    const char* connectionID = YYGetString(arg, 2);
    bool ignoreNonce = YYGetBool(arg, 3);

    galaxy::api::User()->CreateOpenIDConnection(
        secretKey,
        titleID,
        connectionID,
        ignoreNonce
    );
}

YYEXPORT void GOG_User_LoginWithOpenIDConnect(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* titleID = YYGetString(arg, 0);
    const char* connectionID = YYGetString(arg, 1);
    const char* idToken = YYGetString(arg, 2);
    bool createAccount = YYGetBool(arg, 3);
    const char* encryptedRequest = YYGetString(arg, 4);
    const char* playerSecret = YYGetString(arg, 5);

    galaxy::api::User()->LoginWithOpenIDConnect(
        titleID,
        connectionID,
        idToken,
        createAccount,
        encryptedRequest,
        playerSecret
    );
}

YYEXPORT void GOG_User_GetSessionID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_REAL;

    Result.kind = VALUE_INT64;
    Result.v64 = static_cast<uint64_t>(galaxy::api::User()->GetSessionID());
}

YYEXPORT void GOG_User_GetAccessToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_STRING;

    YYCreateString(&Result, galaxy::api::User()->GetAccessToken());
}

YYEXPORT void GOG_User_ReportInvalidAccessToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    const char* accessToken = YYGetString(arg, 0);
    const char* info = YYGetString(arg, 1);

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->ReportInvalidAccessToken(accessToken, info);
}

YYEXPORT void GOG_User_GetRefreshToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_STRING;

    YYCreateString(&Result, galaxy::api::User()->GetRefreshToken());
}

YYEXPORT void GOG_User_GetIDToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_STRING;

    YYCreateString(&Result, galaxy::api::User()->GetIDToken());
}

