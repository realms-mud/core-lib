//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("quit");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        tell_object(initiator, "Saving character...\n");
        initiator->save();

        object *items = deep_inventory(initiator);
        if (sizeof(items))
        {
            foreach(object item in items)
            {
                destruct(item);
            }
        }

        tell_object(initiator, "We hope you enjoyed your time here. Come back soon!\n");

        if (!initiator->Invisibility())
        {
            say(sprintf("%s left the game.\n", capitalize(initiator->RealName())));
        }

        object channels = load_object("/lib/dictionaries/channelDictionary.c");
        if (channels)
        {
            channels->broadcastMessage("status", sprintf("%s (%s) has left"
                " the game.\n", capitalize(initiator->RealName()),
                query_ip_number(initiator) || "???"), initiator);
            channels->unregisterUser(initiator);
        }

        destruct(initiator);
    }
    return ret;
}
