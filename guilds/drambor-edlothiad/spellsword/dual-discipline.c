//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dual Discipline");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research masters the dual "
        "discipline of magic and martial arts.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/legendary-spell-sword.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus defense", 3);
}
