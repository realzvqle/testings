#include "FileManagement/files.h"
#include "network/request.h"
#include <windows.h>

int main(int argc, char** argv) {
    const char* udk = CreateRequest("https://x.com");
    WriteContentToFile("idk.html", udk);
    printf("%s\n", udk);

    return 0;
}
