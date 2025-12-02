//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object TradingService;
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    Description = "Select Port";
    Type = "Port";
    Data = ([]);

    TradingService = getService("trading");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    object *ports = TradingService->getAvailablePorts();
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
        "name": "Return to Previous Menu",
        "type": "exit",
        "description": "Return to the main trading menu.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User && Data[selection]["canShow"])
    {
        ret = (Data[selection]["type"] == "exit");

        if (Data[selection]["type"] == "port")
        {
            object port = Data[selection]["port"];
            if (objectp(port))
            {
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/portMenuSelector.c");
                SubselectorObj->setPort(port);
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
    return objectp(SubselectorObj);
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
