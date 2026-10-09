//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//                      See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell-Infused Strikes");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides the "
        "user with the ability to passively infuse "
        "every strike with residual arcane energy. "
        "Through long practice, the battlemage's "
        "weapons become natural conduits for spell "
        "power, dealing additional magical damage "
        "with each blow without conscious effort.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/"
        "elven-war-magic.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 41
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical enchantment", 3);
    addSpecification("bonus attack", 2);
}
