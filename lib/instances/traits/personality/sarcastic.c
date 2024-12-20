//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "sarcastic");
    addSpecification("description", "You typically use a sharp wit to "
        "mock and convey your contempt for the world around you - and "
        "by extension, all those imbeciles that people it.");
    addSpecification("root", "pessimistic");
    addSpecification("opposing root", "optimistic");
    addSpecification("opinion", 25);
    addSpecification("opposing opinion", -5);
}
