//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "smart");
    addSpecification("description", "You are a person with exceptional "
        "intelligence and creativity.");
    addSpecification("root", "intelligent");
    addSpecification("opposing root", "unintelligent");
    addSpecification("opinion", 5);
    addSpecification("bonus intelligence", 2);
    addSpecification("cost", 1);
}
