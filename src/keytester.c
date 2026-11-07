/*
 * Copyright (c) 2026 Devesh Kachhawaha (SyscallX-18113)
 *
 * Licensed under the Apache License, Version 2.0.
 * See the LICENSE file in the project root for license information.
 */

#include "keytester.h"

int input_1(char *key, size_t size)
{
    struct termios old, new;

    if (tcgetattr(STDIN_FILENO, &old) == -1)
        return 1;

    new = old;
    new.c_lflag &= ~ECHO;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &new) == -1)
        return 1;

    int result = scanf("%8095s", key);

    tcsetattr(STDIN_FILENO, TCSANOW, &old);

    printf("\n");

    if (result != 1)
        return 1;

    return 0;
}

int api_tester(int command, int argc)
{
    printf("\n");

    fflush(stdout);

    if (command == 1)
    {
        printf("\nEnter Github Token: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        const char *body = NULL;
        printf("\n[*] Analyzing Github Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);
        fflush(stdout);
        const char *headers[] = {auth_header, "Accept: application/vnd.github+json"};

        const char *url = "https://api.github.com/user";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 2)
    {
        printf("\nEnter Gitlab Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));


        printf("\n[*] Analyzing Gitlab Token...\n\n");
        sleep(1);
        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "PRIVATE-TOKEN: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://gitlab.com/api/v4/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 3)
    {
        printf("\nEnter Google API Key: ");
char key[BUF_SIZE];
        input_1(key, sizeof(key));

        urls google_urls[] =
            {
                {"Google Maps Geocoding Api Key\n", "https://maps.googleapis.com/maps/api/geocode/json?latlng=40,30&key=%s"},
                {"Google Maps Find Place From Text API key\n", "https://maps.googleapis.com/maps/api/place/findplacefromtext/json?input=MuseumofContemporaryArtAustralia&inputtype=textquery&fields=photos,formatted_address,name,rating,opening_hours,geometry&key=%s"},
                {"Google Maps Static Api Key\n", "https://maps.googleapis.com/maps/api/staticmap?center=45C10&zoom=7&size=400x400&key=%s"},
                {"Google Maps Streetview Key\n", "https://maps.googleapis.com/maps/api/streetview?size=400x400&location=40.720032,-73.988354&fov=90&heading=235&pitch=10&key=%s"},
                {"Google Maps Embed Key\n", "https://www.google.com/maps/embed/v1/place?q=place_id:ChIJyX7muQw8tokR2Vf5WBBk1iQ&key=%s"},
                {"Google Maps Directions Key\n", "https://maps.googleapis.com/maps/api/directions/json?origin=Disneyland&destination=Universal+Studios+Hollywood4&key=%s"},
                {"Google Maps Distance Matrix\n", "https://maps.googleapis.com/maps/api/distancematrix/json?units=imperial&origins=40.6655101,-73.89188969999998&destinations=40.6905615C-73.9976592C40.6905615C-73.99765927C40.69056152C-73.9976592%7C40.69056152C-73.99765927C40.69056152C-73.99765927C40.69056152C-73.99765927C40.6595692C-73.9337837C40.729029C-73.8515247C40.68600722C-73.63342717C40.5985662C-73.75276267C40.6595692C-73.9337837C40.7290292C-73.8515247C40.68600722C-73.63342717C40.5985662C-73.7527626&key=%s"},
                {"Google Maps Autocomplete Key\n", "https://maps.googleapis.com/maps/api/place/autocomplete/json?input=Bingh&types=%28cities%29&key=%s"},
                {"Google Maps Elevation Key\n", "https://maps.googleapis.com/maps/api/elevation/json?locations=39.7391536,-104.9847034&key=%s"},
                {"Google Maps Timezone Key\n", "https://maps.googleapis.com/maps/api/timezone/json?location=39.6034810,-119.6822510&timestamp=1331161200&key=%s"},
                {"Google Maps Roads Key\n", "https://roads.googleapis.com/v1/nearestRoads?points=60.170880,24.942795|60.170879,24.942796|60.170877,24.942796&key=%s"},
                {"Cloud Natural Language API\n", "https://language.googleapis.com/v1/documents:analyzeSentiment?key=%s"},
                {"Cloud Translation API\n", "https://translation.googleapis.com/language/translate/v2/languages?key=%s"},
                {"YouTube Data API\n", "https://www.googleapis.com/youtube/v3/search?part=snippet&q=test&key=%s"},
                {"Google Custom Search JSON API\n", "https://www.googleapis.com/customsearch/v1?key=%s&cx=017576662512468239146:omuauf_lfve&q=test"},
                {"Gemini / Generative Language API\n", "https://generativelanguage.googleapis.com/v1beta/models?key=%s"},
                {"Cloud Text-to-Speech API\n", "https://texttospeech.googleapis.com/v1/voices?key=%s"},
                {"Books API\n", "https://www.googleapis.com/books/v1/volumes?q=test&key=%s"},
                {"Safe Browsing API\n", "https://safebrowsing.googleapis.com/v4/threatMatches:find?key=%s"},
                {"Knowledge Graph Search API\n", "https://kgsearch.googleapis.com/v1/entities:search?query=test&key=%s"},

        };
        printf("\n[*] Analyzing Google Api Key...\n\n");
        sleep(1);
        int total_urls = sizeof(google_urls) / sizeof(google_urls[0]);

        if (1)
        {

            for (int i = 0; i < total_urls; i++)
            {
                const char *body = NULL;
                fflush(stdout);

                char auth_header[8096];
                char auth_url[8096];

                snprintf(auth_url, sizeof(auth_url), google_urls[i].urls, key);

                fflush(stdout);

                printf("Testing %s\n", google_urls[i].description);
                sleep(2);
                const char *headers[] = {auth_header};
                const char *url = auth_url;

                fflush(stdout);

                make_request(url, headers, 0, argc, body);
                auth_url[0] = '\0';
            }

            fflush(stdout);
        }

        urls google_urls_1[] =
            {
                {"Google Vision API\n", "https://vision.googleapis.com/v1/images:annotate"},
                {"Google Video Intelligence\n", "https://videointelligence.googleapis.com/v1/videos:annotate"},
                {"Google Drive API\n", "https://www.googleapis.com/drive/v3/about"},
                {"Google Calendar API\n", "https:/www.googleapis.com/calendar/v3/users/me/calendarList"},
        };

        int total_urls_1 = sizeof(google_urls_1) / sizeof(google_urls_1[0]);
        if (1)
        {

            for (int i = 0; i < total_urls_1; i++)
            {
                const char *body = NULL;
                fflush(stdout);

                char auth_header[8096];

                snprintf(auth_header, sizeof(auth_header), "x-goog-api-key: %s", key);

                fflush(stdout);
                printf("Testing %s\n", google_urls_1[i].description);
                sleep(2);

                const char *headers[] = {auth_header};
                const char *url = google_urls_1[i].urls;

                fflush(stdout);

                make_request(url, headers, 1, argc, body);
                url = '\0';
                auth_header[0] = '\0';
            }
            fflush(stdout);
        }
    }

    if (command == 4)
    {
        printf("\nEnter Resend API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        printf("\n[*] Analyzing Resend API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.resend.com/domains";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 5)
    {
        printf("\nEnter Open AI API key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        printf("\n[*] Analyzing Open AI Api Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.openai.com/v1/models";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 6)
    {
        printf("\nEnter Discord Bot Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        printf("\n[*] Analyzing Discord Bot Token...\n\n");
        sleep(1);
        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bot %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://discord.com/api/v10/users/@me";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 7)
    {
        printf("\nEnter Slack Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        const char *body = NULL;
        printf("\n[*] Analyzing Slack Token...\n\n");
        sleep(1);
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://slack.com/api/auth.test";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 8)
    {
        printf("\nEnter Stripe Secret Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        printf("\n[*] Analyzing Stripe Secret Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.stripe.com/v1/account";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 9)
    {
        printf("\nEnter JWT Token: ");
        char key[20000];
        input_1(key, sizeof(key));

        fflush(stdout);

        printf("\n[*] Analyzing JWT...\n\n");
        sleep(1);

        jwt_analyzer(key);

        fflush(stdout);
    }

    if (command == 10)
    {
        printf("\nEnter Twillio Auth Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        char sid[4096];
        const char *body = NULL;
        printf("Enter Sid: ");

        if (scanf("%4095s", sid) != 1)
        {
            fprintf(stderr, "Failed to read SID\n");
            return 1;
        }

        printf("\n[*] Analyzing Twillio Auth Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", sid, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        char url[4036];
        snprintf(url, sizeof(url), "https://api.twilio.com/2010-04-01/Accounts/%s.json", sid);

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 11)
    {
        printf("\nEnter Sendgrid Api Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));

        printf("\n[*] Analyzing Sendgrid Api Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.sendgrid.com/v3/scopes";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 12)
    {
        printf("\nEnter Mailgun Api Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Mailgun Api Key...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(api:%s)", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.mailgun.net/v3/domains";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 13)
    {
        printf("\nEnter Cloudflare Api Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Cloudflare Api Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.cloudflare.com/client/v4/user/tokens/verify";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 14)
    {
        printf("\nEnter DigitalOcean PAT: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing DigitalOcean PAT...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.digitalocean.com/v2/account";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 15)
    {
        printf("\nEnter Heroku Api Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Heroku Api Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);
        fflush(stdout);
        const char *headers[] = {auth_header, "Accept: application/vnd.heroku+json;"};

        const char *url = "https://api.heroku.com/account";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 16)
    {
        printf("\nEnter NPM Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing NPM Access Token...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://registry.npmjs.org/-/whoami";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 17)
    {
        printf("\nEnter PyPi Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing PyPi Token...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer base64(__token__:%s)", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://upload.pypi.org/legacy/";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 18)
    {
        printf("\nEnter Telegram Bot Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Telegram Bot Token...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];
        char auth_url[10000];

        snprintf(auth_url, sizeof(auth_url), "https://api.telegram.org/bot%s/getMe", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    // command 19 later google

    // command 20 later Azure

    if (command == 21)
    {
        printf("\nEnter Notion Integration Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Notion Integration Token...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);
        fflush(stdout);
        const char *headers[] = {auth_header, "Notion-Version: 2022-06-28"};

        const char *url = "https://api.notion.com/v1/users/me";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 22)
    {
        printf("\nEnter Airtable Personal Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Airtable Personal Access Token...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.airtable.com/v0/meta/whoami";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 23)
    {
        printf("\nEnter Postman API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Postman API Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "X-Api-Key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.getpostman.com/me";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 24)
    {
        printf("\nEnter Vercel API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Vercel API Token...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.vercel.com/v2/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 25)
    {
        printf("\nEnter Netlify Personal Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Netlify Personal Access Token...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.netlify.com/api/v1/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 26)
    {
        printf("\nEnter PagerDuty API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing PagerDuty API Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Token token=%s", key);
        fflush(stdout);
        const char *headers[] = {auth_header, "Accept: application/vnd.pagerduty+json;version=2"};

        const char *url = "https://api.pagerduty.com/users/me";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 27)
    {
        printf("\nEnter Shodan API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Shodan API Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];
        char auth_url[10000];

        snprintf(auth_url, sizeof(auth_url), "https://api.shodan.io/api-info?key=%s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    if (command == 28)
    {
        printf("\nEnter VirusTotal API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing VirusTotal API Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "x-apikey: %s", key);
        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://www.virustotal.com/api/v3/ip_addresses/8.8.8.8";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 29)
    {
        printf("\nEnter Firebase Web API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Firebase Web API Key...\n\n");
        sleep(1);

        fflush(stdout);
        const char *body = NULL;
        char auth_header[8096];
        char auth_url[10000];

        snprintf(auth_url, sizeof(auth_url), "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=%s", key);

        fflush(stdout);

        const char *headers[] = {"Content-Type: application/json"};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 30)
    {
        printf("\nEnter Hugging Face API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Hugging Face API Token...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://huggingface.co/api/whoami-v2";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 31)
    {
        printf("\nEnter OpenWeatherMap API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing OpenWeatherMap API Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];
        char auth_url[10000];

        snprintf(auth_url, sizeof(auth_url), "https://api.openweathermap.org/data/2.5/weather?q=London&appid=%s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    if (command == 32)
    {
        printf("\nEnter Mapbox Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Mapbox Access Token...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];
        char auth_url[10000];

        snprintf(auth_url, sizeof(auth_url), "https://api.mapbox.com/tokens/v2?access_token=%s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    if (command == 33)
    {

        printf("\nEnter Algolia API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        char app_id[4096];
        const char *body = NULL;
        printf("Enter App ID: ");

        if (scanf("%4095s", app_id) != 1)
        {
            fprintf(stderr, "Failed to read App ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Algolia Admin API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_2[6000];
        char auth_url[10000];

        snprintf(auth_header_2, sizeof(auth_header_2), "X-Algolia-Application-Id: %s", app_id);
        snprintf(auth_url, sizeof(auth_url), "https://%s.algolia.net/1/keys/%s", app_id, key);
        snprintf(auth_header, sizeof(auth_header), "X-Algolia-API-Key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header, auth_header_2};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 34)
    {
        printf("\nEnter Supabase API Key: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        char project_url[4096];
        const char *body = NULL;
        printf("Enter Project ID: ");

        if (scanf("%4095s", project_url) != 1)
        {
            fprintf(stderr, "Failed to read Project ID\n");
            return 1;
        }

        char authorization_key[4096];

        printf("Enter Authorization Bearer: ");

        if (scanf("%4095s", project_url) != 1)
        {
            fprintf(stderr, "Failed to read Authorization Bearer\n");
            return 1;
        }

        printf("\n[*] Analyzing Supabase Service Role Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_2[6000];
        char auth_url[10000];

        snprintf(auth_header_2, sizeof(auth_header_2), "Authorization: Bearer %s", authorization_key);
        snprintf(auth_url, sizeof(auth_url), "https://%s.supabase.co/rest/v1/", project_url);
        snprintf(auth_header, sizeof(auth_header), "apikey: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header, auth_header_2};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 35)
    {
        printf("\nEnter PlanetScale Service Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        const char *body = NULL;
        printf("\n[*] Analyzing PlanetScale Service Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.planetscale.com/v1/organizations";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 36)
    {
        printf("\nEnter New Relic API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        const char *body = NULL;
        printf("\n[*] Analyzing New Relic API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "X-Api-Key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.newrelic.com/v2/users.json";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 37)
    {
        printf("\nEnter Datadog API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        const char *body = NULL;
        printf("\n[*] Analyzing Datadog API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "DD-API-KEY: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.datadoghq.com/api/v1/validate";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 38)
    {
        printf("\nEnter Sentry Auth Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        const char *body = NULL;
        printf("\n[*] Analyzing Sentry Auth Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://sentry.io/api/0/organizations/";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 39)
    {
        printf("\nEnter Docker Hub Personal Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        const char *body = NULL;
        char username[4096];

        printf("Enter Username: ");

        if (scanf("%4095s", username) != 1)
        {
            fprintf(stderr, "Failed to read Username\n");
            return 1;
        }

        printf("\n[*] Analyzing Docker Hub Personal Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        char auth_url[10000];

        snprintf(auth_url, sizeof(auth_url), "https://hub.docker.com/v2/repositories/%s/", username);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 40)
    {
        printf("\nEnter Spotify API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char client_id[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Spotify API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        const char *body = "grant_type=client_credentials";

        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", client_id, key);

        fflush(stdout);

        const char *headers[] = {auth_header, "Content-Type: application/x-www-form-urlencoded"};
        const char *url = "https://accounts.spotify.com/api/token";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 41)
    {
        printf("\nEnter Reddit API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char client_id[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Reddit API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        const char *body = "grant_type=client_credentials";

        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", client_id, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://www.reddit.com/api/v1/access_token";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 42)
    {
        printf("\nEnter Twitch API Key: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        char client_id[4096];
        char body_1[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Twitch API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        snprintf(body_1, sizeof(body_1), "client_id=%s&client_secret=%s&grant_type=client_credentials", client_id, key);
        const char *body = body_1;

        snprintf(auth_header, sizeof(auth_header), "Content-Type: application/x-www-form-urlencoded");

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://www.reddit.com/api/v1/access_token";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 43)
    {
        printf("\nEnter Anthropic API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Anthropic API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "x-api-key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header, "anthropic-version: 2023-06-01"};
        const char *url = "https://api.anthropic.com/v1/models";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 44)
    {
        printf("\nEnter Groq API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Groq API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.groq.com/openai/v1/models";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 45)
    {
        printf("\nEnter Cohere API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Cohere API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.cohere.ai/v1/check-api-key";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 46)
    {
        printf("\nEnter Replicate API Token: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Replicate API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.replicate.com/v1/account";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 47)
    {
        printf("\nEnter ElevenLabs API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing ElevenLabs API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "xi-api-key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.elevenlabs.io/v1/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 48)
    {
        printf("\nEnter Figma Personal Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Figma Personal Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "X-Figma-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.figma.com/v1/me";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 49)
    {
        printf("\nEnter Linear API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        char body_1[4096];
        printf("\n[*] Analyzing Linear API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
snprintf(body_1, sizeof(body_1), "{\"query\": \"{ __typename }\"}");
        const char *body = body_1;

        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header, "Content-Type: application/json"};
        const char *url = "https://api.linear.app/graphql";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 50)
    {
        printf("\nEnter Trello API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char token[4096];

        printf("Enter Token: ");

        if (scanf("%4095s", token) != 1)
        {
            fprintf(stderr, "Failed to read Token\n");
            return 1;
        }

        printf("\n[*] Analyzing Trello API Key + Token ...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[8096];

        snprintf(auth_url, sizeof(auth_url), "https://api.trello.com/1/members/me?key=%s&token=%s", key, token);

        const char *body = NULL;

        fflush(stdout);

        const char *headers[] = {auth_header, "Content-Type: application/json"};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 51)
    {
        printf("\nEnter Bitbucket Password: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char username[4096];

        printf("Enter Username: ");

        if (scanf("%4095s", username) != 1)
        {
            fprintf(stderr, "Failed to read Username\n");
            return 1;
        }

        printf("\n[*] Analyzing Bitbucket App Username + Password ...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", username, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.bitbucket.org/2.0/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 52)
    {
        printf("\nEnter Intercom Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Intercom Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header, "Accept: application/json"};
        const char *url = "https://api.intercom.io/me";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 53)
    {
        printf("\nEnter Buildkite API Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Buildkite API Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.buildkite.com/v2/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 54)
    {
        printf("\nEnter Asana Personal Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Asana Personal Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://app.asana.com/api/1.0/users/me";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 55)
    {

        printf("\nEnter Monday.com API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Monday.com API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header, "Content-Type: application/json"};
        const char *url = "https://api.monday.com/v2";

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 56)
    {
        printf("\nEnter ClickUp API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing ClickUp API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.clickup.com/api/v2/user";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 57)
    {
        printf("\nEnter Dropbox Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Dropbox Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.dropboxapi.com/2/users/get_current_account";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 58)
    {
        printf("\nEnter Box API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Box API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.box.com/2.0/users/me";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 59)
    {
        printf("\nEnter Render API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Render API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.render.com/v1/users";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 60)
    {
        printf("\nEnter Scaleway API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Scaleway API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;
        snprintf(auth_header, sizeof(auth_header), "X-Auth-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.scaleway.com/account/v2/projects";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 61)
    {
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        // coming  soon
        char client_id[4096];
        char tenant_id[4096];
        char body_1[4096];

        printf("Enter Tenant ID: ");

        if (scanf("%4095s", tenant_id) != 1)
        {
            fprintf(stderr, "Failed to read Tenant ID\n");
            return 1;
        }

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Azure AD / Entra App Client Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        snprintf(body_1, sizeof(body_1), "client_id=%s&client_secret=%s&grant_type=client_credentials&scope=https://graph.microsoft.com/.default", client_id, key);

        const char *body = body_1;
        snprintf(auth_url, sizeof(auth_url), "https://login.microsoftonline.com/%s/oauth2/v2.0/token", tenant_id);
        snprintf(auth_header, sizeof(auth_header), "Content-Type: application/x-www-form-urlencoded");

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);
    }

    if (command == 62)
    {
        printf("\nEnter Azure Client Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char client_id[4096];
        char tenant_id[4096];
        char body_1[4096];

        printf("Enter Tenant ID: ");

        if (scanf("%4095s", tenant_id) != 1)
        {
            fprintf(stderr, "Failed to read Tenant ID\n");
            return 1;
        }

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Azure AD / Entra App Client Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        snprintf(body_1, sizeof(body_1), "client_id=%s&client_secret=%s&grant_type=client_credentials&scope=https://graph.microsoft.com/.default", client_id, key);

        const char *body = body_1;
        snprintf(auth_url, sizeof(auth_url), "https://login.microsoftonline.com/%s/oauth2/v2.0/token", tenant_id);
        snprintf(auth_header, sizeof(auth_header), "Content-Type: application/x-www-form-urlencoded");

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 63)
    {
        printf("\nEnter HashiCorp Vault Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char vault_id[4096];

        printf("Enter Vault Host Only Not Full Url: ");

        if (scanf("%4095s", vault_id) != 1)
        {
            fprintf(stderr, "Failed to read Vault Host\n");
            return 1;
        }

        printf("\n[*] Analyzing HashiCorp Vault Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;

        snprintf(auth_url, sizeof(auth_url), "https://%s:8200/v1/auth/token/lookup-self", vault_id);
        snprintf(auth_header, sizeof(auth_header), "X-Vault-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 64)
    {
        printf("\nEnter Jenkins API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char username[4096];

        printf("Enter Username: ");

        if (scanf("%4095s", username) != 1)
        {
            fprintf(stderr, "Failed to read Username\n");
            return 1;
        }

        char host[4096];

        printf("Enter Jenkins Host (Format: yourid.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Jenkins Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Jenkins API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;

        snprintf(auth_url, sizeof(auth_url), "https://%s/api/json", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", username, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 65)
    {
        printf("\nEnter CircleCI API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing CircleCI API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Circle-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://circleci.com/api/v2/me";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 66)
    {
        printf("\nEnter Snyk API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Snyk API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Authorization: token %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.snyk.io/rest/self?version=2024-10-15";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 67)
    {
        printf("\nEnter Censys Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char app_id[4096];

        printf("Enter App ID: ");

        if (scanf("%4095s", app_id) != 1)
        {
            fprintf(stderr, "Failed to read App ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Censys API ID + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;

        snprintf(auth_url, sizeof(auth_url), "https://search.censys.io/api/v2/account");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", app_id, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 68)
    {
        printf("\nEnter Postmark Server Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Postmark Server Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "X-Postmark-Server-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.postmarkapp.com/server";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 69)
    {
        printf("\nEnter Mailchimp API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char dc[4096];

        printf("Enter datacenter suffix embedded in the key itself (e.g. -us21): ");

        if (scanf("%4095s", dc) != 1)
        {
            fprintf(stderr, "Failed to read It\n");
            return 1;
        }

        printf("\n[*] Analyzing Mailchimp API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;

        snprintf(auth_url, sizeof(auth_url), "https://%s.api.mailchimp.com/3.0/", dc);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 70)
    {
        printf("\nEnter HubSpot Private App Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing HubSpot Private App Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://api.hubapi.com/account-info/v3/details";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 71)
    {
        printf("\nEnter Square Access Token: ");
char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Square Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://connect.squareup.com/v2/merchants";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 72)
    {
        printf("\nEnter PayPal Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char client_id[4096];
        char body_1[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing PayPal Client ID + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        snprintf(body_1, sizeof(body_1), "grant_type=client_credentials");

        const char *body = body_1;
        snprintf(auth_url, sizeof(auth_url), "https://api-m.paypal.com/v1/oauth2/token");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", client_id, key);

        fflush(stdout);

        const char *headers[] = {"Content-Type: application/x-www-form-urlencoded", auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 73)
    {
        printf("\nEnter Braintree API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char merchant_id[4096];

        printf("Enter Merchant ID: ");

        if (scanf("%4095s", merchant_id) != 1)
        {
            fprintf(stderr, "Failed to read Merchant ID\n");
            return 1;
        }

        char public_key[4096];
        printf("Enter Public Key: ");

        if (scanf("%4095s", public_key) != 1)
        {
            fprintf(stderr, "Failed to read Public Key\n");
            return 1;
        }

        printf("\n[*] Analyzing Braintree API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.braintreegateway.com/merchants/%s/clients", merchant_id);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", public_key, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 74)
    {
        printf("\nEnter Plaid Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        char client_id[4096];
        char body_1[8096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Plaid Client ID + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        snprintf(body_1, sizeof(body_1), "{\"client_id\":\"%s\",\"secret\":\"%s\",\"count\":1,\"offset\":0,\"country_codes\":[\"US\"]}", client_id, key);

        const char *body = body_1;
        snprintf(auth_url, sizeof(auth_url), "https://production.plaid.com/institutions/get");
        snprintf(auth_header, sizeof(auth_header), "Content-Type: application/json");

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 75)
    {
        printf("\nEnter Alpaca Trading Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char client_id[4096];

        printf("Enter API Key ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Alpaca Trading API Key + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_1[4096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.alpaca.markets/v2/account");
        snprintf(auth_header, sizeof(auth_header), "APCA-API-SECRET-KEY: %s", key);
        snprintf(auth_header_1, sizeof(auth_header), "APCA-API-KEY-ID: %s", client_id);

        fflush(stdout);

        const char *headers[] = {auth_header_1, auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 76)
    {
        printf("\nEnter Linode (Akamai Cloud Manager) API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Linode (Akamai Cloud Manager) API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.linode.com/v4/profile");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 77)
    {
        printf("\nEnter Splunk HEC Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter URL Host format( yourhost.com ): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read URL Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Splunk HEC Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s:8088/services/collector/health", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Splunk %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 78)
    {
        printf("\nEnter Honeybadger API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Honeybadger API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://app.honeybadger.io/v2/projects");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:)", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 79)
    {
        printf("\nEnter Rollbar Access Token: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Rollbar Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.rollbar.com/api/1/project");
        snprintf(auth_header, sizeof(auth_header), "X-Rollbar-Access-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 80)
    {
        printf("\nEnter Bugsnag API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Bugsnag API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.bugsnag.com/user");
        snprintf(auth_header, sizeof(auth_header), "Authorization: token %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 81)
    {
        printf("\nEnter Segment Write Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Segment Write Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.segment.io/v1/batch");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:)", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 82)
    {
        printf("\nEnter Mixpanel API Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Mixpanel API Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://mixpanel.com/api/app/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:)", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 83)
    {
        printf("\nEnter Amplitude Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char api[4096];

        printf("Enter Api Key: ");

        if (scanf("%4095s", api) != 1)
        {
            fprintf(stderr, "Failed to read API Key\n");
            return 1;
        }

        printf("\n[*] Analyzing Amplitude API Key + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://amplitude.com/api/2/usage/accounts");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", api, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 84)
    {
        printf("\nEnter GoDaddy Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char api[4096];

        printf("Enter Api Key: ");

        if (scanf("%4095s", api) != 1)
        {
            fprintf(stderr, "Failed to read API Key\n");
            return 1;
        }

        printf("\n[*] Analyzing GoDaddy API Key + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.godaddy.com/v1/domains");
        snprintf(auth_header, sizeof(auth_header), "Authorization: sso-key %s:%s", api, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 85)
    {
        printf("\nEnter Namecheap API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char api_user[4096];

        printf("Enter Api User: ");

        if (scanf("%4095s", api_user) != 1)
        {
            fprintf(stderr, "Failed to read API User\n");
            return 1;
        }

        char username[4096];

        printf("Enter Username: ");

        if (scanf("%4095s", username) != 1)
        {
            fprintf(stderr, "Failed to read Usernamme\n");
            return 1;
        }

        char ip[4096];

        printf("Enter Client Ip: ");

        if (scanf("%4095s", ip) != 1)
        {
            fprintf(stderr, "Failed to read Client Ip\n");
            return 1;
        }

        printf("\n[*] Analyzing Namecheap API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.namecheap.com/xml.response?ApiUser=%s&ApiKey=%s&UserName=%s&Command=namecheap.users.getBalances&ClientIp=%s", api_user, key, username, ip);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    if (command == 86)
    {
        printf("\nEnter Fastly API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Fastly API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.fastly.com/current_user");
        snprintf(auth_header, sizeof(auth_header), "Fastly-Key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 87)
    {
        printf("\nEnter Cloudinary Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char api_key[4096];

        printf("Enter Api Key: ");

        if (scanf("%4095s", api_key) != 1)
        {
            fprintf(stderr, "Failed to read API Key\n");
            return 1;
        }

        char cloud_name[4096];

        printf("Enter Cloud Name: ");

        if (scanf("%4095s", cloud_name) != 1)
        {
            fprintf(stderr, "Failed to read Cloud Name\n");
            return 1;
        }

        printf("\n[*] Analyzing Cloudinary API Key + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.cloudinary.com/v1_1/%s/resources/image", cloud_name);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", api_key, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 88)
    {
        printf("\nEnter Unsplash Access Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Unsplash Access Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.unsplash.com/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Client-ID %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 89)
    {
        printf("\nEnter Mistral AI API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Mistral AI API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.mistral.ai/v1/models");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 90)
    {
        printf("\nEnter Together AI API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Together AI API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.together.xyz/v1/models");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 91)
    {
        printf("\nEnter Terraform Cloud API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Terraform Cloud API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://app.terraform.io/api/v2/account/details");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 92)
    {
        printf("\nEnter Ansible Tower/AWX API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter Url Host (format: yourhost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Url Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Ansible Tower/AWX API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s/api/v2/me/", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 93)
    {
        printf("\nEnter Kubernetes Service Account Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter Url Host (format: yourhost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Url Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Kubernetes Service Account Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s:6443/api/v1/namespaces/default", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 94)
    {
        printf("\nEnter Grafana API Key: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        char host[4096];

        printf("Enter Url Host (format: yourhost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Url Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Grafana API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s/api/org", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 95)
    {
        printf("\nEnter Prometheus Basic Auth: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter Url Host (format: yourhost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Url Host\n");
            return 1;
        }

        char user[4096];

        printf("Enter User Id: ");

        if (scanf("%4095s", user) != 1)
        {
            fprintf(stderr, "Failed to read User Id\n");
            return 1;
        }

        printf("\n[*] Analyzing Prometheus Basic Auth...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s/api/v1/status/config", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Basic base64(%s:%s)", user, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 96)
    {
        printf("\nEnter Elasticsearch API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter Url Host (format: yourhost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Url Host\n");
            return 1;
        }

        char id[4096];

        printf("Enter ID: ");

        if (scanf("%4095s", id) != 1)
        {
            fprintf(stderr, "Failed to read ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Elasticsearch API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s:9200/_security/_authenticate", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: ApiKey {base64 %s:%s}", id, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 97)
    {
        printf("\nEnter Vultr API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Vultr API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.vultr.com/v2/account");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 98)
    {
        printf("\nEnter Redis Cloud API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char account_key[4096];

        printf("Enter Account Key: ");

        if (scanf("%4095s", account_key) != 1)
        {
            fprintf(stderr, "Failed to Account Key\n");
            return 1;
        }

        printf("\n[*] Analyzing Redis Cloud API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_1[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.redislabs.com/v1/subscriptions");
        snprintf(auth_header, sizeof(auth_header), "x-api-key: %s", account_key);
        snprintf(auth_header_1, sizeof(auth_header_1), "x-api-secret-key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header_1, auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 99)
    {
        printf("\nEnter TravisCI API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing TravisCI API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_1[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.travis-ci.com/user");
        snprintf(auth_header, sizeof(auth_header), "Authorization: token %s", key);
        snprintf(auth_header_1, sizeof(auth_header_1), "Travis-API-Version: 3");

        fflush(stdout);

        const char *headers[] = {auth_header_1, auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 100)
    {
        printf("\nEnter Calendly API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Calendly API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.calendly.com/users/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 101)
    {
        printf("\nEnter crates.io API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing crates.io API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://crates.io/api/v1/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 102)
    {
        printf("\nEnter RubyGems API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing RubyGems API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://rubygems.org/api/v1/api_key.json");
        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 103)
    {
        printf("\nEnter Vonage Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char api_key[4096];

        printf("Enter API Key: ");

        if (scanf("%4095s", api_key) != 1)
        {
            fprintf(stderr, "Failed to read API Key\n");
            return 1;
        }

        printf("\n[*] Analyzing Vonage API Key + Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://rest.nexmo.com/account/get-balance?api_key=%s&api_secret=%s", api_key, key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    if (command == 104)
    {
        printf("\nEnter 1Password Connect API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter Connect Host(format: yourconnecthost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Connect Host\n");
            return 1;
        }

        printf("\n[*] Analyzing 1Password Connect API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s/v1/vaults", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 105)
    {
        printf("\nEnter Doppler API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Doppler API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.doppler.com/v3/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 106)
    {
        printf("\nEnter Infisical API Token: ");

        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Infisical API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://app.infisical.com/api/v2/users/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 107)
    {
        printf("\nEnter LaunchDarkly API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing LaunchDarkly API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://app.launchdarkly.com/api/v2/caller-identity");
        snprintf(auth_header, sizeof(auth_header), "Authorization: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 108)
    {
        printf("\nEnter Statuspage API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Statuspage API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.statuspage.io/v1/users/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: OAuth %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 109)
    {
        printf("\nEnter Zapier NLA API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Zapier NLA API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://nla.zapier.com/api/v1/check");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 110)
    {
        printf("\nEnter Contentful Management API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Contentful Management API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.contentful.com/spaces");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 111)
    {
        printf("\nEnter Strapi API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter Strapi Host(format: yourconnecthost.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read Strapi Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Strapi API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s/api/users/me", host);
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 112)
    {
        printf("\nEnter Sanity.io API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Sanity.io API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.sanity.io/v2021-06-07/users/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 113)
    {
        printf("\nEnter Webflow API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Webflow API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.webflow.com/v2/token/authorized_by");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 114)
    {
        printf("\nEnter Squarespace Commerce API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Squarespace Commerce API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_1[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.squarespace.com/1.0/commerce/orders?modifiedAfter=2024-01-01T00:00:00.000Z&modifiedBefore=2024-01-02T00:00:00.000Z");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);
        snprintf(auth_header_1, sizeof(auth_header_1), "User-Agent: keylyzer/1.0");

        fflush(stdout);

        const char *headers[] = {auth_header_1, auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 115)
    {
        printf("\nEnter Checkly API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        printf("\n[*] Analyzing Checkly API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.checklyhq.com/v1/checks");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 116)
    {
        printf("\nEnter Shopify Admin API Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char host[4096];

        printf("Enter your Shopify Host(format: yourshopifystore.myshopify.com): ");

        if (scanf("%4095s", host) != 1)
        {
            fprintf(stderr, "Failed to read your Shopify Host\n");
            return 1;
        }

        printf("\n[*] Analyzing Shopify Admin API Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://%s/admin/api/2024-10/shop.json", host);
        snprintf(auth_header, sizeof(auth_header), "X-Shopify-Access-Token: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 117)
    {
        printf("\nEnter BigCommerce API Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        

        char hash[4096];

        printf("Enter Hash: ");

        if (scanf("%4095s", hash) != 1)
        {
            fprintf(stderr, "Failed to read Hash\n");
            return 1;
        }

        printf("\n[*] Analyzing BigCommerce API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_1[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.bigcommerce.com/stores/%s/v2/store", hash);
        snprintf(auth_header, sizeof(auth_header), "X-Auth-Token: %s", key);
        snprintf(auth_header_1, sizeof(auth_header_1), "Accept: application/json");

        fflush(stdout);

        const char *headers[] = {auth_header_1, auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 118)
    {
        printf("\nEnter Klaviyo API Key: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Klaviyo API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_header_1[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://a.klaviyo.com/api/accounts/");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Klaviyo-API-Key %s", key);
        snprintf(auth_header_1, sizeof(auth_header_1), "revision: 2024-10-15");

        fflush(stdout);

        const char *headers[] = {auth_header_1, auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 2, argc, body);

        fflush(stdout);
    }

    if (command == 119)
    {
        printf("\nEnter ConvertKit API Secret: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing ConvertKit API Secret...\n\n");
        sleep(1);

        fflush(stdout);
        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.convertkit.com/v3/account?api_secret=%s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 0, argc, body);

        fflush(stdout);
    }

    if (command == 120)
    {
        printf("\nEnter Typeform Personal Access Token: ");
        char key[BUF_SIZE];
        input_1(key, sizeof(key));
        
        printf("\n[*] Analyzing Typeform Personal Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body = NULL;
        snprintf(auth_url, sizeof(auth_url), "https://api.typeform.com/me");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }
}
