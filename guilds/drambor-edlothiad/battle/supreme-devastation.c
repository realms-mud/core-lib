//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Devastation");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research amplifies all battle magic "
        " to supreme levels of devastation.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/supreme-battle-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 10);
    addSpecification("bonus magical essence", 8);
}
