//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Serpent Form Active");
    addSpecification("root", "no weapon attacks");
    addSpecification("override short description", "A sinuous serpent");
    addSpecification("description", "You have transformed into a massive "
        "serpent. Venom drips from your fangs, your coils crush with "
        "tremendous force, and your scales deflect blows with ease.");

    addSpecification("triggering research",
        "/guilds/therianthrope/serpent/serpent-root.c");
}
