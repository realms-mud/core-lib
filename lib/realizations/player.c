//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/guilds.c";
virtual inherit "/lib/modules/parties.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/settings.c";
virtual inherit "/lib/modules/secure/persistence.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";
virtual inherit "/lib/modules/domains.c";

private nosave object commandRegistry = 0;
private nosave int timeForNextSave = 0;

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
        add_action("executeCommand", "", 2);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int executeCommand(string command)
{
    int ret = 0;

    if(commandRegistry)
    {
        ret = commandRegistry->executeCommand(command, this_object());
        if (!ret)
        {
            object researchService = getService("research");
            ret = researchService->researchCommand(command);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    living::reset(arg);
    if (!arg)
    {
        addCommands();
        set_heart_beat(1);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void removeInventory(object player)
{
    object *items = deep_inventory(player);
    if (sizeof(items))
    {
        foreach(object item in items)
        {
            destruct(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void checkForLinkDeath(object player)
{
    if ((member(users(), player) < 0) && !interactive(this_object()))
    {
        player->save();
        removeInventory(player);
        unshadow();

        if (environment(player))
        {
            say(sprintf("Link Death arrives on his black stallion and smashes "
                "%s into nothingness!\n", player->Name()));
        }

        object channels = load_object("/lib/dictionaries/channelDictionary.c");
        if (channels && (this_object()->RealName() != ""))
        {
            channels->broadcastMessage("status", sprintf("%s (%s) has gone"
                " link dead.\n", capitalize(this_object()->RealName()),
                this_object()->queryProperty("IP address") || "???"), this_object());
            channels->unregisterUser(this_object());
        }
        player->notifySynchronous("onLeavingGame");

        destruct(player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void heart_beat()
{
    living::heart_beat();

    int currentTime = time();
    if (currentTime >= timeForNextSave)
    {
        timeForNextSave = currentTime + 300;
        this_object()->save();
    }

    checkForLinkDeath(this_object());
}
