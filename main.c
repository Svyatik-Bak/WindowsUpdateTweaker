// libraries
#include <stdio.h>
#include <windows.h>

int var1; //variable
int main()
{
    system("title WindowsUpdateTweaker");
    printf("1. Disable Windows Update\n");
    printf("2. Enable Windows Update\n");
    printf("3. Disable drivers from Windows Update\n");
    printf("4. Enable drivers from Windows Update\n");
    for (int j = 0; j <= 1024; j+=1)
    {
    scanf_s("%i", &var1);
    switch(var1)
    {
    case 1: {
        DWORD number = 0x000000001;
        HKEY key;
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU", 0, KEY_SET_VALUE | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS)
        if (RegSetValueExW(key, L"NoAutoUpdate", 0, REG_DWORD, (LPBYTE)&number, sizeof(DWORD)) == ERROR_SUCCESS)
            printf("Windows Update was successfully disabled\n");
        RegCloseKey(key);
    } break;
    case 2: {
        DWORD number = 0x00000000;
        HKEY key;
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU", 0, KEY_SET_VALUE | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS)
        if (RegSetValueExW(key, L"NoAutoUpdate", 0, REG_DWORD, (LPBYTE)&number, sizeof(DWORD)) == ERROR_SUCCESS)
            printf("Windows Update was successfully enabled\n");
        RegCloseKey(key);
    } break;
    case 3: {
        DWORD number = 0x00000001;
        HKEY key;
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate", 0, KEY_SET_VALUE | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS)
        if (RegSetValueExW(key, L"ExcludeWUDriversInQualityUpdate", 0, REG_DWORD, (LPBYTE)&number, sizeof(DWORD)) == ERROR_SUCCESS)
            printf("Drivers from Windows Update was successfully disabled\n");
        RegCloseKey(key);
    } break;
    case 4: {
        HKEY key;
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate", 0, KEY_SET_VALUE | KEY_WOW64_64KEY, &key) == ERROR_SUCCESS)
        if (RegDeleteValue(key, L"ExcludeWUDriversInQualityUpdate") == ERROR_SUCCESS)
            printf("Drivers from Windows Update was successfully enabled\n");
        RegCloseKey(key);
    } break;
    case 5: {
        system("cls");
        printf("(C) Svyatik Bak\n");
        printf("License: GNU General Public License v3.0\n"); break;
    }
    case 6: {
        system("cls");
        system("more LICENSE.txt"); } break;
    }
}
}
