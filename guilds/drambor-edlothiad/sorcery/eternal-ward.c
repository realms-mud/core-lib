//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the eternal ward, a sorcerous "
        "protection that draws upon the timeless "
        "nature of elven magic. Unlike mortal wards "
        "that decay and fade, this barrier "
        "regenerates itself perpetually from the "
        "ambient magical energy of the world.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "elder-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 5);
    addSpecification("bonus resist magical", 5);
}
