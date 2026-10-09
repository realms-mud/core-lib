//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fluid Motion");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with mastery of fluid motion techniques. "
        "By channeling a constant trickle of arcane "
        "energy through joints and sinews, the "
        "battlemage achieves an almost supernatural "
        "fluidity of movement that allows blade "
        "and spell to flow seamlessly together.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "arcane-instinct.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 29
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus parry", 2);
}
