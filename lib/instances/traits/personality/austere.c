//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "austere");
    addSpecification("description", "You have a rather severe or strict manner "
        "about you and this typically seeps into your attitiude toward others.");
    addSpecification("root", "harsh");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("penalty to persuasion", 1);
    addSpecification("bonus intimidation", 1);
}
