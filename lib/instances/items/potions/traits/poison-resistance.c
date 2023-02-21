//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Poison Resistance");
    addSpecification("description", "You have quaffed the 'Poison "
        "Resistance' potion and are currently benefitting from its effects.");
    addSpecification("root", "resisting");
    addSpecification("opposing root", "vulnerable");
    addSpecification("opinion", 1);
    addSpecification("duration", 180);
    addSpecification("bonus resist poison", 50);
    addSpecification("expire message", "The effects of the 'Poison "
        "Resistance' potion subside.");
}
