//*****************************************************************************
// Class: inventory
// File Name: inventory.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

#include "/lib/include/inventory.h"

private int money;

private nosave string ArmorBlueprint = "lib/items/armor.c";
private nosave string WeaponBlueprint = "lib/items/weapon.c";
private nosave string ModifierBlueprint = "lib/items/modifierObject.c";
private nosave int weight = 0;
 
            
private nosave string Cyan = "[0;36m%s[0m";
private nosave string BoldBlack = "[0;30;1m%s[0m";
private nosave string BoldWhite = "[0;37;1m%s[0m";
private nosave string BoldMagenta = "[0;35;1m%s[0m";
private nosave string Red = "[0;31m%s[0m";
private nosave string Green = "[0;32m%s[0m";
private nosave string BoldGreen = "[0;32;1m%s[0m";
private nosave string Magenta = "[0;35m%s[0m";

private nosave mapping itemRegistry = 
([
    "equipped": ([ 
        "wielded primary": 0,
        "wielded offhand": 0,
        "armor": 0,
        "gloves": 0,
        "helmet": 0,
        "boots": 0,
        "ring 1": 0,
        "ring 2": 0,
        "cloak": 0,
        "amulet": 0,
        "belt": 0,
        "arm greaves": 0,
        "leg greaves": 0,
        "bracers": 0
    ]),
    "guild objects": ([
    ])
]);

