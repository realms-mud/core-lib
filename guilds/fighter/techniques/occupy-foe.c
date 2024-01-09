//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Occupy Foe");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to force an enemy to engage with them in combat.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 1
        ]));
    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 10);
    addSpecification("stamina point cost", 25);
    addSpecification("supercede targets", 1);

    addSpecification("command template", "occupy foe [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::take## an aggressive stance, forcing ##TargetName## "
        "to attack ##InitiatorObjective##.");
}
