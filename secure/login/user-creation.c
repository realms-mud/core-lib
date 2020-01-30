//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/input_to.h"
virtual inherit "/secure/login/core.c";

/////////////////////////////////////////////////////////////////////////////
private nomask void execNewPlayer(string password, string userName)
{
    printf("\n");
    authenticationService->saveUser(userName, password, ipAddress);

    object loginModule = load_object("/lib/modules/secure/login.c");
    object player = loginModule->getPlayerObject(userName);

    if (objectp(player))
    {
        player->setUserName(userName);
        player->save();
        exec(player, this_object());
        addUser(player);

        command("l", player);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void confirmPassword(string confirmPassword, string password,
    string userName)
{
    removeTimeout();

    if (confirmPassword != password)
    {
        write("The entered passwords do not match. Please enter your password: ");
        input_to("setPassword", INPUT_NOECHO | INPUT_IGNORE_BANG,
            userName);
    }
    else
    {
        execNewPlayer(password, userName);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void setPassword(string password, string userName)
{
    removeTimeout();
    write("Please confirm your password: ");
    input_to("confirmPassword", INPUT_NOECHO | INPUT_IGNORE_BANG,
        password, userName);
    call_out("timeout", 90);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void confirmUserName(string confirmation, string userName)
{
    removeTimeout();
    if (member(({ "n", "N", "no", "No", "NO" }), confirmation) > -1)
    {
        printf("OK, what user did you want to log in as? ");
        input_to("getUserLogin", INPUT_IGNORE_BANG);
        call_out("timeout", 90);
    }
    else
    {
        write("Please enter your password: ");
        input_to("setPassword", INPUT_NOECHO | INPUT_IGNORE_BANG,
            userName);
        call_out("timeout", 90);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void createUser(string userName)
{
    removeTimeout();
    printf("This appears to be a new user. Is that correct? (Y/n) ");
    input_to("confirmUserName", INPUT_IGNORE_BANG, userName);
    call_out("timeout", 90);
}
