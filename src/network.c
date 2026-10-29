
#include "network.h"

static size_t receive_data(char *data, size_t size, size_t count, void *userdata)
{
    (void)userdata;

    return fwrite(data, size, count, stdout);
}

void make_request(const char *url, const char *headers[], int header_no, int argc, const char *body)
{
int full_request;

if(argc > 1)
  {
   full_request = 1;
  }

    CURL *curl = curl_easy_init();

    struct curl_slist *curl_headers = NULL;

    for (int i = 0; i < header_no; i++)
    {
        struct curl_slist *updated =
            curl_slist_append(curl_headers, headers[i]);

        if (updated == NULL)
        {
            fprintf(stderr, "Failed to add HTTP header.\n");
            curl_slist_free_all(curl_headers);
            curl_easy_cleanup(curl);
            return;
        }

        curl_headers = updated;
    }

    if (curl == NULL)
    {
        printf("Failed to initialize CURL.\n");
        return;
    }

    if (header_no == 0)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Keylyzer/0.1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receive_data);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15L);
        if(full_request == 1)
        {
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        }
        if (body != NULL) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
}
    }

    else if (header_no == 1)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Keylyzer/0.1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receive_data);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_headers);
        if(full_request == 1)
        {
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        }
        if (body != NULL) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
}
    }

    else if (header_no == 2)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Keylyzer/0.1.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receive_data);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_headers);
        if(full_request == 1)
        {
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        }
        if (body != NULL) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
}
    }

    CURLcode result = curl_easy_perform(curl);

    if (result == CURLE_OK)
    {
        long status = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
        printf("\nHTTP Status: %ld\n", status);
    }
    else
    {
        printf("\nRequest failed: %s\n",
               curl_easy_strerror(result));
    }

    curl_easy_cleanup(curl);
}

static int decode_part(const char *input, char *output, size_t size)
{
    const char *table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

    unsigned int buffer = 0;
    int bits = 0;
    size_t j = 0;

    for (size_t i = 0; input[i]; i++) 
    {
        const char *p = strchr(table, input[i]);
        if (!p) return 0;

        buffer = (buffer << 6) | (unsigned int)(p - table);
        bits += 6;

        if (bits >= 8) 
        {
            bits -= 8;
            if (j + 1 >= size) return 0;
            output[j++] = (char)((buffer >> bits) & 255);
        }
    }

    output[j] = '\0';
    return 1;
}

int jwt_analyzer(const char *key)
{
    char token[10000], header[3000], payload[6000];

    if (!key || strlen(key) >= sizeof(token)) 
    {
        printf("Invalid jwt\n");
        return 1;
    }

    strcpy(token, key);

    char *h = strtok(token, ".");

    char *p = strtok(NULL, ".");

    if (!h || !p || !decode_part(h, header, sizeof(header)) || !decode_part(p, payload, sizeof(payload))) {
        printf("Invalid JWT format or encoding\n");
        return 1;
    }


    printf("\n--- JWT Header ---\n%s\n", header);

    printf("\n--- JWT Payload ---\n%s\n", payload);

    return 0;
}
