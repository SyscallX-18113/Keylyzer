#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>
#include <curl/curl.h>
#include <string.h>


void make_request(const char *url, const char *headers[], int header_no, int argc, const char *body);
int jwt_analyzer(const char *key);


#endif
