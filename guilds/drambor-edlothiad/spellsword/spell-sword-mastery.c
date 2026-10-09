//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Sword Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research achieves mastery of the "
        "spell sword discipline.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/eldritch-combatant.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 25
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 3);
    addSpecification("bonus spellcraft", 5);
}
