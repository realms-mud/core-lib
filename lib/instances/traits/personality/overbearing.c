//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "overbearing");
    addSpecification("description", "Why nurture when you can dominate? "
        "You tend to have an unpleasant, bullying way about you.");
    addSpecification("root", "overbearing");
    addSpecification("opinion", -10);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus intimidation", 1);
}
