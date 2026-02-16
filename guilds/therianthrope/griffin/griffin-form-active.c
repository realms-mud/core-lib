//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Griffin Form Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("override short description", "A majestic griffin");
    addSpecification("description", "You have transformed into a powerful "
        "griffin. Eagle eyes pierce the battlefield, massive wings grant "
        "aerial dominance, and leonine claws rend with savage precision.");

    addSpecification("triggering research",
        "/guilds/therianthrope/griffin/griffin-root.c");
}
