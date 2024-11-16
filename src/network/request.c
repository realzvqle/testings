#include "request.h"





const char* CreateRequest(const char* url){
    naettInit(NULL);

    naettReq* req = naettRequest(
        url,
        naettMethod("GET"),
        naettHeader("accept", "*/*") 
    );

    naettRes* res = naettMake(req);

    while (!naettComplete(res)) {
        Sleep(100); 
    }

    if (naettGetStatus(res) < 0) {
        printf("Request failed\n");
        naettFree(req);
        return NULL;
    }

    int bodyLength = 0;
    const char* body = naettGetBody(res, &bodyLength);

    

    naettFree(req);
    return body;
}

