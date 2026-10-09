//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grand Spell Sword");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the techniques of a grand spell "
        "sword. At this level of mastery, the "
        "warrior seamlessly alternates between "
        "devastating melee combinations and "
        "precisely targeted spell-strikes without "
        "any perceptible pause or transition "
        "between the two disciplines.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "mana-surge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus spellcraft", 4);
}
