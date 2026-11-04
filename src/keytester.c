// Please download last release version currently the code is broken and in Development and Commit of next version

#include "keytester.h"

int api_tester(int command, char *key, int argc)
{
    printf("\n");

    fflush(stdout);

    if (command == 1)
    {

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

        printf("\n[*] Analyzing Google Api Key...\n\n");
        sleep(1);
        const char *body = NULL;
        fflush(stdout);

        char auth_header[8096];
        
        snprintf(auth_header, sizeof(auth_header), "x-goog-api-key: %s", key);

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = "https://generativelanguage.googleapis.com/v1beta/models";

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }

    if (command == 4)
    {

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
        fflush(stdout);

        printf("\n[*] Analyzing JWT...\n\n");
        sleep(1);

        jwt_analyzer(key);

        fflush(stdout);
    }

    //////////////////////
    if (command == 10)
    {
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

        char client_id[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Spotify API...\n\n");
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

        char client_id[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Reddit API...\n\n");
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

        char client_id[4096];
        char body_1[4096];

        printf("Enter Client ID: ");

        if (scanf("%4095s", client_id) != 1)
        {
            fprintf(stderr, "Failed to read Client ID\n");
            return 1;
        }

        printf("\n[*] Analyzing Twitch API...\n\n");
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
//graphql
        printf("\n[*] Analyzing Linear API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];

        const char *body = NULL;

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
// graphql
        
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

        printf("\nComing soon....\n\n");
        
    }

    if (command == 62)
    {

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

        snprintf(body_1, sizeof(body_1), "client_id=%s&client_secret=%s&grant_type=client_credentials&scope=https://graph.microsoft.com/.default",client_id, key);

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

        const char *body;
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

        const char *body; 
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

        printf("\n[*] Analyzing Linode (Akamai Cloud Manager) API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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

        const char *body; 
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


        printf("\n[*] Analyzing Splunk HEC Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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


        printf("\n[*] Analyzing Rollbar Access Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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


        printf("\n[*] Analyzing Bugsnag API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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


        printf("\n[*] Analyzing Segment Write Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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


        printf("\n[*] Analyzing Mixpanel API Secret...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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

        const char *body; 
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

        const char *body; 
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

        const char *body; 
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

        printf("\n[*] Analyzing Fastly API Token...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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

        const char *body; 
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

        printf("\n[*] Analyzing Unsplash Access Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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

        printf("\n[*] Analyzing Mistral AI API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
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

        printf("\n[*] Analyzing Together AI API Key...\n\n");
        sleep(1);

        fflush(stdout);

        char auth_header[8096];
        char auth_url[4096];

        const char *body; 
        snprintf(auth_url, sizeof(auth_url), "https://api.together.xyz/v1/models");
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", key);
        

        fflush(stdout);

        const char *headers[] = {auth_header};
        const char *url = auth_url;

        fflush(stdout);

        make_request(url, headers, 1, argc, body);

        fflush(stdout);
    }


        

}
