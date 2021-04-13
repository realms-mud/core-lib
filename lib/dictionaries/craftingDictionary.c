//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/inventory.h"
#include "materials/materials.h"
#include "materials/weapons.h"
#include "materials/armor.h"
#include "materials/components.h"
#include "materials/enchantments.h"

private mapping BlueprintObjects = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidType(mixed type)
{
    int ret = 0;

    string *types = weaponSubTypes + armorCategories;
    if (stringp(type))
    {
        ret = member(types, type) > -1;
    }
    else if (pointerp(type) && sizeof(type))
    {
        ret = 1;
        foreach(string key in type)
        {
            ret &&= member(types, key) > -1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *validCraftingBonuses()
{
    string *enchantments = m_indices(equipmentEnchantments);
    for(int i = 0; i < sizeof(enchantments); i++)
    {
        enchantments[i] = "crafting " + enchantments[i];
    }
    return enchantments + ({ "crafting value multiplier", "crafting encumberance reduction",
        "crafting weapon class", "crafting defense class", "crafting attack",
        "crafting weight reduction", "crafting armor class", "crafting duration",
        "crafting enchantment power", "crafting potency", "crafting enchantments"
    });
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getTopLevelCraftingMenu(object user)
{
    return ([
        "1":([
            "name":"Craft Armor, Clothing, and Jewelry",
            "description" : "This option lets you create armors, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "armor",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/armor/craftArmor.c", "armorer")                  
        ]),
        "2":([
            "name":"Craft Artwork",
            "description" : "This option lets you create artwork, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "artwork",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/craftArtwork.c", "gem crafting")                  
        ]),
        "3":([
            "name":"Craft Musical Instrument",
            "description" : "This option lets you create musical instruments, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "instruments",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/craftInstrument.c", "luthiery")                  
        ]),
        "4":([
            "name":"Craft Weapons",
            "description" : "This option lets you create weapons, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "weapons",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/weapons/craftWeapons.c", "weapon smithing")                  
        ]),
        "5":([
            "name":"Brew Potions",
            "description" : "This option lets you brew potions, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "potions",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/brewPotions.c", "brewing")                  
        ]),
        "6":([
            "name":"Brew Beverages and Prepare Food",
            "description" : "This option lets you brew beverages and prepare food, provided that you have\n"
                "the proper materials and equipment on hand.\n",
            "selector" : "beverages and food",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/brewBeveragesAndCookFood.c", "cooking")                  
        ]),
        "7":([
            "name":"Refine Materials",
            "description" : "This option lets you refine/repurpose materials, provided that you have\n"
                "the proper equipment on hand.\n",
            "selector" : "refine materials",
            "canShow" : user->canApplyResearchBonus(
                "/lib/instances/research/crafting/refineMaterials.c", "blacksmithing")
        ]),
        "8":([
            "name":"Imbue with Magical Effects",
            "description" : "This option lets you imbue items with magical effect,\n"
                "provided that you have the proper materials and knowledge on hand.\n",
            "selector": "imbue with magical effects",
            "canShow": user->canApplyResearchBonus(
                "/lib/instances/research/crafting/enchantments/imbueItems.c", "spellcraft")
        ]),
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getBlueprintsByType(string type)
{
    mapping items = ([]);
    switch (type)
    {
        case "armor":
        {
            items = armorBlueprints;
            break;
        }
        case "weapons":
        {
            items = weaponBlueprints;
            break;
        }
        case "materials":
        {
            items = materials;
            break;
        }
        case "components":
        {
            items = craftingComponents;
            break;
        }
        case "enchantments":
        {
            items = equipmentEnchantments;
            break;
        }
        default:
        {
            items = ([]);
        }
    }
    return items + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getBlueprintFor(object item)
{
    object blueprintObj = 0;
    string blueprint = item->query("blueprint");
    if (member(BlueprintObjects, blueprint) &&
        objectp(BlueprintObjects[blueprint]))
    {
        blueprintObj = BlueprintObjects[blueprint];
    }
    else
    {
        mapping items = ([]);
        string *itemInheritance = inherit_list(item);

        if (member(itemInheritance, "/lib/items/armor.c") > -1)
        {
            items = armorBlueprints;
        }
        else if (member(itemInheritance, "/lib/items/weapon.c") > -1)
        {
            items = weaponBlueprints;
        }
        else if (member(itemInheritance, "/lib/items/material.c") > -1)
        {
            items = materials;
        }

        blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
        if (sizeof(items) && member(items, blueprint))
        {
            blueprintObj->set("blueprint data", items[blueprint]);
            blueprintObj->set("blueprint", blueprint);
            BlueprintObjects[blueprint] = blueprintObj;
        }
        else
        {
            blueprintObj = 0;
        }
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
                "description": sprintf("This option lets you craft: %s\n", item),
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
    object blueprintObj = 0;
    if (member(BlueprintObjects, item) &&
        objectp(BlueprintObjects[item]))
    {
        blueprintObj = BlueprintObjects[item];
    }
    else
    {
        blueprintObj = clone_object("/lib/items/craftingBlueprint.c");
        mapping blueprints = getBlueprintsByType(type);

        if (sizeof(blueprints) && member(blueprints, item))
        {
            blueprintObj->set("blueprint data", blueprints[item]);
            blueprintObj->set("blueprint", item);
            BlueprintObjects[item] = blueprintObj;
        }
    }
    return blueprintObj;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int prerequisitesMet(object blueprintObj, object user)
{
    return blueprintObj->checkPrerequisites(user) && 
        blueprintObj->checkResearch(user);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int materialsAvailable(object blueprintObj, object user)
{
    return blueprintObj->checkAgregateMaterials(user);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getDescriptionDetails(object blueprintObj)
{
    string colorConfiguration = this_player() ?
        this_player()->colorConfiguration() : "none";
    object configuration = getDictionary("configuration");

    return blueprintObj->displayPrerequisites(colorConfiguration, configuration) +
        blueprintObj->displayNeededMaterials(colorConfiguration, configuration);
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
                "description": sprintf("This option lets you craft: %s\n%s\n", 
                    item, getDescriptionDetails(blueprintObj)),
                "selector": item,
                "type": type,
                "sub type": getSubType(subType),
                "canShow": prereqsMet && materialsMet,
                "prerequisites met": prereqsMet,
                "have materials": materialsMet,
                "show materials": 1,
                "do not format": 1
            ]);
            menuItem++;
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

                ret[to_string(menuItem)] = ([
                    "name": sprintf("Select %s", capitalize(subType)),
                    "description": sprintf("This option lets you craft the %s for your %s\n", 
                        subType, item),
                    "type": subType,
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
private nomask mapping materialsUsedForSubcomponents(string *components,
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
private nomask mapping getMaterialsOfTypeOnHand(string type, object user, 
    object craftingItem)
{
    mapping ret = ([]);

    object *inventory = filter(deep_inventory(user),
        (: ((member(inherit_list($1), "/lib/items/material.c") > -1) &&
            (member($2, $1->query("class")) > -1)) :), 
        getDictionary("materials")->getTypes(type, user));

    if (sizeof(inventory))
    {
        mapping materialsToBeUsed = materialsUsedForCrafting(craftingItem);
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
    int quantity, object craftingItem)
{
    mapping ret = ([]);

    object materialDictionary = getDictionary("materials");

    mapping materialsOnHand = getMaterialsOfTypeOnHand(type, user, craftingItem);
    string *materialsOfType = sort_array(filter(m_indices(materials),
        (: (member($2, materials[$1]["class"]) > -1) :), 
        materialDictionary->getTypes(type, user)),
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

            craftingItem->set("material", material);

            string name = capitalize(material);
            if (sizeof(name) > 20)
            {
                name = name[0..16] + "...";
            }
            ret[to_string(menuItem)] = ([
                "name": name,
                "type": material,
                "description": sprintf("This option lets you craft using: %s\n%s\n", 
                    material, materialDictionary->getEquipmentStatistics(craftingItem, user)),
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
public nomask varargs void setCraftingMaterial(object item, string materialClass,
    string material, string component)
{
    mapping materialSelections = item->query("crafting materials");
    string primaryComponent = item->query("primary component");

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

    object materialsDictionary = getDictionary("materials");

    if ((component == primaryComponent) && 
        (materialsDictionary->getMaterialTypeForMaterial(item->query("material")) == 
        materialsDictionary->getMaterialTypeForMaterial(material)))
    {
        item->set("material", material);
        item->set("primary crafting material", material);

        item->set("crafting experience", to_float(
            materialsDictionary->getBlueprintModifier(item, "base experience") *
            (member(materials[material], "experience modifier") ?
                materials[material]["experience modifier"] : 1.0)));
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

/////////////////////////////////////////////////////////////////////////////
private nomask string replaceDescriptiveText(string text, string type, mapping data)
{
    string ret = text;

    if (member(data, type))
    {
        ret = regreplace(ret, type, data[type], 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string addMaterialsToDescription(object item)
{
    string ret = item->query("long");
    mapping craftingMaterials = item->query("crafting materials");

    if (craftingMaterials && mappingp(craftingMaterials))
    {
        foreach(string materialClass in materialClasses)
        {
            if (member(craftingMaterials, materialClass))
            {
                ret = regreplace(ret, materialClass, craftingMaterials[materialClass], 1);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEquipmentMaterials(object item)
{
    string ret = "";

    mapping craftingMaterials = item->query("crafting materials");
    if (craftingMaterials && mappingp(craftingMaterials))
    {
        string *components = sort_array(filter(m_indices(craftingMaterials),
            (: mappingp($2[$1]) :), craftingMaterials), (: $1 > $2 :));

        if (sizeof(components))
        {
            foreach(string component in components)
            {
                string description = craftingMaterials[component]["description"];

                foreach(string materialClass in materialClasses)
                {
                    description = replaceDescriptiveText(description, materialClass,
                        craftingMaterials[component]);
                }
                ret += sprintf("The %s is %s ", component, description);
            }
        }
        if (item->query("primary crafting material"))
        {
            ret = regreplace(ret, "PrimaryMaterial",
                item->query("primary crafting material"), 1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int allComponentsHaveBeenChosen(object item)
{
    int ret = 0;
    mapping materialsToUse = item->query("crafting materials");

    object blueprintObj = getBlueprintFor(item);
    mapping blueprintMaterials = blueprintObj->query("crafting materials");

    if (sizeof(blueprintMaterials) && sizeof(materialsToUse))
    {
        ret = 1;
        string *materialList = m_indices(blueprintMaterials);
        foreach(string material in materialList)
        {
            ret &&= member(materialsToUse, material);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int useCraftingMaterial(object user, string materialName, int quantity)
{
    int ret = 0;
    object *inventory = filter(deep_inventory(user),
        (: ((member(inherit_list($1), "/lib/items/material.c") > -1) && 
            $1->id($2)) :), materialName);

    if (sizeof(inventory))
    {
        int quantityLeft = quantity;
        foreach(object item in inventory)
        {
            int itemQuantity = item->query("quantity");

            if (itemQuantity >= quantityLeft)
            {
                itemQuantity -= quantityLeft;
                quantityLeft = 0;
                if (itemQuantity > 0)
                {
                    item->set("quantity", itemQuantity);
                }
                else
                {
                    destruct(item);
                }
            }
            else
            {
                quantityLeft -= itemQuantity;
                destruct(item);
            }
        }
        ret = (quantityLeft == 0);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void applyCraftingBonuses(object item, object user)
{
    string *craftingBonuses = validCraftingBonuses();
    foreach(string bonus in craftingBonuses)
    {
        int bonusValue = user->researchBonusTo(bonus);
        if (bonusValue)
        {
            item->set(bonus, bonusValue);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getEnchantmentStrength(string enchantment, object user)
{
    int ret = user->researchBonusTo(sprintf("crafting %s", enchantment));

    mapping skills = equipmentEnchantments[enchantment]["crafting prerequisites"];

    if (sizeof(skills))
    {
        string *skillList = m_indices(skills);
        foreach(string skill in skillList)
        {
            if (skills[skill]["type"] == "skill")
            {
                ret += (user->getSkill(skill) - skills[skill]["value"]) / 10;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int applyEffects(string enchantment, object user, object item,
    int count)
{
    int ret = 1;

    int bonus = getEnchantmentStrength(enchantment, user);

    mapping effects = equipmentEnchantments[enchantment]["effects"] + ([]);
    foreach(string effect in m_indices(effects))
    {
        if (mappingp(effects[effect]))
        {
            foreach(string element in m_indices(effects[effect]))
            {
                effects[effect][element] = 
                    (effects[effect][element] + bonus) * count;
            }
        }
        else if(effect != "damage type")
        {
            effects[effect] = (effects[effect] + bonus) * count;
        }

        ret &&= item->set(effect, effects[effect]);
    }

    if (member(equipmentEnchantments[enchantment], "experience modifier"))
    {
        item->set("crafting experience", item->query("crafting experience") *
            equipmentEnchantments[enchantment]["experience modifier"]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int applyEnchantments(object item, object user)
{
    int ret = 1;
    mapping enchantments = item->query("crafting enchantments");
    if (!mappingp(enchantments))
    {
        enchantments = ([]);
    }
    string *enchantmentList = m_indices(enchantments);
    foreach(string enchantment in enchantmentList)
    {
        if (member(equipmentEnchantments, enchantment))
        {
            ret &&= applyEffects(enchantment, user, item, 
                enchantments[enchantment]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void updateItemExperience(object item)
{
    mapping craftingMaterials = item->query("crafting materials");
    if (craftingMaterials && mappingp(craftingMaterials))
    {
        string *components = filter(m_indices(craftingMaterials),
            (: mappingp($2[$1]) :), craftingMaterials);

        if (sizeof(components))
        {
            foreach(string component in components)
            {
                string key = craftingMaterials[component]["type"];

                item->set("crafting experience", 
                    item->query("crafting experience") *
                    (member(craftingComponents[key], "experience modifier") ?
                        craftingComponents[key]["experience modifier"] : 1.0));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int craftItem(object item, object user)
{
    int canCraft = 0;
    mapping materialsUsed = materialsUsedForCrafting(item);

    updateItemExperience(item);

    if (sizeof(materialsUsed))
    {
        canCraft = 1;
        string *materialsToRemove = m_indices(materialsUsed);
        foreach(string material in materialsToRemove)
        {
            canCraft &&= useCraftingMaterial(user, material, 
                materialsUsed[material]);
        }
    }
    canCraft &&= applyEnchantments(item, user);

    return canCraft;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCraftingSkill(string type, string item, 
    object target, object user)
{
    object blueprintObj = getBlueprintItem(type, item);
    string *skills = blueprintObj->query("crafting skills");
    if (sizeof(skills))
    {
        int craftingSkill = 0;
        foreach(string skill in skills)
        {
            craftingSkill += user->getSkill(skill);
        }
        target->set("craftsmanship", craftingSkill);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canEnchantItem(object item, object user)
{
    return user->isResearched("/lib/instances/research/crafting/enchantments/craftEnchantments.c");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getEnchantmentTypes()
{
    mapping ret = ([]);

    int menuItem = 1;
    string *enchantmentTypes = sort_array(enchantmentClasses, (: $1 > $2 :));
    foreach(string enchantmentType in enchantmentTypes)
    {
        ret[to_string(menuItem)] = ([
            "name": capitalize(enchantmentType),
            "type": enchantmentType,
            "description": sprintf("This option lets you craft using: %s\n",
                enchantmentType),
            "canShow": 1
        ]);
        menuItem++;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getEnchantmentsOfType(string type, object user,
    object craftingItem)
{
    mapping ret = ([]);
    string *enchantmentsOfType = sort_array(
        filter(m_indices(equipmentEnchantments),
        (: (equipmentEnchantments[$1]["class"] == $2) :), type),
        (: $1 > $2 :));

    if (sizeof(enchantmentsOfType))
    {
        int menuItem = 1;
        foreach(string enchantment in enchantmentsOfType)
        {
            int hasMaterials = 1;

            object blueprintObj = getBlueprintItem("enchantments", enchantment);
            int prerequisites = prerequisitesMet(blueprintObj, user);

            string nameDesc = (sizeof(enchantment) < 21) ? enchantment :
                (enchantment[0..16] + "...");

            ret[to_string(menuItem)] = ([
                "name": capitalize(nameDesc),
                "type": enchantment,
                "description" : sprintf("This option lets you craft using: %s\n%s\n",
                    enchantment, getDictionary("materials")->getEquipmentStatistics(craftingItem)),
                "has materials" : hasMaterials,
                "prerequisites met" : prerequisites,
                "canShow" : (hasMaterials && prerequisites)
            ]);
            menuItem++;
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int addEnchantment(object item, string enchantment, int decrement)
{
    int ret = 1;
    mapping craftingEnchantments = item->query("crafting enchantments");
    if (!mappingp(craftingEnchantments))
    {
        craftingEnchantments = ([]);
    }
    if (member(equipmentEnchantments, enchantment))
    {
        int newLevel = decrement ? -1 : 1;
        if (member(craftingEnchantments, enchantment))
        {
            newLevel += craftingEnchantments[enchantment];
        }
        if (newLevel < 0)
        {
            newLevel = 0;
        }

        if (!newLevel)
        {
            m_delete(craftingEnchantments, enchantment);
        }
        else if (newLevel < 4)
        {
            craftingEnchantments[enchantment] = newLevel;
        }
        else
        {
            ret = 0;
        }

        if (sizeof(craftingEnchantments))
        {
            item->set("crafting enchantments", craftingEnchantments);
        }
        else
        {
            item->unset("crafting enchantments");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRandomCraftingElement(mapping elements, 
    string elementClass)
{
    string *elementList = filter(m_indices(elements),
        (: $2[$1]["class"] == $3 :), elements, elementClass);

    return elementList[random(sizeof(elementList))];
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRandomMaterial(string materialClass, 
    string defaultMaterial)
{
    object materialsDictionary = getDictionary("materials");

    string *materialList = filter(m_indices(materials),
        (: $2[$1]["class"] == $3 :), materials, materialClass);

    if (member(materialList, defaultMaterial) == -1)
    {
        defaultMaterial = 0;
    }
    return materialsDictionary->getRandomMaterialFromClass(materialClass,
        defaultMaterial);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRandomComponent(string componentClass)
{
    return getRandomCraftingElement(craftingComponents, componentClass);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateRandomMaterialList(object blueprint)
{
    mapping ret = ([]);
    mapping neededMaterials = blueprint->query("crafting materials");
    string *componentMaterials = filter(m_indices(neededMaterials),
        (: intp($2[$1]) :), neededMaterials);

    string primaryMaterialClass =
        materials[blueprint->query("default material")]["class"];
    foreach(string componentMaterial in componentMaterials)
    {
        if (neededMaterials[componentMaterial] > 0)
        {
            ret[componentMaterial] = getRandomMaterial(componentMaterial,
                blueprint->query("default material"));

            if (componentMaterial == primaryMaterialClass)
            {
                if (blueprint->query("use default material"))
                {
                    ret[componentMaterial] = blueprint->query("default material");
                }
                blueprint->set("primary crafting material", ret[componentMaterial]);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping generateRandomComponents(object blueprint)
{
    mapping ret = ([]);
    mapping neededMaterials = blueprint->query("crafting materials");

    string *components = filter(m_indices(neededMaterials),
        (: mappingp($2[$1]) :), neededMaterials);

    string primaryMaterialClass =
        materials[blueprint->query("default material")]["class"];

    if (sizeof(components))
    {
        foreach(string component in components)
        {
            string usedComponent = getRandomComponent(component);

            ret[component] = ([
                "type": usedComponent,
                "description": craftingComponents[usedComponent]["description"],
                "value": craftingComponents[usedComponent]["value"],
                "experience modifier": craftingComponents[usedComponent]["experience modifier"],
            ]);

            string *componentMaterials = m_indices(neededMaterials[component]);
            foreach(string componentMaterial in componentMaterials)
            {
                if ((neededMaterials[component][componentMaterial] > 0) ||
                    (member(craftingComponents[usedComponent], "crafting materials") &&
                    member(craftingComponents[usedComponent]["crafting materials"],
                        componentMaterial)))
                {
                    ret[component][componentMaterial] =
                        getRandomMaterial(componentMaterial, blueprint->query("default material"));
 
                    if ((componentMaterial == primaryMaterialClass) &&
                       (blueprint->query("primary component") == component))
                    {
                        if (blueprint->query("use default material"))
                        {
                            ret[component][componentMaterial] = 
                                blueprint->query("default material");
                        }
                        blueprint->set("primary crafting material", 
                            ret[component][componentMaterial]);
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void getRandomCraftingMaterial(object item, 
    int useDefaultMaterial)
{
    if (!item->query("crafting in progress"))
    {
        object blueprint = getBlueprintFor(item);
        if(blueprint)
        {
            if (useDefaultMaterial)
            {
                blueprint->set("use default material", 1);
            }
            else
            {
                blueprint->unset("use default material");
            }
            mapping materialList = ([]);

            materialList += generateRandomMaterialList(blueprint) +
                generateRandomComponents(blueprint);

            if (item->query("material"))
            {
                item->set("primary crafting material", item->query("material"));
            }
            else if (blueprint->query("primary crafting material"))
            {
                item->set("primary crafting material",
                    blueprint->query("primary crafting material"));
                item->set("material", blueprint->query("primary crafting material"));
            }
            item->set("crafting materials", materialList);
        }
    }
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
