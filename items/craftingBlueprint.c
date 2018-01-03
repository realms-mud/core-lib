//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
            foreach(string prereq in prereqList)
            {
                addPrerequisite(prereq, prereqs[prereq]);
            }
        }
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
    return ret;
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
                ret = "item"::set(element, data);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialList()
{
    mapping ret = ([]);
    string *materialList = m_indices(itemData["crafting materials"]);
    foreach(string material in materialList)
    {
        if (mappingp(itemData["crafting materials"][material]))
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