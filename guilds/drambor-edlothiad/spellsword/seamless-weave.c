//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Seamless Weave");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows seamless "
        "transition between spell and sword.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/battle-casting.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus spellcraft", 3);
}
