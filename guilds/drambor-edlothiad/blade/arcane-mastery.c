//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents deep mastery of "
        " arcane combat arts.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/unflinching-focus.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 8);
    addSpecification("bonus magical essence", 5);
    addSpecification("bonus spell points", 50);
}
