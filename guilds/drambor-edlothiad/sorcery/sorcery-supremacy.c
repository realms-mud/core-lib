//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sorcery Supremacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with sorcerous supremacy, a level of "
        "magical command that places the battlemage "
        "among the most powerful practitioners in "
        "existence. Every spell cast carries "
        "devastating potency, and the reserves of "
        "power available seem virtually limitless.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "timeless-magic.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 59
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 7);
    addSpecification("bonus spell points", 50);
}
