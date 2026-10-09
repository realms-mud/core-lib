//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Kindle");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research improves the battlemage's "
        "ability to kindle elemental fire within a blade, granting a small "
        "persistent bonus to fire channeling.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/flame-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 2);
    addSpecification("bonus fire attack", 1);
}
