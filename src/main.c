// Please download last release version currently the code is broken and in Development and Commit of next version
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "keytester.h"

#define FULL_REQUEST "--full-request"

int call_api()
{
}

void banner()
{
  printf(
      "\t\t  _  __          _                   \n"
      "\t\t | |/ /___ _   _| |_   _ _______ _ __\n"
      "\t\t | ' // _ \\ | | | | | | |_  / _ \\ '__|\n"
      "\t\t | . \\  __/ |_| | | |_| |/ /  __/ |\n"
      "\t\t |_|\\_\\___|\\__, |_|\\__, /___\\___|_|\n"
      "\t\t           |___/   |___/\n"
      "\n");
  printf("_________________________________________________________________________");
  printf("\n");
  printf("    Keylyzer is an open-source credential analysis and verification tool  \n");
  printf("  written in C for security researchers. It provides a unified, menu-driven   \n");
  printf("    interface to analyze and verify supported API keys, tokens, and secrets \n");
  printf("                using provider-specific validation modules.\n\n");
  printf("\n");
  printf("         Github: https://github.com/SyscallX-18113/Keylyzer \n\n");
  printf("                  Developed By: Syscallx-18113\n\n");
  printf("                             v1.0.0\n\n");
}

void services_printer()
{
  printf(
      "Command: --full-request        Shows full response\n\n"
      "Credential Verification Framework\n"
      "\n"
      "[1] GitHub Token                       [31] OpenWeatherMap API Key              [61] AWS Access Key + Secret(coming_soon) [91] Terraform Cloud API Token\n"
      "[2] GitLab Token                       [32] Mapbox Access Token                 [62] Azure AD / Entra App Client Secret   [92] Ansible Tower/AWX API Token\n"
      "[3] Google API Key                     [33] Algolia Admin API Key               [63] HashiCorp Vault Token                [93] Kubernetes Service Account Token\n"
      "[4] Resend API Key                     [34] Supabase Service Role Key           [64] Jenkins API Token                    [94] Grafana API Key\n"
      "[5] OpenAI API Key                     [35] PlanetScale Service Token           [65] CircleCI API Token                   [95] Prometheus Basic Auth\n"
      "[6] Discord Bot Token                  [36] New Relic API Key                   [66] Snyk API Token                       [96] Elasticsearch API Key\n"
      "[7] Slack Token                        [37] Datadog API Key                     [67] Censys API ID + Secret               [97] Vultr API Key\n"
      "[8] Stripe Secret Key                  [38] Sentry Auth Token                   [68] Postmark Server Token                [98] Redis Cloud API Key\n"
      "[9] JWT Analyzer                       [39] Docker Hub Personal Access Token    [69] Mailchimp API Key                    [99] TravisCI API Token\n"
      "[10] Twilio Auth Token                 [40] Spotify API                         [70] HubSpot Private App Token            [100] Calendly API Token\n"
      "[11] SendGrid API Key                  [41] Reddit API                          [71] Square Access Token                  [101] Cargo/crates.io API Token\n"
      "[12] Mailgun API Key                   [42] Twitch API                          [72] PayPal Client ID + Secret            [102] RubyGems API Key\n"
      "[13] Cloudflare API Token              [43] Anthropic API Key                   [73] Braintree API Key                    [103] Vonage API Key + Secret\n"
      "[14] DigitalOcean PAT                  [44] Groq API Key                        [74] Plaid Client ID + Secret             [104] 1Password Connect API Token\n"
      "[15] Heroku API Key                    [45] Cohere API Key                      [75] Alpaca Trading API Key + Secret      [105] Doppler API Token\n"
      "[16] NPM Access Token                  [46] Replicate API Token                 [76] Linode API Token                     [106] Infisical API Token\n"
      "[17] PyPI API Token                    [47] ElevenLabs API Key                  [77] Splunk HEC Token                     [107] LaunchDarkly API Token\n"
      "[18] Telegram Bot Token                [48] Figma Personal Access Token         [78] Honeybadger API Key                  [108] Statuspage API Key\n"
      "[19] Google Cloud Service Account Key  [49] Linear API Key                      [79] Rollbar Access Token                 [109] Zapier NLA API Key\n"
      "[20] Azure Storage Account Key         [50] Trello API Key + Token              [80] Bugsnag API Key                      [110] Contentful Management API Token\n"
      "[21] Notion Integration Token          [51] Bitbucket App Username + Password   [81] Segment Write Key                    [111] Strapi API Token\n"
      "[22] Airtable Personal Access Token    [52] Intercom Access Token               [82] Mixpanel API Secret                  [112] Sanity.io API Token\n"
      "[23] Postman API Key                   [53] Buildkite API Access Token          [83] Amplitude API Key + Secret           [113] Webflow API Token\n"
      "[24] Vercel API Token                  [54] Asana Personal Access Token         [84] GoDaddy API Key + Secret             [114] Squarespace Commerce API Key\n"
      "[25] Netlify Personal Access Token     [55] Monday.com API Key                  [85] Namecheap API Key                    [115] Checkly API Key\n"
      "[26] PagerDuty API Key                 [56] ClickUp API Token                   [86] Fastly API Token                     [116] Shopify Admin API Access Token\n"
      "[27] Shodan API Key                    [57] Dropbox Access Token                [87] Cloudinary API Key + Secret          [117] BigCommerce API Token\n"
      "[28] VirusTotal API Key                [58] Box API Token                       [88] Unsplash Access Key                  [118] Klaviyo API Key\n"
      "[29] Firebase Web API Key              [59] Render API Key                      [89] Mistral AI API Key                   [119] ConvertKit API Secret\n"
      "[30] Hugging Face API Token            [60] Scaleway API Key                    [90] Together AI API Key                  [120] Typeform Personal Access Token\n\n"
      "[0] Exit ");
}

int main(int argc, char *argv[])
{

  int command;
  char key[100000];

  banner();
  services_printer();

  sleep(1);
  if (isatty(STDIN_FILENO))
  {
    printf("\n\n[*] Interactive terminal detected.\n");
  }
  else
  {
    printf("[*] Non-interactive input detected.\n");
  }
  sleep(1);

  printf("\n\nEnter Number: ");
  fflush(stdout);

  if (scanf("%d", &command) != 1)
  {
    fprintf(stderr, "Invalid  command command\n");
    return 1;
  }
  if (command > 121)
  {
    printf("Invaild Command");
    return 0;
  }

  if (command == 0)
  {
    printf("EXIT");
    return 0;
  }

  printf("\n(High-priority keys first Additional keys or client IDs will be requested when needed.)\n");
  printf("\nEnter [Key/SecretKey/Token/Password/ApiKey/PrivateKey/pass]: ");

  fflush(stdout);

  struct termios old, new;

  tcgetattr(STDIN_FILENO, &old);
  new = old;
  new.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &new);

  if (scanf("%99999s", key) != 1)
  {
    fprintf(stderr, "Failed to read key\n");
    return 1;
  }

  tcsetattr(STDIN_FILENO, TCSANOW, &old);

  printf("\n");

  fflush(stdout);

  api_tester(command, key, argc);

  return 0;
}
