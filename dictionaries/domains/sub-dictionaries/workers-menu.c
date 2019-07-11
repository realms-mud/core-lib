//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/domain-layout.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int canSelectWorkers(mapping componentData)
{
    return 0;
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

    return generateBuildInfo(
        displayLayout(componentData["name"], colorConfiguration, charset),
        displayWorkerData(user, componentData["construction"] + ([]),
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
        foreach(string entry in m_indices(currentSelections))
        {
            string details = currentSelections[entry]["benefits"];
            ret += "    " +
                configuration->decorate(
                    sprintf("%-25s", (sizeof(entry) > 25) ?
                        entry[0..21] + "..." : entry),
                    currentSelections[entry]["level"], "player domains", 
                    colorConfiguration) +
                configuration->decorate(
                    sprintf("Benefits: %-40s\n", (sizeof(details) > 4000) ?
                        details[0..36] + "..." : details),
                    "heading", "player domains", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getWorkersByTypeMenu(object user, string location,
    string type, int confirmDisabled)
{
    mapping ret = ([]);

    mapping henchmen = user->getHenchmen(location, type);
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
                "description": sprintf("This option assigns %s to the task of "
                    "building the selected component.\n", name),
                "is disabled": henchmen[worker]->activity() != "idle",
                "data": henchmen[worker],
                "canShow": 1
            ]);            
        }
    }
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
