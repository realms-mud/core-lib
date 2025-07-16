//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Port;
private object ParentSelector;
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public void setPort(object port)
{
    Port = port;
}

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
    Description = "Port Menu";
    Type = "PortMenu";
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
        "name": "Return to Main Menu",
        "type": "return",
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
        switch(type)
        {
            case "buy":
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/buySelector.c");
                SubselectorObj->setPort(Port);
                break;
            case "sell":
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/sellSelector.c");
                SubselectorObj->setPort(Port);
                break;
            case "warehouse":
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/warehouseSelector.c");
                SubselectorObj->setPort(Port);
                break;
            case "travel":
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/travelSelector.c");
                SubselectorObj->setPort(Port);
                break;
            case "hireCrew":
                // Use workerSelector for hiring crew, passing the port context
                SubselectorObj = clone_object("/lib/modules/domains/workerSelector.c");
                SubselectorObj->setDomain("trading");
                SubselectorObj->setLocation(Port);
                SubselectorObj->setParentSelector(this_object());
                break;
            case "return":
                if (ParentSelector)
                {
                    ParentSelector->onSelectorCompleted(this_object());
                }
                return 1;
        }

        if (SubselectorObj)
        {
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
            return 1;
        }
    }
    return -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    setUpUserForSelection();
    tell_object(User, displayMessage());
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
