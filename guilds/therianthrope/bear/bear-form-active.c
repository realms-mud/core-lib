//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Bear Form Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("override short description", "A massive bear");
    addSpecification("description", "You have transformed into a massive bear. "
        "Raw physical power courses through your limbs, your hide thickens "
        "to absorb punishment, and primal fury guides your claws.");

    addSpecification("triggering research",
        "/guilds/therianthrope/bear/bear-root.c");
}
