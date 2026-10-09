//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward of Ages");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ward of ages, a protective "
        "sorcery that grows stronger with the "
        "passage of time. The longer the battlemage "
        "maintains this enchantment, the more "
        "resilient it becomes, feeding on the "
        "accumulated weight of moments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "supreme-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 6);
    addSpecification("bonus resist physical", 5);
    addSpecification("bonus resist magical", 5);
}
