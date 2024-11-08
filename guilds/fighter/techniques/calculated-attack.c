//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Calculated Attack");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of an extremely meticulous means of discerning the "
        "direction of combat. While this is in effect, you pause your "
        "attacks, waiting for the best time to unleash a special attack. "
        "Your attacks will receive a large damage bonus dependent on how "
        "long you have taken to make your attack.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 5
        ]));
    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 50);
    addSpecification("command template", "calculated attack");
    addSpecification("trait", "/guilds/fighter/techniques/traits/calculated-attack-trait.c");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::take## a stance of carefully poising "
        "##InitiatorPossessive## ##InitiatorWeapon## for attack.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::be## no longer carefully poising "
        "##InitiatorPossessive## ##InitiatorWeapon## for attack.");
}
