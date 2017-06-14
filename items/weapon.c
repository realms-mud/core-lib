//*****************************************************************************
// Class: weapon
// File Name: weapon.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
inherit "/lib/items/equipment.c";

private nosave string ItemTypesBlueprint = "/lib/dictionaries/materialsDictionary.c";
    
/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    if(element == "damage type")
    {
        object itemTypes = load_object(ItemTypesBlueprint);
        if (itemTypes && objectp(itemTypes))
        {
            ret = itemTypes->getMaterialDamageType(this_object());
        }
    }
    else
    {
        ret = "equipment"::query(element);
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
                object itemTypes = load_object(ItemTypesBlueprint);
                if(itemTypes && objectp(itemTypes) &&
                   itemTypes->isValidWeaponType(data))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Weapon: The 'weapon type' element "
                        "must be a string as defined in the keys of the "
                        "itemTypes mapping in %s.\n", ItemTypesBlueprint));          
                }
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
public nomask int unequip(string item, int silently)
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