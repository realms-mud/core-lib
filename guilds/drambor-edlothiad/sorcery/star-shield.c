//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Star Shield");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the star shield, an advanced "
        "protective sorcery that draws power from "
        "celestial bodies. The battlemage manifests "
        "a constellation of tiny points of light "
        "that orbit their body, each one deflecting "
        "incoming attacks with concentrated force.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "moonlight-veil.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist physical", 3);
}
