//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/combinedInstantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "combo blarg");
    addSpecification("source", "blarg");
    addSpecification("description", "This is combo active research");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 10);
    addSpecification("maximum combination chain", 3);
    addSpecification("combination rules", ([
        "must include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemA.c",
            "/lib/tests/support/research/comboPartResearchItemB.c", }),
        "must include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemC.c",
            "/lib/tests/support/research/comboPartResearchItemD.c",
            "/lib/tests/support/research/comboPartResearchItemI.c", }),
        "can include only one of": ({ 
            "/lib/tests/support/research/comboPartResearchItemE.c",
            "/lib/tests/support/research/comboPartResearchItemF.c", }),
        "can include any of": ({ 
            "/lib/tests/support/research/comboPartResearchItemG.c",
            "/lib/tests/support/research/comboPartResearchItemH.c", })]));
    addSpecification("modifiers", ({ 
    ([
        "type": "research",
        "research item": "/lib/tests/support/research/comboPartResearchItemH.c",
        "name": "Combo stuff",
        "formula": "multiplicative",
        "base value": 1,
        "rate": 1.25
    ]) }));

    addSpecification("cooldown", 1);
    addSpecification("event handler", "usedComboEvent");
    addSpecification("command template", "do stuff ##Combinations## [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::ready## a turnip ");
}
