//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendent Spell Sword");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research transcends the mortal "
        "limits of spell and sword.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/legendary-spell-sword.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 7);
    addSpecification("bonus damage", 7);
    addSpecification("bonus spellcraft", 10);
    addSpecification("bonus spell points", 75);
}
