//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Guard");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the eternal guard, "
        " a defensive stance drawing on the undying nature of elvenkind "
        "to create nearly indestructible arcane protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/blade/arcane-fortress.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 59
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("stamina point cost", 75);
    addSpecification("cooldown", 120);
    addSpecification("bonus defense", 20);
    addSpecification("bonus parry", 12);
    addSpecification("bonus resist magical", 15);
    addSpecification("bonus hit points", 75);

    addSpecification("command template", "eternal guard");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::invoke## the eternal guard, elven magic and steel "
        "merging into an undying bastion of protection.");
    addSpecification("use ability deactivate message", "The eternal guard "
        "fades from ##InitiatorName##.");
}
