//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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

        ret += displayBuildingBenefits(user, componentData, construction,
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
            if (textWidth(name) > 23)
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
                "previous selections": member(componentData, "selected sections") ?
                    componentData["selected sections"] : ([ ])
            ]);
            menuItem++;
        }
    }
    
    construction = CastleComponents[componentData["name"]] + ([]);
    ret[to_string(sizeof(ret) + 1)] = ([
        "name": sprintf("%-23s", "Select Workers"),
        "type": "workers",
        "data": (member(construction["construction"], "workers") ?
            construction : ([])),
        "description": "This option lets you select workers for the building "
            "project.\n",
        "canShow": 1
    ]);

    ret[to_string(sizeof(ret) + 1)] = ([
        "name": sprintf("%-23s", "Create Building"),
        "type": "create",
        "description": "This option lets you begin work on the building "
            "project.\n",
        "is disabled": canCreateBuilding(componentData),
        "canShow": 1
    ]);

    ret[to_string(sizeof(ret) + 1)] = ([
        "name":sprintf("%-23s", "Exit Building Menu"),
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
        int sectionSize = (sizeof(details) + 1);
        if (sectionSize < 22)
        {
            sectionSize = 22;
        }
        string *firstSection = playerDomain["layout"][0..sectionSize];
        int firstSectionSize = sizeof(firstSection);

        int size;
        string *extraData = ({});

        for (int i = 0; i < firstSectionSize; i++)
        {
            extraData += ({ sprintf("%s%s",
                sizeof(details) > i ? details[i] : sprintf("%29s", ""), firstSection[i]) });
            size = i;
        }

        if (sizeof(details) > firstSectionSize)
        {
            for (int i = firstSectionSize; i < sizeof(details); i++)
            {
                extraData += ({ details[i] });
            }
        }

        extraData += ({ configuration->decorate(
                sprintf("%-29s", "Select building options for:"),
                "heading", "player domains", user->colorConfiguration()) +
                ((sizeof(playerDomain["layout"]) > (size + 1)) ? 
                    playerDomain["layout"][size + 1] : "")
        });
        firstSection = extraData;

        ret = getConstructionOptions(componentData);
        string *entries = sort_array(m_indices(ret), (: $1 > $2 :));
        foreach(string key in entries)
        {
            if (mappingp(ret[key]))
            {
                ret[key]["layout panel"] = 
                    (sizeof(playerDomain["layout"]) > (count + firstSectionSize)) ?
                    playerDomain["layout"][count + firstSectionSize] : "";

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
