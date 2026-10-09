//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Battle Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research improves all elemental "
        "battle spells through deeper understanding.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/destructive-power.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 3);
    addSpecification("bonus elemental water", 3);
    addSpecification("bonus elemental air", 3);
}
