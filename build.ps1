g++ -o bsodc.exe code.cpp -lkernel32 -lntdll
nasm ./bsod.asm -o bsod.obj -f win64
.\GoLink.exe bsod.obj /entry main kernel32.dll ntdll.dll user32.dll
rm bsod.obj