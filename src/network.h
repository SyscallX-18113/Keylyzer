// Please download last release version currently the code is broken and in Development and Commit of next version
#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>

#define RED     "\033[1;31m"
#define RESET   "\033[0m"

void make_request(const char *url, const char *headers[], int header_no, int argc, const char *body);
int jwt_analyzer(const char *key);

#endif
