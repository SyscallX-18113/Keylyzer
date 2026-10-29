#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keytester.h"

#define FULL_REQUEST "--full-request"

typedef struct
{
  int github_token;
  int gitlab_token;
  int google_api_key;
  int aws_access_key;
  int openai_api_key;
  int discord_bot_token;
  int slack_token;
  int stripe_secret_key;
  int jwt_analyzer;
  int exit;
} command_struc;

int call_api()
{
}

void banner()
{
  printf(
      "\t\t  _  __          _                       \n"
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

void command_receiver()
{
  printf(
      "Command: --full-request             Show full response\n\n"
      "Credential Verification Framework\n"
      "\n"
      "[1] GitHub Token                         [31] OpenWeatherMap API Key                                                                             \n"
      "[2] GitLab Token                         [32] Mapbox Access Token                                                                             \n"
      "[3] Google API Key                       [33] Algolia Admin API Key                                                                             \n"
      "[4] Resend API Key                       [34] Supabase Service Role Key                                                                             \n"
      "[5] OpenAI API Key                       [35] PlanetScale Service Token                                                                             \n"
      "[6] Discord Bot Token                    [36] New Relic API Key                                                                             \n"
      "[7] Slack Token                          [37] Datadog API Key                                                                             \n"
      "[8] Stripe Secret Key                    [38] Sentry Auth Token                                                                             \n"
      "[9] JWT Analyzer                         [39] Docker Hub Personal Access Token                                                                             \n"
      "[10] Twilio Auth Token                   [40] Spotify API                                                                             \n"
      "[11] SendGrid API Key                    [41] Reddit API                                                                             \n"
      "[12] Mailgun API Key                     [42] Twitch API                                                                             \n"
      "[13] Cloudflare API Token                [43] Anthropic API Key                                                                             \n"
      "[14] DigitalOcean PAT                    [44] Groq API Key                                                                             \n"
      "[15] Heroku API Key                      [45] Cohere API Key                                                                             \n"
      "[16] NPM Access Token                    [46] Replicate API Token                                                                             \n"
      "[17] PyPI API Token                      [47] ElevenLabs API Key                                                                             \n"
      "[18] Telegram Bot Token                  [48] Figma Personal Access Token                                                                             \n"
      "[19] Google Cloud Service Account Key    [49] Linear API Key                                                                             \n"
      "[20] Azure Storage Account Key           [50] Trello API Key + Token                                                                             \n"
      "[21] Notion Integration Token            [51] Bitbucket App Username + Password                                                                             \n"
      "[22] Airtable Personal Access Token      [52] Intercom Access Token                                                                             \n"
      "[23] Postman API Key                     [53] Buildkite API Access Token                                                                             \n"
      "[24] Vercel API Token                    [54] Asana Personal Access Token                                                                             \n"
      "[25] Netlify Personal Access Token       [55] Monday.com API Key                                                                             \n"
      "[26] PagerDuty API Key                   [56] ClickUp API Token                                                                             \n"
      "[27] Shodan API Key                      [57] Dropbox Access Token                                                                             \n"
      "[28] VirusTotal API Key                  [58] Box API Token                                                                             \n"
      "[29] Firebase Web API Key                [59] Render API Key                                                                             \n"
      "[30] Hugging Face API Token              [60] Scaleway API Key                                                                             \n\n"
      "[0] Exit ");
    }
    
int main(int argc, char *argv[])
{

  int command;
  char key[30000];

  banner();
  command_receiver();

  printf("\n\nEnter Number: ");
  fflush(stdout);

  if (scanf("%d", &command) != 1)
  {
    fprintf(stderr, "Invalid command\n");
    return 1;
  }
  if (command >= 60)
  {
    printf("Invaild Command");
    return 0;
  }

  if (command == 0)
  {
    printf("EXIT");
    return 0;
  }

  printf("\nEnter [ Key/SecretKey/Token/Password/ApiKey ]: ");
  fflush(stdout);

  if (scanf("%9999s", key) != 1)
  {
    fprintf(stderr, "Failed to read key\n");
    return 1;
  }

  fflush(stdout);

  api_tester(command, key, argc);

  return 0;
}
