//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Blade Conditioning");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the spell sword "
        "to condition their body and mind for the strain of constant spellcasting "
        "while engaged in melee combat, reducing fatigue and cost.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/arcane-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus reduce spell points", 5);
    addSpecification("bonus constitution", 2);
}
