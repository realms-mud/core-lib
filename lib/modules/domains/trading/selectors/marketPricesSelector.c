//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object TradingDictionary;
private object SelectedPort;

/////////////////////////////////////////////////////////////////////////////
private void displayMarketPrices(object port)
{
    if (objectp(port))
    {
        string priceDisplay = TradingDictionary->getMarketPricesDisplay(User, port);
        tell_object(User, priceDisplay);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    Description = "Market Prices";
    Type = "MarketPrices";
    Data = ([]);

    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
    SelectedPort = 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    object *ports = TradingDictionary->getAvailablePorts();
    foreach (object port in ports)
    {
        if (objectp(port))
        {
            Data[to_string(counter++)] = ([
                "name": port->getPortName(),
                "type": "port",
                "description": port->query("short") || "",
                "canShow": 1,
                "port": port
            ]);
        }
    }

    Data[to_string(counter++)] = ([
        "name": "Return to Previous Menu",
        "type": "return",
        "description": "Return to the previous menu.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int result = -1;
    if (User && Data[selection]["canShow"])
    {
        string type = Data[selection]["type"];
        if (type == "return")
        {
            notifySynchronous("onSelectorCompleted");
            result = 1;
        }
        else if (type == "port")
        {
            SelectedPort = Data[selection]["port"];
            displayMarketPrices(SelectedPort);
            result = -1; // Redisplay menu after showing prices
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    cleanUp();
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
