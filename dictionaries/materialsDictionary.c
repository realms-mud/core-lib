//*****************************************************************************
// Class: materialsDictionary
// File Name: materialsDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
//*****************************************************************************
#include "/lib/include/inventory.h"
#include "/lib/include/itemFormatters.h"

private nosave string EquipmentBlueprint = "lib/items/equipment.c";

// TODO: Add minimum craftsmanship levels, research requirements, etc
private nosave mapping materials =
([
    "cloth": ([
        "class": "textile",
        "crafting skill required": 0
    ]),
    "stone": ([
        "class": "stone",
        "crafting skill required": 5,
        "encumberance": 1,
        "defense": ([
            "electricity": 2
        ])
    ]),
    "pine": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "poplar": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "cedar": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "oak": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "maple": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "birch": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "sycamore": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "beech": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "ash": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "hickory": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "mequite": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "walnut": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "pecan": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "dogwood": ([
        "class": "wood",
        "crafting skill required": 1
    ]),
    "cherry": ([
        "class": "wood",
        "crafting skill required": 4
    ]),
    "holly": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "apple": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "teak": ([
        "class": "wood",
        "attack": ([
           "physical": 1,
       ]),
       "crafting skill required": 6
    ]),
    "cypress": ([
        "class": "wood",
        "crafting skill required": 3
    ]),
    "cottonwood": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "hemlock": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "spruce": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "aspen": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "swamp ash": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5
    ]),
    "elm": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
     "basswood": ([
        "class": "wood",
        "crafting skill required": 1,
        "attack": ([
            "physical": -1,
        ]),
        "encumberance": -1,
    ]),
    "bloodwood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5
    ]),
    "rosewood": ([
        "class": "wood",
        "crafting skill required": 5
    ]),
    "buckeye": ([
        "class": "wood",
        "crafting skill required": 4
    ]),
    "buckthorn": ([
        "class": "wood",
        "crafting skill required": 4
    ]),
   "alder": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "ironwood": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 5
    ]),
    "malorn": ([
        "class": "wood",
        "attack rating": 3,
        "attack": ([
            "magical": 2
        ]),
        "crafting skill required": 20
    ]),
    "redwood": ([
        "class": "wood",
        "crafting skill required": 5
    ]),
    "mahogany": ([
        "class": "wood",
        "crafting skill required": 5,
        "attack": ([
            "physical": 1,
        ]),
    ]),
    "mulberry": ([
        "class": "wood",
        "crafting skill required": 2
    ]),
    "marblewood": ([
        "class": "wood",
        "attack": ([
            "physical": 1,
        ]),
        "crafting skill required": 5
    ]),
    "purple heart": ([
        "class": "wood",
        "attack rating": 2,
        "crafting skill required": 10,
        "attack": ([
            "physical": 2,
        ]),
    ]),
    "bubinga": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10
    ]),
    "kingwood": ([
        "class": "wood",
        "attack rating": 2,
        "attack": ([
            "physical": 2,
        ]),
        "crafting skill required": 15
    ]),
    "koa": ([
        "class": "wood",
        "attack rating": 1,
        "crafting skill required": 10
    ]),

    "leather": ([
        "class": "leather",
        "crafting skill required": 3
    ]),
    "bronze": ([
        "class": "metal",
        "crafting skill required": 4,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -1
        ]),
        "encumberance": -1,
    ]),
    "gold": ([
        "class": "metal",
        "crafting skill required": 10,
        "attack": ([
            "physical": -2
        ]),
        "attack rating": -2,
        "defense": ([
            "physical": -3,
            "acid": 15,
            "disease": 5
        ]),
        "encumberance": 2,
    ]),
     "platinum": ([
        "class": "metal",
        "crafting skill required": 15,
        "attack": ([
            "physical": -1
        ]),
        "attack rating": -1,
        "defense": ([
            "physical": -2,
            "acid": 15
        ]),
        "encumberance": 2,
    ]),
   "silver": ([
        "class": "metal",
        "crafting skill required": 10,
        "attack": ([
            "good": 5
        ]),
    ]),
    "aluminum": ([
        "class": "metal",
        "encumberance": -2,
        "crafting skill required": 25
    ]),
    "nickel": ([
        "class": "metal",
        "defense": ([
            "physical": 1
        ]),
        "crafting skill required": 20
    ]),
    "iron": ([
        "class": "metal",
        "crafting skill required": 5
    ]),
    "steel": ([
        "class": "metal",
        "crafting skill required": 15,   
        "attack": ([
            "physical": 1
        ]),
        "attack rating": 1,
        "defense": ([
            "physical": 1
        ])
    ]),
    "mithril": ([
        "class": "metal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 3,
            "magical": 5
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": 5
        ]),
        "encumberance": -4
    ]),
    "admantite": ([
        "class": "metal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 5,
            "magical": 2
        ]),
        "attack rating": 3,
        "defense": ([
            "physical": 2
        ])
    ]),
    "galvorn": ([
        "class": "metal",
        "crafting skill required": 40,
        "attack": ([
            "physical": 8,
            "magical": 5
        ]),
         "attack rating": 5,
       "defense": ([
            "physical": 5,
            "fire": 3,
            "air": 3
        ]),
        "encumberance": 2
    ]),
    "special": 0,
    "spell material": 0,
    "glassteel": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 3,
            "magical": 5
        ]),
        "defense": ([
            "physical": -5
        ]),
        "encumberance": 1
    ]),
    "magical ice": ([
        "class": "crystal",
        "crafting skill required": 35,
        "attack": ([
            "cold": 10
        ]),
        "attack rating": 3,
        "defense": ([
            "cold": 10,
            "fire": -10
        ]),
        "encumberance": 2
    ]),
    "crystal": ([
        "class": "crystal",
        "crafting skill required": 18,
        "attack": ([
            "physical": 2,
            "magical": 3
        ]),
        "defense": ([
            "physical": 2,
            "magical": 2
        ])
    ]),
    "quartz": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "opal": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "topaz": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "turquoise": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "amethyst": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "garnet": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "florite": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "citrine": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "agate": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "onyx": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "jade": ([
        "class": "crystal",
        "crafting skill required": 25,
        "attack": ([
            "physical": 2
        ]),
        "defense": ([
            "physical": 2
        ])
    ]),
    "amber": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ])
    ]),
    "aquamarine": ([
        "class": "crystal",
        "crafting skill required": 20,
        "attack": ([
            "physical": 1
        ]),
        "defense": ([
            "physical": 1
        ])
    ]),
    "emerald": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ])
    ]),
    "sapphire": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ])
    ]),
   "bloodstone": ([
        "class": "crystal",
        "crafting skill required": 30,
        "attack": ([
            "physical": 3
        ]),
        "defense": ([
            "physical": 3
        ])
    ]),
    "diamond": ([
        "class": "crystal",
        "crafting skill required": 35,
        "attack": ([
            "physical": 4
        ]),
        "defense": ([
            "physical": 4
        ])
    ]),
    "kirluin": ([
        "class": "crystal",
        "crafting skill required": 50,
        "attack": ([
            "physical": 8,
            "electricity": 10
        ]),
        "attack rating": 6,
        "defense": ([
            "physical": 8,
            "electricity": 10
        ]),
        "encumberance": -3
    ]),
    "dragon scale": ([
        "class": "exotic",
        "crafting skill required": 50,
        "defense": ([
            "fire": 15,
            "physical": 10
        ])
    ])
]);

