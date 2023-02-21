//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _generate_component_c
#define _generate_component_c

#include "/lib/dictionaries/materials/components/blueprints.c"

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComponentOfType(object item, string componentType,
    string component)
{
    mapping ret = 0;

    mapping craftingMaterials = 0;
    string itemType = item->query("blueprint");
    if (isValidWeaponBlueprint(itemType))
    {
        craftingMaterials = weaponBlueprints[itemType]["crafting materials"];
    }
    else if (isValidArmorBlueprint(itemType))
    {
        craftingMaterials = armorBlueprints[itemType]["crafting materials"];
    }
    else if (isValidInstrumentBlueprint(itemType))
    {
        craftingMaterials = instrumentBlueprints[itemType]["crafting materials"];
    }

    if (member(craftingMaterials, componentType))
    {
        if (member(craftingComponents, component) &&
            (craftingComponents[component]["class"] == componentType))
        {
            ret = craftingComponents[component] + ([]);
            if (!member(ret, "crafting materials"))
            {
                ret["crafting materials"] = craftingMaterials[componentType];
            }
            else if(sizeof(craftingMaterials[componentType]))
            {
                string *materialList = filter(
                    m_indices(craftingMaterials[componentType]),
                    (: ($2[$3][$1] > 0) :), craftingMaterials, componentType);

                if (sizeof(materialList))
                {
                    foreach(string material in materialList)
                    {
                        ret["crafting materials"][material] =
                            craftingMaterials[componentType][material];
                    }
                }
            }
        }
        else
        {
            raise_error(sprintf("ERROR in materials: %s is not a valid %s "
                "component.\n", component, componentType));
        }
    }
    else
    {
        raise_error(sprintf("ERROR in materials: %s is not a valid %s "
            "component type.\n", componentType, itemType));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping generateComponent(object item, string componentType,
    string component, mapping materialList)
{
    mapping ret = ([]);
    mapping componentData = getComponentOfType(item, componentType, component);

    ret = ([
        "description": componentData["description"],
        "value": componentData["value"],
        "type": component
    ]);

    if (sizeof(materialList))
    {
        foreach(string materialType in
            m_indices(componentData["crafting materials"]))
        {
            if (member(materialList, materialType) &&
                isValidMaterial(materialList[materialType]) &&
                materials[materialList[materialType]]["class"] == materialType)
            {
                ret[materialType] = materialList[materialType];
            }
            else if (!member(materialList, materialType))
            {
                raise_error(sprintf("ERROR in materials: The %s material is "
                    "missing from the component (%s) definition.\n",
                    materialType, componentType));
            }
            else
            {
                raise_error(sprintf("ERROR in materials: %s is not a valid "
                    "material for the specified component (%s - %s).\n",
                    materialList[materialType], componentType, component));
            }
        }
    }
    return ret + ([]);
}

#endif
