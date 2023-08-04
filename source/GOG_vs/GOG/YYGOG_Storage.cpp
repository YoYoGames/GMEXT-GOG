
#include "YYGOG.h"
#include <vector>

YYEXPORT void GOG_Storage_FileWrite(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* fileName = YYGetString(arg, 0);
	double buffer = YYGetReal(arg, 1);

	DebugConsoleOutput("GOG_Storage_FileWrite buffer: %i\n", buffer);

	unsigned char* buffer_data;
	int buffer_size;

	if (!BufferGetContent(static_cast<int32_t>(buffer), (void**)(&buffer_data), &buffer_size))
	{
		DebugConsoleOutput("GOG_Storage_FileWrite - error: specified buffer not found\n");
		return;
	}

	//if (size <= -1 || size > buffer_size) 
	//	size = buffer_size;
	DebugConsoleOutput("GOG_Storage_FileWrite size: %i\n", buffer_size);
	galaxy::api::Storage()->FileWrite(fileName, buffer_data, buffer_size);

	YYFree(buffer_data);
}

YYEXPORT void GOG_Storage_FileRead(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	const char* fileName = YYGetString(arg, 0);
	DebugConsoleOutput("GOG_Storage_FileRead\n");
	if (!galaxy::api::Storage()->FileExists(fileName))
	{
		DebugConsoleOutput("GOG_Storage_FileRead NO EXISTS\n");
		Result.kind = VALUE_REAL;
		Result.val = -1;
		return;
	}

	DebugConsoleOutput("GOG_Storage_FileRead EXISTS\n");

	int size = galaxy::api::Storage()->GetFileSize(fileName);


	DebugConsoleOutput("GOG_Storage_FileRead size: %i\n",size);

	std::vector<uint8_t> data;
	data.reserve(size);
	uint8_t* d = data.data();

	galaxy::api::Storage()->FileRead(fileName, d, size);

	int bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	BufferWriteContent(bufferID, 0, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Storage_FileDelete(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* fileName = YYGetString(arg, 0);
	galaxy::api::Storage()->FileDelete(fileName);
}

YYEXPORT void GOG_Storage_FileExists(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* fileName = YYGetString(arg, 0);
	Result.kind = VALUE_BOOL;
	Result.val = galaxy::api::Storage()->FileExists(fileName);
}

YYEXPORT void GOG_Storage_GetFileSize(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;
	
	const char* fileName = YYGetString(arg, 0);
	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetFileSize(fileName);
}

YYEXPORT void GOG_Storage_GetFileTimestamp(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* fileName = YYGetString(arg, 0);
	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetFileTimestamp(fileName);
}

YYEXPORT void GOG_Storage_GetFileCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetFileCount();
}

YYEXPORT void GOG_Storage_GetFileNameByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	double index = YYGetReal(arg, 0);
	YYCreateString(&Result, galaxy::api::Storage()->GetFileNameByIndex(static_cast<uint32_t>(index)));
}

//YYEXPORT void GOG_Storage_GetFileNameCopyByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Storage()->GetFileNameCopyByIndex();
//}

class YYIFileShareListener : public galaxy::api::IFileShareListener
{
public:
	virtual void OnFileShareSuccess(const char* fileName, galaxy::api::SharedFileID sharedFileID)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Storage_FileShare");
		DsMapAddInt64(map, "sharedFileID", sharedFileID);
		DsMapAddString(map, "fileName", fileName);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnFileShareFailure(const char* fileName, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Storage_FileShare");
		DsMapAddString(map, "fileName", fileName);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Storage_FileShare(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	const char* fileName = YYGetString(arg, 0);

	YYIFileShareListener* callback = new YYIFileShareListener();
	galaxy::api::Storage()->FileShare(fileName, callback);
}

class YYISharedFileDownloadListener : public galaxy::api::ISharedFileDownloadListener
{
public:
	virtual void OnSharedFileDownloadSuccess(galaxy::api::SharedFileID sharedFileID, const char* fileName)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Storage_DownloadSharedFile");
		DsMapAddInt64(map, "sharedFileID", sharedFileID);
		DsMapAddString(map, "fileName", fileName);
		CreateAsyncEventWithDSMap(map, 70);
	}
	virtual void OnSharedFileDownloadFailure(galaxy::api::SharedFileID sharedFileID, FailureReason failureReason)
	{
		int map = CreateDsMap(0, 0);
		DsMapAddString(map, "type", "GOG_Storage_DownloadSharedFile");
		DsMapAddInt64(map, "sharedFileID", sharedFileID);
		switch (failureReason)
		{
		case FailureReason::FAILURE_REASON_CONNECTION_FAILURE:DsMapAddString(map, "error", "FAILURE_REASON_CONNECTION_FAILURE"); break;
		case FailureReason::FAILURE_REASON_UNDEFINED: DsMapAddString(map, "error", "FAILURE_REASON_UNDEFINED"); break;
		}
		CreateAsyncEventWithDSMap(map, 70);
	}
};
YYEXPORT void GOG_Storage_DownloadSharedFile(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

	uint64_t sharedFileID = YYGetInt64(arg, 0);

	YYISharedFileDownloadListener* callback = new YYISharedFileDownloadListener();
	galaxy::api::Storage()->DownloadSharedFile(sharedFileID, callback);
}

YYEXPORT void GOG_Storage_GetSharedFileName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRING;

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	YYCreateString(&Result, galaxy::api::Storage()->GetSharedFileName(sharedFileID));
}

//YYEXPORT void GOG_Storage_GetSharedFileNameCopy(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	//galaxy::api::Storage()->GetSharedFileNameCopy
//}

YYEXPORT void GOG_Storage_GetSharedFileSize(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	Result.kind = VALUE_REAL;
	Result.val = galaxy::api::Storage()->GetSharedFileSize(sharedFileID);
}

YYEXPORT void GOG_Storage_GetSharedFileOwner(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_STRUCT;

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	galaxy::api::GalaxyID userID = galaxy::api::Storage()->GetSharedFileOwner(sharedFileID);

	RValue Struct = getStructFromGalaxyID(userID);


	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void GOG_Storage_SharedFileRead(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_REAL;

	uint64_t sharedFileID = YYGetInt64(arg, 0);
	
	int size = galaxy::api::Storage()->GetSharedFileSize(sharedFileID);

	std::vector<uint8_t> data;
	data.reserve(size);
	uint8_t* d = data.data();

	galaxy::api::Storage()->SharedFileRead(sharedFileID, d, size);

	int bufferID = CreateBuffer(size, eBuffer_Format_Fixed, 1);
	BufferWriteContent(bufferID, 0, d, size);

	Result.kind = VALUE_REAL;
	Result.val = bufferID;
}

YYEXPORT void GOG_Storage_SharedFileClose(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	GOG_NotInitialisedReturn_BOOL;

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

	double index = YYGetReal(arg, 0);

	Result.kind = VALUE_INT64;
	Result.v64 = galaxy::api::Storage()->GetDownloadedSharedFileByIndex(static_cast<uint32_t>(index));
}