private nosave mapping weaponBlueprints = ([
    "long sword": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 10,
        "skill to use": "long sword",
        "default wc": 10,
        "default dc": 2,
        "default attack": 5,
        "default encumberance": 5
    ]),
    "broad sword": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 15,
        "skill to use": "long sword",
        "default wc": 10,
        "default dc": 4,
        "default attack": 4,
        "default encumberance": 6
    ]),
    "rapier": ([
        "type": "one-handed weapon",
        "damage type": "thrust",
        "skill to craft": 15,
        "skill to use": "long sword",
        "default wc": 6,
        "default dc": 2,
        "default attack": 8,
        "default encumberance": 3
    ]),
    "katana": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 25,
        "skill to use": "hand and a half sword",
        "default wc": 10,
        "default dc": 3,
        "default attack": 10,
        "default encumberance": 4
    ]),
    "scimitar": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 10,
        "skill to use": "long sword",
        "default wc": 8,
        "default dc": 2,
        "default attack": 5,
        "default encumberance": 4
    ]),
    "cutlass": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 12,
        "skill to use": "long sword",
        "default wc": 8,
        "default dc": 3,
        "default attack": 5,
        "default encumberance": 4
    ]),
    "sabre": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 15,
        "skill to use": "long sword",
        "default wc": 8,
        "default dc": 4,
        "default attack": 5,
        "default encumberance": 5
    ]),
    "spatha": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 15,
        "skill to use": "long sword",
        "default wc": 10,
        "default dc": 2,
        "default attack": 5,
        "default encumberance": 5
    ]),
    "gladius": ([
        "type": "one-handed weapon",
        "damage type": "thrust",
        "skill to craft": 10,
        "skill to use": "short sword",
        "default wc": 6,
        "default dc": 4,
        "default attack": 4,
        "default encumberance": 3
    ]),
    "harpe": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 15,
        "skill to use": "short sword",
        "default wc": 6,
        "default dc": 5,
        "default attack": 5,
        "default encumberance": 3
    ]),
    "wakisashi": ([
        "type": "one-handed weapon",
        "damage type": "thrust",
        "skill to craft": 20,
        "skill to use": "short sword",
        "default wc": 6,
        "default dc": 6,
        "default attack": 6,
        "default encumberance": 3
    ]),
    "machete": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 5,
        "skill to use": "short sword",
        "default wc": 5,
        "default dc": 2,
        "default attack": 4,
        "default encumberance": 2
    ]),
    "dagger": ([
        "type": "one-handed weapon",
        "damage type": "thrust",
        "skill to craft": 5,
        "skill to use": "dagger",
        "default wc": 4,
        "default dc": 2,
        "default attack": 5,
        "default encumberance": 1
    ]),
    "dirk": ([
        "type": "one-handed weapon",
        "damage type": "thrust",
        "skill to craft": 10,
        "skill to use": "dagger",
        "default wc": 4,
        "default dc": 2,
        "default attack": 6,
        "default encumberance": 1
    ]),
    "stiletto": ([
        "type": "one-handed weapon",
        "damage type": "thrust",
        "skill to craft": 10,
        "skill to use": "dagger",
        "default wc": 5,
        "default dc": 0,
        "default attack": 6,
        "default encumberance": 1
    ]),
    "claymore": ([
        "type": "two-handed weapon",
        "damage type": "slash",
        "skill to craft": 25,
        "skill to use": "two-handed sword",
        "default wc": 16,
        "default dc": 4,
        "default attack": 5,
        "default encumberance": 12
    ]),
    "great sword": ([
        "type": "two-handed weapon",
        "damage type": "slash",
        "skill to craft": 20,
        "skill to use": "two-handed sword",
        "default wc": 15,
        "default dc": 4,
        "default attack": 5,
        "default encumberance": 10
    ]),
    "odachi": ([
        "type": "two-handed weapon",
        "damage type": "slash",
        "skill to craft": 35,
        "skill to use": "two-handed sword",
        "default wc": 18,
        "default dc": 4,
        "default attack": 6,
        "default encumberance": 10
    ]),
    "bastard sword": ([
        "type": "one-handed weapon",
        "damage type": "slash",
        "skill to craft": 20,
        "skill to use": "hand and a half sword",
        "default wc": 12,
        "default dc": 3,
        "default attack": 5,
        "default encumberance": 7
    ]),
    "sword staff": ([
        "type": "two-handed weapon",
        "damage type": "slash",
        "skill to craft": 25,
        "skill to use": "pole arm",
        "default wc": 15,
        "default dc": 4,
        "default attack": 5,
        "default encumberance": 15
    ]),
    "staff": ([
        "type": "two-handed weapon",
        "damage type": "bludgeon",
        "skill to craft": 1,
        "skill to use": "staff",
        "default wc": 4,
        "default dc": 2,
        "default attack": 4,
        "default encumberance": 2
    ]),
    "shield staff": ([
        "type": "two-handed weapon",
        "damage type": "bludgeon",
        "skill to craft": 8,
        "skill to use": "staff",
        "default wc": 4,
        "default dc": 6,
        "default attack": 2,
        "default encumberance": 5
    ]),
    "shield": ([
        "type": "one-handed weapon",
        "damage type": "bludgeon",
        "skill to craft": 5,
        "skill to use": "shield",
        "default wc": 1,
        "default dc": 5,
        "default attack": 0,
        "default encumberance": 5
    ]),

]);

