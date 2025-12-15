//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cure Poison");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the cure poison spell. The caster calls upon Ilyrth's "
        "purifying waters to neutralize poisons afflicting the target.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 9 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/toxin-dilution.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);

    addSpecification("remove modifier", "poison");

    addSpecification("cooldown", 30);
    addSpecification("event handler", "curePoisonEvent");
    addSpecification("command template", "cure poison [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ilryth's purifying power as sacred water "
        "flows through ##TargetName##, neutralizing the poison within.");
}
