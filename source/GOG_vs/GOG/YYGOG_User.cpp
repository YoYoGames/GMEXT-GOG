
#include "YYGOG.h"
#include <string>

YYEXPORT void GOG_User_SignedIn(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->SignedIn();
}

YYEXPORT void GOG_User_GetGalaxyID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    RValue Struct = getStructFromGalaxyID(galaxy::api::User()->GetGalaxyID());

    COPY_RValue(&Result, &Struct);
    FREE_RValue(&Struct);
}


class YYIAuthListener : public galaxy::api::IAuthListener
{
public:

    std::string event;

    virtual void OnAuthSuccess()
    {
        int map = CreateDsMap(0, 0);
        DsMapAddString(map, "type", event.c_str());
        CreateAsyncEventWithDSMap(map, 70);
    }

    virtual void OnAuthFailure(FailureReason failureReason)
    {
        int map = CreateDsMap(0, 0);
        DsMapAddString(map, "type", event.c_str());
        switch (failureReason)
        {
            case FailureReason::FAILURE_REASON_CONNECTION_FAILURE: DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
            case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
            case FailureReason::FAILURE_REASON_GALAXY_SERVICE_NOT_AVAILABLE: DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_SERVICE_NOT_AVAILABLE"); break;
            case FailureReason::FAILURE_REASON_GALAXY_SERVICE_NOT_SIGNED_IN: DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_SERVICE_NOT_SIGNED_IN"); break;
            case FailureReason::FAILURE_REASON_NO_LICENSE: DsMapAddString(map, "error", "FAILURE_REASON_NO_LICENSE"); break;
            case FailureReason::FAILURE_REASON_INVALID_CREDENTIALS: DsMapAddString(map, "error", "FAILURE_REASON_INVALID_CREDENTIALS"); break;
            case FailureReason::FAILURE_REASON_GALAXY_NOT_INITIALIZED: DsMapAddString(map, "error", "FAILURE_REASON_GALAXY_NOT_INITIALIZED"); break;
            case FailureReason::FAILURE_REASON_EXTERNAL_SERVICE_FAILURE: DsMapAddString(map, "error", "FAILURE_REASON_EXTERNAL_SERVICE_FAILURE"); break;
        }
        CreateAsyncEventWithDSMap(map, 70);
    }

    virtual void OnAuthLost()
    {
        int map = CreateDsMap(0, 0);
        DsMapAddString(map, "type", event.c_str());
        DsMapAddString(map, "error", "FAILURE_REASON_OnAuthLost");

        CreateAsyncEventWithDSMap(map, 70);
    }
};

YYEXPORT void GOG_User_SignInCredentials(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* login = YYGetString(arg, 0);
    const char* password = YYGetString(arg, 1);

    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInCredentials";
    galaxy::api::User()->SignInCredentials(login,password, callback);
}

YYEXPORT void GOG_User_SignInToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* refreshToken = YYGetString(arg, 0);

    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInToken";
    galaxy::api::User()->SignInToken(refreshToken,callback);
}

YYEXPORT void GOG_User_SignInLauncher(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInLauncher";
    galaxy::api::User()->SignInLauncher(callback);
}

//YYEXPORT void GOG_User_SignInSteam(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//    galaxy::api::User()->SignInSteam();
//}

YYEXPORT void GOG_User_SignInGalaxy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    bool requireOnline = YYGetBool(arg, 0);
    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInGalaxy";
    galaxy::api::User()->SignInGalaxy(requireOnline, callback);
}

//Deprecated on V1.150
//YYEXPORT void GOG_User_SignInUWP(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//    YYIAuthListener* callback = new YYIAuthListener();
//    callback->event = "GOG_User_SignInUWP";
//    galaxy::api::User()->SignInUWP(callback);
//}

YYEXPORT void GOG_User_SignInPS4(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* ps4ClientID = YYGetString(arg, 0);

    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInPS4";
    galaxy::api::User()->SignInPS4(ps4ClientID,callback);
}

YYEXPORT void GOG_User_SignInXB1(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* xbocOneClientID = YYGetString(arg, 0);

    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInXB1";
    galaxy::api::User()->SignInXB1(xbocOneClientID,callback);
}

YYEXPORT void GOG_User_SignInXBLive(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* token = YYGetString(arg, 0);
    const char* signature = YYGetString(arg, 1);
    const char* marketplaceID = YYGetString(arg, 2);
    const char* locale = YYGetString(arg, 3);

    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInXBLive";
    galaxy::api::User()->SignInXBLive(token,signature,marketplaceID,locale,callback);
}

YYEXPORT void GOG_User_SignInAnonymous(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInAnonymous";
    galaxy::api::User()->SignInAnonymous(callback);
}

