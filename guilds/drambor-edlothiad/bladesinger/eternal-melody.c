//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Melody");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research connects the blade "
        "singer to the eternal melody of "
        "creation.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/bladesinger/voice-of-the-blade.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus long sword", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus charisma", 2);
}
