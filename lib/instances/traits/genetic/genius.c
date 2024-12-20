//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "genius");
    addSpecification("description", "You are an absolutely brilliant person with exceptional "
        "intelligence and creativity.");
    addSpecification("root", "intelligent");
    addSpecification("opposing root", "unintelligent");
    addSpecification("opinion", 10);
    addSpecification("bonus intelligence", 5);
    addSpecification("cost", 2);
}
