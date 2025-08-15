//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

protected nosave string ItemTypesBlueprint = "/lib/services/materialsService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch (element)
    {
        case "type":
        {
            ret = "material";
            break;
        }
        case "encumberance":
        {
            ret = member(itemData, "encumberance") ? itemData["encumberance"] :
                materialsObject()->getBlueprintModifier(this_object(), "encumberance");
            break;
        }
        case "scarcity":
        {
            ret = member(itemData, "scarcity") ? itemData["scarcity"] :
                materialsObject()->getBlueprintDetails(this_object(), "scarcity");
            break;
        }
        case "class":
        {
            ret = member(itemData, "class") ? itemData["class"] :
                materialsObject()->getBlueprintDetails(this_object(), "class");
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of " + query("class");
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be " + query("class");
            break;
        }
        case "some light description":
        {
            ret = query("class");
            break;
        }
        case "crafting guilds":
        {
            object guilds = getService("guilds");
            if (guilds)
            {
                ret = guilds->guildsInClass("smithing");
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
