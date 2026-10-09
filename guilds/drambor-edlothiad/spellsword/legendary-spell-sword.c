//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Spell Sword");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the legendary status of a spell "
        "sword master. The warrior's name joins "
        "those whispered in reverence among the "
        "Drambor, for they have achieved a fusion "
        "of blade and sorcery that transcends "
        "anything taught by mortal instructors.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/"
        "grand-spell-sword.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus spell points", 30);
}
