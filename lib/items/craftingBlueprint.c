//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int setPrerequisiteData(mapping data)
{
    int ret = 1;
    if (member(data, "crafting prerequisites"))
    {
        mapping prereqs = data["crafting prerequisites"];
        string *prereqList = m_indices(prereqs);
        if (sizeof(prereqList))
        {
            itemData["crafting skills"] = ({});
            itemData["crafting research"] = ({});

            foreach(string prereq in prereqList)
            {
                addPrerequisite(prereq, prereqs[prereq]);

                if (prereqs[prereq]["type"] == "skill")
                {
                    itemData["crafting skills"] += ({ prereq });
                }
                if (prereqs[prereq]["type"] == "research")
                {
                    itemData["crafting research"] += ({ prereq });
                }
            }
        }
    }
    if (member(data, "skill to craft"))
    {
        itemData["skill to craft"] = data["skill to craft"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int setMaterials(mapping data)
{
    int ret = 1;
    if (member(data, "crafting materials"))
    {
        itemData["crafting materials"] = data["crafting materials"];
    }
    if (member(data, "default material"))
    {
        itemData["default material"] = data["default material"];
    }    return ret;
    if (member(data, "primary component"))
    {
        itemData["primary component"] = data["primary component"];
    }    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;
    
    if(element && stringp(element))
    {
        switch(element)
        {
            case "blueprint data":
            {
                ret = mappingp(data) &&
                    setPrerequisiteData(data) &&
                    setMaterials(data);
                break;
            }
            default:
            {
                ret = item::set(element, data);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping getMaterialList(string component)
{
    mapping ret = ([]);
    string *materialList = m_indices(itemData["crafting materials"]);
    foreach(string material in materialList)
    {
        if (mappingp(itemData["crafting materials"][material]) &&
            (!component || (material == component)))
        {
            string *componentMaterials =
                m_indices(itemData["crafting materials"][material]);

            foreach(string componentMaterial in componentMaterials)
            {
                if (!member(ret, componentMaterial))
                {
                    ret[componentMaterial] = 0;
                }
                ret[componentMaterial] +=
                    itemData["crafting materials"][material][componentMaterial];
            }
        }
        else
        {
            if (!member(ret, material))
            {
                ret[material] = 0;
            }
            ret[material] += itemData["crafting materials"][material];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialsOnHand(object user)
{
    mapping ret = ([]);
    object *inventory = filter(deep_inventory(user),
        (: (member(inherit_list($1), "lib/items/material.c") > -1) :));

    if (sizeof(inventory))
    {
        foreach(object item in inventory)
        {
            string type = item->query("class");
            string material = item->query("blueprint");
            if (!member(ret, type))
            {
                ret[type] = ([]);
                ret[type]["top"] = 0;
            }
            if (!member(ret[type], material))
            {
                ret[type][material] = 0;
            }
            ret[type][material] += item->query("quantity");

            if (!ret[type]["top"] || (ret[type][material] > ret[type][ret[type]["top"]]))
            {
                ret[type]["top"] = material;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int checkResearch(object user)
{
    int ret = 1;

    string *research = itemData["crafting research"];
    if (sizeof(research))
    {
        foreach(string item in research)
        {
            ret &&= user->canApplyResearchBonus(item);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int checkAgregateMaterials(object user)
{
    int ret = 1;

    if (member(itemData, "crafting materials") &&
        mappingp(itemData["crafting materials"]) &&
        sizeof(itemData["crafting materials"]))
    {
        mapping neededMaterials = getMaterialList();
        mapping materialsOnHand = getMaterialsOnHand(user);

        if (sizeof(neededMaterials))
        {
            string *materials = m_indices(neededMaterials);
            foreach(string material in materials)
            {
                ret &&= member(materialsOnHand, material) || !neededMaterials[material];
                if (ret && neededMaterials[material])
                {
                    string topMaterial = materialsOnHand[material]["top"];
                    ret &&= (materialsOnHand[material][topMaterial] >=
                        neededMaterials[material]);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string displayNeededMaterials(string colorConfiguration, 
    object configuration, string component)
{
    string ret = "";

    if (member(itemData, "crafting materials") &&
        mappingp(itemData["crafting materials"]) &&
        sizeof(itemData["crafting materials"]))
    {
        ret = "\n\x1b[0;36mMaterials:\n";
        mapping neededMaterials = getMaterialList(component);

        if (sizeof(neededMaterials))
        {
            string *materials = sort_array(m_indices(neededMaterials), (: $1 > $2 :));
            foreach(string material in materials)
            {
                ret += ((neededMaterials[material] > 0) ?
                    (configuration->decorate(sprintf("    %s needed: ",
                        capitalize(material)), "field data", "research", 
                        colorConfiguration) +
                    configuration->decorate(to_string(neededMaterials[material]),
                        "prerequisite", "research", colorConfiguration)) :
                    (configuration->decorate("    (Optional) ",
                        "formula type", "research", colorConfiguration) +
                     configuration->decorate(sprintf("%s can be used to embellish "
                            "the design", capitalize(material)),
                         "prerequisite", "research", colorConfiguration))) + "\n";
            }
        }
    }
    return ret + "\n";
}
