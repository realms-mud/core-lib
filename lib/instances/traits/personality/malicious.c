//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "malicious");
    addSpecification("description", "You tend to revel in mean-spirited "
        "and spiteful behavior, be it speech, kicking orphans, and so on. "
        "In short, you're a real jerk.");
    addSpecification("root", "cruel");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -25);
    addSpecification("bonus intimidation", 1);
}
