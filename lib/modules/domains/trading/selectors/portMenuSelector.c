//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Port;
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Select a task";
    Type = "Port Menu";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    string portName = objectp(Port) ? Port->getPortName() : "Unknown Port";

    Data[to_string(counter++)] = ([
        "name": sprintf("Buy Goods at %s", portName),
        "type": "buy",
        "description": "Purchase goods for your vehicles or warehouse at this port.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": sprintf("Sell Goods at %s", portName),
        "type": "sell",
        "description": "Sell goods from your vehicles or warehouse at this port.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": sprintf("Manage Warehouse at %s", portName),
        "type": "warehouse",
        "description": "Transfer cargo between your vehicles and warehouse at this port.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": sprintf("Travel to Another Port from %s", portName),
        "type": "travel",
        "description": "Send a vehicle from this port to another destination.",
        "canShow": 1
    ]);
    Data[to_string(counter++)] = ([
        "name": sprintf("Hire Crew at %s", portName),
        "type": "hireCrew",
        "description": "Hire crew members for your vehicles at this port.",
        "canShow": 1
    ]);
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
        string type = Data[selection]["type"];
        ret = (type == "exit");

        switch(type)
        {
            case "buy":
            {
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/buySelector.c");
                SubselectorObj->setPort(Port);
                break;
            }
            case "sell":
            {
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/sellSelector.c");
                SubselectorObj->setPort(Port);
                break;
            }
            case "warehouse":
            {
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/warehouseSelector.c");
                SubselectorObj->setPort(Port);
                break;
            }
            case "travel":
            {
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/travelSelector.c");
                SubselectorObj->setPort(Port);
                break;
            }
            case "hireCrew":
            {
                SubselectorObj = clone_object("/lib/modules/domains/workerSelector.c");
                SubselectorObj->setDomain("trading");
                SubselectorObj->setLocation(Port);
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
