#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED





#include "../superheader.h"

CHAR* ReadContentFromFile(const CHAR* file);
BOOL WriteContentToFile(const CHAR* file, const CHAR* content);

#endif