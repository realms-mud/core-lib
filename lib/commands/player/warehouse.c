//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Actions";
    addCommandTemplate("warehouse");
}

/////////////////////////////////////////////////////////////////////////////
private void displayWarehouseStatus(object player, object trader, object port) {
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    mapping warehouse = trader->getWarehouse(trader->getCurrentLocation());
    
    object commandsDict = getDictionary("commands");
    object configDict = getDictionary("configuration");
    object tradingDict = getDictionary("trading");
    
    string warehouseDisplay = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                             sprintf("%s Warehouse", trader->getCurrentLocation()));
    
    string capacityLine = configDict->decorate("Capacity: ",
                         "selector field header", "selector", colorConfiguration) +
                         configDict->decorate(sprintf("%d/%d units used",
                         tradingDict->calculateWarehouseUsed(warehouse), warehouse["capacity"]),
                         "selector field data", "selector", colorConfiguration);
    
    warehouseDisplay += commandsDict->banneredContent(colorConfiguration, charset, capacityLine);
    
    if (!sizeof(warehouse["inventory"])) 
    {
        warehouseDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                           configDict->decorate("Warehouse is empty.",
                           "selector note", "selector", colorConfiguration));
    } 
    else 
    {
        warehouseDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                           configDict->decorate("Stored Items:",
                           "selector field header", "selector", colorConfiguration));
        
        string *items = m_indices(warehouse["inventory"]);
        foreach(string item in items) 
        {
            string itemLine = configDict->decorate(sprintf("  %-30s: ", item),
                             "selector choice enabled", "selector", colorConfiguration) +
                             configDict->decorate(sprintf("%d units", warehouse["inventory"][item]),
                             "selector data", "selector", colorConfiguration);
            
            warehouseDisplay += commandsDict->banneredContent(colorConfiguration, charset, itemLine);
        }
    }
    
    warehouseDisplay += commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(player, warehouseDisplay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object trader = initiator->getModule("trader");
        if (!trader) {
            tell_object(initiator, "You need to be a registered trader to use warehouses.");
        } else {
            object environment = environment(initiator);
            if (!environment || !environment->isPort()) {
                tell_object(initiator, "You must be at a trading port to access your warehouse.");
            } else {
                displayWarehouseStatus(initiator, trader, environment);
            }
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "View warehouse inventory and status";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The warehouse command displays your warehouse inventory "
        "at the current trading port. Warehouses provide secure, long-term "
        "storage for trading goods and have much larger capacity than "
        "your vehicle.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: trading, prices, travel";
}
