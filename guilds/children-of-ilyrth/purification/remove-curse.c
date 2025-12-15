//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Remove Curse");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the remove curse spell. The caster invokes Ilryth's "
        "divine power to break magical curses and corrupting enchantments.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/paralysis-immunity.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("remove modifier", "cursed");

    addSpecification("cooldown", 120);
    addSpecification("event handler", "removeCurseEvent");
    addSpecification("command template", "remove curse [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ilryth's divine authority as radiant waters "
        "wash over ##TargetName##, shattering the curse that bound "
        "##TargetObjective##.");
}
