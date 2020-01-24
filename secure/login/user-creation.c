//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/input_to.h"
virtual inherit "/secure/login/core.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int containsInappropriateLanguage(string userName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isReservedName(string userName)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int hasNoInvalidCharacters(string userName)
{
    int ret = (userName == regreplace(userName, "([^A-Za-z'-])", "", 1));

    if (!ret)
    {
        write("The only valid characters for a name are: a-z, ', and -\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int isValidUserName(string userName)
{
    return hasNoInvalidCharacters(userName) &&
        !containsInappropriateLanguage(userName) &&
        !isReservedName(userName);
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
        call_out("timeout", 90);
    }
    else
    {
        authenticationService->createUser(userName, password, ipAddress);
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
