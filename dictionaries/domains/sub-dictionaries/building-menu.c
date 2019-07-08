//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/domain-layout.c";

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
