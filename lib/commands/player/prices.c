// /lib/commands/player/prices.c
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Information";
    addCommandTemplate("prices");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object environment = environment(initiator);
        if (!environment || !environment->isPort()) 
        {
            tell_object(initiator, "You must be at a trading port to view market prices.");
        } 
        else 
        {
            object tradingDict = getDictionary("trading");
            tell_object(initiator, tradingDict->getMarketPricesDisplay(initiator, environment));
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "View current market prices at trading ports";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The prices command displays current market prices for "
        "common trading goods at the current trading port. Prices vary "
        "between ports based on local supply, demand, and specializations.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: trading, contracts, warehouse";
}
