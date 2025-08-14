//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object TradingDictionary;
private object SelectedPort;
private int justDisplayedStatus = 0;

/////////////////////////////////////////////////////////////////////////////
private void displayTradingStatus()
{
    mapping data = User->getTradingData();
    string colorConfig = User->colorConfiguration();
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();

    string statusDisplay =
        commandsDictionary->buildBanner(colorConfig, charset, "top",
            sprintf("%s Trading Status", data["firm"]));

    // Company information
    statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Location: ", "field header", "research", colorConfig) +
        configuration->decorate(data["location"], "field data", "research", colorConfig) +
        configuration->decorate("        Date: ", "field header", "research", colorConfig) +
        configuration->decorate(data["date"], "field data", "research", colorConfig));

    // Financial status
    statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Cash: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", data["cash"]), "field data", "research", colorConfig) +
        configuration->decorate("     Bank: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", data["bank"]), "field data", "research", colorConfig) +
        configuration->decorate("     Debt: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", data["debt"]),
            data["debt"] > 0 ? "penalty modifier" : "field data", "research", colorConfig));

    // Vehicle information (updated for multiple vehicles)
    object *vehicles = User->getVehicles();
    if (sizeof(vehicles))
    {
        foreach(object vehicle in vehicles)
        {
            if (objectp(vehicle))
            {
                mapping blueprint = vehicle->getBlueprint();
                statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
                    configuration->decorate(sprintf("Vehicle: %s", blueprint["type"]), "field header", "research", colorConfig) +
                    configuration->decorate(sprintf("  Location: %s", blueprint["location"]), "field data", "research", colorConfig)
                );
                statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
                    configuration->decorate("Capacity: ", "field header", "research", colorConfig) +
                    configuration->decorate(sprintf("%d/%d units", vehicle->getUsedSpace(), blueprint["capacity"]),
                        "field data", "research", colorConfig) +
                    configuration->decorate("     Protection: ", "field header", "research", colorConfig) +
                    configuration->decorate(sprintf("%d", blueprint["protection"]), "field data", "research", colorConfig)
                );
            }
        }
    }
    else
    {
        statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
            configuration->decorate("No vehicles owned.", "penalty modifier", "research", colorConfig));
    }

    statusDisplay += commandsDictionary->buildBanner(colorConfig, charset, "bottom", "-");

    tell_object(User, statusDisplay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Main Trading Menu";
    Type = "Trading";
    Data = ([]);

    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
    SelectedPort = 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    Data[to_string(counter++)] = ([
        "name": "View Company Status",
        "type": "status",
        "description": "Display your trading company's financial status, vehicle information, and current location.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": "View Market Prices",
        "type": "prices",
        "description": "View current market prices for all goods at any port.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": "Browse Contracts",
        "type": "contracts",
        "description": "View and accept trading contracts.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": "Visit Bank",
        "type": "bank",
        "description": "Deposit, withdraw money, or manage loans.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": "Select Port",
        "type": "selectPort",
        "description": "Choose a port to manage trading actions at that location.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": "Exit Trading Menu",
        "type": "exit",
        "description": "Close the trading interface.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        string selectionType = Data[selection]["type"];
        ret = (selectionType == "exit");

        if (!ret && Data[selection]["canShow"])
        {
            switch(selectionType)
            {
                case "status":
                {
                    displayTradingStatus();
                    justDisplayedStatus = 1;
                    ret = -1;
                    break;
                }
                case "prices":
                {
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/marketPricesSelector.c");
                    break;
                }
                case "contracts":
                {
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/contractsSelector.c");
                    break;
                }
                case "bank":
                {
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankSelector.c");
                    break;
                }
                case "selectPort":
                {
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/selectPortSelector.c");
                    break;
                }
            }

            if (SubselectorObj)
            {
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    int ret = objectp(SubselectorObj) || justDisplayedStatus;
    if (justDisplayedStatus)
    {
        justDisplayedStatus = 0;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}
