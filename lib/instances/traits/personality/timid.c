//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "timid");
    addSpecification("description", "You tend to lack confidence in "
        "yourself and generally show a lack of courage when interacting "
        "with others.");
    addSpecification("root", "coward");
    addSpecification("opposing root", "brave");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -10);
    addSpecification("penalty to persuasion", 2);
}
