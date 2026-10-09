//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fey Resistance");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the innate resistance to harmful "
        "magic that characterizes fey-blooded "
        "creatures. The battlemage's aura naturally "
        "repels hostile enchantments, causing spells "
        "to slide off like water from oiled steel.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/heritage/"
        "fey-ancestry.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 23
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist magical", 8);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus resist cold", 3);
}
