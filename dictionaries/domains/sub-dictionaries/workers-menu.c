//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/domain-layout.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int canSelectWorkers(mapping componentData)
{
    int ret = 0;

    if (member(componentData["construction"], "workers") &&
        member(componentData["construction"], "assigned workers"))
    {
        ret = 1;

        mapping data = componentData["construction"];
        foreach(string workerType in m_indices(data["workers"]))
        {
            ret &&= member(data["assigned workers"], workerType) && 
                (sizeof(data["assigned workers"][workerType]) ==
                    data["workers"][workerType]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getWorkersMenu(object user, string location,
    mapping componentData)
{
    mapping ret = ([]);

    if(member(componentData, "construction") && 
        member(componentData["construction"], "workers"))
    {
        ret[to_string(sizeof(ret) + 1)] = ([
            "name":"Auto-Select Workers",
            "type": "auto-select",
            "description": "This option will automatically select workers "
                "to optimally build the structure in question.\n",
            "canShow": 1
        ]);

        string *workers = sort_array(
            m_indices(componentData["construction"]["workers"]),
            (: $1 > $2 :));

        foreach(string worker in workers)
        {
            ret[to_string(sizeof(ret) + 1)] = ([
                "name": sprintf("Select %s", pluralizeValue(worker)),
                "type": worker,
                "quantity": componentData["construction"]["workers"][worker],
                "duration": componentData["construction"]["duration"],
                "description": "This option assigns workers to the task of "
                    "building the selected component.\n",
                "is disabled": canSelectWorkers(componentData),
                "canShow": 1
            ]);            
        }
        ret[to_string(sizeof(ret) + 1)] = ([
            "name": "Confirm Selected Workers",
            "type": "confirm",
            "description": "This option assigns workers to the task of "
                "building the selected component.\n",
            "is disabled": canSelectWorkers(componentData),
            "canShow": 1
        ]);
    }

    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Exit Building Menu",
        "type": "exit",
        "description": "This option lets you exit the building "
            "projects menu.\n",
        "canShow": 1
    ]);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getComponentWorkerInfo(object user, mapping componentData)
{
    // Unicode character is: \xe2\x99\x99
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    string name = componentData["name"];

    return generateBuildInfo(
        displayLayout(name, colorConfiguration, charset),
        displayWorkerData(user, componentData,
            CastleComponents[name]["construction"] + ([]),
            colorConfiguration, charset)[1..]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getWorkersOfType(object user, string type, 
    string location, int quantity, mapping currentSelections)
{
    string ret = "\n";
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    if (quantity == sizeof(currentSelections))
    {
        ret += configuration->decorate(
            sprintf("All required %s have been assigned.\nSelect 'Confirm "
            "Selections' to continue.\n", pluralizeValue(type, 1)),
            "selected", "player domains", colorConfiguration);
    }
    else
    {
        ret += configuration->decorate(
            sprintf("%s selected: %d of %d.\n", pluralizeValue(type),
                sizeof(currentSelections), quantity), 
            "selected", "player domains", colorConfiguration);
    }

    if (sizeof(currentSelections))
    {
        string *currentList = 
            sort_array(m_indices(currentSelections), (: $1 > $2 :));

        foreach(string entry in currentList)
        {
            string details = 
                currentSelections[entry]["benefits"]["description"];

            ret += "    " +
                configuration->decorate(
                    sprintf("%-25s", (sizeof(entry) > 25) ?
                        entry[0..21] + "..." : entry),
                    currentSelections[entry]["level"], "player domains", 
                    colorConfiguration) +
                configuration->decorate(
                    sprintf("%-50s\n", details),
                    "heading", "player domains", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getWorkersByTypeMenu(object user, string location,
    string type, int confirmDisabled, int duration, int currentCost)
{
    mapping ret = ([]);

    mapping henchmen = user->getHenchmen(type);
    if(sizeof(henchmen))
    {
        string *workers = sort_array(m_indices(henchmen), (: $1 > $2 :));

        foreach(string worker in workers)
        {
            string name = generateTitle(worker);
            if (sizeof(name) > 24)
            {
                name = name[0..20] + "...";
            }

            ret[to_string(sizeof(ret) + 1)] = ([
                "name": name,
                "type": worker,
                "description": 
                    format(sprintf("This option assigns %s to the task of "
                    "building the selected component.\nStats:\n", name), 78) +
                    this_object()->getHenchmanDetails(user, henchmen[worker], type, 
                        name, location),
                "do not format": 1,
                "is disabled": henchmen[worker]->activity() != "idle",
                "is remote": (location != henchmen[worker]->location()),
                "cost": henchmen[worker]->cost(),
                "data": henchmen[worker],
                "canShow": 1
            ]);            
        }
    }
    int cost = duration * 25;
    ret[to_string(sizeof(ret) + 1)] = ([
        "name": sprintf("Hire Apprentice ($%d)", cost),
        "type": "hire apprentice",
        "description": "This option hires a low-end contract worker in leiu "
            "of a henchman\n",
        "duration": duration,
        "cost": cost,
        "is disabled": user->Money() < (cost + currentCost),
        "canShow": 1
    ]);

    cost = duration * 225;
    ret[to_string(sizeof(ret) + 1)] = ([
        "name": sprintf("Hire Journeyman ($%d)", cost),
        "type": "hire journeyman",
        "description": "This option hires a contract worker in leiu "
            "of a henchman\n",
        "duration": duration,
        "cost": cost,
        "is disabled": user->Money() < (cost + currentCost),
        "canShow": 1
    ]);
    ret[to_string(sizeof(ret) + 1)] = ([
        "name": "Confirm Selections",
        "type": "confirm",
        "description": "This option assigns workers to the task of "
            "building the selected component.\n",
        "is disabled": confirmDisabled,
        "canShow": 1
    ]);

    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Exit Building Menu",
        "type": "exit",
        "description": "This option lets you exit the building "
            "projects menu.\n",
        "canShow": 1
    ]);
    return ret;
}
