
#include "YYGOG.h"
#include <vector>

YYEXPORT void GOG_Storage_FileWrite(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(2);

	const char* fileName = YYGetString(arg, 0);
	double buffer = YYGetReal(arg, 1);

	unsigned char* buffer_data = nullptr;
	int buffer_size = 0;

	if (!BufferGetContent(static_cast<int32_t>(buffer), (void**)(&buffer_data), &buffer_size))
	{
		DebugConsoleOutput("[GMEXT-GOG]: GOG_Storage_FileWrite - error: specified buffer not found\n");
		return;
	}

	galaxy::api::Storage()->FileWrite(fileName, buffer_data, buffer_size);

	YYFree(buffer_data);
}

YYEXPORT void GOG_Storage_FileRead(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	const char* fileName = YYGetString(arg, 0);
	int bufferID = (argc > 1) ? YYGetInt32(arg, 1) : -1;
	int byteOffset = (argc > 2) ? YYGetInt32(arg, 2) : 0;

	if (!galaxy::api::Storage()->FileExists(fileName))
	{
		Result.kind = VALUE_REAL;
		Result.val = -1;
		return;
	}

	uint32_t size = galaxy::api::Storage()->GetFileSize(fileName);
	std::vector<uint8_t> data;
	data.resize(size);
	uint8_t* d = data.data();

	// returns how many bytes were actually written
	size = galaxy::api::Storage()->FileRead(fileName, d, size);

	if (bufferID < 0)
	{
		bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	}
	BufferWriteContent(bufferID, byteOffset, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Storage_FileDelete(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* fileName = YYGetString(arg, 0);
	galaxy::api::Storage()->FileDelete(fileName);
}

YYEXPORT void GOG_Storage_FileExists(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* fileName = YYGetString(arg, 0);
	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Storage()->FileExists(fileName);
}

YYEXPORT void GOG_Storage_GetFileSize(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);
	
	const char* fileName = YYGetString(arg, 0);
	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetFileSize(fileName);
}

YYEXPORT void GOG_Storage_GetFileTimestamp(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	const char* fileName = YYGetString(arg, 0);
	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetFileTimestamp(fileName);
}

YYEXPORT void GOG_Storage_GetFileCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetFileCount();
}

YYEXPORT void GOG_Storage_GetFileNameByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	double index = YYGetReal(arg, 0);
	YYCreateString(&Result, galaxy::api::Storage()->GetFileNameByIndex(static_cast<uint32_t>(index)));
}

YYEXPORT void GOG_Storage_FileShare(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	const char* fileName = YYGetString(arg, 0);

	galaxy::api::Storage()->FileShare(fileName);
}

YYEXPORT void GOG_Storage_DownloadSharedFile(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	uint64_t sharedFileID = YYGetInt64(arg, 0);

	galaxy::api::Storage()->DownloadSharedFile(sharedFileID);
}

YYEXPORT void GOG_Storage_GetSharedFileName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;
	GOG_EnsureArgc(1);

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	YYCreateString(&Result, galaxy::api::Storage()->GetSharedFileName(sharedFileID));
}

YYEXPORT void GOG_Storage_GetSharedFileSize(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetSharedFileSize(sharedFileID);
}

YYEXPORT void GOG_Storage_GetSharedFileOwner(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;
	GOG_EnsureArgc(1);

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	galaxy::api::GalaxyID userID = galaxy::api::Storage()->GetSharedFileOwner(sharedFileID);

	RValue Struct = getStructFromGalaxyID(userID);


	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Storage_SharedFileRead(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;
	GOG_EnsureArgc(1);

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	int bufferID = (argc > 1) ? YYGetInt32(arg, 1) : -1;
	int byteOffset = (argc > 2) ? YYGetInt32(arg, 2) : 0;
	
	uint32_t size = galaxy::api::Storage()->GetSharedFileSize(sharedFileID);

	std::vector<uint8_t> data;
	data.resize(size);
	uint8_t* d = data.data();

	// returns the actual amount written to buffer
	size = galaxy::api::Storage()->SharedFileRead(sharedFileID, d, size);

	if (bufferID < 0)
	{
		bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	}
	BufferWriteContent(bufferID, byteOffset, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Storage_SharedFileClose(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	GOG_EnsureArgc(1);

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	galaxy::api::Storage()->SharedFileClose(sharedFileID);
}

YYEXPORT void GOG_Storage_GetDownloadedSharedFileCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetDownloadedSharedFileCount();
}

YYEXPORT void GOG_Storage_GetDownloadedSharedFileByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_INT64;
	GOG_EnsureArgc(1);

	double index = YYGetReal(arg, 0);

	Result.kind = VALUE_INT64;
	Result.v64 = galaxy::api::Storage()->GetDownloadedSharedFileByIndex(static_cast<uint32_t>(index));
}