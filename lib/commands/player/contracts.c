//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Information";
    addCommandTemplate("contracts");
}

/////////////////////////////////////////////////////////////////////////////
private void displayAvailableContracts(object player, object port) 
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    mapping contracts = port->getContracts();
    
    object commandsDict = getService("commands");
    object configDict = getService("configuration");
    
    string contractDisplay = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                            sprintf("%s Trading Contracts", port->getPortName()));
    
    if (!sizeof(contracts)) 
    {
        contractDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                          configDict->decorate("No contracts available at this time.",
                          "selector note", "selector", colorConfiguration));
    } 
    else 
    {
        string *contractIds = m_indices(contracts);
        foreach(string id in contractIds) 
        {
            mapping contract = contracts[id];
            
            string contractLine = configDict->decorate(sprintf("%s: ", id),
                                 "selector menu name", "selector", colorConfiguration) +
                                 configDict->decorate(contract["description"],
                                 "selector description", "selector", colorConfiguration);
            
            contractDisplay += commandsDict->banneredContent(colorConfiguration, charset, contractLine);
            
            string rewardLine = configDict->decorate("  Reward: ",
                               "selector field header", "selector", colorConfiguration) +
                               configDict->decorate(sprintf("%d gold", contract["reward"]),
                               "selector field data", "selector", colorConfiguration) +
                               configDict->decorate("  Deadline: ",
                               "selector field header", "selector", colorConfiguration) +
                               configDict->decorate(ctime(contract["deadline"]),
                               "selector field data", "selector", colorConfiguration);
            
            contractDisplay += commandsDict->banneredContent(colorConfiguration, charset, rewardLine);
        }
    }
    
    contractDisplay += commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(player, contractDisplay);
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
            tell_object(initiator, "You must be at a trading port to view contracts.");
        } 
        else 
        {
            displayAvailableContracts(initiator, environment);
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "View available trading contracts at ports";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The contracts command displays available trading contracts "
        "at the current port. Contracts are delivery missions that offer "
        "rewards for transporting specific goods to designated destinations "
        "within time limits.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: trading, travel, prices";
}
