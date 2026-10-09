//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elder Knowledge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with elder knowledge passed down from "
        "the most ancient of elven sorcerers. These "
        "secrets predate the written word and were "
        "preserved only through direct mind-to-mind "
        "transmission across the generations.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/"
        "profound-understanding.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 4);
    addSpecification("bonus spell points", 25);
}