/////////////////////////////////////////////////////////////////////////////
static nomask int isEquipment(object itemToCheck)
{
    int ret = 0;
    // In order to prevent people from doing what I deem to be "really bad
    // stuff" that might break "really important stuff", living things will
    // ONLY be able to be worn/wielded if they inherit equipment.  There
    // should be plenty of flexibility within equipment to do anything you
    // can dream up. This check is done here to remove the opportunity to
    // "cheat"
    if(itemToCheck && objectp(itemToCheck) &&
       ((member(inherit_list(itemToCheck), ArmorBlueprint) > -1) ||
        (member(inherit_list(itemToCheck), WeaponBlueprint) > -1)))
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object materialsObject()
{
    return getDictionary("materials");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int canEquip(object item)
{
    int ret = 1;
    string *dictionaries = ({ "guilds", "racial", "traits", "background" });
    
    foreach(string dictionary in dictionaries)
    {
        object dictionaryObject = getDictionary(dictionary);

        if(dictionaryObject && objectp(dictionaryObject) && isEquipment(item) &&
           function_exists("canUseEquipmentOfType", dictionaryObject) &&
           !dictionaryObject->canUseEquipmentOfType(this_object(), item))
        {
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask int isModifierItem(object itemToCheck)
{
    int ret = 0;
    // In order to prevent people from circumventing modifier limits, all
    // items that can affect skills, attributes, combat stats, etc MUST inherit
    // modifierObject
    if(itemToCheck && objectp(itemToCheck) &&
       (member(inherit_list(itemToCheck), ModifierBlueprint) > -1))
    {
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isEquipped(object itemToCheck)
{
    int ret = 0;
    
    if(isEquipment(itemToCheck) && member(itemRegistry, "equipped") &&
       mappingp(itemRegistry["equipped"]))
    {
        ret = (member(m_values(itemRegistry["equipped"]), itemToCheck) > -1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object *equippedByMask(int mask)
{
    object *items = ({ });
    
    string *itemsToCheck = materialsObject()->slotsUsedByItemMask(mask);
    
    if(sizeof(itemsToCheck))
    {
        foreach(string item in itemsToCheck)
        {
            if(item && member(itemRegistry["equipped"], item) && 
                itemRegistry["equipped"][item] &&
                objectp(itemRegistry["equipped"][item]) &&
                (member(items, itemRegistry["equipped"][item]) < 0))
            {
                items += ({ itemRegistry["equipped"][item] });
            }
        }
    }
    return items + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int usingEquipmentOfType(string type, int location)
{
    int ret = 0;

    object *items = equippedByMask(AllWielded | AllWorn);
    if(sizeof(items) > 0)
    {
        foreach(object equipment in items)
        {
            ret ||= (equipment->query("weapon type") == type) ||
                (equipment->query("armor type") == type) ||
                (member(
                    materialsObject()->slotsUsedByItemMask(equipment->query("equipment locations")),
                    type) > -1);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object equipmentInSlot(string slot)
{
    object ret = 0;
    
    if(slot && stringp(slot) && member(itemRegistry, "equipped") &&
       mappingp(itemRegistry["equipped"]) &&
       member(itemRegistry["equipped"], slot) &&
       itemRegistry["equipped"][slot] && 
       objectp(itemRegistry["equipped"][slot]))
    {
        ret = itemRegistry["equipped"][slot];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int removeEquippedItemFromSlot(string slot)
{
    int ret = 0;
    
    if(equipmentInSlot(slot))
    {
        itemRegistry["equipped"][slot] = 0;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int equipItemInSlot(string slot, object item)
{
    int ret = 0;
    
    if(slot && stringp(slot) && member(itemRegistry, "equipped") &&
       mappingp(itemRegistry["equipped"]) &&
       member(itemRegistry["equipped"], slot) &&
       !itemRegistry["equipped"][slot])
    {
        itemRegistry["equipped"][slot] = item;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void inventoryEvent(string event)
{
    object eventObj = getService("events");
    if(eventObj && objectp(eventObj))
    {
        eventObj->notify(event);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int unequip(object itemToUnequip, int silently)
{
    int ret = 0;
    if(isEquipment(itemToUnequip) && (itemToUnequip->canUnequip() || silently)
       && isEquipped(itemToUnequip))
    {
        int itemMask = itemToUnequip->query("equipment locations");
        if(itemToUnequip->query("offhand") && (itemMask != TwohandedWeapon))
        {
            itemMask = OffhandWeapon;
        }
        
        ret = itemToUnequip->canUnequip() || silently;
        
        string *slotsToUnequip = materialsObject()->slotsUsedByItemMask(itemMask);
        foreach(string slot : slotsToUnequip)
        {
            if(equipmentInSlot(slot) == itemToUnequip)
            {
                removeEquippedItemFromSlot(slot);
            }
        }
    }
    if(ret)
    {    
        inventoryEvent("onUnequip");
        if(itemToUnequip->query("register event handler"))
        {
            object events = getService("events");
            if(events)
            {
                events->unregisterEvent(itemToUnequip);
            }
        }        
    }    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int equip(object itemToEquip)
{
    int ret = 0;

    if(isEquipment(itemToEquip) && canEquip(itemToEquip))
    {
        int itemMask = itemToEquip->query("equipment locations");
        if(itemToEquip->query("offhand") && (itemMask != TwohandedWeapon))
        {
            itemMask = OffhandWeapon;
        }
        
        if(itemMask)
        {
            int failedUnequip = 0;
            object *itemsToUnequip = equippedByMask(itemMask);
            foreach(object item : itemsToUnequip)
            {
                failedUnequip += unequip(item);
            }                    
                        
            string *slotsToEquip = materialsObject()->slotsUsedByItemMask(itemMask);
            
            if(!failedUnequip && !itemToEquip->isEquipped())
            {
                ret = itemToEquip->canEquip(this_object());
                if(ret)
                {
                    foreach(string slot : slotsToEquip)
                    {
                        if(ret)
                        {
                            ret = equipItemInSlot(slot, itemToEquip);
                        }
                    }
                }    
            }
        }
    }
    if(ret)
    {
        if(itemToEquip->query("register event handler"))
        {
            object events = getService("events");
            if(events)
            {
                events->registerEvent(itemToEquip);
            }
        }
        inventoryEvent("onEquip");
    }  
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validModifier(string type, string modifier)
{
    int ret = 0;
    if(type && modifier && stringp(type) && stringp(modifier))
    {
        string serviceName = "valid" + capitalize(type);
    
        if(function_exists(serviceName))
        {
            string *modifiers = call_other(this_object(), serviceName);
            
            if(modifiers && (member(modifiers, modifier) > -1))
            {
                ret = 1;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object *registeredInventoryObjects()
{
    object *ret = 0;
    
    if(itemRegistry && 
       member(itemRegistry, "guild objects") &&
       mappingp(itemRegistry["guild objects"]))
    {
        ret = m_values(itemRegistry["guild objects"]);
        if(sizeof(ret) && !objectp(ret[0]))
        {
            ret = 0;
        }
    }
    return ret + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask object registeredInventoryObject(string fullyQualifiedName)
{
    object ret = 0;
    if(itemRegistry && 
       member(itemRegistry, "guild objects") &&
       mappingp(itemRegistry["guild objects"]) &&
       member(itemRegistry["guild objects"], fullyQualifiedName))
    {
        ret = itemRegistry["guild objects"][fullyQualifiedName];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int registerObjectAsInventory(object item)
{
    int ret = 0;
    if(isModifierItem(item) && itemRegistry && 
       member(itemRegistry, "guild objects") &&
       mappingp(itemRegistry["guild objects"]) &&
       (!member(itemRegistry["guild objects"], item->fullyQualifiedName()) ||
       !itemRegistry["guild objects"][item->fullyQualifiedName()]))
    {
        itemRegistry["guild objects"][item->fullyQualifiedName()] = item;
        ret = 1;
    }
    if(ret)
    {
        if(item->query("register event handler"))
        {
            object events = getService("events");
            if(events)
            {
                events->registerEvent(item);
            }
        }
        inventoryEvent("onRegisterItem");
    }      
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int unregisterObjectAsInventory(object item)
{
    int ret = 0;
    if(isModifierItem(item) && itemRegistry && 
        member(itemRegistry, "guild objects") &&
        mappingp(itemRegistry["guild objects"]) &&
        member(itemRegistry["guild objects"], item->fullyQualifiedName()))
    {
        m_delete(itemRegistry["guild objects"], item->fullyQualifiedName());
        ret = 1;
    }
    if(ret)
    {
        inventoryEvent("onUnregisterItem");
        if(item->query("register event handler"))
        {
            object events = getService("events");
            if(events)
            {
                events->unregisterEvent(item);
            }
        }        
    }      
    return ret;
}
       
/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetModifier(string type, string modifier)
{
    int ret = 0;
 
    if(validModifier(type, modifier))
    {
        object *equippedItems = equippedByMask(AllWorn | AllWielded) +
            registeredInventoryObjects();
        foreach(object item : equippedItems)
        {
            // Item in this array CAN be null
            if(item && objectp(item) && (isEquipment(item) || isModifierItem(item)))
            {   
                int itemVal = item->query(modifier);
                if(intp(itemVal))
                {
                    ret += itemVal;
                }
            }
        }
    }
    return ret;
}
    
/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryAttributeBonus(string attribute)
{
    return inventoryGetModifier("attributes", sprintf("bonus %s", attribute));
}
     
/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetArmorClass()
{
    return inventoryGetModifier("combatModifiers", "armor class");
}    

/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetDefenseBonus(string damageType)
{
    int ret = inventoryGetModifier("combatModifiers", "bonus defense");

    object *equippedItems = equippedByMask(AllWorn | AllWielded) +
        registeredInventoryObjects();
    object armor = equipmentInSlot("armor");
    
    foreach(object item : equippedItems)
    {
        if(item && objectp(item) && (isEquipment(item) || isModifierItem(item)))
        {
            mapping resistances = item->query("resistances");
            if(resistances && mappingp(resistances) && 
               member(resistances, damageType) && 
               resistances[damageType] && 
               intp(resistances[damageType]))
            {
                ret += resistances[damageType];
            }

            if((armor == item) && materialsObject())
            {
                ret += materialsObject()->getMaterialDefense(armor, damageType);
            }
            else
            {
                ret += item->query("armor class");
            }
        }
    }  
        
    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
private nomask int encumberanceForObject(object item, string skill)
{
    int ret = 0;

    if (item && objectp(item))
    {
        ret = item->query("encumberance");
        string skillType = item->query(skill);

        if (has("skills") && skillType && stringp(skillType))
        {
            if (materialsObject())
            {
                ret += materialsObject()->getMaterialEncumberance(item);
            }
            ret -= call_other(this_object(), "getSkillModifier",
                skillType);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetEncumberance()
{
    // Only armor and weapon encumberance is used for this
    int ret = 0;
    
    ret += encumberanceForObject(equipmentInSlot("armor"), "armor type") +
        encumberanceForObject(equipmentInSlot("wielded primary"), "weapon type") + 
        encumberanceForObject(equipmentInSlot("wielded offhand"), "weapon type");

    return (ret > 0) ? ret : 0;
}   
    
/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetDefendAttackBonus()
{
    int ret = inventoryGetModifier("bonusSkills", "bonus parry") +
              inventoryGetModifier("combatModifiers", "defense class") +
              inventoryGetModifier("combatModifiers", "bonus defense class") +
              inventoryGetModifier("bonusSkills", "bonus dodge");
              
    // Might want to make this allow a bonus for any offhand weapon. For now,
    // only shields give a bonus. IsEquipped does all of the needed
    // object checks (not null, is equipment, etc)
    object offhand = equipmentInSlot("wielded offhand");
    if(isEquipped(offhand))
    {
        string weaponType = offhand->query("weapon type");
        if(weaponType && stringp(weaponType) && (weaponType == "shield") && has("skills"))
        {
            ret += call_other(this_object(), "getSkillModifier",
                weaponType);
        }
        
        if(materialsObject())
        {
            ret += materialsObject()->getMaterialDefendAttack(offhand);
        }        
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetAttackBonus(object weapon)
{
    int ret = 0;
    object *equippedItems = equippedByMask(AllWorn) + 
        registeredInventoryObjects();
    string skillToUse = 0;
    
    if(isEquipped(weapon))
    {
        equippedItems += ({ weapon });
        
        string skillToUse = weapon->query("weapon type");
        if (skillToUse && stringp(skillToUse) && has("skills"))
        {
            ret += call_other(this_object(), "getSkillModifier",
                skillToUse);
        }

        if(validModifier("combatModifiers", "skill level"))
        {
            ret -= weapon->query("skill level");            
        }
        
        if(materialsObject())
        {
            ret += materialsObject()->getMaterialAttack(weapon);
        }

        object offhand = equipmentInSlot("wielded offhand");
        if (isEquipped(offhand))
        {
            string weaponType = offhand->query("weapon type");
            if (weaponType && stringp(weaponType) && (weaponType != "shield") && has("skills"))
            {
                ret += (((offhand == weapon) ? -10 : -5) + 
                    call_other(this_object(), "getSkillModifier", "dual wield"));
            }
        }
    }
    
    foreach(object item in equippedItems)
    {
        if(item && objectp(item) && (isEquipment(item) || isModifierItem(item)) &&
           validModifier("combatModifiers", "bonus attack"))
        {
            int itemBonus = item->query("bonus attack");
            if(intp(itemBonus))
            {
                ret += itemBonus;
            }
        }
    }  
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int inventoryGetDamageBonus(object weapon, string damageType)
{
    int ret = 0;
    object *equippedItems = equippedByMask(AllWorn) + 
        registeredInventoryObjects();
    string skillToUse = 0;
    
    if(isEquipped(weapon))
    {
        equippedItems += ({ weapon });
        skillToUse = weapon->query("weapon type");   
        if (skillToUse && stringp(skillToUse) && has("skills") && (damageType == "physical"))
        {
            ret += call_other(this_object(), "getSkillModifier", skillToUse) + 
                weapon->query("weapon class");
        }

        if(materialsObject())
        {
            ret += materialsObject()->getMaterialDamage(weapon, damageType);
        }
    }
    
    foreach(object item : equippedItems)
    {
        if(item && objectp(item) && (isEquipment(item) || isModifierItem(item)))
        {
            mapping enchantments = item->query("enchantments");
            if(enchantments && mappingp(enchantments) && 
               member(enchantments, damageType) && 
               enchantments[damageType] && 
               intp(enchantments[damageType]))
            {
                ret += enchantments[damageType];
            }
        }
        if (item && objectp(item) && (isEquipment(item) || isModifierItem(item)) &&
            validModifier("combatModifiers", "bonus damage") && (damageType == "physical"))
        {
            int itemBonus = item->query("bonus damage");
            if (intp(itemBonus))
            {
                ret += itemBonus;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getExtraDamageTypes(object weapon)
{
    string *types = ({});
    
    if(isEquipped(weapon))
    {
        types += ({ "physical" });
        mapping enchantments = weapon->query("enchantments");
        if(enchantments && mappingp(enchantments))
        {
            foreach(string enchantment : m_indices(enchantments))
            {
                if(enchantment && stringp(enchantment))
                {
                    types += ({ enchantment });
                }
            }
        }
        object materialsObj = materialsObject();
        if(materialsObj)
        {
            string extraDamage = materialsObj->hasExtraAttackType(weapon);
            if(extraDamage)
            {
                types += ({ extraDamage });
            }
        }

        types = m_indices(mkmapping(types));
    }
    return types;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int Money(int newMoney)
{
    // newMoney must be a positive number
    if(intp(newMoney) && (newMoney > 0))
    {
        money = newMoney;
    }
    return money;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addMoney(int moneyToAdd)
{
    int ret = 0;
    if(intp(moneyToAdd))
    {
        ret = 1;
        money += moneyToAdd;
        if(money < 0)
        {
            money = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object transferMoney(int moneyToDrop)
{
    object ret = 0;
    if(Money() >= moneyToDrop)
    {
        ret = clone_object("/obj/money");
        if(ret)
        {
            ret->set_money(moneyToDrop);
            addMoney(-moneyToDrop);
        }
    }
    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
public nomask int transferItemsTo(object destination)
{
    int ret = 0;
    
    if(destination && objectp(destination))
    {
        foreach(object item : equippedByMask(AllWielded | AllWorn))
        {
            if(item)
            {
                item->unequip(item->query("name"), Silently);
            }
        }
        
        foreach(object item : all_inventory())
        {
            if(item && objectp(item) && !item->drop(Silently))
            {
                move_object(item, destination);
            }
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
// These will need to get fixed after I hack the driver
public nomask int add_weight(int weightToAdd)
{
    int ret = 0;
    
    object attributes = getService("attributes");
    if(attributes)
    {
        int maxWeight = 2 * attributes->Str() + 10;
        ret = ((weightToAdd + weight) > maxWeight) ? 0 : 1;
        if (ret)
        {
            weight += weightToAdd;
            if (weight < 0)
            {
                weight = 0;
            }
        }
    }
    else
    {
        ret = 1;
    }
    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
public nomask int can_put_and_get()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string colorizeText(object item, int verbose)
{
    string ret = "";

    if (item && item->short())
    {
        string formatter = BoldWhite;

        if (materialsObject() && (materialsObject()->getMaterialCraftsmanshipBonus(item) > 4))
        {
            formatter = BoldGreen;
        }
        else if (materialsObject() && (materialsObject()->getMaterialCraftsmanshipBonus(item)))
        {
            formatter = Green;
        }
        else if (item->query("enchanted") > 4)
        {
            formatter = BoldMagenta;
        }
        else if (item->query("enchanted"))
        {
            formatter = Magenta;
        }
        ret = sprintf(formatter, item->short());

        if (verbose)
        {
            string details = "   " + materialsObject()->getMaterialDetails(item);
            ret += details ? details : "";
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string equipmentText(string item, int verbose)
{
    string ret = colorizeText(equipmentInSlot(item), verbose);
    if (ret == "")
    {
        ret = sprintf(BoldBlack, "nothing");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask string inventoryText(int verbose)
{
    string ret = "";

    object *equippedItems = equippedByMask(AllWielded | AllWorn);

    if (sizeof(equippedItems))
    {
        string eqFormatter = sprintf(Red, "| ") + Cyan + "%s\n";

        ret += sprintf(Red, "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        ret += sprintf(eqFormatter, "Primary Weapon:\t", equipmentText("wielded primary", verbose));
        ret += sprintf(eqFormatter, "Equipped Offhand:\t", equipmentText("wielded offhand", verbose));
        ret += sprintf(Red, "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        ret += sprintf(eqFormatter, "Worn Armor:\t\t", equipmentText("armor", verbose));
        ret += sprintf(eqFormatter, "Worn Helmet:\t\t", equipmentText("helmet", verbose));
        ret += sprintf(eqFormatter, "Worn Gloves:\t\t", equipmentText("gloves", verbose));
        ret += sprintf(eqFormatter, "Worn Boots:\t\t", equipmentText("boots", verbose));
        ret += sprintf(eqFormatter, "Worn Cloak:\t\t", equipmentText("cloak", verbose));
        ret += sprintf(eqFormatter, "Worn Amulet:\t\t", equipmentText("amulet", verbose));
        ret += sprintf(eqFormatter, "Worn Belt:\t\t", equipmentText("belt", verbose));
        ret += sprintf(eqFormatter, "Worn Arm Greaves:\t", equipmentText("arm greaves", verbose));
        ret += sprintf(eqFormatter, "Worn Leg Greaves:\t", equipmentText("leg greaves", verbose));
        ret += sprintf(eqFormatter, "Worn Bracers:\t\t", equipmentText("bracers", verbose));
        ret += sprintf(eqFormatter, "Worn First Ring:\t", equipmentText("ring 1", verbose));
        ret += sprintf(eqFormatter, "Worn Second Ring:\t", equipmentText("ring 2", verbose));
        ret += sprintf(Red, "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    object *allItems = all_inventory(this_object());
    int addFooter = 0;
    foreach(object equipment in allItems)
    {
        if ((member(equippedItems, equipment) == -1) && equipment->short())
        {
            ret += sprintf(Red, "| ") + colorizeText(equipment, verbose) + "\n";
            addFooter = 1;
        }
    }
    if (addFooter)
    {
        ret += sprintf(Red, "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    return ret;
}


