#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>

#include "fat_process.h"

int main(int argc, char *argv[])
{
    char* szFilename = 0;
    char* szFilename_FAT1 = 0;
    char* szFilename_FAT2 = 0;
    int   nPatchFat = 0;
    int   nReturnValue = 0;

    if (argc == 4)
    {
        szFilename = argv[1];
        szFilename_FAT1 = argv[2];
        szFilename_FAT2 = argv[3];
        nPatchFat = 0;
    }
    else if (argc == 5)
    {
        szFilename = argv[1];
        szFilename_FAT1 = argv[2];
        szFilename_FAT2 = argv[3];
        nPatchFat = 0;

        if (0 != strcmp(argv[4], "--patch"))
        {
            nReturnValue = -1;
            goto usage;
        }
        else
        {
            nPatchFat = 1;
        }
    }
    else
    {
        nReturnValue = -1;
        goto usage;
    }

    nReturnValue = process_image_file(szFilename, szFilename_FAT1, szFilename_FAT2, nPatchFat);
    goto exit;

usage:
    fprintf(stderr, "Usage: %s [input file] [output file 1] [output file 2] [--patch]\n", argv[0]);

exit:
#ifdef _DEBUG
    system("pause");
#endif

    return nReturnValue;
}
