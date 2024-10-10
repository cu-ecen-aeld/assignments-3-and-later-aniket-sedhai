#include <stdio.h>
#include <syslog.h>

int main(int argc, char* argv[])
{
    /* there should be 3 arguments*/
    if (argc != 3)
    {
        return 1;
    }

    //log all levels
    setlogmask(LOG_UPTO (LOG_DEBUG));

    // open the log
    openlog("WriterLog", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    FILE* fptr = NULL;

    //open the file
    fptr = fopen(argv[1], "w");
    if (fptr == NULL)
    {
        syslog(LOG_ERR, "Could not open %s\n", argv[1]);
        return 1;
    }

    else
    {
        syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2], argv[1]);
        fprintf(fptr, "%s", argv[2]);
        fclose(fptr);
    }

    closelog();

    return 0;
}
