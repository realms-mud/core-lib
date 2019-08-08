//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/domain-layout.c";

/////////////////////////////////////////////////////////////////////////////
private nomask string *getComponentInfo(object user, mapping componentData)
{
    string* ret = ({});

    if (member(CastleComponents, componentData["name"]))
    {
        string colorConfiguration = user->colorConfiguration();
        string charset = user->charsetConfiguration();

        mapping construction =
            CastleComponents[componentData["name"]]["construction"] + ([]);

        ret += displayLayout(componentData["name"], 
                colorConfiguration, charset) +
            displayCompletionTime(user, componentData, construction,
                colorConfiguration, charset) +
            displayMaterialsData(user, componentData, construction, 
                colorConfiguration, charset) +
            displayWorkerData(user, componentData, construction,
                colorConfiguration, charset);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int canCreateBuilding(mapping componentData)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getConstructionOptions(mapping componentData)
{
    mapping ret = ([]);
    mapping construction = 
        CastleComponents[componentData["name"]]["construction"]["materials"] + ([]);

    string *sections = sort_array(m_indices(construction), (: $1 > $2 :));

    int menuItem = 1;
    if (sizeof(sections))
    {
        foreach(string section in sections)
        {
            string name = generateTitle(section);
            if (sizeof(name) > 23)
            {
                name = name[0..19] + "...";
            }
            ret[to_string(menuItem)] = ([
                "name": sprintf("%-23s", name),
                "description": sprintf("This option lets you select the type "
                    "of %s you will be constructing for your %s\n", 
                    section, componentData["name"]),
                "type": section,
                "canShow": 1,
                "selected": 1,
                "details": construction,
            ]);
            menuItem++;
        }
    }
    
    construction = CastleComponents[componentData["name"]] + ([]);
    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Select Workers",
        "type": "workers",
        "data": (member(construction["construction"], "workers") ?
            construction : ([])),
        "description": "This option lets you select workers for the building "
            "project.\n",
        "canShow": 1
    ]);

    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Create Building",
        "type": "create",
        "description": "This option lets you begin work on the building "
            "project.\n",
        "is disabled": canCreateBuilding(componentData),
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

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildComponentMenu(object user, string location,
    mapping componentData)
{
    mapping ret = ([]);

    string domainType = user->getDomainType(location);

    mapping playerDomain = getPlayerDomain(user, location, domainType,
        componentData["type"]);

    if (objectp(user) && member(componentData, "name") && 
        member(CastleComponents, componentData["name"]) &&
        stringp(domainType) && sizeof(playerDomain))
    {
        string *details = getComponentInfo(user, componentData);

        int count = 1;
        int offset = 0;
        string *firstSection = playerDomain["layout"][0..(sizeof(details) + 1)];

        if (sizeof(firstSection) > sizeof(details))
        {
            int size;
            string *extraData = ({});

            for (int i = 0; i < sizeof(firstSection); i++)
            {
                extraData += ({ sprintf("%29s%s",
                    sizeof(details) > i ? details[i] : "", firstSection[i]) });
                size = i;
            }

            extraData += ({ configuration->decorate(
                    sprintf("%-29s", "Select building options for:"),
                    "heading", "player domains", user->colorConfiguration()) +
                playerDomain["layout"][size + 1]
            });
            firstSection = extraData;
            offset = sizeof(firstSection) - 1;
        }

        ret = getConstructionOptions(componentData);
        string *entries = sort_array(m_indices(ret), (: $1 > $2 :));
        foreach(string key in entries)
        {
            if (mappingp(ret[key]))
            {
                ret[key]["layout panel"] = (sizeof(playerDomain["layout"]) > count+offset) ?
                    playerDomain["layout"][count + offset] : "";

                if (firstSection)
                {
                    ret[key]["first section"] = firstSection;
                    firstSection = 0;
                }
            }
            count++;
        }
    }

    return ret;
}
