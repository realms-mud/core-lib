//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "War Caster");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research masters the art of "
        "casting in the heat of battle.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/seamless-weave.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus reduce spell points", 5);
    addSpecification("bonus spellcraft", 3);
}
