//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earth Blades");
    addSpecification("source", "geomancer");

    addSpecification("description", "This provides the user with the ability "
        "to summon razor-sharp blades of crystallized earth that orbit around "
        "their hands, adding slashing damage to their attacks.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "geomancer",
            "value": 9 ]));

    addPrerequisite("/guilds/geomancer/earth/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "elemental earth",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 30);

    addSpecification("spell point cost", 50);

    addSpecification("bonus attack", 10);
    addSpecification("bonus earth attack", 10);
    addSpecification("duration", 120);

    addSpecification("event handler", "earthBladesEvent");
    addSpecification("command template", "earth blades");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## hands and shards of "
        "crystallized earth begin orbiting around ##InitiatorPossessive## "
        "fingers.");
}