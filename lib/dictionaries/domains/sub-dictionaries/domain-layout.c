//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";

/////////////////////////////////////////////////////////////////////////////
private nomask void transformLayout(mapping building)
{
    string layout = implode(building["layout"], "\n");

    foreach(string key in m_indices(building["components"]))
    {
        foreach(string section in 
            m_indices(building["components"][key]["sections"]))
        {
            layout = regreplace(layout, section,
                building["components"][key]["sections"][section], 1);
        }
    }
    building["layout"] = explode(layout, "\n");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string applyIsBuildingBackground(string message,
    string colorConfiguration)
{
    string ret = message;
    string colorReplacement = "";

    switch (colorConfiguration)
    {
        case "3-bit":
        {
            colorReplacement = "\x1b[0;31;1";
            break;
        }
        case "8-bit":
        {
            colorReplacement = "\x1b[0;48;5;52;\\1";
            break;
        }
        case "24-bit":
        {
            colorReplacement = "\x1b[0;48;2;90;0;0;\\1";
            break;
        }
    }

    return 
        regreplace(ret, "\x1b.0;([^m]+)", colorReplacement, 1);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string applyColorToBuilding(mapping component, string key, 
    string colorConfiguration, string charset)
{
    string ret = 0;
    string *colors = m_indices(CastleComponents[key]["colors"]);
       
    ret = component[charset];
    if (sizeof(colors))
    {
        foreach(string color in colors)
        {
            string transformColor = 
                member(CastleComponents[key]["colors"][color], colorConfiguration) ?
                    CastleComponents[key]["colors"][color][colorConfiguration] :
                    "";

            ret = regreplace(ret, color, transformColor, 1);
        }
    }

    ret = member(CastleComponents[key]["colors"]["default"], colorConfiguration) ?
        CastleComponents[key]["colors"]["default"][colorConfiguration] +
        ret + "\x1b[0m" : ret;

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *getComponentDetails(mapping component)
{
    string *ret = ({ "" });

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void updateSections(mapping blueprint, string *sections, 
    string key, string component, string highlightComponent,
    string colorConfiguration, string charset)
{
    foreach(string section in sections)
    {
        blueprint[section] = applyColorToBuilding(
                CastleComponents[key]["components"][section] + ([]),
                key, colorConfiguration, charset);

        if (stringp(highlightComponent) && (highlightComponent == component))
        {
            blueprint[section] =
                applyIsBuildingBackground(blueprint[section], colorConfiguration);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getUnbuiltDomain(string type, string highlightComponent, 
    string colorConfiguration, string charset)
{
    mapping ret = ([]);

    if (stringp(type) && member(CastleBlueprints, type))
    {
        ret = CastleBlueprints[type] + ([]);

        string *components = m_indices(ret["components"]);
        foreach(string component in components)
        {
            ret["components"][component]["sections"] = ([]);

            string key = sprintf("unbuilt %s", component);

            updateSections(ret["components"][component]["sections"],
                m_indices(CastleComponents[key]["components"]),
                sprintf("unbuilt %s", component),
                component, highlightComponent, colorConfiguration, charset);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void applyDomainUpgrades(mapping domains, object player, 
    string location, string highlightComponent, string colorConfiguration, 
    string charset)
{
    mapping upgrades = player->getDomainUpgrades(location);

    if (sizeof(upgrades))
    {
        foreach(string upgrade in m_indices(upgrades))
        {
            string upgradeName = upgrades[upgrade]["name"];

            if (member(CastleComponents, upgradeName))
            {
                updateSections(domains["components"][upgrade]["sections"],
                    m_indices(CastleComponents[upgradeName]["components"]),
                    upgradeName, upgrade, highlightComponent,
                    colorConfiguration, charset);

                domains["components"][upgrade]["constructed"] = 
                    upgrades[upgrade];
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void applyCurrentComponent(mapping domains, string component,
    string highlightComponent, string colorConfiguration, string charset)
{
    if (component && member(CastleComponents, component))
    {
        string upgrade = CastleComponents[component]["type"];

        updateSections(domains["components"][upgrade]["sections"],
            m_indices(CastleComponents[component]["components"]),
            component, upgrade, highlightComponent, colorConfiguration, charset);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getPlayerDomain(object player, string location,
    string type, string highlightComponent, string currentComponent)
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();

    mapping ret = 
        getUnbuiltDomain(type, highlightComponent, colorConfiguration, charset);

    applyDomainUpgrades(ret, player, location, highlightComponent,
        colorConfiguration, charset);

    applyCurrentComponent(ret, currentComponent, highlightComponent,
        colorConfiguration, charset);

    if (sizeof(ret))
    {
        transformLayout(ret);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getLayout(string component, 
    string colorConfiguration, string charset)
{
    string* ret = ({ });

    if (member(CastleComponents, component))
    {
        string* sections = sort_array(
            m_indices(CastleComponents[component]["components"]),
            (: $1 > $2 :));

        foreach(string section in sections)
        {
            ret += ({ 
                applyColorToBuilding(
                CastleComponents[component]["components"][section] + ([]),
                component, colorConfiguration, charset)
            });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayLayout(string component, 
    string colorConfiguration, string charset)
{
    string *ret = getLayout(component, colorConfiguration, charset);

    if (sizeof(ret))
    {
        for (int i = 0; i < sizeof(ret); i++)
        {
            ret[i] = "        " + ret[i] +
                sprintf("%-" + to_string(21 - textWidth(ret[i])) + "s", "");
        }

        ret[0] = regreplace(ret[0], "        ",
            configuration->decorate("Layout: ", "heading", "player domains",
                colorConfiguration));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getSectionDurations(mapping sections)
{
    int ret = 0;

    foreach(string section in m_indices(sections))
    {
        if (member(sections[section], "selection") &&
            member(BuildingComponents, sections[section]["selection"]) &&
            member(BuildingComponents[sections[section]["selection"]],
                "added duration"))
        {
            ret += BuildingComponents[sections[section]["selection"]]
                    ["added duration"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getWorkerDurations(int initialValue, mapping workers)
{
    int ret = 0;

    float multiplier = 0.0;
    int numWorkers = 0;

    if (sizeof(workers))
    {
        foreach(string workerType in m_indices(workers))
        {
            foreach(string worker in m_indices(workers[workerType]))
            {
                if (member(workers[workerType][worker], "benefits") &&
                    member(workers[workerType][worker]["benefits"], "duration"))
                {
                    numWorkers++;
                    multiplier -=
                        to_float(workers[workerType][worker]["benefits"]["duration"]);
                }
            }
        }
    }
    return to_int(initialValue * (100.0 + (multiplier / 
        (numWorkers ? numWorkers : 1))) / 100.0);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayCompletionTime(object user, mapping componentData,
    mapping constructionData, string colorConfiguration, string charset)
{
    int completionTime = constructionData["duration"];

    if (member(componentData, "selected sections"))
    {
        completionTime += 
            getSectionDurations(componentData["selected sections"]);
    }

    if (member(componentData, "assigned workers"))
    {
        completionTime = getWorkerDurations(completionTime,
            componentData["assigned workers"]);
    }

    return ({
        configuration->decorate("Completion time: ", "heading",
            "player domains", colorConfiguration) +
        configuration->decorate(sprintf("%-12d", completionTime),
            "value", "player domains", colorConfiguration),
        configuration->decorate(sprintf("%-29s", ""), "heading",
            "player domains", colorConfiguration)
    });
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayMaterialsData(object user, mapping componentData,
    mapping constructionData, string colorConfiguration, string charset)
{
    string *ret = ({});

    foreach(string material in m_indices(constructionData["materials"]))
    {
        string selection = configuration->decorate(sprintf("    %-25s", "<select>"),
            "selection needed", "player domains", colorConfiguration);

        if (member(componentData, "selected sections") &&
            member(componentData["selected sections"], material))
        {
            selection = componentData["selected sections"][material]["selection"];
            if (sizeof(selection) > 25)
            {
                selection = selection[0..21] + "...";
            }
            selection = configuration->decorate(sprintf("    %-25s", selection),
                "value", "player domains", colorConfiguration);
        }
        ret += ({ 
            configuration->decorate(
                sprintf("%-29s", generateTitle(material) + ":"),
                "heading", "player domains", colorConfiguration),
            selection
        });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayWorkerData(object user, mapping workerData,
    mapping constructionData, string colorConfiguration, string charset)
{
    string *ret = ({ 
        configuration->decorate(
            sprintf("%-29s", ""),
            "heading", "player domains", colorConfiguration),
        configuration->decorate(
            sprintf("%-29s", "Needed workers:"),
            "heading", "player domains", colorConfiguration),
    });

    string *workers = sort_array(m_indices(constructionData["workers"]),
        (: $1 > $2 :));

    foreach(string worker in workers)
    {
        int currentNumber = (mappingp(workerData) &&
            member(workerData, "assigned workers") &&
            mappingp(workerData["assigned workers"]) &&
            member(workerData["assigned workers"], worker)) ?
            sizeof(workerData["assigned workers"][worker]) : 0;

        int totalNeeded = constructionData["workers"][worker];

        ret += ({ 
            configuration->decorate(
                sprintf("    %-17s - ", generateTitle(worker)),
                "worker", "player domains", colorConfiguration) +
            configuration->decorate(sprintf("%2d", currentNumber),
                (currentNumber >= totalNeeded) ? "value" : "incomplete",
                "player domains", colorConfiguration) +
            configuration->decorate("/", currentNumber,
                "heading", "player domains", colorConfiguration) +
            configuration->decorate(sprintf("%-2d", totalNeeded),
                "total", "player domains", colorConfiguration)
        });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping aggregateUnitList(mapping constructionData,
    mapping componentData)
{
    mapping units = ([]);

    foreach(string material in m_indices(constructionData["materials"]))
    {
        if (member(componentData, "selected sections") &&
            member(componentData["selected sections"], material) &&
            member(BuildingComponents,
                componentData["selected sections"][material]["selection"]))
        {
            string key = componentData["selected sections"][material]["selection"];

            if (member(BuildingComponents[key], "default units"))
            {
                foreach(string unit in
                    m_indices(BuildingComponents[key]["default units"]))
                {
                    if (!member(units, unit))
                    {
                        units[unit] = 0;
                    }
                    units[unit] +=
                        BuildingComponents[key]["default units"][unit];
                }
            }
            if (member(BuildingComponents[key], "henchmen"))
            {
                foreach(string unit in
                    m_indices(BuildingComponents[key]["henchmen"]))
                {
                    if (!member(units, "henchman"))
                    {
                        units["henchman"] = 0;
                    }
                    units["henchman"] +=
                        BuildingComponents[key]["henchmen"][unit];
                }
            }
        }
    }
    return units;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping aggregateBonuses(mapping constructionData,
    mapping componentData)
{
    mapping bonuses = ([]);

    foreach(string material in m_indices(constructionData["materials"]))
    {
        if (member(componentData, "selected sections") &&
            member(componentData["selected sections"], material) &&
            member(BuildingComponents, 
                componentData["selected sections"][material]["selection"]))
        {
            string key = componentData["selected sections"][material]["selection"];
            
            foreach(string bonus in ({ "structure", "defend ground attack",
                "defend air attack", "ground attack", "air attack" }))
            {
                if (member(BuildingComponents[key], bonus))
                {
                    bonuses[bonus] = bonuses[bonus] +
                        BuildingComponents[key][bonus];
                }
            }
        }
    }
    return bonuses;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *formatUnits(string *layout, mapping componentData, 
    mapping constructionData, string colorConfiguration, string charset)
{
    int offset = 0;
    string *ret = ({ 
        configuration->decorate(sprintf("%-29s", "Layout:"),
            "heading", "player domains", colorConfiguration) 
    });

    mapping units = aggregateUnitList(constructionData, componentData);

    int componentSize = 9 - textWidth(CastleComponents[componentData["name"]]["components"]
        [m_indices(CastleComponents[componentData["name"]]["components"])[0]]["ascii"]);

    if (sizeof(units))
    {
        ret = ({
            configuration->decorate(sprintf("%-9s %-19s", "Layout:", "Units:"),
                "heading", "player domains", colorConfiguration)
        });

        foreach(string unit in m_indices(units))
        {
            string unitName = pluralizeValue(unit);
            if (sizeof(unitName) > (15 + componentSize))
            {
                unitName = unitName[0..(11 + componentSize)] + "...";
            }

            ret += ({ ((sizeof(layout) > offset) ? layout[offset] : 
                sprintf("%-" + to_string(9 + componentSize) + "s", "")) +
                configuration->decorate(sprintf("%3d ", units[unit]),
                    "selected", "player domains", colorConfiguration) +
                configuration->decorate(
                    sprintf("%-" + to_string(16 - componentSize) + "s", unitName),
                    "value", "player domains", colorConfiguration)
            });

            offset++;
        }
    }

    if (sizeof(ret) <= sizeof(layout))
    {
        for (int i = offset; i < sizeof(layout); i++)
        {
            ret += ({ 
                (sizeof(layout) > offset) ? (layout[i] + 
                sprintf("%-" + to_string(29 - textWidth(layout[i])) + "s", "")) : 
                sprintf("%-29s", "") });
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *formatBonuses(mapping componentData, 
    mapping constructionData, string colorConfiguration, string charset)
{
    string *ret = ({ });

    mapping bonuses = aggregateBonuses(constructionData, componentData);

    if (sizeof(bonuses))
    {
        ret += ({
        configuration->decorate(sprintf("%-29s", "Effects:"),
            "heading", "player domains", colorConfiguration)
        });

        foreach(string bonus in m_indices(bonuses))
        {
            ret += ({ 
                configuration->decorate(sprintf("+%-3d", bonuses[bonus]),
                    "selected", "player domains", colorConfiguration) +
                configuration->decorate(sprintf(" to %-21s", bonus),
                    "value", "player domains", colorConfiguration)
            });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayBuildingBenefits(object user, mapping componentData,
    mapping constructionData, string colorConfiguration, string charset)
{
    string *layout = getLayout(componentData["name"], colorConfiguration, charset);

    string *ret = formatUnits(layout, componentData, constructionData,
        colorConfiguration, charset);

    ret += formatBonuses(componentData, constructionData,
        colorConfiguration, charset);

    return ret;
}
