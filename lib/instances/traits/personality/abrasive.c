//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "abrasive");
    addSpecification("description", "You have a knack for getting under the skin of others.");
    addSpecification("root", "harsh");
    addSpecification("opposing root", "eloquent");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -15);
    addSpecification("penalty to persuasion", 1);
}
