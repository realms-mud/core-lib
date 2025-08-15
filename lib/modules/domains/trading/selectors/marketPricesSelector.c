//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object TradingService;
private string SelectedCategory = 0;
private string SelectedItem = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    NumColumns = 3;
    Description = "Display market prices";
    Type = "Market Prices";
    Data = ([]);

    TradingService = getService("trading");
    SelectedCategory = 0;
    SelectedItem = 0;
}

/////////////////////////////////////////////////////////////////////////////
private string displayPriceBoard(string itemPath)
{
    string ret = "";
    object itemObj = load_object(itemPath);

    if(itemObj)
    {
        string colorConfig = User->colorConfiguration();
        int basePrice = itemObj->query("value");

        object configuration = getService("configuration");
        ret += configuration->decorate(
            sprintf("One trade unit of %s:\n", itemObj->query("name")),
            "title", "selector", colorConfig);

        object *ports = TradingService->getAvailablePorts();
        string *specialtyPorts = ({});
        string *importPorts = ({});

        // Gather specialty/import info for highlighting
        foreach (object port in ports)
        {
            if (objectp(port))
            {
                string *specialties = port->getSpecialties();
                string *imports = port->getImportNeeds();
                string itemType = port->getItemCategory(itemObj);

                if (itemType && member(specialties, itemType) > -1)
                {
                    specialtyPorts += ({ port->getPortName() });
                }

                if (itemType && member(imports, itemType) > -1)
                {
                    importPorts += ({ port->getPortName() });
                }
            }
        }


        foreach (object port in ports)
        {
            if (objectp(port))
            {
                ret += configuration->decorate(
                    sprintf("%-16s ", port->getPortName()),
                        "port name", "trade", colorConfig);

                float price = port->getItemPrice(itemPath);
                float diff = (basePrice > 0) ? (price / basePrice - 100.0) : 0.0;
                string trend = "";
                if (diff > 0.01)
                {
                    trend = configuration->decorate(sprintf(" (+%.2f%%)", diff),
                        "positive trend", "trade", colorConfig);
                }
                else if (diff < -0.01)
                {
                    trend = configuration->decorate(sprintf(" (%.2f%%)", diff),
                        "negative trend", "trade", colorConfig);
                }
                else
                {
                    trend = " (no change)";
                }
                string trendPadding = to_string(14 - textWidth(trend));

                ret += configuration->decorate(sprintf("%6d gold%s%" + trendPadding + "s", 
                    to_int(price), trend, ""),
                    "value", "trade", colorConfig);

                string highlight = "";
                if (member(specialtyPorts, port->getPortName()) > -1)
                {
                    highlight = configuration->decorate("[Specialty]", 
                        "specialty", "trade", colorConfig);
                }
                else if (member(importPorts, port->getPortName()) > -1)
                {
                    highlight = configuration->decorate("[Import]", 
                        "import", "trade", colorConfig);
                }

                ret += highlight + "\n";
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    int counter = 1;

    if (!SelectedCategory)
    {
        SuppressColon = 0;
        Description = "Select type of trade item";
        string *categories = TradingService->getTradingTypes();
        foreach (string category in categories)
        {
            if (sizeof(category) > 18)
            {
                category = category[0..14] + "...";
            }

            Data[to_string(counter++)] = ([
                "name": capitalize(category),
                "type": "category",
                "category": category,
                "description": "",
                "canShow": 1
            ]);
        }
        Data[to_string(counter++)] = ([
            "name": "Return to Previous Menu",
            "type": "return",
            "description": "Return to the previous menu.",
            "canShow": 1
        ]);
    }
    else if (!SelectedItem)
    {
        SuppressColon = 0;
        Description = "Select a trade item";
        string *items = TradingService->getItemListForType(SelectedCategory);
        foreach (string itemPath in items)
        {
            object itemObj = load_object(itemPath);
            if (itemObj)
            {
                string name = itemObj->query("name");
                if (sizeof(name) > 18)
                {
                    name = name[0..14] + "...";
                }

                Data[to_string(counter++)] = ([
                    "name": name,
                    "type": "item",
                    "itemPath": itemPath,
                    "description": "",
                    "canShow": 1
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
    else
    {
        SuppressColon = 1;
        Description = displayPriceBoard(SelectedItem);
        Data["1"] = ([
            "name": "Return to Previous Menu",
            "type": "return",
            "description": "Return to the previous menu.",
            "canShow": 1
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int result = -1;
    if (User && Data[selection]["canShow"])
    {
        string type = Data[selection]["type"];
        switch (type)
        {
            case "return":
            {
                notifySynchronous("onSelectorCompleted");
                result = 1;
                break;
            }
            case "back":
            {
                if (SelectedItem)
                {
                    SelectedItem = 0;
                }
                else if (SelectedCategory)
                {
                    SelectedCategory = 0;
                }

                setUpUserForSelection();
                tell_object(User, displayMessage());
                result = -1;
                break;
            }
            case "category":
            {
                SelectedCategory = Data[selection]["category"];
                setUpUserForSelection();
                tell_object(User, displayMessage());
                result = -1;
                break;
            }
            case "item":
            {
                SelectedItem = Data[selection]["itemPath"];
                setUpUserForSelection();
                tell_object(User, displayMessage());
                result = -1;
                break;
            }
        }
    }
    return result;
}


/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-19s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}
