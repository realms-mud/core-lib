//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object Port;
private string selectedItem;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    NumColumns = 2;
    Description = "Sell Goods";
    Type = "Sell Cargo";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object tradingDict = getService("trading");
    Data = ([]);
    
    // Get all sellable cargo from trading service - keyed by item path
    mapping cargoForSale = tradingDict->getCargoForSale(User, Port);
    
    if (mappingp(cargoForSale) && sizeof(cargoForSale))
    {
        int counter = 1;
        string *itemPaths = m_indices(cargoForSale);
        
        foreach(string itemPath in itemPaths)
        {
            mapping itemData = cargoForSale[itemPath];
            
            // Build source list for display
            string *sourceNames = m_indices(itemData["sources"]);
            string sourceList = implode(sourceNames, ", ");
            
            // Convert float prices to integers for display
            int price = to_int(itemData["price"]);
            int totalValue = to_int(itemData["total value"]);
            
            // Create display entry
            Data[to_string(counter++)] = ([
                "name": sprintf("%s x%d (%d gold each) [%s]",
                    itemData["item name"],
                    itemData["total quantity"],
                    price,
                    sourceList),
                "type": "item",
                "item path": itemPath,
                "item data": itemData,
                "description": sprintf("Sell %s. Total available: %d units at %d gold each (Total value: %d gold) from: %s",
                    itemData["item name"],
                    itemData["total quantity"],
                    price,
                    totalValue,
                    sourceList),
                "canShow": 1
            ]);
        }
    }

    // Always add return option
    int counter = sizeof(m_indices(Data)) + 1;
    Data[to_string(counter)] = ([
        "name": "Return to Trading Menu",
        "type": "exit",
        "description": "Return to the main trading menu.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;

    if (User && member(Data, selection))
    {
        if (Data[selection]["type"] == "exit")
        {
            ret = 1;
        }
        else if (Data[selection]["type"] == "item")
        {
            selectedItem = Data[selection]["item path"];
            mapping itemData = Data[selection]["item data"];
            
            // Build targets mapping from sources
            mapping targets = ([]);
            mapping sources = itemData["sources"];
            
            foreach(string sourceName in m_indices(sources))
            {
                mapping sourceData = sources[sourceName];
                targets[sourceName] = ([
                    "object": sourceData["object"],
                    "maxQuantity": sourceData["quantity"]
                ]);
            }
            
            if (sizeof(targets))
            {
                SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
                SubselectorObj->setItem(selectedItem);
                SubselectorObj->setTargets(targets);
                SubselectorObj->setPrice(itemData["price"]);
                SubselectorObj->setAction("sell");
                SubselectorObj->setPort(Port);
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
                ret = -1;
            }
            else
            {
                object configuration = getService("configuration");
                tell_object(User, configuration->decorate(
                    "No sellable cargo found.",
                    "failure", "selector", User->colorConfiguration()));
                ret = 0;
            }
        }
        else
        {
            ret = 0;
        }
    }
    else
    {
        ret = 0;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        object configuration = getService("configuration");
        if (caller == SubselectorObj)
        {
            tell_object(User, configuration->decorate(
                sprintf("Sale completed successfully at %s.",
                    objectp(Port) ? Port->getPortName() : "the selected port"),
                "success", "quests", User->colorConfiguration()));
        }

        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    if (objectp(caller))
    {
        caller->cleanUp();
    }
    SubselectorObj = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorAborted(object caller)
{
    if (User)
    {
        object configuration = getService("configuration");
        if (caller == SubselectorObj)
        {
            tell_object(User, configuration->decorate(
                "Sale cancelled.",
                "info", "selector", User->colorConfiguration()));
        }

        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    if (objectp(caller))
    {
        caller->cleanUp();
    }
    SubselectorObj = 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    object configuration = getService("configuration");
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    string colorConfig = User->colorConfiguration();

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfig),
        padSelectionDisplay(choice),
        configuration->decorate("%-35s", displayType, "selector", colorConfig),
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
protected string descriptionFormatter(string choice)
{
    string ret = "";
    
    if (member(Data[choice], "description"))
    {
        ret = Data[choice]["description"];
    }
    return ret;
}
