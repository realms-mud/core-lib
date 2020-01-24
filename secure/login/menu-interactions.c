//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/secure/login/core.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void executeWhoCommand()
{
    object whoCommand = load_object("/lib/commands/players/who.c");
    whoCommand->execute("who", this_object());
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
