//*****************************************************************************
// Class: armor
// File Name: armor.c
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
    return "equipment"::query(element);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;
    
    if(element && stringp(element))
    {
        switch(element)
        {
            case "armor class":
            {
                if(data && intp(data))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Armor: The passed '%s' data "
                        "must be an integer.\n", element));
                }
                break;
            }
            case "armor type":
            {
                object itemTypes = load_object(ItemTypesBlueprint);
                if(itemTypes && objectp(itemTypes) && data && stringp(data) &&
                   itemTypes->isValidArmorType(data))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Armor: The 'armor type' element "
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
public void init()
{
    add_action("equip", "wear");
    add_action("unequip", "remove");
    "equipment"::init();
}

