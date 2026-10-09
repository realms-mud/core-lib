//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Profound Understanding");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with a profound understanding of the "
        "fundamental nature of magic. The battlemage "
        "perceives sorcery not as a collection of "
        "spells but as a living force with its own "
        "currents and tides, learning to ride those "
        "flows rather than fighting against them.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "star-shield.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus intelligence", 1);
}
