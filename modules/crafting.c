//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave object CraftingItem;

/////////////////////////////////////////////////////////////////////////////
private nomask void craftingEvent(string event)
{
    object eventObj = getService("events");
    if (eventObj && objectp(eventObj))
    {
        eventObj->notifySynchronous(event, CraftingItem);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs object itemBeingCrafted(object item)
{
    if (item && objectp(item))
    {
        CraftingItem = item;
        craftingEvent("onCraftingStarted");
    }
    return CraftingItem;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void completeCrafting()
{
    if (CraftingItem)
    {
        move_object(CraftingItem, this_object());
        craftingEvent("onCraftingCompleted");
        CraftingItem = 0;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void abortCrafting()
{
    if (CraftingItem)
    {
        destruct(CraftingItem);
        craftingEvent("onCraftingAborted");
        CraftingItem = 0;
    }
}
