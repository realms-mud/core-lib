//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
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
        destruct(initiator);
    }
    return ret;
}
