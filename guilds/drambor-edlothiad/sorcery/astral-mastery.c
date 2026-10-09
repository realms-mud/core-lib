//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Astral Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with astral mastery, command over the "
        "ethereal planes that border reality. The "
        "battlemage can draw energy from these "
        "adjacent realms at will, supplementing "
        "their reserves with power drawn from "
        "beyond the material world.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "cosmic-awareness.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 40);
    addSpecification("bonus heal spell points rate", 5);
}
