//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Song of the Stars");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research channels the song of the "
        "stars through the blade.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/blade-singers-perfection.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 49
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 8);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus charisma", 2);
}
