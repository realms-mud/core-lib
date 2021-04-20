//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Defensive Stance");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to move into a cautious, defense-oriented stance. "
        "They will sacrifice attack ability with an enhanced ability to "
        "prevent an enemy's attack.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 1
        ]));
    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);
    addSpecification("command template", "defensive stance");
    addSpecification("trait", 
        "/guilds/fighter/techniques/traits/defensive-stance-trait.c");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::take## a defensive stance, poising "
        "##InitiatorPossessive## ##InitiatorWeapon## to parry attacks.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::be## no longer in a defensive stance.");
}
