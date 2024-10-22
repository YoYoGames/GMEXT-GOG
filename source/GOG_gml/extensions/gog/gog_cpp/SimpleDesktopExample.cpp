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
		DebugConsoleOutput("[GMEXT-GOG]: ERROR : YYRunnerInterface mismatch, expected sizeof %d got %d\n",
			static_cast<int>(sizeof(YYRunnerInterface)),
			static_cast<int>(_functions_size));
	} // end if

	DebugConsoleOutput("[GMEXT-GOG]: YYExtensionInitialise CONFIGURED, size=%d\n", static_cast<int>(_functions_size));

	OldPreGraphicsInitialisation();
}
