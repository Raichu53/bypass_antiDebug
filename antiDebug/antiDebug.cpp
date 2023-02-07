#include "antiDebug.h"

bool jmpTo(uintptr_t* dst,uintptr_t* src);

bool disableDebuggerChecks()
{
	//resetPBE(GetPEB());
	if (IsDebuggerPresent()) {
		std::cout << "present";
	}
	return true;
}
PVOID GetPEB()
{
#ifdef _WIN64
	return (PVOID)__readgsqword(0x0C * sizeof(PVOID));
#else
	return (PVOID)__readfsdword(0x0C * sizeof(PVOID));
#endif
}
void resetPBE(PVOID ptrPEB) {
	((PEB*)(ptrPEB))->BeingDebugged = 0;

}

bool jmpTo(uintptr_t* dst,uintptr_t* funcPtr) {



	return true;
}