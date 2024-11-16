#include "files.h"
#include <errhandlingapi.h>
#include <fileapi.h>
#include <handleapi.h>
#include <winnt.h>



CHAR* ReadContentFromFile(const CHAR* file) {
    HANDLE hFile = CreateFileA(
        file,
        GENERIC_READ,
        0,                 
        NULL,               
        OPEN_EXISTING,      
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (hFile == INVALID_HANDLE_VALUE) {
        ShowFormattedMessageBox(GetLastError());
        return NULL;
    }

    LARGE_INTEGER fileSize;
    if (!GetFileSizeEx(hFile, &fileSize)) {
        ShowFormattedMessageBox(GetLastError());
        CloseHandle(hFile);
        return NULL;
    }

    if (fileSize.QuadPart > MAXDWORD) {
        printf("File is too large to be read.\n");
        CloseHandle(hFile);
        return NULL;
    }

    DWORD bufferSize = (DWORD)fileSize.QuadPart;
    CHAR* buffer = (CHAR*)malloc(bufferSize + 1); 
    if (!buffer) {
        printf("Failed to allocate memory for buffer.\n");
        CloseHandle(hFile);
        return NULL;
    }

    DWORD bytesRead = 0;
    BOOL result = ReadFile(
        hFile, 
        buffer, 
        bufferSize, 
        &bytesRead, 
        NULL
    );
    if (!result) {
        DWORD error = GetLastError();
        printf("Failed to read file. Error: %lu\n", error);
        free(buffer);
        CloseHandle(hFile);
        return NULL;
    }

    buffer[bytesRead] = '\0';

    CloseHandle(hFile);

    return buffer;
}

BOOL WriteContentToFile(const CHAR* file, const CHAR* content){
    HANDLE hFile = CreateFileA(
        file,
        GENERIC_WRITE,
        0,                 
        NULL,               
        OPEN_ALWAYS,      
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (hFile == INVALID_HANDLE_VALUE) {
        ShowFormattedMessageBox(GetLastError());
        return FALSE;
    }
    BOOL result = WriteFile(
        hFile,
        content,
        strlen(content),
        NULL,
        NULL
    );
    if(!result){
        ShowFormattedMessageBox(GetLastError());
        return FALSE;
    }
    return TRUE;
}