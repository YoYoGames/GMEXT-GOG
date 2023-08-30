#include "Extension_Interface.h"

#include "YYRValue.h"

YYRunnerInterface gs_runnerInterface;
YYRunnerInterface* g_pYYRunnerInterface;

extern void OldPreGraphicsInitialisation();

YYEXPORT void YYExtensionInitialise(const struct YYRunnerInterface* _pFunctions, size_t _functions_size)
{
	//copy out all the functions 
	memcpy(&gs_runnerInterface, _pFunctions, sizeof(YYRunnerInterface));
	g_pYYRunnerInterface = &gs_runnerInterface;

	if (_functions_size < sizeof(YYRunnerInterface)) {
		DebugConsoleOutput("ERROR : runner interface mismatch in extension DLL\n ");
	} // end if

	DebugConsoleOutput("[GMEXT-GOG]: YYExtensionInitialise CONFIGURED \n ");

	OldPreGraphicsInitialisation();
}
