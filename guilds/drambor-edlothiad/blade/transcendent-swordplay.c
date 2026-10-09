//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Swordplay");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research pushes the battlemage's "
        "swordplay beyond mortal limits through arcane enhancement.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/elven-war-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 12);
    addSpecification("bonus defense", 10);
    addSpecification("bonus damage", 8);
    addSpecification("bonus long sword", 10);
    addSpecification("bonus parry", 5);
}
