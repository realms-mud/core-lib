//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/sys/input_to.h"

protected string ipAddress;

protected object authenticationService = 
    load_object("/lib/modules/secure/dataServices/authenticationDataService.c");

/////////////////////////////////////////////////////////////////////////////
public nomask int preventShadows()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void removeTimeout()
{
    while (remove_call_out("timeout") != -1);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void timeout()
{
    printf("\nThe time limit for this operation has been exceeded.\n"
        "Please try again.\n");
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void pruneOtherCharacters(string userName, 
    string characterName)
{
    string *charactersForUser = 
        authenticationService->getCharacters(userName);

    object *characterObjects = filter(efun::users(),
        (: (member($2, $1->RealName()) > -1) :), charactersForUser);

    foreach(object character in characterObjects)
    {
        tell_object(character,
            sprintf("The character '%s' just logged in with this account.\n",
                characterName));
        command("quit", character);
    }
}

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
