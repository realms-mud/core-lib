//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Supremacy");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the culmination of arcane warrior "
        "training. The battlemage's command over the "
        "interplay of magic and melee combat reaches "
        "a pinnacle, granting supremacy in both "
        "disciplines that few mortals could ever hope "
        "to match.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "warrior-transcendence.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus defense", 4);
    addSpecification("bonus spell points", 40);
}
