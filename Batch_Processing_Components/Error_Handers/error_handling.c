#include "error_handling.h"

NO_RETURN void error_handle(uint8_t errorCode) {
    fprintf(stderr, "FATAL ERROR: ");
    switch(errorCode) {
        case 1:
            fprintf(stderr, "Invalid input file path.\n");
            break;
        case 2:
            fprintf(stderr, "Failed to parse coordinates.\n");
            break;
        case 3:
            fprintf(stderr, "Memory allocation failed.\n");
            break;
        default:
            fprintf(stderr, "An unknown error occurred (Code: %u).\n", errorCode);
            break;
    }
    exit(errorCode != 0 ? errorCode : 1);
}