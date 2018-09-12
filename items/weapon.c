//*****************************************************************************
// Class: weapon
// File Name: weapon.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/items/equipment.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "damage type":
        {
            ret = materialsObject()->getMaterialDamageType(this_object());
            break;
        }
        case "weapon attack":
        {
            ret = member(itemData, "weapon attack") ? itemData["weapon attack"] :
                materialsObject()->getBlueprintModifier(this_object(), "default attack");

            if (member(itemData, "crafting attack"))
            {
                ret += itemData["crafting attack"];
            }
            break;
        }
        case "weapon class":
        {
            ret = member(itemData, "weapon class") ? itemData["weapon class"] :
                materialsObject()->getBlueprintModifier(this_object(), "default wc");

            if (member(itemData, "crafting weapon class"))
            {
                ret += itemData["crafting weapon class"];
            }
            break;
        }
        case "defense class":
        {
            ret = member(itemData, "defense class") ? itemData["defense class"] :
                materialsObject()->getBlueprintModifier(this_object(), "default dc");

            if (member(itemData, "crafting defense class"))
            {
                ret += itemData["crafting defense class"];
            }
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                "equipment"::query("weapon type");
            break;
        }
        case "weapon type":
        {
            ret = member(itemData, "weapon type") ? itemData["weapon type"] :
                materialsObject()->getBlueprintModifier(this_object(), "skill to use");
            break;
        }
        case "type":
        {
            ret = "weapon";
            break;
        }
        default:
        {
            ret = "equipment"::query(element);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int checkBlueprint(string data)
{
    int ret = 0;
    if (data && stringp(data))
    {
        ret = materialsObject()->isValidWeaponBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
    }
    else
    {
        raise_error(sprintf("Weapon: The 'blueprint' element must be"
            " a string as defined in the keys of the weaponBlueprints"
            " mapping in %s.\n",
            MaterialsBlueprint));
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
            case "defense class":
            case "weapon class":
            case "weapon attack":
            {
                if(data && intp(data))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Weapon: The passed '%s' data "
                        "must be an integer.\n", element));
                }
                break;
            }
            case "hit method":
            {
                if(data && stringp(data) && function_exists(data, this_object()))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Weapon: The passed '%s' %s "
                        "must be a function that exists in this item.\n", 
                        data, element));
                }
                break;                
            }
            case "weapon type":
            {
                if(materialsObject()->isValidWeaponType(data))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Weapon: The 'weapon type' element "
                        "must be a string as defined in the keys of the "
                        "itemTypes mapping in %s.\n", MaterialsBlueprint));
                }
                break;
            }
            case "blueprint":
            {
                ret = checkBlueprint(data);
                break;
            }
            default:
            {
                ret = "equipment"::set(element, data);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int offhand(string item)
{
    int ret = 0;

    if (item && stringp(item))
    {
        ret = equip(sprintf("%s offhand", item));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int equip(string item)
{
    int ret = 0;

    string *check = regexp(({item}), ".* offhand");
    if(sizeof(check))
    {
        // We have an attempt to wield this offhand. This key can never be set
        // via the 'set' method. This approach is also called "a hack"
        itemData["offhand"] = 1;
        item = regreplace(item, "(.*) offhand", "\\1");
        ret = "equipment"::equip(item);
        
        if(!ret)
        {
            // Yeah, this is awful...
            m_delete(itemData, "offhand");
        }
    }
    else
    {
        ret = "equipment"::equip(item);
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int unequip(string item, int silently)
{
    int ret = "equipment"::unequip(item, silently);
    
    // If this was wielded offhand, remove that property
    if(query("offhand"))
    {
        m_delete(itemData, "offhand");
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    if(!living(environment()) && query("offhand"))
    {
        m_delete(itemData, "offhand");
    }
    
    add_action("equip", "wield");
    add_action("offhand", "offhand");
    add_action("unequip", "unwield");
    "equipment"::init();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canDamageEthereal()
{
    int canDamage = (materialsObject()->getMaterialCraftsmanshipBonus(
        this_object()) > 4);

    string *damageTypes = 
        materialsObject()->getMaterialDamageType(this_object());
    if (query("enchantments"))
    {
        damageTypes += m_indices(query("enchantments"));
    }
    if (sizeof(damageTypes))
    {
        foreach(string validDamage in ({ "electricity", "energy", "evil", "good",
            "fire", "magical" }))
        {
            if (member(damageTypes, validDamage) > -1)
            {
                canDamage = 1;
                break;
            }
        }
    }
    return canDamage;
}
