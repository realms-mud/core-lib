//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Insight");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research grants deeper insight into "
        " the magical nature of the world.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 1
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical essence", 2);
    addSpecification("bonus spellcraft", 2);
}
