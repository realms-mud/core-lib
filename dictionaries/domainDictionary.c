//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "domains/buildings.h"
#include "domains/castles.h"
#include "domains/castle-components.h"
#include "domains/buildingEffects.h"
#include "domains/troops.h"
#include "domains/troopEffects.h"

private string DomainSelectorBase = "/lib/modules/domains/%sSelector.c";

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
public nomask mapping getBuildingMenu(object user)
{
    return ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getAdministrationMenu(object user)
{
    return ([]);
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
        foreach(string section in m_indices(building["components"][key]))
        {
            layout = regreplace(layout, section,
                building["components"][key][section], 1);
        }
    }
    building["layout"] = explode(layout, "\n");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string applyColorToBuilding(mapping component, string key, 
    string colorConfiguration, string charset)
{
    string ret = 0;
    string *colors = m_indices(CastleComponents[key]["colors"]);
       
    if (member(CastleComponents[key]["colors"]["default"], colorConfiguration))
    {
        ret = component[charset];
        if (sizeof(colors))
        {
            foreach(string color in colors)
            {
                ret = regreplace(ret, color,
                    CastleComponents[key]["colors"][color][colorConfiguration], 1);
            }
        }

        ret = CastleComponents[key]["colors"]["default"][colorConfiguration] +
            ret + "\x1b[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getPlayerDomain(object player, string location,
    string type)
{
    mapping ret = ([]);

    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();

    if (stringp(type) && member(CastleBlueprints, type))
    {
        ret = CastleBlueprints[type] + ([]);

        string *components = m_indices(ret["components"]);
        foreach(string component in components)
        {
            string key = sprintf("unbuilt %s", component);
            foreach(string section in m_indices(CastleComponents[key]["components"]))
            {
                ret["components"][component][section] =
                    applyColorToBuilding(
                        CastleComponents[key]["components"][section] + ([]),
                        key, colorConfiguration, charset);
            }
        }
    }

    mapping upgrades = player->getDomainUpgrades(location, type);
    if (sizeof(upgrades))
    {
        foreach(string upgrade in m_indices(upgrades))
        {
            printf("Oy!\n");
            if (member(CastleComponents, upgrades[upgrade]))
            {
                mapping components = 
                    CastleComponents[upgrades[upgrade]]["components"];

                foreach(string section in m_indices(components))
                {
                    ret["components"][upgrade][section] =
                        applyColorToBuilding(
                            CastleComponents[upgrades[upgrade]]["components"][section] + ([]),
                            upgrades[upgrade], colorConfiguration, charset);
                }
            }
        }
    }

    transformLayout(ret);
    return ret;
}
