// /lib/commands/player/travel.c
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Actions";
    addCommandTemplate("travel");
    addCommandTemplate("travel ##Target##");
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
private void displayTravelOptions(object player, object port) 
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    mapping routes = port->getTradeRoutes();
    
    object commandsDict = getService("commands");
    object configDict = getService("configuration");
    
    string travelDisplay = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                          "Available Destinations");
    
    if (!sizeof(routes)) 
    {
        travelDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                        configDict->decorate("No routes available from this port.",
                        "selector note", "selector", colorConfiguration));
    } 
    else 
    {
        string *destinations = m_indices(routes);
        foreach(string dest in destinations) 
        {
            mapping route = routes[dest];
            
            string routeLine = configDict->decorate(sprintf("%-15s", dest),
                              "selector menu name", "selector", colorConfiguration) +
                              configDict->decorate(sprintf("(%s route, %d days, danger %d%%)",
                              route["type"], route["days"], route["danger"]),
                              "selector description", "selector", colorConfiguration);
            
            travelDisplay += commandsDict->banneredContent(colorConfiguration, charset, routeLine);
        }
        
        travelDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                        configDict->decorate("Use 'travel <destination>' to begin journey.",
                        "selector instructions", "selector", colorConfiguration));
    }
    
    travelDisplay += 
        commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(player, travelDisplay);
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
            tell_object(initiator, "You must be at a trading port to plan travel.");
            ret = 1;
        } 
        else 
        {
            string destination = "";
            if (sscanf(command, "travel %s", destination) == 1) 
            {

                object travelSelector = 
                    clone_object("/lib/modules/domains/trading/selectors/travelSelector.c");
                move_object(travelSelector, initiator);
                travelSelector->setDestination(destination);
                travelSelector->registerEvent(this_object());
                travelSelector->initiateSelector(initiator);
            } 
            else 
            {

                displayTravelOptions(initiator, environment);
            }
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Plan and initiate travel between trading ports";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The travel command allows you to plan and initiate journeys "
        "between trading ports. Without arguments, it displays available "
        "destinations. With a destination argument, it begins the travel "
        "planning process including route selection and cost calculation.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: trading, contracts, prices";
}
