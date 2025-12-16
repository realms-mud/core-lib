//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Aegis of the Deep");
    addSpecification("root", "mana shield");
    addSpecification("description", "You are surrounded by a protective "
        "barrier of sacred water.");

    addSpecification("triggering research",
        "/guilds/children-of-ilyrth/devotion/root.c");
}
