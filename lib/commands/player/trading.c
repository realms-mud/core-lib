// /lib/commands/player/trading.c
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player R&D";
    addCommandTemplate("trading");
    addCommandTemplate("trade");
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object trader = initiator->getService("trader");
        if (!trader) 
        {
            // Initialize trader service if it doesn't exist
            trader = clone_object("/lib/modules/domains/trading/trader.c");
            trader->initializeTrader();
            initiator->setService("trader", trader);
        }
        
        object selector = 
            clone_object("/lib/modules/domains/trading/selectors/tradingSelector.c");

        move_object(selector, initiator);
        selector->registerEvent(this_object());
        selector->initiateSelector(initiator);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Enter the trading subsystem menu";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The trading command is used to buy and sell goods, manage "
        "warehouses, travel between ports, and conduct merchant business. A menu is "
        "displayed through which the player can navigate to perform "
        "any trading activity - so long as they have the funds and "
        "meet the requirements.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: research, guilds";
}
