//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Lyric verse thingy");
        addSpecification("source", "blarg");
        addSpecification("composite research",
            "lib/tests/support/research/compositeRoot.c");
        addSpecification("default composite description",
            "I'm a lyric verse thingy woman!");
        addSpecification("composite type", "lyric");
        addSpecification("description", "This is limited active research");
        addSpecification("usage summary", "This lyrically blargifies stuff.");
        addSpecification("scope", "area");
        addSpecification("research type", "granted");
        addSpecification("research cost", 1);
        addSpecification("damage stamina points", ({ ([
            "probability": 100,
            "base damage": 25,
            "range": 0
        ]) }));
        addSpecification("damage type", "sonic");
        addSpecification("event handler", "usedResearchEvent");
        addSpecification("use composite message", "##InitiatorName## ##Infinitive::drone## on, '##CompositeSegment##'");
    }
}
