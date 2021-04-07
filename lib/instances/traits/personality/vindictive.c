//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "vindictive");
    addSpecification("description", "You tend to hold grudges and look "
        "to avenge yourself from any slights you perceive.");
    addSpecification("root", "cruel");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -25);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus intimidation", 1);
}