private nosave mapping armorBlueprints = ([
    "chainmail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 5,
        "default location": Armor,
        "default encumberance": 10
    ]),
    "gloves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Gloves,
        "default encumberance": 1
    ]),
    "helmet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Helmet,
        "default encumberance": 1
    ]),
    "boots": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Boots,
        "default encumberance": 1
    ]),
    "ring": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Ring,
        "default encumberance": 1
    ]),
    "cloak": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Cloak,
        "default encumberance": 1
    ]),
    "amulet": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Amulet,
        "default encumberance": 1
    ]),
    "belt": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": Belt,
        "default encumberance": 1
    ]),
    "arm greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": ArmGreaves,
        "default encumberance": 1
    ]),
    "leg greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default location": LegGreaves,
        "default encumberance": 1
    ]),
    "bracers": ([
        "type": "armor",
        "skill to craft": 15,
        "default location": Bracers,
        "default encumberance": 1
    ])
]);

private nosave string *validBonuses = ({ "strength", "intelligence", "dexterity",
    "wisdom", "constitution", "charisma",  });
    
private nosave string *validArmorLocations = ({ "armor", "gloves", "helmet", 
    "boots", "ring", "cloak", "amulet", "belt", "arm greaves", "leg greaves",
    "bracers" });
private nosave string *validArmorTypes = ({ "plate armor", "splint armor", "chainmail",
    "scalemail", "hard leather", "soft leather", "no armor" });
