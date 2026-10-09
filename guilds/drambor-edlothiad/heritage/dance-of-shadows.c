//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dance of Shadows");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the dance of shadows, a "
        "movement art learned from observing the "
        "interplay of light and darkness beneath "
        "ancient forest canopies. The battlemage "
        "weaves through combat like a flickering "
        "shadow, present one moment and gone the "
        "next.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "ethereal-movement.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 3);
}
