//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

protected nosave string ItemTypesBlueprint = "/lib/dictionaries/materialsDictionary.c";

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
                materialsObject()->getBlueprintModifier(this_object(), "scarcity");
            break;
        }
        case "class":
        {
            ret = member(itemData, "class") ? itemData["class"] :
                materialsObject()->getBlueprintModifier(this_object(), "class");
            break;
        }
        case "description":
        {
            ret = member(itemData, "description") ? itemData["description"] :
                materialsObject()->getBlueprintModifier(this_object(), "description");
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}