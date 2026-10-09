//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eldritch Combatant");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research becomes an eldritch "
        "combatant, equally deadly with spell "
        "and sword.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/spellsword/arcane-flow.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus spellcraft", 4);
}
