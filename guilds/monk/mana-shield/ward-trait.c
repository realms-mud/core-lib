//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Mindful Ward");
    addSpecification("root", "mana shield");
    addSpecification("description", "Your spell points absorb incoming "
        "damage through a sustained ward.");
    addSpecification("triggering research",
        "/guilds/monk/mana-shield/mindful-ward.c");
}
