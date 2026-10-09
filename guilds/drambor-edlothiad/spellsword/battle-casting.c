//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battle Casting");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enables effective "
        "spellcasting during melee combat.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/spell-weave.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 5
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus attack", 1);
}
