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
private nomask string *displaySectionData(object user, mapping sections,
    string colorConfiguration, string charset)
{
    string *ret = ({ configuration->decorate("Building Sections:",
        "heading", "player domains", colorConfiguration)
    });

    string selectedSection = sections["selected section"];
    string *sectionList = sort_array(m_indices(sections), (: $1 > $2 :));

    sectionList -= ({ "name", "selected section", "selected materials", 
        "chosen section" });

    foreach(string section in sectionList)
    {
        string currentSection = member(sections, "chosen section") ?
            configuration->decorate(sections["chosen section"],
                "selected", "player domains", colorConfiguration) :
            configuration->decorate("<Make Selection>",
                "selection needed", "player domains", colorConfiguration);

        string sectionInfo = (section == selectedSection) ? currentSection :
            configuration->decorate("<Not Selected Yet>",
                "not selected yet", "player domains", colorConfiguration);

        string entry = "    " +
            configuration->decorate(generateTitle(section),
                "value", "player domains", colorConfiguration) + ": " +
            (member(sections[section], "selection") ?
                configuration->decorate(
                    generateTitle(sections[section]["selection"]["name"]),
                    "selected", "player domains", colorConfiguration) :
                sectionInfo);

        ret += ({ entry });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBuildSectionInfo(object user, mapping componentData)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    return generateBuildInfo(
        displayLayout(componentData["name"], colorConfiguration, charset),
        displaySectionData(user, 
            componentData + ([]),
            colorConfiguration, charset));
}
