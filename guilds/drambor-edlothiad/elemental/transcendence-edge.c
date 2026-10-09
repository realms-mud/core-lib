//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Transcendence Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents mastery of pure "
        " arcane blade techniques. The battlemage sustains an enchantment "
        "that transcends normal magical boundaries.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/eldritch-blade.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 57
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 90);
    addSpecification("bonus magical enchantment", 15);
    addSpecification("bonus magical attack", 15);
    addSpecification("bonus damage", 8);

    addSpecification("command template", "transcendence edge");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade shimmers with otherworldly energy as the transcendence enchantment takes hold.");
    addSpecification("use ability deactivate message", "The transcendence "
        "enchantment fades from ##InitiatorPossessive## blade.");
}
