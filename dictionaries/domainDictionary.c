//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "domains/buildings.h"
#include "domains/castles.h"
#include "domains/castle-components.h"
#include "domains/buildingEffects.h"
#include "domains/locations.h"
#include "domains/troops.h"
#include "domains/troopEffects.h"

private string DomainSelectorBase = "/lib/modules/domains/%sSelector.c";

private object configuration =
    load_object("/lib/dictionaries/configurationDictionary.c");

/////////////////////////////////////////////////////////////////////////////
public nomask string generateTitle(string data)
{
    string *words = explode(data, " ");
    int size = sizeof(words);
    for(int i = 0; i < size; i++)
    {
        words[i] = capitalize(words[i]);
    }

    return implode(words, " ");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validBuildings(mixed buildings)
{
    int ret = 0;

    string *buildingList = ({});
    if (stringp(buildings))
    {
        buildingList += ({ buildings });
    }
    else if(pointerp(buildings) && sizeof(buildings) &&
        stringp(buildings[0]))
    {
        buildingList += buildings;
    }

    if (sizeof(buildingList))
    {
        ret = 1;

        string *blueprints = m_indices(BuildingBlueprints);
        foreach(string building in buildingList)
        {
            ret &&= (member(blueprints, building) > -1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validBuildingEffects(mapping effects)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validTroopEffects(mapping effects)
{
    return 0;
}

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
private nomask string *getComponentDetails(mapping component)
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
private nomask varargs mapping getPlayerDomain(object player, string location,
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
public nomask mapping getTopLevelDomainMenu(object user)
{
    return ([
        "1":([
            "name":"Administration Projects",
            "description" : "This option lets you administer to your realm - "
                "be it the taxation of your subjects or the assigning of "
                "workers to the various projects in your domain.\n",
            "selector" : "administration",
            "selector file": sprintf(DomainSelectorBase, "administration"),
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/domains/administration/basicAdministration.c",
                "diplomacy")                  
        ]),
        "2":([
            "name":"Building Projects",
            "description" : "This option lets you build large projects in your realm.\n",
            "selector": "build",
            "selector file": sprintf(DomainSelectorBase, "build"),
            "canShow": user->canApplyResearchBonus(
                "lib/instances/research/domains/construction/basicBuilding.c",
                "carpentry")                    
        ]),
        "3":([
            "name":"Resources and Holdings",
            "description" : "This option lets you increase your holdings, prospect for "
                "new resources, and manage resources in your domain.\n",
            "selector": "improvement",
            "selector file": sprintf(DomainSelectorBase, "improvement"),
            "canShow": user->canApplyResearchBonus(
                "lib/instances/research/domains/holdings/basicHoldings.c",
                "engineering")                
        ]),
        "4":([
            "name":"Hire New Henchmen",
            "description" : "This option lets you hire henchmen that can be used to "
                "perform tasks within your domain.\n",
            "selector": "hiring",
            "selector file": sprintf(DomainSelectorBase, "hiring"),
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/domains/hiring/basicHiring.c",
                "persuasion")  
        ]),
        "5":([
            "name":"Manage Tasks",
            "description" : "This option lets you assign tasks to your hired "
                "henchmen and companions.\n",
            "selector": "task",
            "selector file": sprintf(DomainSelectorBase, "task"),
            "canShow": user->canApplyResearchBonus(
                "lib/instances/research/domains/tasks/basicTasks.c",
                "persuasion")                 
        ]),
        "6":([
            "name":"Manage Troops",
            "description" : "This option lets you create and manage "
                "your troops and their activities.\n",
            "selector": "troops",
            "selector file": sprintf(DomainSelectorBase, "troops"),
            "canShow": user->canApplyResearchBonus(
                "lib/instances/research/domains/troops/basicTroops.c",
                "persuasion")                 
        ]),
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getTroopsMenu(object user)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getTaskMenu(object user)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getHiringMenu(object user)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getHoldingsMenu(object user)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getComponents(object user, string location, 
    string type, string highlightComponent)
{
    string *components = ComponentTypes + ({});
    string domainType = user->getDomainType(location);

    if (member(Locations, location) && (member(components, type) > -1))
    {
        if (highlightComponent && member(CastleComponents, 
            sprintf("unbuilt %s", highlightComponent)))
        {
            components = sort_array(
                filter(m_indices(CastleComponents),
                (: CastleComponents[$1]["type"] == $2 :), highlightComponent),
                    (: $1 > $2 :));

            components -= ({ sprintf("unbuilt %s", highlightComponent) });
        }
        else if (domainType && member(CastleBlueprints, domainType))
        {
            components = sort_array(
                filter(m_indices(CastleBlueprints[domainType]["components"]),
                (: CastleBlueprints[$2]["components"][$1]["type"] == $3 :),
                    domainType, type),
                    (: CastleBlueprints[$3]["components"][$1]["sort order"] >
                        CastleBlueprints[$3]["components"][$2]["sort order"] :),
                    domainType);
        }
    }
    return components;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComponentCategory(string component, string location)
{
    return ([
        "name": sprintf("Construct %s", generateTitle(component))[0..18],
        "type": component,
        "description": sprintf("From this menu, you can initiate, "
            "modify, or abort %s projects in your holdings at %s.",
            component, Locations[location]["name"]),
        "canShow": 1,
        "is category": 1,
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComponentClass(string component, mapping playerDomain)
{
    return ([
        "name": playerDomain["components"][component]["display name"][0..18],
        "type" : component,
        "description" : playerDomain["components"][component]["description"],
        "canShow" : 1,
        "details": getComponentDetails(playerDomain["components"][component])
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComponentOptions(string component, mapping playerDomain)
{
    return ([                
        "name": CastleComponents[component]["display name"][0..18],
        "value": component,
        "type": CastleComponents[component]["type"],
        "description": CastleComponents[component]["description"],
        "canShow": 1,
        "details": getComponentDetails(
            playerDomain["components"][CastleComponents[component]["type"]])
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildingMenu(object user, string location, 
    string type, string highlightComponent)
{
    mapping ret = ([]);
    string *components = getComponents(user, location, type, highlightComponent);
    string domainType = user->getDomainType(location);

    int showCategories = implode(sort_array(components, (: $1 > $2 :)), "") == 
        implode(sort_array(ComponentTypes, (: $1 > $2 :)), "");

    mapping playerDomain = getPlayerDomain(user, location, domainType,
        highlightComponent);

    int count = 1;
    int offset = 0;
    string *firstSection = 0;

    if (sizeof(playerDomain["layout"]) > sizeof(components))
    {
        offset = sizeof(playerDomain["layout"]) - sizeof(components);
        firstSection = playerDomain["layout"][0..(offset - 1)];
    }

    foreach(string component in components)
    {
        string key = to_string(count);
        if(showCategories)
        {
            ret[key] = getComponentCategory(component, location);
        }
        else if (member(playerDomain["components"], component))
        {
            ret[key] = getComponentClass(component, playerDomain);
        }
        else
        {
            ret[key] = getComponentOptions(component, playerDomain);
        }

        if (mappingp(ret[key]))
        {
            ret[key]["layout panel"] = (sizeof(playerDomain["layout"]) >= count) ?
                playerDomain["layout"][count + offset - 1] : "";

            if (firstSection)
            {
                ret[key]["first section"] = firstSection;
                firstSection = 0;
            }
        }
        count++;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *displayLayout(string component, 
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
private nomask string *displayCompletionTime(object user, 
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
private nomask string *displayMaterialsData(object user, mapping componentData,
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
private nomask string *displayWorkerData(object user, 
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
            displayCompletionTime(user, construction, 
                colorConfiguration, charset) +
            displayMaterialsData(user, componentData, construction, 
                colorConfiguration, charset) +
            displayWorkerData(user, construction, 
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
        CastleComponents[componentData["name"]]["construction"]["materials"];

    string *sections = sort_array(m_indices(construction), (: $1 > $2 :));

    int menuItem = 1;
    if (sizeof(sections))
    {
        foreach(string section in sections)
        {
            ret[to_string(menuItem)] = ([
                "name": sprintf("%-23s", generateTitle(section)),
                "description": sprintf("This option lets you select the type "
                    "of %s you will be constructing for your %s\n", 
                    section, componentData["name"]),
                "type": section,
                "canShow": 1,
                "selected": 1,
                "details": construction[section],
            ]);
            menuItem++;
        }
    }
    
    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Select Workers",
        "type": "workers",
        "data": member(CastleComponents[componentData["name"]]["construction"], 
            "workers") ?
            (CastleComponents[componentData["name"]] + ([])) : ([]),
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

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getAdministrationMenu(object user)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int hasMaterials(object player, string upgrade)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canBuild(object player, string location, string type,
    string element, string upgrade)
{
    return member(Locations, location) &&
        (Locations[location]["type"] == type) &&
        member(CastleBlueprints, type) &&
        member(CastleBlueprints[type]["components"], element) &&
        member(CastleComponents, upgrade) &&
        hasMaterials(player, upgrade);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping build(object player, string location, string type,
    string element, string upgrade)
{
    mapping ret = 0;

    if (canBuild(player, location, type, element, upgrade))
    {
        ret = ([
            "name": upgrade,
            "construction started": time(),
            "construction completion": 
                time() + CastleComponents[upgrade]["construction time"]
        ]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getPlayerHolding(object player, string location)
{
    mapping ret = 0;

    if (member(Locations, location))
    {
        ret = Locations[location] + ([]);
        ret["upgrades"] = ([]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getLocationDisplayName(string location)
{
    string ret = 0;

    if (member(Locations, location))
    {
        ret = Locations[location]["name"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getFeatureDescription(string element)
{
    string ret = 0;

    if (member(CastleComponents, element))
    {
        ret = CastleComponents[element]["feature description"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildSectionMenu(object user, string location,
    mapping sectionData)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getSectionMaterialsMenu(object user, string location,
    mapping componentData)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getWorkersMenu(object user, string location,
    mapping componentData)
{
    mapping ret = ([]);

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
public nomask int isValidHenchman(mapping data)
{
    return mappingp(data) && member(data, "name") &&
        member(data, "type") && member(data, "persona") &&
        member(data, "level") && member(data, "vitals") &&
        member(data, "activity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidActivity(string location, mapping activity)
{
    return 1;
}
