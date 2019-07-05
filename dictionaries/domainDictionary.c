//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "domains/building-components.h"
#include "domains/buildings.h"
#include "domains/castles.h"
#include "domains/castle-components.h"
#include "domains/buildingEffects.h"
#include "domains/locations.h"
#include "domains/troops.h"
#include "domains/troopEffects.h"
#include "materials/materials.h"

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
private nomask string pluralizeValue(string data)
{
    string ret = data;
    ret = regreplace(ret, "(s|ch|sh|x|z|dg|o)$", "\\1e");
    ret = regreplace(ret, "([^aeiou])y$", "\\1ie");
    ret += "s";
    ret = regreplace(ret, "(.*)mans$", "\\1men");

    return generateTitle(ret);
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
                "details": construction,
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
private nomask int canSelectSection(object user, string option)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping materialsNeededForSection(mapping sectionData,
    string selection)
{
    mapping ret = sectionData[sectionData["selected section"]] + ([]);

    if (selection && member(BuildingComponents, selection) &&
        member(BuildingComponents[selection], "building materials"))
    {
        mapping additionalMaterials =
            BuildingComponents[selection]["building materials"];

        foreach(string material in m_indices(additionalMaterials))
        {
            ret[material] += additionalMaterials[material];
        }
    }
    return filter(ret, (: ret[$1] > 0 :));
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateMaterialMenuEntries(mapping sectionData)
{
    mapping ret = ([]);

    string *materialsInSection = sort_array(
        m_indices(sectionData[sectionData["selected section"]]),
        (: $1 > $2 :));

    mapping neededMaterials = materialsNeededForSection(sectionData,
        (member(sectionData, "chosen section") ? 
            sectionData["chosen section"] : 0));

    foreach(string material in materialsInSection)
    {
        ret[to_string(sizeof(ret) + 1)] = ([
            "name": "Select " + generateTitle(material),
            "type": "material",
            "material type": material, 
            "description": "This option assigns workers to the task of "
                "building the selected component.\n",
            "is disabled": !member(neededMaterials, material),
            "selected material": 
                member(sectionData["selected materials"], material) ?
                    sectionData["selected materials"][material] : 0,
            "canShow": 1
        ]); 
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateSectionOptions(mapping output, object user,
    mapping sectionData)
{
    string *sectionOptions = sort_array(filter(m_indices(BuildingComponents),
        (: BuildingComponents[$1]["class"] == $2 :), 
            sectionData["selected section"]),
        (: $1 > $2 :));

    foreach(string option in sectionOptions)
    {
        output[to_string(sizeof(output) + 1)] = ([
            "name": generateTitle(option),
            "type": option,
            "description": "This option assigns workers to the task of "
                "building the selected component.\n",
            "is disabled": canSelectSection(user, option),
            "canShow": 1
        ]); 
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int beginConstructionIsEnabled(mapping sectionData)
{
    int ret = member(sectionData, "chosen section") && 
        member(BuildingComponents, sectionData["chosen section"]) &&
        member(sectionData, "selected materials");

    if (ret)
    {
        mapping neededMaterials = materialsNeededForSection(sectionData,
            sectionData["chosen section"]);

        foreach(string material in m_indices(neededMaterials))
        {
            ret &&= member(sectionData["selected materials"], material);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getBuildSectionMenu(object user, string location,
    mapping sectionData)
{
    mapping ret = ([]);

    if(mappingp(sectionData) && member(sectionData, "selected section"))
    {
        ret = generateMaterialMenuEntries(sectionData);
        generateSectionOptions(ret, user, sectionData);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getSectionMaterialsMenu(object user, string location,
    mapping componentData)
{
    return ([]);
}

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
private nomask string generateBuildInfo(string *leftColumn, string *rightColumn)
{
    string ret = "";

    int leftColumnSize = sizeof(leftColumn);
    int rightColumnSize = sizeof(rightColumn);
    int sharedRows = (leftColumnSize > rightColumnSize) ? 
        rightColumnSize : leftColumnSize;

    for (int i = 0; i < sharedRows; i++)
    {
        ret += sprintf("%" + sizeof(leftColumn[i]) + "s%s\n",
            leftColumn[i], rightColumn[i]);
    }
    if (leftColumnSize > rightColumnSize)
    {
        ret += implode(leftColumn[rightColumnSize..], "\n");
    }
    else
    {
        for (int i = leftColumnSize; i < rightColumnSize; i++)
        {
            ret += sprintf("%29s%s\n", "", rightColumn[i]);
        }
    }
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

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidHenchmanType(string data)
{
    return member(({ "aegis", "diplomat", "senechal", "advisor", "soldier",
        "concubine", "mage", "artisan", "sage", "noble", "scholar",
        "engineer", "architect", "craftsman", "banker", "innkeeper",
        "retailer", "manager", "scientist", "arcane craftsman" }), data) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidHenchman(mapping data)
{
    return mappingp(data) && member(data, "name") &&
        member(data, "type") && isValidHenchmanType(data["type"]) &&
        member(data, "persona") && member(data, "level") && 
        member(data, "vitals") && member(data, "activity");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidActivity(string location, mapping activity)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private string *getTypes(string type, object user)
{
    string *types = ({ type });
    if ((type == "metal") && user->isResearched("lib/instances/research/crafting/materials/useCrystalsAsMetal.c"))
    {
        types += ({ "crystal" });
    }
    else if (type == "stone")
    {
        if (user->isResearched("lib/instances/research/crafting/materials/useCrystalsAsStone.c"))
        {
            types += ({ "crystal" });
        }

        if (user->isResearched("lib/instances/research/crafting/materials/useClaysAsStone.c"))
        {
            types += ({ "clay" });
        }
    }

    return types;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialsOfTypeOnHand(string type, object user,
    mapping sectionData, mapping materialsToBeUsed)
{
    mapping ret = ([]);

    object *inventory = filter(deep_inventory(user),
        (: ((member(inherit_list($1), "lib/items/material.c") > -1) &&
            (member($2, $1->query("class")) > -1)) :), getTypes(type, user));

    if (sizeof(inventory))
    {
        foreach(object item in inventory)
        {
            string material = item->query("blueprint");
            if (!member(ret, material))
            {
                ret[material] = 0;
            }
            ret[material] += item->query("quantity");
            if (member(materialsToBeUsed, material))
            {
                ret[material] -= materialsToBeUsed[material];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getMaterialsOfType(string type, object user, 
    mapping sectionData)
{
    mapping ret = ([]);

    mapping materialsToBeUsed = materialsNeededForSection(sectionData,
        (member(sectionData, "chosen section") ?
            sectionData["chosen section"] : 0));

    mapping materialsOnHand = getMaterialsOfTypeOnHand(type, user, 
        sectionData, materialsToBeUsed);

    string *materialsOfType = sort_array(filter(m_indices(materials),
        (: (member($2, materials[$1]["class"]) > -1) :), getTypes(type, user)),
        (: $1 > $2 :));

    if(sizeof(materialsOfType))
    {
        int menuItem = 1;

        object materialDictionary = 
            load_object("/lib/dictionaries/materialsDictionary.c");

        foreach(string material in materialsOfType)
        {
            int hasMaterials = (member(materialsOnHand, material) &&
                (materialsOnHand[material] >= materialsToBeUsed[type]));

            object blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
            if (sizeof(materials) && member(materials, material))
            {
                blueprintObj->set("blueprint data", materials[material]);
                blueprintObj->set("blueprint", material);
            }

            int prerequisites = blueprintObj->checkPrerequisites(user) &&
                blueprintObj->checkResearch(user);
            destruct(blueprintObj);

            string name = capitalize(material);
            if (sizeof(name) > 20)
            {
                name = name[0..16] + "...";
            }
            ret[to_string(menuItem)] = ([
                "name": name,
                "type": material,
                "description": sprintf("This options selects %s as your %s "
                    "building material.", material, type),
                "has materials": hasMaterials,
                "prerequisites met": prerequisites,
                "canShow": (hasMaterials && prerequisites)
            ]);
            menuItem++;
        }
    }

    ret[to_string(sizeof(ret) + 1)] = ([
        "name":"Exit Material Menu",
        "type": "exit",
        "description": "This option lets you exit the material "
            "selection menu.\n",
        "canShow": 1
    ]);
    return ret;
}
