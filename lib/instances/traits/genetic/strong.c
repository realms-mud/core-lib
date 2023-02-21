//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "strong");
    addSpecification("description", "You are a rather brawny person.");
    addSpecification("root", "strong");
    addSpecification("opposing root", "weak");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("bonus strength", 2);
    addSpecification("cost", 1);
}
