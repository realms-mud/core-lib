//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
private string getItemPathForType(string itemType)
{
    switch(itemType)
    {
        case "materials": return "/lib/instances/items/materials/metal/iron";
        case "weapons": return "/lib/instances/items/weapons/swords/long-sword";
        case "food": return "/lib/instances/items/food/bread";
        case "textiles": return "/lib/instances/items/materials/textile/silk";
        default: return "/lib/instances/items/materials/metal/iron";
    }
}

/////////////////////////////////////////////////////////////////////////////
private int calculateContractProgress(mapping contract)
{
    string requiredItem = getItemPathForType(contract["item type"]);
    int has = User->getCargoQuantity(requiredItem);

    if (has > 0)
    {
        int needed = contract["quantity"];
        return (has * 100) / needed;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private void displayActiveContracts()
{
    mapping activeContracts = User->getActiveContracts();
    string colorConfiguration = User->colorConfiguration();
    object configuration = getDictionary("configuration");
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();

    string contractDisplay = commandsDictionary->buildBanner(colorConfiguration, charset, "top",
        "Active Trading Contracts");

    if (!sizeof(activeContracts))
    {
        contractDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
            configuration->decorate("You have no active contracts.",
                "note", "selector", colorConfiguration));
    }
    else
    {
        string *contractIds = m_indices(activeContracts);
        foreach(string id in contractIds)
        {
            mapping contract = activeContracts[id];

            int timeLeft = contract["deadline"] - time();
            int daysLeft = timeLeft / 86400;
            string urgencyColor = "field data";
            if (daysLeft <= 1)
                urgencyColor = "penalty modifier";
            else if (daysLeft <= 3)
                urgencyColor = "warning";

            string contractLine = configuration->decorate(sprintf("%s: ", id),
                "field header", "research", colorConfiguration) +
                configuration->decorate(contract["description"],
                "field data", "research", colorConfiguration);

            contractDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, contractLine);

            string statusLine = configuration->decorate("  Destination: ",
                "field header", "research", colorConfiguration) +
                configuration->decorate(contract["destination"],
                "field data", "research", colorConfiguration) +
                configuration->decorate("  Time Left: ",
                "field header", "research", colorConfiguration) +
                configuration->decorate(sprintf("%d days", daysLeft),
                urgencyColor, "research", colorConfiguration);

            contractDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, statusLine);

            int progress = calculateContractProgress(contract);
            string progressLine = configuration->decorate("  Progress: ",
                "field header", "research", colorConfiguration) +
                configuration->decorate(sprintf("%d%% complete", progress),
                progress >= 100 ? "bonus modifier" : "field data",
                "research", colorConfiguration);

            contractDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, progressLine);
        }
    }

    contractDisplay += commandsDictionary->buildBanner(colorConfiguration, charset, "bottom", "-");
    tell_object(User, contractDisplay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Trading Contracts";
    Type = "Contracts";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object environment = environment(User);
    object configuration = getDictionary("configuration");

    if (!environment || !environment->isPort())
    {
        tell_object(User, configuration->decorate("You must be at a trading port to view contracts.",
            "failure", "selector", User->colorConfiguration()));
        return;
    }

    mapping contracts = environment->getContracts();
    mapping activeContracts = User->getActiveContracts();

    Data = ([]);
    int counter = 1;

    if (sizeof(activeContracts))
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("View Active Contracts (%d)", sizeof(activeContracts)),
            "type": "active",
            "description": "Review your currently accepted contracts and their status.",
            "canShow": 1
        ]);
    }

    if (!pointerp(contracts) || !sizeof(contracts))
    {
        Data[to_string(counter++)] = ([
            "name": "No Contracts Available",
            "type": "empty",
            "description": "There are no contracts available at this port currently.",
            "canShow": 0
        ]);
    }
    else
    {
        string *contractIds = m_indices(contracts);
        foreach(string id in contractIds)
        {
            mapping contract = contracts[id];
            int timeLeft = contract["deadline"] - time();
            int daysLeft = timeLeft / 86400;

            if (timeLeft > 0)
            {
                string urgency = "";
                if (daysLeft <= 3)
                    urgency = " [URGENT]";
                else if (daysLeft <= 7)
                    urgency = " [Soon]";

                Data[to_string(counter++)] = ([
                    "name": sprintf("%s%s", contract["description"], urgency),
                    "type": "available",
                    "contract id": id,
                    "contract data": contract,
                    "days left": daysLeft,
                    "description": sprintf("Contract: %s\n"
                        "Destination: %s\n"
                        "Reward: %d gold\n"
                        "Time Remaining: %d days\n"
                        "Item Type: %s (Quantity: %d)",
                        contract["description"],
                        contract["destination"],
                        contract["reward"],
                        daysLeft,
                        contract["item type"],
                        contract["quantity"]),
                    "canShow": 1
                ]);
            }
        }
    }

    Data[to_string(counter++)] = ([
        "name": "Return to Trading Menu",
        "type": "exit",
        "description": "Return to the main trading menu.",
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
        switch(type)
        {
            case "active":
                displayActiveContracts();
                result = -1;
                break;
            case "available":
            {
                object configuration = getDictionary("configuration");
                tell_object(User, configuration->decorate(
                    "Contract acceptance system not yet implemented.",
                    "note", "selector", User->colorConfiguration()));
                result = -1;
                break;
            }
            case "exit":
                notifySynchronous("onSelectorCompleted");
                result = 1;
                break;
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
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    object configuration = getDictionary("configuration");
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    string colorConfiguration = User->colorConfiguration();

    string urgencyIndicator = "";
    if (Data[choice]["type"] == "available" && member(Data[choice], "days left"))
    {
        if (Data[choice]["days left"] <= 3)
        {
            urgencyIndicator = configuration->decorate(" [!]", "penalty modifier",
                "research", colorConfiguration);
        }
    }

    return sprintf("%s[%s]%s - %s%s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-40s", displayType, "selector", colorConfiguration),
        urgencyIndicator,
        displayDetails(choice));
}
