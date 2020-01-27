//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/secure/login/core.c";

/////////////////////////////////////////////////////////////////////////////
static nomask void terminateWhoConnection()
{
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void executeWhoCommand()
{
    object whoCommand = load_object("/lib/commands/player/who.c");
    whoCommand->execute("who", this_object());
    call_out("terminateWhoConnection", 0);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void pruneOtherCharacters(string characterName,
    object currentPlayer)
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void execCharacter(string characterName, string userName)
{
    object loginModule = load_object("/lib/modules/secure/login.c");

    object player = loginModule->getPlayerObject(characterName);
    pruneOtherCharacters(characterName, player);

    if (objectp(player))
    {
        exec(player, this_object());
        addUser(player);

        command("l", player);
    }
    else
    {
        destruct(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void displayMenu(string userName)
{
    printf("We're displaying a menu now.\n");
    execCharacter(userName, userName);
}
