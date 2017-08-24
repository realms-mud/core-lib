//*****************************************************************************
// Class: player
// File Name: player.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/parties.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/research.c";
virtual inherit "/lib/modules/secure/persistence.c";

private nosave object commandRegistry = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfPlayer()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addCommands()
{
    commandRegistry = load_object("/lib/commands/commandRegistry.c");
    if(commandRegistry)
    {
        commandRegistry->init();

        add_action("executeCommand"); add_xverb("");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int executeCommand(string command)
{
    int ret = 0;

    if(commandRegistry)
    {
        ret = commandRegistry->executeCommand(command, this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    "living"::reset(arg);
    if (!arg)
    {
        addCommands();
        set_heart_beat(1);
    }
}