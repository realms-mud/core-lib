//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object TradingDictionary;
private object ParentSelector;

/////////////////////////////////////////////////////////////////////////////
public void setParentSelector(object parent)
{
    ParentSelector = parent;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    Description = "Select Port";
    Type = "Port";
    Data = ([]);

    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    object *ports = TradingDictionary->getAvailablePorts();
    foreach(object port in ports)
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
        "name": "Cancel",
        "type": "cancel",
        "description": "Return to the main trading menu.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    if (User && Data[selection]["canShow"])
    {
        string type = Data[selection]["type"];
        if (type == "cancel")
        {
            if (ParentSelector)
            {
                ParentSelector->onSelectorCompleted(this_object());
            }
            return 1;
        }
        if (type == "port")
        {
            object port = Data[selection]["port"];
            if (objectp(port))
            {
                object portMenu = clone_object("/lib/modules/domains/trading/selectors/portMenuSelector.c");
                portMenu->setPort(port);
                portMenu->setParentSelector(ParentSelector);
                move_object(portMenu, User);
                portMenu->initiateSelector(User);
                return 1;
            }
        }
    }
    return -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (ParentSelector)
    {
        ParentSelector->onSelectorCompleted(this_object());
    }
    caller->cleanUp();
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
