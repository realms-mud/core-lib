//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object Port;
private string selectedItem;
private string selectedCategory;
private int showingCategories;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    NumColumns = 2;
    Description = "Buy Goods";
    Type = "Purchase";
    Data = ([]);
    showingCategories = 1;
    selectedCategory = "";
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
private mapping getVehicleCapabilityCache()
{
    mapping cache = ([
        "has capacity": 0,
        "max capacity": 0
    ]);

    object *vehicles = User->getVehicles();
    if (sizeof(vehicles) > 0)
    {
        int totalAvailableCapacity = 0;
        foreach(object vehicle in vehicles)
        {
            if (objectp(vehicle))
            {
                int available = vehicle->getFreeSpace();

                totalAvailableCapacity += available;
                if (available > 0)
                {
                    cache["has capacity"] = 1;
                }
            }
        }
        cache["max capacity"] = totalAvailableCapacity;
    }

    return cache;
}

/////////////////////////////////////////////////////////////////////////////
private int checkItemCapacity(string item, mapping capacityCache)
{
    return (capacityCache["has capacity"] && capacityCache["max capacity"] > 0);
}

/////////////////////////////////////////////////////////////////////////////
private mapping getBuyTargets()
{
    mapping targets = ([]);

    object *vehicles = User->getVehicles();
    foreach(object vehicle in vehicles)
    {
        if (objectp(vehicle))
        {
            int available = vehicle->getFreeSpace();
            if (available > 0)
            {
                targets[vehicle->getName()] = ([
                    "object": vehicle,
                    "maxQuantity": available
                ]);
            }
        }
    }

    object warehouse = User->getWarehouseAtPort(Port);
    if (objectp(warehouse))
    {
        int available = warehouse->getFreeSpace();
        if (available > 0)
        {
            targets["Warehouse"] = ([
                "object": warehouse,
                "maxQuantity": available
            ]);
        }
    }

    return targets;
}

