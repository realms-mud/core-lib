//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object TradingDictionary;

///////////////////////////////////////////////////////////////////////////////
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
        string* contractIds = m_indices(activeContracts);
        foreach(string id in contractIds)
        {
            mapping contract = activeContracts[id];

            int minutesLeft = TradingDictionary->getMinutesUntilDeadline(contract["deadline"]);
            string timeLeftDisplay = TradingDictionary->formatTimeLeft(minutesLeft);

            string urgencyColor = "field data";
            if (minutesLeft <= 1440)
                urgencyColor = "penalty modifier";
            else if (minutesLeft <= 3 * 1440)
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
                configuration->decorate(timeLeftDisplay,
                    urgencyColor, "research", colorConfiguration);

            contractDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, statusLine);

            int progress = TradingDictionary->calculateContractProgress(User, contract);
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

///////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Trading Contracts";
    Type = "Contracts";
    Data = ([]);
    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
}

///////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object configuration = getDictionary("configuration");
    mapping contracts = TradingDictionary->queryAvailableContracts(User);
    mapping activeContracts = User->getActiveContracts();

    Data = ([]);
    int counter = 1;

    if (sizeof(activeContracts))
    {
        Data[to_string(counter++)] = ([
            "name":sprintf("View Active Contracts (%d)", sizeof(activeContracts)),
            "type" : "active",
            "description" : "Review your currently accepted contracts and their status.",
            "canShow" : 1
        ]);
    }

    if (!mappingp(contracts) || !sizeof(contracts))
    {
        Data[to_string(counter++)] = ([
            "name":"No Contracts Available",
            "type" : "empty",
            "description" : "There are no contracts available currently.",
            "canShow" : 0
        ]);
    }
    else
    {
        string* contractIds = m_indices(contracts);
        foreach(string id in contractIds)
        {
            mapping contract = contracts[id];
            int minutesLeft = TradingDictionary->getMinutesUntilDeadline(contract["deadline"]);
            string timeLeftDisplay = TradingDictionary->formatTimeLeft(minutesLeft);

            if (minutesLeft > 0)
            {
                string urgency = "";
                if (minutesLeft <= 3 * 1440)
                    urgency = " [URGENT]";
                else if (minutesLeft <= 7 * 1440)
                    urgency = " [Soon]";

                Data[to_string(counter++)] = ([
                    "name": sprintf("%s%s", contract["description"], urgency),
                    "type": "available",
                    "contract id" : id,
                    "contract data" : contract,
                    "minutes left" : minutesLeft,
                    "description" : sprintf("Contract: %s\n"
                        "Destination: %s\n"
                        "Reward: %d gold\n"
                        "Time Remaining: %s\n"
                        "Item Type: %s (Quantity: %d)",
                        contract["description"],
                        contract["destination"],
                        contract["reward"],
                        timeLeftDisplay,
                        contract["item type"],
                        contract["quantity"]),
                    "canShow": 1
                ]);
            }
        }
    }

    Data[to_string(counter++)] = ([
        "name":"Return to Trading Menu",
        "type" : "exit",
        "description" : "Return to the main trading menu.",
        "canShow" : 1
    ]);
}

///////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int result = -1;
    if (User && Data[selection]["canShow"])
    {
        string type = Data[selection]["type"];
        switch (type)
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

///////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    cleanUp();
}

///////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

///////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    object configuration = getDictionary("configuration");
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    string colorConfiguration = User->colorConfiguration();

    string urgencyIndicator = "";
    if (Data[choice]["type"] == "available" && member(Data[choice], "minutes left"))
    {
        if (Data[choice]["minutes left"] <= 3 * 1440)
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
