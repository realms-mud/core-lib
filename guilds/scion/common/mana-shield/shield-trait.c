//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Mana Shield");
    addSpecification("root", "mana shield");
    addSpecification("description", "You are surrounded by a mana shield.");

    addSpecification("triggering research",
        "/guilds/scion/common/mana-shield/root.c");
}
