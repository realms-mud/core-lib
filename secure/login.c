//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/input_to.h"
virtual inherit "/secure/login/core.c";
virtual inherit "/secure/login/menu-interactions.c";
virtual inherit "/secure/login/user-creation.c";

private int totalAuthFailures = 0;

/////////////////////////////////////////////////////////////////////////////
private nomask void displayBanner()
{
    string *bannerArt = get_dir("/art/*", 0x10) - ({ "art/.", "art/.." });

    if (sizeof(bannerArt))
    {
        write(read_file(bannerArt[random(sizeof(bannerArt))]));
    }

    if (file_size("/secure/DISCLAIMER") > 0)
    {
        write(read_file("/secure/DISCLAIMER"));
    }

    printf("\nRealmsmud is running on LDMud %s\n\nType 'guest' as your login "
        "name if you just want to look around.\n"
        "Type 'who' is you would like to view the list of logged-in "
        "users.\n\n", version());
}

/////////////////////////////////////////////////////////////////////////////
static nomask void enterPassword(string password, string userName, 
    int numberOfAttempts)
{
    if (password == "")
    {
        printf("No password supplied. Closing session.\n");
        destruct(this_object());
    }
    else if (totalAuthFailures > 12)
    {
        authenticationService->temporarilyBanIP(ipAddress);
        printf("Authentication for user '%s' repeatedly failed. "
            "Goodbye.\n", userName);
        destruct(this_object());
    }
    else
    {
        string authenticationStatus =
            authenticationService->authenticateUser(userName, password);
        switch (authenticationStatus)
        {
            case "authenticated":
            {
                removeTimeout();
                displayMenu(userName);
                break;
            }
            case "failed":
            {
                totalAuthFailures++;
                printf("Authentication for user '%s' failed. Please "
                    "try again.\n", userName);
                write("Please enter your password: ");
                input_to("enterPassword", INPUT_NOECHO | INPUT_IGNORE_BANG,
                    userName, numberOfAttempts + 1);
                break;
            }
            default:
            {
                // Practically, this will not happen. It's only possible if
                // a user is deleted between the call to getUserLogin and 
                // enterPassword
                totalAuthFailures++;
                printf("User '%s' does not exist. Please try again.\n", 
                    userName);
                write("Please enter your login name: ");
                input_to("getUserLogin", INPUT_IGNORE_BANG);
                break;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void getUserLogin(string userName)
{
    if (!authenticationService->addressTemporarilyBanished(ipAddress))
    {
        switch (userName)
        {
            case "who":
            {
                executeWhoCommand();
                break;
            }
            case "":
            case "quit":
            {
                printf("Login attempt aborted.\n");
                destruct(this_object());
                break;
            }
            case "guest":
            {
                break;
            }
            default:
            {
                userName = lower_case(userName);
                if (authenticationService->userExists(userName))
                {
                    write("Please enter your password: ");
                    input_to("enterPassword", INPUT_NOECHO | INPUT_IGNORE_BANG, 
                        userName, 1);
                }
                else
                {
                    if (isValidUserName(userName))
                    {
                        createUser(userName);
                    }
                    else
                    {
                        write("Please enter your login name: ");
                        input_to("getUserLogin", INPUT_IGNORE_BANG);
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int logon()
{
    int wizardCount = sizeof(wizards());
    int playerCount = sizeof(players());

    ipAddress = query_ip_number(this_object());
    displayBanner();

    printf("There are %d wizards and %d mortals online.\n\n", wizardCount,
        playerCount);

    if (authenticationService->addressTemporarilyBanished(ipAddress))
    {
        printf(format("You IP address is currently banned from logging in "
            "due to excessive failed login attempts or other nuisance "
            "activity. Please try again later.\n", 78));
    }
    else
    {
        write("Please enter your login name: ");
        input_to("getUserLogin", INPUT_IGNORE_BANG);
        call_out("timeout", 90);
    }
    return 1;
}
