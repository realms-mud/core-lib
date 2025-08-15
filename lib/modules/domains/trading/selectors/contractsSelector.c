//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object TradingService;

///////////////////////////////////////////////////////////////////////////////
private string padAndDecorate(string text, int width, string deco, string section, string color)
{
    // Pad the raw text to the desired width, then decorate
    int pad = width - textWidth(text);
    string padded = text + ((pad > 0) ? sprintf("%*s", pad, "") : "");
    return configuration->decorate(padded, deco, section, color);
}

///////////////////////////////////////////////////////////////////////////////
private string padRowToBanner(string row, int bannerWidth)
{
    int pad = bannerWidth - textWidth(row);

    return row + ((pad > 0) ? sprintf("%*s", pad, "") : "");
}

///////////////////////////////////////////////////////////////////////////////
private void displayActiveContracts()
{
    mapping activeContracts = User->getActiveContracts();
    string colorConfiguration = User->colorConfiguration();
    object configuration = getService("configuration");
    object commandsService = getService("commands");
    string charset = User->charsetConfiguration();

    int bannerWidth = 75;
    string contractDisplay = commandsService->buildBanner(colorConfiguration, charset, "top",
        "Active Trading Contracts");

    if (!sizeof(activeContracts))
    {
        string line = configuration->decorate(
            "You have no active contracts.", "note", "selector", colorConfiguration);
        contractDisplay += commandsService->banneredContent(
            colorConfiguration, charset, padRowToBanner(line, bannerWidth));
    }
    else
    {
        string *contractIds = m_indices(activeContracts);
        foreach(string id in contractIds)
        {
            mapping contract = activeContracts[id];

            int minutesLeft = TradingService->getMinutesUntilDeadline(contract["deadline"]);
            string timeLeftDisplay = TradingService->formatTimeLeft(minutesLeft);

            // Determine urgency color and label
            string urgencyColor = "field data";
            string urgencyLabel = "";
            if (minutesLeft > 0)
            {
                if (minutesLeft <= 3 * 1440)
                {
                    urgencyColor = "failure";
                    urgencyLabel = " [URGENT]";
                }
                else if (minutesLeft <= 7 * 1440)
                {
                    urgencyColor = "warning";
                    urgencyLabel = " [Soon]";
                }
            }
            else
            {
                timeLeftDisplay = "expired";
            }

            string contractLine = configuration->decorate(
                sprintf("  %s: %s", id, contract["description"]),
                "field header", "selector", colorConfiguration);
            contractDisplay += commandsService->banneredContent(
                colorConfiguration, charset, padRowToBanner(contractLine, bannerWidth));

            // Decorate only the time left with urgency color, and append urgency label
            string statusLine = sprintf("    Destination: %s     Time Left: %s%s",
                contract["destination"],
                configuration->decorate(timeLeftDisplay, urgencyColor, "selector", colorConfiguration),
                configuration->decorate(urgencyLabel, "selected", "selector", colorConfiguration));
            statusLine = configuration->decorate(statusLine, "field data", "selector", colorConfiguration);

            contractDisplay += commandsService->banneredContent(
                colorConfiguration, charset, padRowToBanner(statusLine, bannerWidth));

            int progress = TradingService->calculateContractProgress(User, contract);
            string progressLine = configuration->decorate(
                sprintf("    Progress: %d%% complete", progress),
                progress >= 100 ? "bonus modifier" : "field data", "selector", colorConfiguration);
            contractDisplay += commandsService->banneredContent(
                colorConfiguration, charset, padRowToBanner(progressLine, bannerWidth));
        }
    }

    contractDisplay += commandsService->buildBanner(colorConfiguration, charset, "bottom", "-");
    tell_object(User, contractDisplay);
}

///////////////////////////////////////////////////////////////////////////////
private void acceptContract(mapping contractData)
{
    object configuration = getService("configuration");
    string contractId = contractData["contract id"];
    string portName = contractData["destination"];

    int accepted = TradingService->acceptContract(User, portName, contractId);

    if (accepted)
    {
        tell_object(User, configuration->decorate(
            sprintf("You have accepted the contract '%s' to %s.", 
                contractData["description"], 
                portName),
            "success", "selector", User->colorConfiguration()));
    }
    else
    {
        tell_object(User, configuration->decorate(
            "Failed to accept the contract.", "failure", "selector", User->colorConfiguration()));
    }
}

///////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Trading Contracts";
    Type = "Contracts";
    Data = ([]);
    TradingService = getService("trading");
}

///////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object configuration = getService("configuration");
    mapping contracts = TradingService->queryAvailableContracts(User);
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

            int minutesLeft = TradingService->getMinutesUntilDeadline(contract["deadline"]);
            string timeLeftDisplay = TradingService->formatTimeLeft(minutesLeft);

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
                    "destination" : contract["destination"],
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
            acceptContract(Data[selection]);
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
    object configuration = getService("configuration");
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
