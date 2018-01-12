//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/inventory.h"
#include "/lib/include/itemFormatters.h"
#include "materials/materials.h"
#include "materials/weapons.h"
#include "materials/armor.h"
#include "materials/components.h"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getTopLevelCraftingMenu(object user)
{
    return ([
        "1":([
            "name":"Craft Armor and Clothing",
            "description" : "This option lets you create armors, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "armor",
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/crafting/craftArmor.c", "armorer")                  
        ]),
        "2":([
            "name":"Craft Jewelry and Artwork",
            "description" : "This option lets you create jewelry and artwork, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "jewelry and artwork",
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/crafting/craftArtwork.c", "gem crafting")                  
        ]),
        "3":([
            "name":"Craft Musical Instrument",
            "description" : "This option lets you create musical instruments, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "instruments",
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/crafting/craftInstrument.c", "luthiery")                  
        ]),
        "4":([
            "name":"Craft Weapons",
            "description" : "This option lets you create weapons, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "weapons",
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/crafting/craftWeapons.c", "weapon smithing")                  
        ]),
        "5":([
            "name":"Brew Potions",
            "description" : "This option lets you brew potions, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "potions",
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/crafting/brewPotions.c", "brewing")                  
        ]),
        "6":([
            "name":"Brew Beverages and Prepare Food",
            "description" : "This option lets you brew beverages and prepare food, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "beverages and food",
            "canShow" : user->canApplyResearchBonus(
                "lib/instances/research/crafting/brewBeveragesAndCookFood.c", "cooking")                  
        ]),
        "7":([
            "name":"Refine Materials",
            "description" : "This option lets you refine/repurpose materials, provided that you have\n"
                "the proper equipment on hand.\n",
            "selector" : "refine materials",
            "canShow" : 1                 
        ]),
        "8":([
            "name":"Imbue Materials with Magical Effects",
            "description" : "This option lets you imbue crafting materials with magical effect,\n"
                "provided that you have the proper materials and knowledge on hand.\n",
            "selector": "imbue with magical effects",
            "canShow": user->getSkill("spellcraft")
        ]),
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getBlueprintsByType(string type)
{
    mapping items = ([]);
    if (type == "armor")
    {
        items = armorBlueprints;
    }
    else if (type == "weapons")
    {
        items = weaponBlueprints;
    }
    else if (type == "materials")
    {
        items = materials;
    }
    return items + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getBlueprintFor(object item)
{
    mapping items = ([]);
    string *itemInheritance = inherit_list(item);

    if (member(itemInheritance, "lib/items/armor.c") > -1)
    {
        items = armorBlueprints;
    }
    else if (member(itemInheritance, "lib/items/weapon.c") > -1)
    {
        items = weaponBlueprints;
    }
    else if (member(itemInheritance, "lib/items/material.c") > -1)
    {
        items = materials;
    }

    object blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
    string blueprint = item->query("blueprint");
    if (sizeof(items) && member(items, blueprint))
    {
        blueprintObj->set("blueprint data", items[blueprint]);
        blueprintObj->set("blueprint", blueprint);
    }
    else
    {
        destruct(blueprintObj);
        blueprintObj = 0;
    }
    return blueprintObj;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getEquipmentSubTypes(string type)
{
    string *ret = ({});
    mapping items = getBlueprintsByType(type);
    string *indices = m_indices(items);

    if (sizeof(indices))
    {
        foreach(string item in indices)
        {
            if (member(ret, items[item]["subtype"]) < 0)
            {
                ret += ({ items[item]["subtype"] });
            }
        }
    }
    return sort_array(ret, (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCraftingList(string type, object user)
{
    mapping ret = ([]);
    string *itemSubtypes = getEquipmentSubTypes(type);

    int menuItem = 1;
    if (sizeof(itemSubtypes))
    {
        foreach(string item in itemSubtypes)
        {
            ret[to_string(menuItem)] = ([
                "name": capitalize(item),
                "description": sprintf("This option lets you craft: %s", item),
                "selector": type,
                "sub type": item,
                "canShow": 1
            ]);
            menuItem++;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getEquipmentBySubType(string type, string subType)
{
    mapping items = getBlueprintsByType(type);
    string *indices = m_indices(items);

    return sort_array(filter(indices,
        (: $3[$1]["subtype"] == $2 :), subType, items),
        (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getBlueprintItem(string type, string item)
{
    object blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
    mapping blueprints = getBlueprintsByType(type);

    if (sizeof(blueprints) && member(blueprints, item))
    {
        blueprintObj->set("blueprint data", blueprints[item]);
        blueprintObj->set("blueprint", item);
    }
    return blueprintObj;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int prerequisitesMet(object blueprintObj, object user)
{
    return blueprintObj->checkPrerequisites(user);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int materialsAvailable(object blueprintObj, object user)
{
    return blueprintObj->checkAgregateMaterials(user);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getDescriptionDetails(object blueprintObj)
{
    return blueprintObj->displayPrerequisites() +
        blueprintObj->displayNeededMaterials();
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getSubType(string subType)
{
    string ret = regreplace(subType, " ", "-");
    ret = regreplace(ret, "(s|ch|sh|x|z|dg|o)$", "\\1e");
    ret = regreplace(ret, "([^aeiou])y$", "\\1ie");
    ret += "s";
    ret = regreplace(ret, "(.*ing|.*armor|.*thrown)s$", "\\1");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCraftingListBySubType(string type, string subType,
    object user)
{
    mapping ret = ([]);
    string *itemSubtypes = getEquipmentBySubType(type, subType);

    int menuItem = 1;
    if (sizeof(itemSubtypes))
    {
        foreach(string item in itemSubtypes)
        {
            object blueprintObj = getBlueprintItem(type, item);

            int prereqsMet = prerequisitesMet(blueprintObj, user);
            int materialsMet = materialsAvailable(blueprintObj, user);
            string nameDesc = (sizeof(item) < 21) ? item :
                (item[0..16] + "...");
            ret[to_string(menuItem)] = ([
                "name": capitalize(nameDesc),
                "description": sprintf("This option lets you craft: %s\n%s", 
                    item, getDescriptionDetails(blueprintObj)),
                "selector": item,
                "type": type,
                "sub type": getSubType(subType),
                "canShow": prereqsMet && materialsMet,
                "prerequisites met": prereqsMet,
                "have materials": materialsMet,
                "show materials": 1
            ]);
            menuItem++;
            destruct(blueprintObj);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialByClass(string materialClass)
{
    return filter(m_indices(materials),
        (: materials[$1]["class"] == $2 :), materialClass);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getCraftingDataForItem(string type, string item, object user)
{
    mapping ret = ([]);
    mapping blueprints = getBlueprintsByType(type);

    if (sizeof(blueprints) && member(blueprints, item))
    {
        string *itemSubtypes = sort_array(
            m_indices(blueprints[item]["crafting materials"]), (: $1 > $2 :));

        int menuItem = 1;
        if (sizeof(itemSubtypes))
        {
            foreach(string subType in itemSubtypes)
            {
                int isMaterial = 
                    !mappingp(blueprints[item]["crafting materials"][subType]);
                
                string elementType = isMaterial ?
                    blueprints[item]["crafting materials"][subType] : subType;

                ret[to_string(menuItem)] = ([
                    "name": sprintf("Select %s", capitalize(subType)),
                    "description": sprintf("This option lets you craft the %s for your %s", 
                        elementType, item),
                    "type": elementType,
                    "details": blueprints[item]["crafting materials"][subType],
                    "selector": (isMaterial ? "material" : "component"),
                ]);
                menuItem++;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string *getTypes(string type, object user)
{
    string *types = ({ type });
    if ((type == "metal") && user->isResearched("lib/instances/research/crafting/useCrystalsAsMetal.c"))
    {
        types += ({ "crystal" });
    }
    return types;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getMaterialsOfTypeOnHand(string type, object user)
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
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getMaterialsOfType(string type, object user,
    int quantity, object craftingItem)
{
    mapping ret = ([]);
    mapping materialsOnHand = getMaterialsOfTypeOnHand(type, user);
    string *materialsOfType = sort_array(filter(m_indices(materials),
        (: (member($2, materials[$1]["class"]) > -1) :), getTypes(type, user)),
        (: $1 > $2 :));

    if(sizeof(materialsOfType))
    {
        int menuItem = 1;
        string currentMaterial = craftingItem->query("material");
        foreach(string material in materialsOfType)
        {
            int hasMaterials = (member(materialsOnHand, material) &&
                (materialsOnHand[material] >= quantity));

            object blueprintObj = getBlueprintItem("materials", material);
            int prerequisites = prerequisitesMet(blueprintObj, user);
            destruct(blueprintObj);

            craftingItem->set("material", material);

            ret[to_string(menuItem)] = ([
                "name": capitalize(material),
                "type": material,
                "description": sprintf("This option lets you craft using: %s\n%s", 
                    material, load_object("/lib/dictionaries/materialsDictionary.c")->getEquipmentStatistics(craftingItem)),
                "has materials": hasMaterials,
                "prerequisites met": prerequisites,
                "canShow": (hasMaterials && prerequisites)
            ]);
            menuItem++;
        }
        craftingItem->set("material", currentMaterial);
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
        (: $2[$1] :), materialsData);

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
        string *materialsList = m_indices(materialsData);
        foreach(string material in materialsList)
        {
            ret[to_string(menuItem)] = ([
                "name": sprintf("Select %s", material),
                "is optional": materialsData[material] == 0,
                "selector": "material",
                "type": material,
                "description": sprintf("This option selects the %s you will "
                    "use to craft the %s", material, type),
            ]);
            menuItem++;
        }
    }
    foreach(string component in components)
    {
        string name = capitalize(component);
        if (sizeof(name) > 20)
        {
            name = name[0..16] + "...";
        }
        ret[to_string(menuItem)] = ([
            "name": name,
            "type": component,
            "description": format("This is " + craftingComponents[component]["description"], 78)
        ]);
        menuItem++;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setCraftingMaterial(object item, string materialClass,
    string material, string component)
{
    mapping materialSelections = item->query("crafting materials");
    if (!materialSelections)
    {
        materialSelections = ([]);
    }

    if (!component)
    {
        if (!member(materialSelections, materialClass))
        {
            materialSelections[materialClass] = material;
        }
    }
    else
    {
        if (!member(materialSelections, component))
        {
            materialSelections[component] = ([]);
        }
        materialSelections[component][materialClass] = material;
    }
    item->set("crafting materials", materialSelections);
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
    if (materialSelections && mappingp(materialSelections))
    {
        ret = materialSelections[component]["type"];
    }
    return ret;
}