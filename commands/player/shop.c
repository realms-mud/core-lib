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
        CommandType = "interactions";
        addCommandTemplate("shop");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    object location = environment(initiator);
    object shop = location ? location->getShop() : 0;

    if (canExecuteCommand(command) && shop)
    {
        shop->initiateShopInteraction(initiator);
        ret = 1;
    }
    return ret;
}
