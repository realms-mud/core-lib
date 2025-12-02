//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _materials_c
#define _materials_c

#include "/lib/services/crafting/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping materialsUsedForSubcomponents(string *components,
    mapping craftingMaterials, mapping blueprintMaterials)
{
    mapping ret = ([]);
    foreach(string component in components)
    {
        foreach(string materialClass in materialClasses)
        {
            if (member(craftingMaterials[component], materialClass))
            {
                string type = craftingMaterials[component]["type"];
                if (member(craftingComponents, type) &&
                    member(craftingComponents[type], "crafting materials") &&
                    member(craftingComponents[type]["crafting materials"], materialClass))
                {
                    if (!member(ret, craftingMaterials[component][materialClass]))
                    {
                        ret[craftingMaterials[component][materialClass]] = 0;
                    }
                    ret[craftingMaterials[component][materialClass]] +=
                        craftingComponents[type]["crafting materials"][materialClass];
                }
                else if (member(blueprintMaterials, component) &&
                    member(blueprintMaterials[component], materialClass))
                {
                    if (!member(ret, craftingMaterials[component][materialClass]))
                    {
                        ret[craftingMaterials[component][materialClass]] = 0;
                    }
                    ret[craftingMaterials[component][materialClass]] +=
                        blueprintMaterials[component][materialClass];
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping materialsUsedForSingleComponentItem(
    mapping craftingMaterials, mapping blueprintMaterials)
{
    mapping ret = ([]);
    foreach(string materialClass in materialClasses)
    {
        if (member(craftingMaterials, materialClass))
        {
            if (member(blueprintMaterials, materialClass))
            {
                if (!member(ret, craftingMaterials[materialClass]))
                {
                    ret[craftingMaterials[materialClass]] = 0;
                }
                ret[craftingMaterials[materialClass]] +=
                    blueprintMaterials[materialClass];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping materialsUsedForCrafting(object item)
{
    mapping ret = ([]);
    mapping craftingMaterials = item->query("crafting materials");
    if (craftingMaterials && mappingp(craftingMaterials))
    {
        string *components = filter(m_indices(craftingMaterials),
            (: mappingp($2[$1]) :), craftingMaterials);

        object blueprintObj = getBlueprintFor(item);
        mapping blueprintMaterials = blueprintObj->query("crafting materials");
        if (sizeof(blueprintMaterials))
        {
            if (sizeof(components))
            {
                ret = materialsUsedForSubcomponents(components,
                    craftingMaterials, blueprintMaterials);
            }
            else
            {
                ret = materialsUsedForSingleComponentItem(
                    craftingMaterials, blueprintMaterials);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasMaterialsSelected(object item, string component,
    mapping materialsData)
{
    int ret = 0;
    mapping componentData = item->query("crafting materials");

    string *materialsList = filter(m_indices(materialsData),
        (: ($2[$1] || ($3 && member($3, $4) && 
            member(craftingComponents, $3[$4]["type"]) &&
            member(craftingComponents[$3[$4]["type"]], "crafting materials") &&
            member(craftingComponents[$3[$4]["type"]]["crafting materials"], $1))) :),
            materialsData, componentData, component);

    if (componentData && member(componentData, component) &&
        member(componentData[component], "type") && sizeof(materialsData))
    {
        ret = 1;
        foreach(string material in materialsList)
        {
            ret &&= member(componentData[component], material);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateMaterial(object item)
{
    if (!item->query("crafting in progress"))
    {
        object blueprint = getBlueprintFor(item);
        mapping materialList = item->query("crafting materials");

        string materialClass = blueprint ?
            materials[blueprint->query("default material")]["class"] : 
            0;

        if (materialClass && mappingp(materialList) &&
            !item->query("do not update material"))
        {
            item->set("do not update material", 1);

            item->set("primary crafting material", item->query("material"));
            if (blueprint->query("primary component") &&
                member(materialList, blueprint->query("primary component")))
            {
                materialList[blueprint->query("primary component")]
                    [materialClass] = item->query("material");
            }
            else
            {
                materialList[materialClass] = item->query("material");
            }
            item->set("crafting materials", materialList);
            item->unset("do not update material");
        }
    }
}

#endif
