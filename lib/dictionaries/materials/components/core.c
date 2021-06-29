//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _core_c
#define _core_c

#include "/lib/dictionaries/materials/armor.h"
#include "/lib/dictionaries/materials/components.h"
#include "/lib/dictionaries/materials/drinks.h"
#include "/lib/dictionaries/materials/enchantments.h"
#include "/lib/dictionaries/materials/food.h"
#include "/lib/dictionaries/materials/instruments.h"
#include "/lib/dictionaries/materials/materials.h"
#include "/lib/dictionaries/materials/potions.h"
#include "/lib/dictionaries/materials/weapons.h"

protected nosave string EquipmentBlueprint = "/lib/items/equipment.c";

protected nosave string *validBonuses = ({ "strength", "intelligence", "dexterity",
    "wisdom", "constitution", "charisma",  });
    
protected nosave string *validArmorLocations = ({ "armor", "gloves", "helmet",
    "boots", "ring", "cloak", "amulet", "belt", "arm greaves", "leg greaves",
    "bracers" });
protected nosave string *validArmorTypes = ({ "plate armor", "splint armor", "chainmail",
    "scalemail", "hard leather", "soft leather", "no armor" });
protected nosave string *validWeaponTypes = ({ "shield", "axe", "long sword",
    "hand and a half sword", "short sword", "dagger", "bow", "crossbow", "sling",
    "thrown", "two-handed sword", "pole arm", "mace", "hammer", "flail", "staff" });
protected nosave string *validDamageTypes = ({ "slash", "bludgeon", "thrust",
    "arrow", "bolt", "bullet" });
protected nosave object configuration = getDictionary("configuration");

protected mapping defaultValues = ([
    "armor": 250,
    "weapon": 250,
    "instrument": 250,
    "potion": 150,
]);

protected nosave mapping WeightedMaterials = ([]);

/////////////////////////////////////////////////////////////////////////////
protected nomask int isValidItem(object item)
{
    return (item && objectp(item) && 
           (member(inherit_list(item), EquipmentBlueprint) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidMaterial(string material)
{
    return (materials && mappingp(materials) &&
            member(materials, material) &&
            member(materials[material], "crafting skill required") &&
            member(materials[material], "class"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidMaterialType(string materialType)
{
    return (member(({ "wood", "textile", "stone", "leather", "metal", 
        "crystal", "skeletal", "plumage" }), materialType) > -1);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string colorConfiguration(object initiator)
{
    string ret = "none";

    if (objectp(initiator))
    {
        ret = initiator->colorConfiguration();
    }
    else if (this_player())
    {
        ret = this_player()->colorConfiguration();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs string detailsText(string colorConfiguration, 
    string name, string value, string range)
{
    string ret = configuration->decorate(sprintf("    %s: ", name),
        "field", "equipment", colorConfiguration);

    if (value && stringp(value))
    {
        ret += configuration->decorate(value, "value", "equipment", colorConfiguration);
    }
    if (range && stringp(range))
    {
        ret += configuration->decorate(sprintf(" to %s", range), 
            "value", "equipment", colorConfiguration);
    }

    return ret + "\n";
}

#endif