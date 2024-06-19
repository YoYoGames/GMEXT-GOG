
#include "YYGOG.h"
#include <string>
#include <vector>

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
    GOG_EnsureArgc(2);

    const char* login = YYGetString(arg, 0);
    const char* password = YYGetString(arg, 1);

    galaxy::api::User()->SignInCredentials(login,password);
}

YYEXPORT void GOG_User_SignInToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(1);

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
    GOG_EnsureArgc(2);

    int steamTicketBuffer = YYGetInt32(arg, 0);
    void* steamTicket = nullptr; int steamTicketSize = 0;
    if (!BufferGetContent(steamTicketBuffer, &steamTicket, &steamTicketSize))
    {
        // no buffer?
        return;
    }

    const char* personaName = YYGetString(arg, 1); // steam_get_persona_name() from GMEXT-Steamworks...
    galaxy::api::User()->SignInSteam(steamTicket, steamTicketSize, personaName);
    YYFree(steamTicket);
}

YYEXPORT void GOG_User_SignInGalaxy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    switch (argc) {
        case 0:
            galaxy::api::User()->SignInGalaxy();
            break;
        case 1:
            galaxy::api::User()->SignInGalaxy(/*requireOnline:*/ YYGetBool(arg, 0));
            break;
        case 2: default: // ignore leftover arguments...
            galaxy::api::User()->SignInGalaxy(/*requireOnline:*/ YYGetBool(arg, 0), /*timeout:*/ YYGetUint32(arg, 1));
            break;
    }
}

YYEXPORT void GOG_User_SignInPS4(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(1);

    const char* ps4ClientID = YYGetString(arg, 0);

    galaxy::api::User()->SignInPS4(ps4ClientID);
}

YYEXPORT void GOG_User_SignInXB1(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(1);

    const char* xboxOneClientID = YYGetString(arg, 0);

    galaxy::api::User()->SignInXB1(xboxOneClientID);
}

YYEXPORT void GOG_User_SignInXbox(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(1);

    // should be compatible with the GDK Extension
    // ("user signed in" - Async System event)
    uint64_t xuidFromGdk = YYGetInt64(arg, 0); // XUID as I64
    // pseudo-XUIDs 0 or -1 are not compatible, this must be a real (positive) XUID.

    galaxy::api::User()->SignInXbox(xuidFromGdk);
}

YYEXPORT void GOG_User_SignInXBLive(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(4);

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
    GOG_EnsureArgc(1);

    const char* serverKey = YYGetString(arg, 0);

    galaxy::api::User()->SignInServerKey(serverKey);
}

YYEXPORT void GOG_User_SignInAuthorizationCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(2);

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

    galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

    galaxy::api::User()->RequestUserData(userID);
}

YYEXPORT void GOG_User_IsUserDataAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;

    galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->IsUserDataAvailable(userID);
}

YYEXPORT void GOG_User_GetUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(1); // userID optional

    const char* key = YYGetString(arg, 0);
    galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);

    YYCreateString(&Result, galaxy::api::User()->GetUserData(key, userID));
}

YYEXPORT void GOG_User_SetUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(2);

    const char* key = YYGetString(arg, 0);
    const char* value = YYGetString(arg, 1);

    galaxy::api::User()->SetUserData(key, value);
}

YYEXPORT void GOG_User_GetUserDataCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_REAL;

    galaxy::api::GalaxyID userID = GOG_GetOptUserId(0);

    Result.kind = VALUE_REAL;
    Result.val = galaxy::api::User()->GetUserDataCount(userID);
}

YYEXPORT void GOG_User_GetUserDataByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_STRUCT;
    GOG_EnsureArgc(1);

    double index = YYGetReal(arg, 0);
    galaxy::api::GalaxyID userID = GOG_GetOptUserId(1);
    
    char key[4096] = { '\0' };
    char value[4096] = { '\0' };

    galaxy::api::User()->GetUserDataByIndex(static_cast<uint32_t>(index), key, sizeof(key), value, sizeof(value), userID);

    YYStructCreate(&Result);

    YYStructAddString(&Result, "key", key);
    YYStructAddString(&Result, "value", value);
}

YYEXPORT void GOG_User_DeleteUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(1);

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
    GOG_EnsureArgc(1);

    double bufferId = YYGetReal(arg, 0);

    unsigned char* buffer_data = nullptr;
    int buffer_size = 0;

    if (bufferId >= 0 && !BufferGetContent(static_cast<int32_t>(bufferId), (void**)(&buffer_data), &buffer_size))
    {
        DebugConsoleOutput("[GMEXT-GOG]: GOG_User_RequestEncryptedAppTicket() - error: specified buffer not found\n");
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
    Result.kind = VALUE_REAL;
    Result.val = -1.0;

    int bufferID = (argc > 0) ? YYGetInt32(arg, 0) : -1;
    int byteOffset = (argc > 1) ? YYGetInt32(arg, 1) : 0;

    uint32_t ticketSize = 0;
    galaxy::api::User()->GetEncryptedAppTicket(nullptr, 0, ticketSize);
    if (ticketSize == 0)
    {
        return; // there is probably no ticket then
    }

    std::vector<uint8_t> ticketData;
    ticketData.resize(ticketSize);
    galaxy::api::User()->GetEncryptedAppTicket(ticketData.data(), ticketSize, ticketSize);

    if (bufferID < 0)
    {
        bufferID = CreateBuffer(ticketSize, eBuffer_Format_Fixed, 1);
    }
    BufferWriteContent(bufferID, byteOffset, ticketData.data(), ticketSize);

    Result.kind = VALUE_REAL;
    Result.val = bufferID;
}

YYEXPORT void GOG_User_CreateOpenIDConnection(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    GOG_NotInitialisedReturn_BOOL;
    GOG_EnsureArgc(3);

    const char* secretKey = YYGetString(arg, 0);
    const char* titleID = YYGetString(arg, 1);
    const char* connectionID = YYGetString(arg, 2);
    bool ignoreNonce = (argc > 3) ? YYGetBool(arg, 3) : true;

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
    GOG_EnsureArgc(3);

    const char* titleID = YYGetString(arg, 0);
    const char* connectionID = YYGetString(arg, 1);
    const char* idToken = YYGetString(arg, 2);
    bool createAccount = (argc > 3) ? YYGetBool(arg, 3) : true;
    const char* encryptedRequest = (argc > 4) ? YYGetString(arg, 4) : nullptr;
    const char* playerSecret = (argc > 5) ? YYGetString(arg, 5) : nullptr;

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
    GOG_EnsureArgc(1); // info optional

    const char* accessToken = YYGetString(arg, 0);
    const char* info = (argc > 1) ? YYGetString(arg, 1) : nullptr;

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