/////////////////////////////////////////////////////////////////////////////
private void setUpCategorySelection()
{
    object tradingDict = getService("trading");
    string *categories = tradingDict->getTradingTypes();
    int counter = 1;

    // Pre-calculate vehicle capacity once
    mapping capacityCache = getVehicleCapabilityCache();

    foreach(string category in categories)
    {
        string *items = tradingDict->getItemListForType(category);
        int affordableItems = 0;
        int totalItems = 0;

        foreach(string item in items)
        {
            object itemObj;
            string err = catch (itemObj = load_object(item); nolog);
            if (!err && itemObj)
            {
                totalItems++;
                int price = Port->getItemPrice(item);
                int canAffordAny = (User->getCash() >= price) ? 1 : 0;
                int hasCapacity = checkItemCapacity(item, capacityCache);

                if (canAffordAny && hasCapacity)
                {
                    affordableItems++;
                }
            }
        }

        string name = sprintf("%s (%d/%d available)", capitalize(category), affordableItems, totalItems);
        if (sizeof(name) > 28)
        {
            name = name[0..24] + "...";
        }

        Data[to_string(counter++)] = ([
            "type": "category",
            "name": name,
            "category": category,
            "is disabled": (affordableItems == 0),
            "canShow": 1,
            "description": sprintf("Browse %s items. %d of %d items are affordable and fit in your vehicles.",
                                 category, affordableItems, totalItems)
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private void setUpItemSelection()
{
    object tradingDict = getService("trading");
    string *items = tradingDict->getItemListForType(selectedCategory);
    int counter = 1;

    // Pre-calculate vehicle capacity once
    mapping capacityCache = getVehicleCapabilityCache();

    foreach(string item in items)
    {
        object itemObj;
        string err = catch (itemObj = load_object(item); nolog);
        if (!err && itemObj)
        {
            float price = Port->getItemPrice(item);
            int canAfford = User->getCash() / to_int(price);
            int canAffordAny = (User->getCash() >= to_int(price)) ? 1 : 0;
            int hasCapacity = checkItemCapacity(item, capacityCache);

            // Calculate max quantity based on capacity
            int maxCapacity = capacityCache["max capacity"];
            int maxQuantity = (maxCapacity > 0 && maxCapacity < canAfford) ?
                maxCapacity : canAfford;

            if (maxQuantity <= 0 && canAffordAny && hasCapacity)
            {
                maxQuantity = 1;
            }

            string name = itemObj->query("name");
            if (sizeof(name) > 16)
            {
                name = name[0..12] + "...";
            }

            // Format price for display
            string priceDisplay;
            if (price >= 1000000.0)
            {
                priceDisplay = sprintf("%.1fM", price / 1000000.0);
            }
            else if (price >= 1000.0)
            {
                priceDisplay = sprintf("%.1fK", price / 1000.0);
            }
            else
            {
                priceDisplay = sprintf("%d", to_int(price));
            }

            Data[to_string(counter++)] = ([
                "type": "item",
                "name": name,
                "item path": item,
                "price": to_int(price),
                "price display": priceDisplay,
                "can afford": canAfford,
                "max quantity": maxQuantity,
                "is disabled": (!canAffordAny || !hasCapacity),
                "canShow": 1,
                "description": sprintf("Purchase %s at %s. Price: %d gold each. You can afford %d units (capacity allows %d).",
                                     itemObj->query("name"),
                                     Port->getPortName(),
                                     to_int(price),
                                     canAfford,
                                     maxQuantity)
            ]);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object configuration = getService("configuration");

    if (objectp(Port) && Port->isPort())
    {
        Data = ([]);
        int counter = 1;

        if (showingCategories)
        {
            setUpCategorySelection();
            counter = sizeof(m_indices(Data)) + 1;
        }
        else
        {
            setUpItemSelection();
            counter = sizeof(m_indices(Data)) + 1;
        }

        Data[to_string(counter)] = ([
            "name": showingCategories ?
                sprintf("Return to %s Menu", Port->getPortName()) :
                "Return to the category selection menu.",
            "type": "exit",
            "description": showingCategories ?
                sprintf("Return to the %s port menu.", Port->getPortName()) :
                "Return to the category selection menu.",
            "canShow": 1
        ]);
    }
    else
    {
        tell_object(User, configuration->decorate("No valid trading port has been selected.",
                   "failure", "selector", User->colorConfiguration()));

        Data["1"] = ([
            "name": "Return to Trading Menu",
            "type": "exit",
            "description": "Return to the main trading menu.",
            "canShow": 1
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;

    if (User && member(Data, selection))
    {
        if (member(Data[selection], "is disabled") && Data[selection]["is disabled"])
        {
            object configuration = getService("configuration");
            string message;

            if (Data[selection]["type"] == "category")
            {
                message = "That category has no affordable items that fit in your vehicles.";
            }
            else if (Data[selection]["type"] == "item")
            {
                message = "You cannot afford that item or lack cargo capacity.";
            }
            else
            {
                message = "That option is not available.";
            }

            tell_object(User, configuration->decorate(message,
                "failure", "selector", User->colorConfiguration()));
            ret = 0;
        }
        else if (Data[selection]["type"] == "exit")
        {
            if (showingCategories)
            {
                ret = 1;
            }
            else
            {
                showingCategories = 1;
                selectedCategory = "";
                setUpUserForSelection();
                tell_object(User, displayMessage());
                ret = -1;
            }
        }
        else if (Data[selection]["type"] == "category")
        {
            selectedCategory = Data[selection]["category"];
            showingCategories = 0;
            setUpUserForSelection();
            tell_object(User, displayMessage());
            ret = -1;
        }
        else if (Data[selection]["type"] == "item")
        {
            selectedItem = Data[selection]["item path"];
            mapping targets = getBuyTargets();

            if (sizeof(targets))
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
                SubselectorObj->setItem(selectedItem);
                SubselectorObj->setTargets(targets);
                SubselectorObj->setPrice(Data[selection]["price"]);
                SubselectorObj->setAction("buy");
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
                    "No available space in vehicles or warehouse for this purchase.",
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
                sprintf("Purchase completed successfully at %s.",
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
                "Purchase cancelled.",
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
protected nomask string displayDetails(string choice)
{
    string ret = "  ";

    if (member(Data[choice], "is disabled") && Data[choice]["is disabled"])
    {
        ret = configuration->decorate((User->charsetConfiguration() == "unicode") ?
            " \u2717" : " X", "choice disabled", "selector",
            colorConfiguration);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    object configuration = getService("configuration");
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) ? "choice disabled" : "choice enabled";
    string colorConfiguration = User->colorConfiguration();

    string columnFormat = "";

    if (Data[choice]["type"] == "item")
    {
        string itemName = configuration->decorate(
            sprintf("%-16s", Data[choice]["name"]),
            displayType, "selector", colorConfiguration);

        string priceInfo = sprintf("(%4s g)",
            configuration->decorate(Data[choice]["price display"],
                "number", "selector", colorConfiguration));

        string disabledMarker = displayDetails(choice);

        columnFormat = sprintf("%s[%s]%s - %s %s%s",
            "   ",
            configuration->decorate("%s", "number", "selector", colorConfiguration),
            padSelectionDisplay(choice),
            itemName,
            priceInfo,
            disabledMarker);
    }
    else
    {
        string itemName = configuration->decorate(
            sprintf("%-28s", Data[choice]["name"]),
            displayType, "selector", colorConfiguration);

        string disabledMarker = displayDetails(choice);

        columnFormat = sprintf("%s[%s]%s - %s%s",
            (NumColumns < 3) ? "   " : "",
            configuration->decorate("%s", "number", "selector", colorConfiguration),
            padSelectionDisplay(choice),
            itemName,
            disabledMarker);
    }

    return columnFormat;
}

/////////////////////////////////////////////////////////////////////////////
protected string descriptionFormatter(string choice)
{
    string ret = "";
    object configuration = getService("configuration");
    string colorConfiguration = User->colorConfiguration();

    if (member(Data[choice], "description"))
    {
        ret = Data[choice]["description"];
    }
    return ret;
}
