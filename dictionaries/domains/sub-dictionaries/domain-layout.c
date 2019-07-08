//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    string location, string type, string highlightComponent, 
    string colorConfiguration, string charset)
{
    mapping upgrades = player->getDomainUpgrades(location, type);
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
protected nomask varargs mapping getPlayerDomain(object player, string location,
    string type, string highlightComponent, string currentComponent)
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();

    mapping ret = 
        getUnbuiltDomain(type, highlightComponent, colorConfiguration, charset);

    applyDomainUpgrades(ret, player, location, type, highlightComponent,
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
protected nomask string *displayLayout(string component, 
    string colorConfiguration, string charset)
{
    string* ret = ({ });

    if (member(CastleComponents, component))
    {
        string* sections = sort_array(
            m_indices(CastleComponents[component]["components"]),
            (: $1 > $2 :));

        string padding = sprintf("%" + to_string(21 - sizeof(
            CastleComponents[component]["components"][sections[0]]["ascii"])) +
            "s", "");

        foreach(string section in sections)
        {
            ret += ({ "        " +
                applyColorToBuilding(
                CastleComponents[component]["components"][section] + ([]),
                component, colorConfiguration, charset) + padding
            });
        }

        ret[0] = regreplace(ret[0], "        ",
            configuration->decorate("Layout: ", "heading", "player domains",
                colorConfiguration));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayCompletionTime(object user,
    mapping constructionData, string colorConfiguration, string charset)
{
    return ({
        configuration->decorate("Completion time: ", "heading",
            "player domains", colorConfiguration) +
        configuration->decorate(sprintf("%-12d", constructionData["duration"]),
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
        ret += ({ 
            configuration->decorate(
                sprintf("%-29s", generateTitle(material) + ":"),
                "heading", "player domains", colorConfiguration),
            member(componentData, material) ?
            configuration->decorate(
                sprintf("    %-25s", componentData[material]),
                "value", "player domains", colorConfiguration) :
            configuration->decorate(sprintf("    %-25s", "<select>"),
                "selection needed", "player domains", colorConfiguration)
        });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *displayWorkerData(object user,
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
        int currentNumber = 0;
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
