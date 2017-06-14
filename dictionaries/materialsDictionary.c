//*****************************************************************************
// Class: materialsDictionary
// File Name: materialsDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
//*****************************************************************************
#include "/lib/include/inventory.h"

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

private nosave mapping itemTypes = ([
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
    "chainmail": ([
        "type": "armor",
        "skill to craft": 10,
        "skill to use": "chainmail",
        "default ac": 5,
        "default encumberance": 10
    ]),
    "gloves": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "helmet": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "boots": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "ring": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "cloak": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "amulet": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "belt": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "arm greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "leg greaves": ([
        "type": "armor",
        "skill to craft": 5,
        "default encumberance": 1
    ]),
    "bracers": ([
        "type": "armor",
        "skill to craft": 15,
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
public nomask int isValidEquipmentType(string type)
{
    return (itemTypes && mappingp(itemTypes) &&
            member(itemTypes, type) &&
            member(itemTypes[type], "skill to craft") &&
            member(itemTypes[type], "type") &&
            member(itemTypes[type], "default encumberance"));
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
    if(isValidEquipmentType(type))
    {
        //TODO
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
        
        string itemType = item->query("type");
        if(isValidEquipmentType(itemType))
        {
            retVal -= itemTypes[itemType]["skill to craft"];
        }
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
        
        string itemType = item->query("armor type") || item->query("weapon type");
        if(isValidEquipmentType(itemType))
        {
            retVal += itemTypes[itemType]["default encumberance"];
        }
        
        retVal -= getMaterialCraftsmanshipBonus(item);
    }
    return retVal;
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
        string weaponType = weapon->query("weapon type");
        if (isValidWeaponType(weaponType) && member(itemTypes, weaponType))
        {
            ret = ({ itemTypes[weaponType]["damage type"] });
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

            string itemType = item->query("armor type") || item->query("weapon type");
            if(!ac && isValidEquipmentType(itemType))
            {
                ac = itemTypes[itemType]["default ac"];
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
    string ret = "";

    int idBonus = getLevelOfIdKnowledge(equipment);

    return ret;
}