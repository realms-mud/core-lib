//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Interactions";
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


/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Enter the shop subsystem menu when in a shop";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The shop command enters the shop menu when a player is "
        "in a store or other location where you can purchase or sell "
        "items.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: talk";
}
