//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "socializer");
    addSpecification("description", "You are an outgoing, sociable "
        "person, greatly enjoying the company of others.");
    addSpecification("root", "extravert");
    addSpecification("opposing root", "introvert");
    addSpecification("opinion", 1);
    addSpecification("opposing opinion", -1);
}
