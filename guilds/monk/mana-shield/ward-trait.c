//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Shield");
    addSpecification("description",
        "A luminous weave of chi moves with your breath, sheltering the "
        "quiet center from which every movement begins.");
    addSpecification("type", "sustained effect");
    addSpecification("root", "mana shield");
    addSpecification("triggering research",
        "/guilds/monk/mana-shield/mindful-ward.c");
}
