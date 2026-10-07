//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave object CraftingItem;

/////////////////////////////////////////////////////////////////////////////
private void recordCraftingObservation(string type)
{
    if (objectp(CraftingItem) &&
        function_exists("recordObservation", this_object()))
    {
        this_object()->recordObservation(([
            "type": type,
            "subject": program_name(CraftingItem),
            "context": ([
                "name": CraftingItem->query("name"),
                "blueprint": CraftingItem->query("blueprint"),
                "recipe": CraftingItem->query("blueprint"),
                "materials": CraftingItem->query("crafting materials"),
                "craftsmanship": CraftingItem->query("craftsmanship")
            ])
        ]));
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void craftingEvent(string event)
{
    object eventObj = getModule("events");
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
        int changed = CraftingItem != item;
        CraftingItem = item;
        if (changed)
        {
            recordCraftingObservation("craft.started");
        }
        craftingEvent("onCraftingStarted");
    }
    return CraftingItem;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void completeCrafting()
{
    if (CraftingItem)
    {
        object guilds = getModule("guilds");
        int experience = to_int(CraftingItem->query("crafting experience"));

        if (guilds && experience)
        {
            guilds->distributeExperience(experience,
                CraftingItem->query("crafting guilds"));
        }
        CraftingItem->unset("crafting in progress");
        move_object(CraftingItem, this_object());
        recordCraftingObservation("craft.completed");
        craftingEvent("onCraftingCompleted");
        CraftingItem = 0;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void abortCrafting()
{
    if (CraftingItem)
    {
        recordCraftingObservation("craft.aborted");
        destruct(CraftingItem);
        craftingEvent("onCraftingAborted");
        CraftingItem = 0;
    }
}