YYEXPORT void GOG_User_SignInAnonymousTelemetry(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInAnonymousTelemetry";
    galaxy::api::User()->SignInAnonymousTelemetry(callback);
}

YYEXPORT void GOG_User_SignInServerKey(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* serverKey = YYGetString(arg, 0);

    YYIAuthListener* callback = new YYIAuthListener();
    callback->event = "GOG_User_SignInServerKey";
    galaxy::api::User()->SignInServerKey(serverKey,callback);
}

YYEXPORT void GOG_User_SignOut(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    galaxy::api::User()->SignOut();
}

class YYISpecificUserDataListener : public galaxy::api::ISpecificUserDataListener
{
public:
    std::string event;
    virtual void OnSpecificUserDataUpdated(galaxy::api::GalaxyID userID)
    {
        int map = CreateDsMap(0, 0);
        DsMapAddString(map, "type", event.c_str());
        RValue struct_userID = getStructFromGalaxyID(userID);
        DsMapAddRValue(map, "userID", &struct_userID);
        CreateAsyncEventWithDSMap(map, 70);
    }
};
YYEXPORT void GOG_User_RequestUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    RValue* pV = &(arg[0]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    YYISpecificUserDataListener *callback = new YYISpecificUserDataListener();
    callback->event = "GOG_User_RequestUserData";
    galaxy::api::User()->RequestUserData(userID,callback);
}

YYEXPORT void GOG_User_IsUserDataAvailable(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    RValue* pV = &(arg[0]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->IsUserDataAvailable(userID);
}

YYEXPORT void GOG_User_GetUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* key = YYGetString(arg, 0);

    RValue* pV = &(arg[1]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    YYCreateString(&Result, galaxy::api::User()->GetUserData(key, userID));
}

//YYEXPORT void GOG_User_GetUserDataCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//    //galaxy::api::User()->
//}

YYEXPORT void GOG_User_SetUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* key = YYGetString(arg, 0);
    const char* value = YYGetString(arg, 1);

    YYISpecificUserDataListener* callback = new YYISpecificUserDataListener();
    callback->event = "GOG_User_SetUserData";
    galaxy::api::User()->SetUserData(key, value,callback);
}

YYEXPORT void GOG_User_GetUserDataCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    RValue* pV = &(arg[0]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);

    Result.kind = VALUE_REAL;
    Result.val = galaxy::api::User()->GetUserDataCount(userID);
}

YYEXPORT void GOG_User_GetUserDataByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    int index = YYGetReal(arg, 0);
    RValue* pV = &(arg[1]);
    galaxy::api::GalaxyID userID = GalaxyIDFromStruct(pV);
    
    char key[9999];
    char value[9999];

    galaxy::api::User()->GetUserDataByIndex(index,key,9999,value,9999,userID);

    RValue Struct = { 0 };
    YYStructCreate(&Struct);

    YYStructAddString(&Struct, "key", key);
    YYStructAddString(&Struct, "value", value);

    COPY_RValue(&Result, &Struct);
    FREE_RValue(&Struct);
}

YYEXPORT void GOG_User_DeleteUserData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* key = YYGetString(arg, 0);

    YYISpecificUserDataListener* callback = new YYISpecificUserDataListener();
    callback->event = "GOG_User_DeleteUserData";
    galaxy::api::User()->DeleteUserData(key,callback);
}

YYEXPORT void GOG_User_IsLoggedOn(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->IsLoggedOn();
}

//YYEXPORT void GOG_User_RequestEncryptedAppTicket(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//    galaxy::api::User()->RequestEncryptedAppTicket();
//}

//YYEXPORT void GOG_User_GetEncryptedAppTicket(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//    galaxy::api::User()->GetEncryptedAppTicket();
//}

YYEXPORT void GOG_User_GetSessionID(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    Result.kind = VALUE_REAL;
    Result.val = galaxy::api::User()->GetSessionID();
}

YYEXPORT void GOG_User_GetAccessToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    YYCreateString(&Result, galaxy::api::User()->GetAccessToken());
}

//YYEXPORT void GOG_User_GetAccessTokenCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//    //galaxy::api::User()->
//}

YYEXPORT void GOG_User_ReportInvalidAccessToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    const char* accessToken = YYGetString(arg, 0);
    const char* info = YYGetString(arg, 1);

    Result.kind = VALUE_BOOL;
    Result.val = galaxy::api::User()->ReportInvalidAccessToken(accessToken, info);
}


YYEXPORT void GOG_User_GetRefreshToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
    YYCreateString(&Result, galaxy::api::User()->GetRefreshToken());
}

//YYEXPORT void GOG_User_GetRefreshTokenCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//}
