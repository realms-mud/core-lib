//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Blade Focus");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with deepened focus on the spell blade "
        "technique. Through disciplined meditation "
        "and endless repetition, the spell sword "
        "refines the mental pathways needed to "
        "simultaneously maintain a blade's edge and "
        "a spell's weave, making what was once "
        "difficult appear effortless.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus long sword", 2);
}
