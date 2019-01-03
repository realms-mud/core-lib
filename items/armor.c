//*****************************************************************************
// Class: armor
// File Name: armor.c
//
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/items/equipment.c";

private nosave string ItemTypesBlueprint = "/lib/dictionaries/materialsDictionary.c";
    
/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "armor class":
        {
            ret = member(itemData, "armor class") ? itemData["armor class"] :
                materialsObject()->getBlueprintModifier(this_object(), "default ac");

            if (member(itemData, "crafting armor class"))
            {
                ret += itemData["crafting armor class"];
            }
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                "equipment"::query("armor type");
            break;
        }
        case "armor type":
        {
            ret = member(itemData, "armor type") ? itemData["armor type"] :
                materialsObject()->getBlueprintModifier(this_object(), "skill to use");
            break;
        }
        case "type":
        {
            ret = "armor";
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
        ret = materialsObject()->isValidArmorBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
    }
    else
    {
        raise_error(sprintf("Armor: The 'blueprint' element must be"
            " a string as defined in the keys of the armorBlueprints"
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
                if(data && stringp(data) && materialsObject()->isValidArmorType(data))
                {
                    itemData[element] = data;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("Armor: The 'armor type' element "
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
public void init()
{
    add_action("equip", "wear");
    add_action("unequip", "remove");
    "equipment"::init();
}
