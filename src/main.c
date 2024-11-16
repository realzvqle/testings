#include "FileManagement/files.h"
#include "network/request.h"
#include <windows.h>

int main(int argc, char** argv) {
    const char* udk = CreateRequest("https://google.com");
    WriteContentToFile("idk.html", udk);
    printf("%s\n", udk);
    //naettFree(res);

    return 0;
}
