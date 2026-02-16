//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Bestial Rage Active");
    addSpecification("root", "offensive stance");
    addSpecification("description", "You have surrendered to bestial fury, "
        "sacrificing defensive awareness for savage offensive power.");

    addSpecification("triggering research",
        "/guilds/therianthrope/chimera/bestial-rage.c");
}
