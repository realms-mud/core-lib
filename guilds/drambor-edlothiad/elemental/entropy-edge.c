//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Entropy Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents mastery of acid "
        " blade techniques. The battlemage sustains an entropic enchantment "
        "that accelerates decay in everything the blade touches.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/vitriol-blade.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
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
    addSpecification("bonus acid enchantment", 15);
    addSpecification("bonus acid attack", 15);
    addSpecification("bonus damage", 8);

    addSpecification("command template", "entropy edge");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade shimmers with the unraveling forces of entropy, matter decaying at its touch.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::release## the entropy enchantment, the blade returning to normal.");
}
