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
}
