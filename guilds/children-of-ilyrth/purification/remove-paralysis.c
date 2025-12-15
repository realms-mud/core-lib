//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Remove Paralysis");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the remove paralysis spell. The caster calls upon "
        "Ilyrth's flowing waters to wash away the binding forces that "
        "hold the target immobile.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 19 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/paralysis-ward.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);

    addSpecification("remove modifier", "paralysis");

    addSpecification("cooldown", 60);
    addSpecification("event handler", "removeParalysisEvent");
    addSpecification("command template", "remove paralysis [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ilryth's flowing power as sacred currents "
        "surge through ##TargetName##, freeing ##TargetObjective## from "
        "paralysis.");
}
