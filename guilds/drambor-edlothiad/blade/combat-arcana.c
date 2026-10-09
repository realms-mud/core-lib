//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Combat Arcana");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches advanced combat "
        "arcana techniques unique to the Drambor.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/blade-harmony.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 6);
    addSpecification("bonus magical attack", 5);
    addSpecification("bonus damage", 4);
}
