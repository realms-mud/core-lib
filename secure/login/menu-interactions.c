//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/input_to.h"
virtual inherit "/secure/login/core.c";

/////////////////////////////////////////////////////////////////////////////
static nomask void terminateWhoConnection()
{
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void executeWhoCommand(int doNotDestruct)
{
    object whoCommand = load_object("/lib/commands/player/who.c");
    whoCommand->execute("who", this_object());

    if (!doNotDestruct)
    {
        call_out("terminateWhoConnection", 0);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void execCharacter(string characterName, string userName)
{
    printf("\n");
    object loginModule = load_object("/lib/modules/secure/login.c");

    pruneOtherCharacters(userName, characterName);
    object player = loginModule->getPlayerObject(characterName);

    if (objectp(player))
    {
        exec(player, this_object());
        addUser(player);
        configureCharset(player, player->charsetConfiguration());
        command("l", player);
    }
    else
    {
        destruct(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void displayMenuChoices(mapping options)
{
    foreach(string option in sort_array(m_indices(options), (: $1 > $2 :)))
    {
        printf("    %s) %s\n", option, options[option]["text"]);
    }
    call_out("timeout", 90);
    printf("\nYour selection: ");
    input_to("processMenuInput", INPUT_IGNORE_BANG, options);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void confirmPasswordChange(string confirmPassword, string password,
    mapping options)
{
    removeTimeout();

    if (confirmPassword != password)
    {
        write("The entered passwords do not match. Please enter your password: ");
        input_to("changePassword", INPUT_NOECHO | INPUT_IGNORE_BANG,
            options);
    }
    else
    {
        authenticationService->saveUser(options["1"]["character"], password, 
            ipAddress);
        printf("\nYour password has been updated.\n\n");
        displayMenuChoices(options);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void changePassword(string password, mapping options)
{
    removeTimeout();
    write("Please confirm your password: ");
    input_to("confirmPasswordChange", INPUT_NOECHO | INPUT_IGNORE_BANG,
        password, options);
    call_out("timeout", 90);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void getCharacterName(string name, mapping options)
{
    removeTimeout();

    name = lower_case(name);
    if (authenticationService->characterExists(name))
    {
        printf("A character named '%s' already exists. Please try again.\n",
            name);
        displayMenuChoices(options);
    }
    else
    {
        if (isValidUserName(name))
        {
            execCharacter(name, options["1"]["character"]);
        }
        else
        {
            write("That is not a valid character name.\n");
            displayMenuChoices(options);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void processMenuInput(string selection, mapping options)
{
    removeTimeout();

    if (selection == "")
    {
        selection = "1";
    }
    if (member(options, selection))
    {
        switch (options[selection]["type"])
        {
            case "log in":
            {
                authenticationService->saveUser(options["1"]["character"], 
                    options["1"]["password"], ipAddress);

                execCharacter(options[selection]["character"], 
                    options["1"]["character"]);
                break;
            }
            case "create":
            {
                authenticationService->saveUser(options["1"]["character"],
                    options["1"]["password"], ipAddress);

                call_out("timeout", 90);
                printf("By what name will your new character be known? ");
                input_to("getCharacterName", INPUT_IGNORE_BANG,
                    options);
                break;
            }
            case "password":
            {
                call_out("timeout", 90);
                printf("Please enter your new password: ");
                input_to("changePassword", INPUT_NOECHO | INPUT_IGNORE_BANG,
                    options);

                break;
            }
            case "who":
            {
                executeWhoCommand(1);
                printf("\n\n");
                displayMenuChoices(options);
                break;
            }
            case "log off":
            {
                destruct(this_object());
                break;
            }
        }
    }
    else
    {
        displayMenuChoices(options);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping displayCharacterOptions(string userName,
    string password)
{
    mapping ret = ([
        "1": ([ 
            "text": sprintf("Log in with %s (Default)", capitalize(userName)),
            "character": userName,
            "type": "log in",
            "password": password
        ])
    ]);

    int count = 2;
    string *characters = authenticationService->getCharacters(userName) -
        ({ userName });

    if (sizeof(characters) > 0)
    {
        foreach(string alternateCharacter in characters)
        {
            ret[to_string(count)] = ([
                "text":sprintf("Log in with %s", 
                    capitalize(alternateCharacter)),
                "character" : alternateCharacter,
                "type": "log in"
            ]);
            count++;
        }
    }
    ret[to_string(count)] = ([
        "text": "Create a new character",
        "type": "create"
    ]);
    ret[to_string(count + 1)] = ([
        "text": "Change your password",
        "type" : "password"
    ]);
    ret[to_string(count + 2)] = ([
        "text": "See who is currently playing",
        "type" : "who"
    ]);
    ret[to_string(count + 3)] = ([
        "text": "Log off",
        "type" : "log off"
    ]);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void displayMenu(string userName, string password)
{
    removeTimeout();

    printf("\n\nYou have the following login options:\n");
    mapping options = displayCharacterOptions(userName, password);

    displayMenuChoices(options);
}