//private nosave string *validWeaponTypes = ({ "one-handed weapon", 
//    "two-handed weapon", "ranged weapon" });
private nosave string *validWeaponTypes = ({ "shield", "axe", "long sword",
    "hand and a half sword", "short sword", "dagger", "bow", "crossbow", "sling",
    "thrown", "two-handed sword", "pole arm", "mace", "hammer", "flail", "staff" });
private nosave string *validDamageTypes = ({ "slash", "bludgeon", "thrust" });

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidItem(object item)
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
        "crystal", "exotic" }), materialType) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *slotsUsedByItemMask(int mask)
{
    string *items = ({});

    if (mask & Armor)
    {
        items += ({ "armor" });
    }
    if (mask & Cloak)
    {
        items += ({ "cloak" });
    }
    if (mask & Helmet)
    {
        items += ({ "helmet" });
    }
    if (mask & Amulet)
    {
        items += ({ "amulet" });
    }
    if (mask & Belt)
    {
        items += ({ "belt" });
    }
    if (mask & ArmGreaves)
    {
        items += ({ "arm greaves" });
    }
    if (mask & LegGreaves)
    {
        items += ({ "leg greaves" });
    }
    if (mask & Gloves)
    {
        items += ({ "gloves" });
    }
    if (mask & Bracers)
    {
        items += ({ "bracers" });
    }
    if (mask & Boots)
    {
        items += ({ "boots" });
    }
    if (mask & Ring)
    {
        items += ({ "ring 1", "ring 2" });
    }
    if (mask & PrimaryWeapon)
    {
        items += ({ "wielded primary" });
    }
    if (mask & OffhandWeapon)
    {
        items += ({ "wielded offhand" });
    }

    return items + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getMaterialTypeForMaterial(string material)
{
    string type = 0;

    if(isValidMaterial(material) && 
        isValidMaterialType(materials[material]["class"]))
    {
        type = materials[material]["class"];
    }
    return type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidWeaponBlueprint(string type)
{
    return (weaponBlueprints && mappingp(weaponBlueprints) &&
            member(weaponBlueprints, type) &&
            member(weaponBlueprints[type], "skill to craft") &&
            member(weaponBlueprints[type], "type") &&
            member(weaponBlueprints[type], "default encumberance"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidArmorBlueprint(string type)
{
    return (armorBlueprints && mappingp(armorBlueprints) &&
        member(armorBlueprints, type) &&
        member(armorBlueprints[type], "skill to craft") &&
        member(armorBlueprints[type], "type") &&
        member(armorBlueprints[type], "default encumberance"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidArmorLocation(string type)
{
    return (member(validArmorLocations, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidArmorType(string type)
{
    return (member(validArmorTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidWeaponType(string type)
{
    return (member(validWeaponTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidDamageType(string type)
{
    return (member(validDamageTypes, type) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidBonus(string bonus)
{
    return (member(validBonuses, bonus) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getDefaultEquipmentLocations(string type)
{
    int ret = 0;

        //TODO
  
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getBlueprintModifier(object item, string type)
{
    int ret = 0;
    string itemType = item->query("blueprint");
    if (isValidWeaponBlueprint(itemType))
    {
        ret = weaponBlueprints[itemType][type];
    }
    else if (isValidArmorBlueprint(itemType))
    {
        ret = armorBlueprints[itemType][type];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialCraftsmanshipBonus(object item)
{
    int retVal = 0;
    
    if(isValidItem(item))
    {
        retVal = item->query("craftsmanship");
        
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            retVal -= materials[material]["crafting skill required"];
        }
        
        retVal -= getBlueprintModifier(item, "skill to craft");
    }

    return (retVal > 0) ? retVal / 5 : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialEncumberance(object item)
{
    int retVal = 0;
    
    if(isValidItem(item))
    {
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            if(member(materials[material], "encumberance"))
            {
                retVal = materials[material]["encumberance"];
            }
        }
        retVal += getBlueprintModifier(item, "default encumberance");
        retVal -= getMaterialCraftsmanshipBonus(item);
    }

    return  (retVal > 0) ? retVal : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string hasExtraAttackType(object item)
{
    string retVal = 0;

    if(isValidItem(item))
    {
        string material = item->query("material");
        if(isValidMaterial(material))
        {    
            // Only one extra attack type... if someone adds a material with more, 
            // it's their own damned fault that I ignore it.
            string *listOfAttackTypes = m_indices(materials[material]["attack"]);
            
            if(member(listOfAttackTypes, "physical") > -1)
            {
                listOfAttackTypes -= ({ "physical" });
            }
            
            retVal = listOfAttackTypes[0];
        }
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getMaterialDamageType(object weapon)
{
    string *ret;
    if (isValidItem(weapon))
    {
        string weaponType = weapon->query("blueprint");
        if (isValidWeaponBlueprint(weaponType))
        {
            ret = ({ weaponBlueprints[weaponType]["damage type"] });
        }
        else
        {
            ret = ({ "physical" });
        }

        string material = weapon->query("material");
        if (isValidMaterial(material) && member(materials[material], "attack"))
        {
            string *materialDmgs = m_indices(materials[material]["attack"]);
            materialDmgs -= ({ "physical" });

            ret += materialDmgs;
        }
    }
    return ret + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialDamage(object item, string type)
{
    int retVal = 0;

    if(isValidItem(item))
    {
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            if(member(materials[material], "attack") &&
               member(materials[material]["attack"], type))
            {
                retVal = materials[material]["attack"][type];
            }
        }
                  
        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialDefense(object item, string type)
{
    int retVal = 0;
    if(isValidItem(item))
    {
        string material = item->query("material");
        if(isValidMaterial(material))
        {
            if(member(materials[material], "defense") &&
               member(materials[material]["defense"], type))
            {
                retVal = materials[material]["defense"][type];
            }

            int ac = item->query("armor class");

            if(!ac)
            {
                ac = getBlueprintModifier(item, "default ac");
            }
            retVal += ac;
        }
                  
        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialDefendAttack(object item)
{
    int retVal = 0;

    if(isValidItem(item))
    {
        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaterialAttack(object item)
{
    int retVal = 0;

    if (isValidItem(item))
    {
        string material = item->query("material");
        if (isValidMaterial(material))
        {
            if (member(materials[material], "attack rating"))
            {
                retVal = materials[material]["attack rating"];
            }
        }

        retVal += getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getMaterialDetails(object item)
{
    string retVal = "(blarg)";

    return retVal;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string applyMaterialQualityToText(object equipment, string text)
{
    string ret = NormalEquipment;
    string qualityText = "typical for its type";

    if (getMaterialCraftsmanshipBonus(equipment) > 4)
    {
        ret = Masterwork;
        if(!text)
        {
            qualityText = "a masterwork item";
        }
    }
    else if (equipment->query("enchanted") > 4)
    {
        ret = StrongEnchantment;
        if (!text)
        {
            qualityText = "enchanted with a powerful aura";
        }
    }
    else if (equipment->query("enchanted"))
    {
        ret = Enchanted;
        if (!text)
        {
            qualityText = "enchanted";
        }
    }
    else if (getMaterialCraftsmanshipBonus(equipment))
    {
        ret = WellCrafted;
        if (!text)
        {
            qualityText = "a well-crafted item";
        }
    }

    if(!text)
    {
        text = sprintf("This %s is %s.\n", 
            equipment->query("blueprint") || "item",
            qualityText);
    }
    return sprintf(ret, text);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int getLevelOfIdKnowledge(object equipment)
{
    int ret = 0;

    if (this_player())
    {
        if(equipment->query("weapon type"))
        {
            ret = this_player()->getSkillModifier("weapon smithing");
        }
        else if(equipment->query("armor type"))
        {
            ret = this_player()->getSkillModifier("armorer");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getEquipmentStatistics(object equipment)
{
    string ret = applyMaterialQualityToText(equipment);

    int idBonus = getLevelOfIdKnowledge(equipment);

    return ret;
}