//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _component_menu_c
#define _component_menu_c

#include "/lib/dictionaries/crafting/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getMaterialsDataForItem(string type,
    object user, mapping materialsData)
{
    mapping ret = ([]);
    string *components = sort_array(filter(m_indices(craftingComponents),
        (: (craftingComponents[$1]["class"] == $2) :), type),
        (: $1 > $2 :));
    int menuItem = 1;

    if (sizeof(materialsData))
    {
        string *materialsList = sort_array(m_indices(materialsData), (: $1 > $2 :));
        foreach(string material in materialsList)
        {
            ret[to_string(menuItem)] = ([
                "name": sprintf("Select %s", material),
                "is disabled": materialsData[material] == 0,
                "selector": "material",
                "type": material,
                "description": sprintf("This option selects the %s you will "
                    "use to craft the %s\n", material, type),
            ]);
            menuItem++;
        }
    }
    foreach(string component in components)
    {
        object blueprintObj = getBlueprintItem("components", component);

        string name = capitalize(component);
        if (sizeof(name) > 20)
        {
            name = name[0..16] + "...";
        }
        ret[to_string(menuItem)] = ([
            "name": name,
            "type": component,
            "materials": blueprintObj->query("crafting materials"),
            "is disabled": (!prerequisitesMet(blueprintObj, user) || !materialsAvailable(blueprintObj, user)),
            "description": "This is " + craftingComponents[component]["description"] +
                "\n" + getDescriptionDetails(blueprintObj) + "\n"
        ]);
        menuItem++;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void selectComponent(object item, string component, string value)
{
    mapping materialSelections = item->query("crafting materials");
    if (!materialSelections)
    {
        materialSelections = ([]);
    }
    if (member(craftingComponents, value))
    {
        if (!member(materialSelections, component))
        {
            materialSelections[component] = ([]);
        }
        materialSelections[component]["type"] = value;
        materialSelections[component]["value"] = 
            craftingComponents[value]["value"];
        materialSelections[component]["experience modifier"] = 
            craftingComponents[value]["experience modifier"];
        materialSelections[component]["description"] = 
            craftingComponents[value]["description"];
        item->set("crafting materials", materialSelections);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getCraftingMaterial(object item, string materialClass,
    string component)
{
    string ret = "none";
    mapping materialSelections = item->query("crafting materials");
    if (materialSelections && mappingp(materialSelections))
    {
        if (!component)
        {
            if (member(materialSelections, materialClass))
            {
                ret = materialSelections[materialClass];
            }
        }
        else
        {
            if (member(materialSelections, component) &&
                member(materialSelections[component], materialClass))
            {
                ret = materialSelections[component][materialClass];
            }
        }
    }
    if (sizeof(ret) > 9)
    {
        ret = ret[0..5] + "...";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selectionForComponent(object item, string component)
{
    string ret = "";
    mapping materialSelections = item->query("crafting materials");
    if (materialSelections && mappingp(materialSelections) &&
        member(materialSelections, component))
    {
        ret = materialSelections[component]["type"];
    }
    return ret;
}

#endif
