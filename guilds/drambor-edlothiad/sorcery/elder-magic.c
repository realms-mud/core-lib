//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elder Magic");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "Magic of the elder age, the deepest "
        "secrets  of elven sorcery.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/elder-knowledge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 39
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 12);
    addSpecification("bonus magical essence", 10);
    addSpecification("bonus spell points", 75);
}
