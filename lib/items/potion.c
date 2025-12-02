//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch (element)
    {
        case "type":
        {
            ret = "potion";
            break;
        }
        case "blueprint":
        {
            ret = member(itemData, "blueprint") ? itemData["blueprint"] :
                item::query("potion type");
            break;
        }
        case "potion type":
        {
            ret = member(itemData, "potion type") ? itemData["potion type"] :
                materialsObject()->getBlueprintDetails(this_object(), "skill to use");
            break;
        }
        case "biological effect":
        {
            if (!member(itemData, "biological effect"))
            {
                object biologicalService = getService("biological");
                itemData["biological effect"] =
                    biologicalService->getBiologicalEffect(this_object());
            }
            ret = itemData["biological effect"];
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of an object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be a potion";
            break;
        }
        case "crafting guilds":
        {
            object guilds = getService("guilds");
            if (guilds)
            {
                ret = guilds->guildsInClass("brewing");
            }
            break;
        }
        default:
        {
            ret = item::query(element);
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
        ret = materialsObject()->isValidPotionBlueprint(data);
    }

    if (ret)
    {
        itemData["blueprint"] = data;
    }
    else
    {
        raise_error(sprintf("Potion: The 'blueprint' element must be"
            " a string as defined in the keys of the potions"
            " mapping in %s.\n",
            MaterialsBlueprint));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int set(string element, mixed data)
{
    int ret = 0;

    if (element && stringp(element))
    {
        switch (element)
        {
            case "blueprint":
            {
                ret = checkBlueprint(data);
                break;
            }
            default:
            {
                ret = item::set(element, data);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int consume(string name)
{
    int ret = 0;

    if (id(name) && present(name, this_player()))
    {
        object biologicalService = getService("biological");

        ret = biologicalService->consumeItem(this_player(), this_object());
        if (ret)
        {
            outputMessageFromTemplate(
                sprintf("##UserName## ##Infinitive::%s## %s.\n",
                    query_verb(), query("name")));
            destruct(this_object());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("consume", "quaff");
    add_action("consume", "drink");
    add_action("consume", "consume");
    item::init();
}
