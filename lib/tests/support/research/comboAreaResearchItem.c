//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/combinedInstantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "combo blarg3");
    addSpecification("source", "blarg");
    addSpecification("description", "This is combo active research");
    addSpecification("scope", "area");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 1);
    addSpecification("maximum combination chain", 3);
    addSpecification("combination rules", ([
        "must include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemA.c",
            "lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemC.c",
            "lib/tests/support/research/comboPartResearchItemD.c",
            "lib/tests/support/research/comboPartResearchItemI.c", }),
        "can include only one of": ({ 
            "lib/tests/support/research/comboPartResearchItemE.c",
            "lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "lib/tests/support/research/comboPartResearchItemG.c",
            "lib/tests/support/research/comboPartResearchItemH.c", })]));
    addSpecification("modifiers", ({ 
    ([
        "type": "research",
        "research item": "lib/tests/support/research/comboPartResearchItemH.c",
        "name": "Combo stuff",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]) }));
    addSpecification("cooldown", 1);
    addSpecification("event handler", "usedComboEvent");
    addSpecification("command template", "do to area ##Combinations##");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::ready## a turnip ");
}
