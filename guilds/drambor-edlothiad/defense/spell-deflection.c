//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Deflection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with mastery of spell deflection. "
        "Rather than merely absorbing hostile magic, "
        "the battlemage learns to recognize incoming "
        "spells by their weave patterns and redirect "
        "them harmlessly aside with precisely timed "
        "counterspell gestures.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/"
        "elven-fortitude.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 8);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus resist cold", 5);
}
