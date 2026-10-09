//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the supreme ward, a pinnacle of "
        "elven protective sorcery. This barrier is "
        "woven from pure willpower given form, "
        "creating an impenetrable shell of "
        "concentrated magical intent that repels "
        "all manner of assault.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "astral-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 49
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist magical", 6);
    addSpecification("bonus resist physical", 4);
}
