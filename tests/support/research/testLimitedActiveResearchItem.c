//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    instantaneousActiveResearchItem::init();
    addSpecification("name", "Active research");
    addSpecification("description", "This is limited active research");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 1);
    addSpecification("limited by", (["equipment": "long sword"]));
    addSpecification("increase hit points", ({ ([
        "probability":100,
        "base damage" : 25,
        "range" : 25
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("event handler", "usedResearchEvent");
    addSpecification("command template", "throw turnip at ##Target##");
}

