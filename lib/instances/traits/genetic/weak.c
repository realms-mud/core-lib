//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "weak");
    addSpecification("description", "You are a rather wimpy person.");
    addSpecification("root", "weak");
    addSpecification("opposing root", "strong");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("penalty to strength", 2);
    addSpecification("cost", -1);
}
